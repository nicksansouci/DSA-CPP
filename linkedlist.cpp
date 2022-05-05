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

	void printList() {
		temp = head;
		while (temp != nullptr){
			std::cout<< temp->data << "\n";
			temp = temp->next;
		}
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
		Node* before = nullptr;
		Node* after = nullptr;
		if (head == nullptr)
		{
			std::cout << "No nodes to delete." << "\n";
			return 0;
		}
		after = head->next;
		//Implemented these if statements to make sure after->next & 
		//before->next are not nullptr so I'm not dereferencing a nullptr ptr.
		if (after->next != nullptr && after->data != n)
		{
			before = after;
			after = after->next;
		}
		if (before->next != nullptr && after->data == n) {
			before->next = after->next;
			after->next = nullptr;
		}
		else
		{
			std::cout << "There is no node with the value " << n << "." << "\n";
		}
		length--;
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
	my_list.reverseList();
	my_list.printList();
	return 0;

}