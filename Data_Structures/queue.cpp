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
		std::cout << "Destructed Queue" << std::endl;
	}
	//Push an item to the back of the queue.
	void enqueue(int data)
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
	void dequeue()
	{
		if (length == 0) {
			std::cout << "There are no items to pop from the queue.";
			return;
		}
		else
		{
			temp = front;
			temp = std::move(temp->next);
			front = temp;
		}
	}
	void print_queue() {
		temp = front;
		while (temp)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
};






int main()
{
	Queue q1;
	q1.enqueue(6);
	q1.enqueue(10);
	q1.enqueue(8);
	q1.dequeue();
	q1.dequeue();
	q1.print_queue();
}