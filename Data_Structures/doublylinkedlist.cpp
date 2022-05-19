#include <iostream>

class Node {
public:
	Node* next;
	Node* prev;
	int data;

};

class DoublyLinkedList {
public:
	int length;
	Node* temp;
	Node* head;
	Node* tail;
	DoublyLinkedList() {
		length = 0;
		temp = nullptr;
		head = nullptr;
		tail = nullptr;
	}

	void printList() {
		temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << "\n";
			temp = temp->next;
		}
		std::cout << "The length of the list is " << length << "." << "\n";
	}

	int insert(int n) {
		temp = new Node;
		temp->data = n;
		temp->next = nullptr;
		temp->prev = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = tail->next;
		}
		length++;
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
			Node* prev = tail->prev;
			if (prev != nullptr)
			{
				prev->next = nullptr;
			}
			tail->prev = nullptr;
			delete tail;
			tail = prev;
			length--;
		}
		return 0;
	}
	int pop_front()
	{
		if (length == 0)
		{
			std::cout << "There are no nodes to pop." << "\n";
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
	int remove(int n)
	{
		Node* before = nullptr;
		Node* after = nullptr;
		if (head == nullptr)
		{
			std::cout << "There are no nodes to delete." << "\n";
			return 0;
		}
		if (head->data == n)
		{
			pop_front();
		}
		temp = head;
		after = head->next;
		if (after->data != n)
		{
			after = after->next;
			temp = temp->next;
		}
		if (after->data == n && after->next != nullptr)
		{
			after = after->next;
			temp = temp->next;
			before = temp->prev;
			temp->next = nullptr;
			temp->prev = nullptr;
			after->prev = before;
			before->next = after;
			delete temp;
			length--;
		}
		if (after->data == n && after->next == nullptr)
		{
			pop_back();
		}
		else
		{
			std::cout << "There are no nodes with the value " << n << "." << "\n";
		}
		return 0;
	}
};

int main()
{
	DoublyLinkedList my_list;
	my_list.insert(0);
	my_list.insert(2);
	my_list.insert(12);
	my_list.insert(5);
	my_list.insert(6);
	my_list.printList();
	my_list.pop_back();
	my_list.remove(2);
	my_list.printList();
	
	
}