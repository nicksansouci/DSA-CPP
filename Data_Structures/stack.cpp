#include <iostream>

class Node {
public:
	Node* next;
	int data;

};

struct Stack
{
	Node* top;
	Node* temp;
	int height;

	Stack() :top{ nullptr }, height{ 0 }, temp{ nullptr }{}

	int push(int n)
	{
		temp = new Node;
		temp->data = n;
		temp->next = nullptr;
		if (height == 0)
		{
			top = temp;
		}
		else
		{
			temp->next = top;
			top = temp;
		}
		height++;
		return 0;
	}

	int pop()
	{
		if (height == 0)
		{
			std::cout << "There are no nodes to pop." << "\n";
			return 0;
		}
		else
		{
			temp = top;
			top = top->next;
			temp->next = nullptr;
			delete temp;
			height--;
		}
		return 0;
	}


	int print_stack()
	{
		if (height == 0)
		{
			std::cout << "There is nothing in the stack." << std::endl;
			return 0;
		}
		temp = top;
		while (temp)
		{
			std::cout << temp->data << "\n";
			temp = temp->next;
		}
		return 0;
		
	}
};


int main() {
	Stack my_stack;

	my_stack.push(0);
	my_stack.push(3);
	my_stack.push(9);
	my_stack.pop();
	my_stack.print_stack();
}

