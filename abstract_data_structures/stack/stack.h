#ifndef STACK_H_
#define STACK_H_

#include <ostream>

class stack {
	int *values;
	size_t stack_size;
	size_t array_capacity;

public:
	// Creates an empty stack
	stack() :
		values(new int[5]),
		stack_size(0),
		array_capacity(5)
	{
	}

	// Copy constructor
	stack(const stack& stk);

	// Initializer list constructor
	stack(std::initializer_list<int> ilist);

	// Copy assignment
	stack& operator=(const stack& stk);

	// Insert an item at the top of the stack
	void push(int val);

	// Returns the value of the topmost item of the stack;
	// throws an exception if the stack is empty
	int peek() const;

	// Remove the topmost item from the stack
	// throws an exception if the stack is empty
	void pop();

	// Remove everything from the stack
	void clear();

	// Returns the number of items on the stack
	size_t size() const;

	// Returns whether or not the stack is currently empty
	bool empty() const;

	// Print out the contents of the stack
	void print(std::ostream& out) const{

		out << "[";
		for (size_t i = 0; i < stack_size; ++i) {
			if (i > 0) {
				out << ", ";
			}
			out << values[i];
		}
		out << "]";
	}

	// Destructor
	~stack();
};

inline std::ostream& operator<<(std::ostream& out, const stack& stk){
	stk.print(out);
	return out;
}

#endif /* STACK_H_ */
