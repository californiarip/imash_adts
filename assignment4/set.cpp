#include "set.h"
#include <iostream>

treenode* copynodes(treenode* original){
    if(original == nullptr)
		return nullptr;

	treenode* newNode = new treenode(original->value);
	newNode->left = copynodes(original->left);
	newNode->right = copynodes(original->right);

	return newNode;
}

void deallocatenodes(treenode* node) {
	if(node == nullptr)
		return;

	deallocatenodes(node->left);
	deallocatenodes(node->right);

	delete node;
}

bool set::contains(int i) const{
    treenode* current = root; 

    while(current != nullptr){
        if(i == current->value){
            return true;
        }
        else if(i < current->value){
            current = current->left;
        }
        else if(i > current->value){
            current = current->right;
        }
    }

    return false;
}

bool set::insert(int i){
    if(root == nullptr){
        root = new treenode(i);
        set_size++;
        return true; 
    }

    treenode* current = root;
    treenode* prev = nullptr;

    while(current != nullptr){
        if(i == current->value){
            return false;
        }
        else if(i < current->value){
            prev = current;
            current = current->left;
        }
        else if(i > current->value){
            prev = current;
            current = current->right;
        }
    }

    if(i < prev->value){
        prev->left = new treenode(i);
    }
    else if(i > prev->value){
        prev->right = new treenode(i);
    }

    set_size++;
    return true;
}

void set::clear(){
    deallocatenodes(root);
	root = nullptr;
	set_size = 0;
}

bool set::empty() const{
    return (set_size == 0);
}

size_t set::size() const{
    return set_size;
}
