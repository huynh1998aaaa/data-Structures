#include <iostream>
using namespace std;
template <class T>

struct Node 
{
	T val; 
	Node<T> *next; 
};

template <class T>
class MyQueue {
private:
	Node<T> *first; 
        Node<T> *last;
	int size;
public:
	MyQueue(){
		first= NULL;
		last= NULL;
		size =0;
	};
	~MyQueue(){
	};
	void addQueue(T value){
		Node<T> *newNode = new Node<T>;
		newNode->val = value;
		newNode->next= NULL;
		if(size== 0){
			first = last = newNode;
		}else{
			last->next = newNode;
			last= newNode;
		}
		size++;
		
	};
	bool deleteQueue(){
		if(size == 0) return false;
		if(first == last){
			first = last = NULL;
			delete first;
			delete last;
			size--;
			return true;
		}
		Node<T>* prev = first;
		first = prev->next;
		prev= NULL;
		delete prev;
		size--;
		return true;
	}
	T deQueue(){
		if(size == 0) return T();
		T temp;
		if(first == last){
			temp= first->val;
			first = last = NULL;
			delete first;
			delete last;
			size--;
			return temp;
		}
		Node<T>* prev = first;
		temp= prev->val;
		first = prev->next;
		prev= NULL;
		delete prev;
		size--;
		return temp;
	}
	int Lenght(){return size;};
	bool isEmpty(){
		if(size) return false;
		return true;
	}
	T front(){
		return first->val;
	}
	T back(){
		return last->val;
	}
};
