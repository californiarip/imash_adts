#ifndef SET_H_
#define SET_H_

#include <ostream>
#include <list>
#include <cstdlib>
#include <math.h>

// Case insensitive string equality
bool equal(const std::string& s1, const std::string& s2);

// Hash function for case insensitive strings
size_t hash(const std::string& s);

class set {
	std::list<std::string>* bucket_array;
	size_t bucket_array_size;
	size_t set_size;
	const double max_load_factor = 3.0;

public:
	// Creates an empty set
	set() :
		bucket_array(new std::list<std::string>[4]),
		bucket_array_size(4),
		set_size(0)
	{

	}

	// Copy constructor
	set(const set& s);

	// Initializer list constructor
	set(std::initializer_list<std::string> ilist);

	// Copy assignment
	set& operator=(const set& s);

	// Insert the given value into the set, if it is not already there.
	// Returns true if and only if the value was not already there
	bool insert(std::string val);

	// Returns true if and only if the value is in the set
	bool contains(std::string val) const;

	// Removes the given value from the set, if it is currently there
	// Returns true if and only if the value was there to be removed
	bool remove(std::string val);

	// Remove everything from the set
	void clear();

	// Returns the number of items on the set
	size_t size() const;
	
	// Returns whether or not the set is currently empty
	bool empty() const;
	
	// Returns the number of buckets in the underlying hash table
	size_t bucketcount() const {
		return bucket_array_size;
	}

	// Returns the number of items in the bucket at index i
	size_t bucketsize(size_t i) const {
		return bucket_array[i].size();
	}
	
	// Returns the current load factor of the underlying hash table
	double loadfactor() const {
		return (double)set_size / (double)bucket_array_size;
	}

	// Returns the standard deviation of the number of items in the buckets
	double standarddev() const {
		double sum = 0.0;
		double lf = loadfactor();

		for (size_t i = 0; i < bucket_array_size; ++i) {
			double dif = bucket_array[i].size() - lf;
			sum += dif * dif;
		}

		return sqrt(sum / bucket_array_size);
	}

	// Print out the contents of the set -- here we are showing the items
	// in each of the individual buckets
	void print(std::ostream& out) const {
		for (size_t i = 0; i < bucket_array_size; ++i) {
			std::list<std::string> bucket = bucket_array[i];

			out << "bucket[" << i << "] = {";

				bool first = true;

				for (std::string val : bucket) {
					if (first) {
						out << val;
						first = false;
					} else {
						out << ", " << val;
					}
				}

			out << "}" << std::endl;
		}
	}

	// Destructor
	~set();
};

inline std::ostream& operator<<(std::ostream& out, const set& s) {
	s.print(out);
	return out;
}

#endif /* SET_H_ */
