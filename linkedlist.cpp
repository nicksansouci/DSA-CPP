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
	LinkedList(){
		length = 0;
		temp = NULL;
		head = NULL;
		tail = NULL;
	};

	void printList() {
		temp = head;
		while (temp != NULL){
			std::cout<< temp->data << "\n";
			temp = temp->next;
		}
		std::cout << "The length of the list is " << length << "\n";
	}
	void insert(int n) 
	{
		temp = new Node;
		temp->data = n;
		temp->next = NULL;
		if (head == NULL)
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
		Node* before = NULL;
		Node* after = NULL;
		if (head == NULL)
		{
			std::cout << "No nodes to delete." << "\n";
			return 0;
		}
		after = head->next;
		//Implemented these if statements to make sure after->next & 
		//before->next are not NULL so I'm not dereferencing a NULL ptr.
		if (after->next != NULL && after->data != n)
		{
			before = after;
			after = after->next;
		}
		if (before->next != NULL && after->data == n) {
			before->next = after->next;
			after->next = NULL;
		}
		length--;
	}
	

};




int main() {

	LinkedList my_list;

	my_list.insert(5);
	my_list.insert(500);
	my_list.insert(60);
	my_list.insert(12);
	my_list.remove(60);
	my_list.printList();
	return 0;

}