#include <iostream>
#include <memory>
class Node
{
public:
	std::shared_ptr<Node> next;
	int data;
};


class Queue
{
public:
	int length;
	std::shared_ptr<Node> front;
	std::shared_ptr<Node> back;
	std::shared_ptr<Node> temp;

	Queue() : length{ 0 }, front{ nullptr }, temp{ nullptr }, back{ nullptr }{}

	~Queue() {
		while (front)
		{
			front = std::move(front->next);
		}
		std::cout << "\n";
		std::cout << "Destroyed queue" << std::endl;
	}
	//Push an item to the back of the queue.
	void push(int data)
	{
		if (length == 0)
		{
			front = std::make_shared<Node>();
			front->data = data;
			back = front;
		}
		else
		{
			temp = back;
			back = std::make_shared<Node>();
			back->data = data;
			temp->next = back;
		}
		length++;
	}
	//Pop item in the front of the queue.
	void pop()
	{
		if (length == 0) {
			std::cout << "There are no items to pop from the queue.";
			return;
		}
		else
		{
			temp = front;
			temp = std::move(temp->next);
			front->next = nullptr;
			front = temp;
		}
	}
	void print_queue() {
		temp = front;
		while (temp)
		{
			std::cout << temp->data << " ";
			temp = std::move(temp->next);
		}
	}
};






int main()
{
	Queue q1;
	q1.push(6);
	q1.push(10);
	q1.push(8);
	q1.pop();
	q1.print_queue();
}