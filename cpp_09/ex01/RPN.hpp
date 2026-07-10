#ifndef CLASS_RPN_HPP
# define CLASS_RPN_HPP

# include <stack>

enum Operator {
	MULT,
	DIV,
	PlUS,
	MINUS,
	UNKNOWN
};

class RPN {
	private:
		std::stack<int>	_data;
	public:
		// Constractors
		RPN(void) = default;
		RPN(const RPN& other) = default;

		// Overloaded Operators
		RPN& operator=(const RPN& other) = default;

		// Deconstructor
		~RPN(void) = default;

		// Member functions
		void pushStack(char **input);
		Operator stringToEnum(const std::string &input);


};

#endif