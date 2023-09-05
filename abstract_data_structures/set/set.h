#ifndef SET_INCLUDED
#define SET_INCLUDED    1 

#include <iostream>
// Type used to create nodes of a binary search tree for our set
// implementation
struct treenode {
	int value;
	treenode* left;
	treenode* right;

	treenode(int val)
		: value(val),
		  left(nullptr),
		  right(nullptr)
   { }

};

// This is a recursive helper function that should create and return an exact
// copy of the tree structure rooted at original
treenode* copynodes(treenode* original);

// This is a recursive helper function that should deallocate all of the nodes
// in the tree structure rooted at node
void deallocatenodes(treenode* node);

// BST-based set
class set {

	// Fields of the BST-based set object
	size_t set_size;
	treenode* root;

	// This is a recursive helper function called by print to output all of the
	// values of the tree in sorted order using an in-order traversal
	static void printhelper(std::ostream &out, treenode* node){
		if (node != nullptr) {
			if (node->left != nullptr) {
				printhelper(out, node->left);
				out << ", ";
			}
			out << node->value;
			if (node->right != nullptr) {
				out << ", ";
				printhelper(out, node->right);
			}
		}
	}

public:
	// Default ordered set is empty
	set() : set_size(0), root(nullptr) { }

	// Copy constructor
	set(const set &s) : set_size(s.set_size), root(nullptr) {
		root = copynodes(s.root);
	}

	// Initializer list constructor
	set(std::initializer_list<int> init) : set_size(0), root(nullptr) {
		for (auto el : init) {
			insert(el);
		}
	}

	// Copy assignment
	set& operator=(const set &s) {
		if (&s != this) {
			deallocatenodes(root);
			root = copynodes(s.root);
			set_size = s.set_size;
		}
		return *this;
	}

	// Returns true if the value i is in the ordered set
	bool contains(int i) const;

	// If the value i is not previously in the ordered set,
	// insert it preserving the ordering and return true;
	// Otherwise return false (indicating the value was already
	// in the set)
	bool insert(int i);

	// Remove everything from the set
	void clear();

	// Returns the number of items in the set
	size_t size() const;

	// Returns whether or not the set is currently empty
	bool empty() const;

	// Print out the contents of the set, in order from smallest to largest
	void print(std::ostream &out) const {
		out << "{";
		printhelper(out, root);
		out << "}";
	}

	// Destructor
	~set() {
		deallocatenodes(root);
	}
};

inline std::ostream& operator<<(std::ostream &out, const set &s) {
	s.print(out);
	return out;
}

#endif
