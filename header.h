#pragma once

#include <iostream>
#include <cstddef>

#define TEST_SIZE 5
#define T true
#define F false

using namespace std;


struct Node {
	int data;
	Node* next;
};

class ListOp {
private:
	
	Node* head, * tail;
	

public:
	ListOp() {
		head = nullptr;
		tail = nullptr;
	}
	~ListOp() {
		while (head) {
			tail = head->next;
			delete head;
			head = tail;
		}

	}
	void print(); //done
	void push_back(int); //done
	void push_front(int); //done
	void pop_back(); //done
	void pop_front(); //done
	void insert(int, size_t); //done
	int at(size_t); //done
	void remove(size_t); //done
	size_t get_size(); //done
	void clear(); //done
	void set(size_t, int); //done
	bool isEmpty(); //done
	int list_checker(int);
	friend ostream& operator<<(ostream& out, const ListOp& lst);
	bool contains(ListOp &);

};
