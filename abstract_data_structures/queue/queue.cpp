#include <initializer_list>
#include "queue.h"

queue::queue(const queue& q):
    	queue_size(0), 
	front(nullptr), 
	back(nullptr)
{
    if(q.front != nullptr){
        node* copyPtr = q.front;
        node* trackPtr = new node(copyPtr->value);
        front = trackPtr;
        back = trackPtr;
        queue_size++;

        while(copyPtr->next != nullptr){
            copyPtr = copyPtr->next;
            trackPtr->next = new node(copyPtr->value);
            trackPtr = trackPtr->next;
            back = trackPtr;
            queue_size++;
        }
    }
}

queue::queue(std::initializer_list<int> ilist):
    queue_size(0),
    front(nullptr),
    back(nullptr)
{
    for(int value: ilist){
        push(value);
    }
}

queue& queue::operator=(const queue& q){
    if(this != &q){
        clear();
        if(q.front != nullptr){
            node* copyPtr = q.front;
            node* trackPtr = new node(copyPtr->value);
            front = trackPtr;
            back = trackPtr;
            queue_size++;
        
            while(copyPtr->next != nullptr){
                copyPtr = copyPtr->next;
                trackPtr->next = new node(copyPtr->value);
                trackPtr = trackPtr->next;
                back = trackPtr;
                queue_size++;
            }
        }
    }
    return *this;
}

void queue::push(int val){
    node* pushPtr = new node(val);

    if(front == nullptr){
        front = pushPtr;
        back = pushPtr;
        queue_size++;
    } else{
        back->next = pushPtr;
        back = pushPtr;
        queue_size++;
    } 
}

int queue::peek() const{
    if(front == nullptr){
        throw std::runtime_error("empty queue!!");
    }
    return front->value;
}

void queue::pop(){
    if(front == nullptr){
        throw std::runtime_error("already empty queue!!");
    }
    node* delPtr = front;
    front = front->next;
    delete delPtr;
    queue_size--;
}

void queue::clear(){
    node* delPtr = front;
    while(delPtr != nullptr){
        node* trackPtr = delPtr->next;
        delete delPtr;
        delPtr = trackPtr;
    }
    queue_size = 0;
    front = 0;
    back = 0;
}

size_t queue::size() const{
    return queue_size;
}

bool queue::empty() const{
    return (queue_size == 0);
}

queue::~queue(){
    node* clrPtr = front;
    while(clrPtr != nullptr){
        node* next = clrPtr->next;
        delete clrPtr;
        clrPtr = next;
    }
}
