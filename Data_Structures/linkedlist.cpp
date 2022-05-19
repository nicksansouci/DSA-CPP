#include <iostream>

class Node {
public:
	Node* next;
	int data;

};

class LinkedList {
public:
	int length;
	Node* temp;
	Node* head;
	Node* tail;
	LinkedList() :length{0}, temp{nullptr}, head{nullptr}, tail{nullptr}{}

	~LinkedList() {
		temp = head;
		while (temp)
		{
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
		head = nullptr;
	}
	int pop_front()
	{
		if (length == 0)
		{
			std::cout << "There are no nodes to pop." << "\n";
			return 0;
		}
		else {
			Node* before = head;
			head = head->next;
			before->next = nullptr;
			delete before;
			length--;
		}
		return 0;
	}
	int pop_back()
	{
		if (length == 0)
		{
			std::cout << "There are no nodes to pop." << std::endl;
			return 0;
		}
		else
		{
			Node* prev = head;
			while (prev->next != tail)
			{
				prev = prev->next;
			}
			prev->next = nullptr;
			delete tail;
			tail = prev;
			length--;
		}
		return 0;
	}

	void printList() {
		temp = head;
		while (temp != nullptr){
			std::cout<< temp->data << "->" << " ";
			if (temp->next == NULL)
				std::cout << "NULL";
			temp = temp->next;
		}
		std::cout <<"\n";
		std::cout << "The length of the list is " << length << "\n";
	}
	void insert(int n) 
	{
		// Initializing many "nullptr" to make the code easier to follow/understand.
		temp = new Node;
		temp->data = n;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
		length++;
	}
	int remove(int n)
	{
		if (n == head->data)
		{
			pop_front();
		}
		if (n == tail->data)
		{
			pop_back();
		}
		else {
			Node* temp = head;
			Node* after = temp;
			while (temp->next->data != n)
			{
				temp = temp->next;
				after = temp;
			}
			after = temp->next;
			temp->next = temp->next->next;
			after->next = NULL;
			delete after;
			length--;
		}
		return 0;
	
	}
	void reverseList()
	{
		Node* before = nullptr;
		Node* after = nullptr;
		temp = head;
		while (temp)
		{
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after;
		}
		head = before;
	}
	

};




int main() {

	LinkedList my_list;

	my_list.insert(5);
	my_list.insert(500);
	my_list.insert(60);
	my_list.insert(12);
	my_list.insert(9);
	my_list.printList();
	my_list.remove(9);
	my_list.printList();
	return 0;

}