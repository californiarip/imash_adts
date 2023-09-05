#include "set.h"
#include <iostream>

bool equal(const std::string& s1, const std::string& s2){
    if(s1.length() != s2.length())
        return false;

    for(size_t i = 0; i < s1.length(); ++i){
        if (std::tolower(s1[i]) != std::tolower(s2[i]))
            return false;
    }
    return true;
}

size_t hash(const std::string& s){
	size_t hash_val = 0;
   	for(char ch: s){
        	hash_val = (hash_val * 31) + std::tolower(ch);
    	}
    	return hash_val;
}

set::set(const set& s):
    bucket_array(new std::list<std::string>[s.bucket_array_size]),
    bucket_array_size(s.bucket_array_size),
    set_size(s.set_size)
    {
    for(int i = 0; i < bucket_array_size; i++){
        bucket_array[i] = s.bucket_array[i];
    }
}

set::set(std::initializer_list<std::string> ilist):
    bucket_array(new std::list<std::string>[4]),
    bucket_array_size(4),
    set_size(0)
    {
    for(const std::string& val : ilist){
        insert(val);
    }
}

set& set::operator=(const set& s){
    if(this == &s)
        return *this;

    delete[] bucket_array;
    bucket_array = new std::list<std::string>[s.bucket_array_size];
    bucket_array_size = s.bucket_array_size;
    set_size = s.set_size;

    for(int i = 0; i < bucket_array_size; i++){
        bucket_array[i] = s.bucket_array[i];
    }
    return *this;
}

bool set::insert(std::string val){
    size_t index = hash(val) % bucket_array_size;
    std::list<std::string>& bucket = bucket_array[index];

    for(const std::string& bucket_element: bucket){
        if(equal(bucket_element, val)){
            return false;
        }
    }

    bucket.push_front(val);
    set_size++;

    if(loadfactor() >= max_load_factor){
        size_t new_bucket_array_size = bucket_array_size * 2;
        std::list<std::string>* new_bucket_array = new std::list<std::string>[new_bucket_array_size];

        for(int i = 0; i < bucket_array_size; i++){
            for(const std::string& bucket_element : bucket_array[i]){
                size_t new_hash_val = hash(bucket_element) % new_bucket_array_size;
                new_bucket_array[new_hash_val].push_front(bucket_element);
            }
        }

        delete[] bucket_array;
        bucket_array = new_bucket_array;
        bucket_array_size = new_bucket_array_size;
    } 
    return true;
}

bool set::contains(std::string val) const{
    size_t hash_val = hash(val) % bucket_array_size;
    const std::list<std::string>& bucket = bucket_array[hash_val];

    for(const std::string& exist_val: bucket){
        if(equal(exist_val, val)){
            return true;
        }
    }
    return false;
}

bool set::remove(std::string val){
    size_t hash_val = hash(val) % bucket_array_size;
    std::list<std::string>& bucket = bucket_array[hash_val];

    for(auto it = bucket.begin(); it != bucket.end(); it++){
        if(equal(*it, val)){
            bucket.erase(it);
            set_size--;
            return true;
        }
    }
    return false;
}

void set::clear(){
    for(int i = 0; i < bucket_array_size; i++){
        bucket_array[i].clear();
    }
    set_size = 0;
}

size_t set::size() const{
    return set_size;
}

bool set::empty() const {
    return (set_size == 0);
}

set::~set() {
    delete[] bucket_array;
}
