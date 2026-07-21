#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include "PmergeMe.hpp"

static std::vector<Pair> makePairs(const std::vector<int>& input);
static std::vector<int> extractWinners(const std::vector<Pair>& pairs);
static std::vector<Pair> orderPairsByWinners(const std::vector<Pair>& pairs,
											const std::vector<int>& sortedWinners);
static void buildMainAndPend(const std::vector<Pair>& orderedPairs,
							std::vector<int>& mainChain,
							std::vector<PendNode>& pend);
static std::vector<std::size_t> buildInsertionOrder(std::size_t pendSize);
static void insertPend(std::vector<int>& mainChain,
						const std::vector<PendNode>& pend,
						const std::vector<std::size_t>& order);


// -------------------- MEMBER FUNCTIONS PRIVATE --------------------

	std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int>& input) {
		if (input.size() <= 1)
			return input;

		// 1) Copy input and detach straggler if size is odd
		std::vector<int> data = input;
		std::optional<int> straggler;

		if (data.size() % 2 != 0) {
			straggler = data.back();
			data.pop_back();
		}

		// 2) Build pairs from even-sized 'data'
		std::vector<Pair> pairs = makePairs(data);

		std::vector<int> winners = extractWinners(pairs);
		std::vector<int> sortedWinners = fordJohnsonVector(winners);

		std::vector<Pair> orderedPairs = orderPairsByWinners(pairs, sortedWinners);

		std::vector<int> mainChain;
		std::vector<PendNode> pend;
		buildMainAndPend(orderedPairs, mainChain, pend); // no straggler params now

		std::vector<std::size_t> order = buildInsertionOrder(pend.size());
		insertPend(mainChain, pend, order);

		// 3) Insert straggler at the very end with full-range lower_bound
		if (straggler.has_value()) {
			std::vector<int>::iterator pos =
				std::lower_bound(mainChain.begin(), mainChain.end(), *straggler);
			mainChain.insert(pos, *straggler);
		}

		return mainChain;
	}

// -------------------- HELPERS --------------------

static std::vector<Pair> makePairs(const std::vector<int>& input) {
	std::vector<Pair> pairs;

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

static std::vector<int> extractWinners(const std::vector<Pair>& pairs) {
	std::vector<int> winners;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].large);
	return winners;
}

static std::vector<Pair> orderPairsByWinners(const std::vector<Pair>& pairs,
											const std::vector<int>& sortedWinners) {
	std::vector<Pair> orderedPairs;
	std::vector<bool> used(pairs.size(), false);

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

static void buildMainAndPend(const std::vector<Pair>& orderedPairs,
							std::vector<int>& mainChain,
							std::vector<PendNode>& pend) {
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

static std::vector<std::size_t> buildInsertionOrder(std::size_t pendSize) {
	std::vector<std::size_t> order;
	if (pendSize == 0)
		return order;

	std::vector<std::size_t> jacob;
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

	std::vector<bool> used(pendSize, false);
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

static void insertPend(std::vector<int>& mainChain,
					const std::vector<PendNode>& pend,
					const std::vector<std::size_t>& order) {
	for (std::size_t i = 0; i < order.size(); ++i) {
		const PendNode& node = pend[order[i]];

		std::vector<int>::iterator partnerIt =
			std::find(mainChain.begin(), mainChain.end(), node.partnerLarge);

		std::vector<int>::iterator pos =
			std::lower_bound(mainChain.begin(), partnerIt, node.small);

		mainChain.insert(pos, node.small);
	}
}
