#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include "PmergeMe.hpp"

static std::deque<Pair> makePairs(const std::deque<int>& input);
static std::deque<int> extractWinners(const std::deque<Pair>& pairs);
static std::deque<Pair> orderPairsByWinners(const std::deque<Pair>& pairs,
											const std::deque<int>& sortedWinners);
static void buildMainAndPend(const std::deque<Pair>& orderedPairs,
							std::deque<int>& mainChain,
							std::deque<PendNode>& pend);
static std::deque<std::size_t> buildInsertionOrder(std::size_t pendSize);
static void insertPend(std::deque<int>& mainChain,
						const std::deque<PendNode>& pend,
						const std::deque<std::size_t>& order);


// -------------------- MEMBER FUNCTIONS PRIVATE --------------------

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int>& input) {
    if (input.size() <= 1)
        return input;

    // 1) Copy input and detach straggler if size is odd
    std::deque<int> data = input;
    std::optional<int> straggler;

    if (data.size() % 2 != 0) {
        straggler = data.back();
        data.pop_back();
    }

    // 2) Build pairs from even-sized 'data'
    std::deque<Pair> pairs = makePairs(data);

    std::deque<int> winners = extractWinners(pairs);
    std::deque<int> sortedWinners = fordJohnsonDeque(winners);

    std::deque<Pair> orderedPairs = orderPairsByWinners(pairs, sortedWinners);

    std::deque<int> mainChain;
    std::deque<PendNode> pend;
    buildMainAndPend(orderedPairs, mainChain, pend); // no straggler params now

    std::deque<std::size_t> order = buildInsertionOrder(pend.size());
    insertPend(mainChain, pend, order);

    // 3) Insert straggler at the very end with full-range lower_bound
    if (straggler.has_value()) {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), *straggler);
        mainChain.insert(pos, *straggler);
    }

    return mainChain;
}

// -------------------- HELPERS --------------------

static std::deque<Pair> makePairs(const std::deque<int>& input) {
	std::deque<Pair> pairs;

	for (std::size_t i = 0; i + 1 < input.size(); i += 2) {
		Pair p;
		if (input[i] < input[i + 1]) {
			p.small = input[i];
			p.large = input[i + 1];
		} else {
			p.small = input[i + 1];
			p.large = input[i];
		}
		pairs.push_back(p);
	}
	return pairs;
}

static std::deque<int> extractWinners(const std::deque<Pair>& pairs) {
	std::deque<int> winners;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].large);
	return winners;
}

static std::deque<Pair> orderPairsByWinners(const std::deque<Pair>& pairs,
											const std::deque<int>& sortedWinners) {
	std::deque<Pair> orderedPairs;
	std::deque<bool> used(pairs.size(), false);

	for (std::size_t i = 0; i < sortedWinners.size(); ++i) {
		for (std::size_t j = 0; j < pairs.size(); ++j) {
			if (!used[j] && pairs[j].large == sortedWinners[i]) {
				orderedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	return orderedPairs;
}

static void buildMainAndPend(const std::deque<Pair>& orderedPairs,
							std::deque<int>& mainChain,
							std::deque<PendNode>& pend) {
	mainChain.clear();
	pend.clear();

	if (orderedPairs.empty())
		return;

	// first pair: both to mainChain
	mainChain.push_back(orderedPairs[0].small);
	mainChain.push_back(orderedPairs[0].large);

	// others: large -> mainChain, small -> pend
	for (std::size_t i = 1; i < orderedPairs.size(); ++i) {
		mainChain.push_back(orderedPairs[i].large);

		PendNode node;
		node.small = orderedPairs[i].small;
		node.partnerLarge = orderedPairs[i].large;
		pend.push_back(node);
	}
}

static std::deque<std::size_t> buildInsertionOrder(std::size_t pendSize) {
	std::deque<std::size_t> order;
	if (pendSize == 0)
		return order;

	std::deque<std::size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < pendSize + 1) {
		std::size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	std::size_t prev = 1;
	for (std::size_t i = 1; i < jacob.size(); ++i) {
		std::size_t curr = jacob[i];
		std::size_t upper = std::min(curr - 1, pendSize + 1);

		for (std::size_t idx = upper; idx > prev; --idx)
			order.push_back(idx - 2);

		prev = curr - 1;
		if (prev >= pendSize + 1)
			break;
	}

	std::deque<bool> used(pendSize, false);
	for (std::size_t i = 0; i < order.size(); ++i) {
		if (order[i] < pendSize)
			used[order[i]] = true;
	}

	for (std::size_t i = pendSize; i > 0; --i) {
		if (!used[i - 1])
			order.push_back(i - 1);
	}

	return order;
}

static void insertPend(std::deque<int>& mainChain,
					const std::deque<PendNode>& pend,
					const std::deque<std::size_t>& order) {
	for (std::size_t i = 0; i < order.size(); ++i) {
		const PendNode& node = pend[order[i]];

		std::deque<int>::iterator partnerIt =
			std::find(mainChain.begin(), mainChain.end(), node.partnerLarge);

		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), partnerIt, node.small);

		mainChain.insert(pos, node.small);
	}
}