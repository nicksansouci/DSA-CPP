#include <cmath>
#include <iostream>

class Recursion
{	
public:
	// Return the fibonacci number of given int n
	int fibonacci_number(int n)
	{
		if (n <= 2)
			return 1;

		return (fibonacci_number(n - 1) + fibonacci_number(n - 2));
		
	}

};



int main() 
{
	Recursion test;
	std::cout << test.fibonacci_number(7);
	return 0;
}