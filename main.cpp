#include "header.h"


int main() {
	ListOp ls;
	int pos;
	int index;
	int d;
	//Push back
	ls.push_back(1);
	ls.push_back(23);
	ls.push_back(10);
	ls.push_back(40);
	//Push front
	ls.push_front(0);
	ls.push_front(55);
	ls.push_front(41);
	ListOp lst;
	lst.push_back(0);
	lst.push_back(55);
	lst.push_back(41);
	
	if (ls.contains(lst) == T) {
		cout << "Cool\n";
	}
	

	//Pop back
	//ls.pop_back();

	//Pop front
	//ls.pop_front();
	/*
	size_t num; cin >> num;
	int dat; cin >> dat;
	ls.set(num, dat);
	*/
	//ls.clear();
	/*
	//Remove with index
	cin >> index;
	ls.remove(index);
	*/

	/*
	//Insert element by index
	cout << "---------------\n";
	cin >> index;
	cin >> d;
	ls.insert(d, index);
	*/
	/*
	//Find the element with it's index
	cin >> pos;
	cout << "Element which index is #" << pos << " is " << ls.at(pos) << endl;

	//Empty or not
	if (ls.isEmpty()) {
		cout << "Empty\n";
	}
	else {
		cout << "Not Empty\n";
	}
	*/
	//Size of List
	//cout << "Size: " << ls.get_size() << "\n" << ls;
	return 0;
}

void ListOp::set(size_t index, int data) {
	Node* temp_to_set = new Node;
	temp_to_set = head;
	for (size_t i = 0; i < index+1; ++i) {
		if (i == index) {
			temp_to_set->data = data;
		}
		if (index > get_size() || index < 0) {
			cout << "Error Code #1" << endl;
			return;
		}
		else {
			temp_to_set = temp_to_set->next;

		}
	}
}

void ListOp::clear() {
	while (head) {
		tail = head->next;
		delete head;
		head = tail;
	}
}

void ListOp::remove(size_t index) {
	Node* temp_to_remove = new Node;
	Node* del = new Node;
	temp_to_remove = head;
	for (size_t i = 0; i < index; ++i) {
		del = temp_to_remove;
		temp_to_remove = temp_to_remove->next;
	}
	del->next = temp_to_remove->next;
	if (del != nullptr)
		del = nullptr;
	delete del;

}

void ListOp::pop_front() {
	Node* temp_to_pop_front = new Node;
	temp_to_pop_front = head;
	head = temp_to_pop_front->next;
	if (temp_to_pop_front != nullptr)
		temp_to_pop_front = nullptr;
	delete temp_to_pop_front;
}

void ListOp::insert(int data_insert, size_t index_insert) {
	
	Node* pre = new Node;
	Node* cur = new Node;
	Node* temp = new Node;
	cur = head;
	for (size_t i = 0; i < index_insert; ++i)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = data_insert;
	pre->next = temp;
	temp->next = cur;
}



size_t ListOp::get_size() {
	size_t size = 0;
	Node* temp_to_size = new Node;
	temp_to_size = head;
	while (temp_to_size) {
		++size;
		temp_to_size = temp_to_size->next;
	}
	if (!head) {
		cout << "Error Code #";
		return 1;
	}
	return size;
}

void ListOp::pop_back() {
	Node* temp_to_pop_back = new Node;
	temp_to_pop_back = head;
	if (get_size() > 1) {
		for (size_t i = 0; i < get_size()-2; ++i) {
			temp_to_pop_back = temp_to_pop_back->next;
			tail = temp_to_pop_back->next;
		}
		tail = temp_to_pop_back;
		if(temp_to_pop_back->next != nullptr)
			temp_to_pop_back->next = nullptr;
		delete temp_to_pop_back->next;
	}

	
}

void ListOp::push_back(int data) {
	Node* temp_to_push_back = new Node;
	temp_to_push_back->next = NULL;
	temp_to_push_back->data = data;
	if (head != NULL) {
		tail->next = temp_to_push_back;
		tail = temp_to_push_back;
	}
	
	else if(head == NULL) {
		head = tail = temp_to_push_back;
	}
}

void ListOp::push_front(int data) {
	Node* temp_to_push_front = new Node;
	temp_to_push_front->data = data;
	if (head != NULL) {
		temp_to_push_front->next = head;
		head = temp_to_push_front;
	}
	else if (head == NULL) {
		head = tail = temp_to_push_front;
	}
}


void ListOp::print() {
	if (isEmpty()) return;
	Node* temp_to_print = new Node;
	temp_to_print = head;
	while (temp_to_print) {
		cout << temp_to_print->data << " | ";
		temp_to_print = temp_to_print->next;
	}
	cout << endl;

}

int ListOp::at(size_t position) {
	int size_to_find_element = -1;
	Node* temp_to_find_element = new Node;
	temp_to_find_element = head;
	while (temp_to_find_element) {
		
		++size_to_find_element;
		if (size_to_find_element != 0){
			temp_to_find_element = temp_to_find_element->next;
		}
		if (position > (get_size() - 1) || position < 0) {
			cout << "Sorry, try with another index\n";
			return 1;
		}
		if (size_to_find_element == position) {
			return temp_to_find_element->data;
		}
	}
}
	
/*

void ListOp::insert(int, size_t) {

}


*/
bool ListOp::isEmpty() {
	return head == nullptr;
}

int ListOp::list_checker(int checker) {
	Node* temp_to_check = new Node;
	temp_to_check = head;
	for (int i = 0; i <= checker; ++i) {
		if (i == checker) {
			return temp_to_check->data;
		}
		temp_to_check = temp_to_check->next;
	}
	
}

bool ListOp::contains(ListOp& subls)
{
	if (subls.isEmpty())
		return true;

	Node* current_node = new Node;
	current_node = head;
	int size_delta = get_size() - subls.get_size();
	int count = 0;

	while (current_node != nullptr)
	{
		if (count > size_delta)
			return false;

		if (current_node->data == subls.head->data)
		{
			Node* localNode = new Node;
			localNode = current_node->next;
			Node* sublistNode = new Node;
			sublistNode = subls.head->next;
			bool foundSublist = true;

			while (sublistNode != nullptr)
			{
				if (!sublistNode->data == localNode->data)
				{
					foundSublist = false;
					break;
				}
				sublistNode = sublistNode->next;
				localNode = localNode->next;
			}

			if (foundSublist)
				return true;
		}
		current_node = current_node->next;
		++count;
	}

	return false;
}


ostream& operator<<(ostream &out, const ListOp &lst) {
	Node* temp = new Node;
	temp = lst.head;
	while (temp != nullptr) {
		out << temp->data << " ";
		temp = temp->next;
	}
	
	return out;
}



