#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>


T BubbleSort(T& v1)
{
	for (int i=0; i < v1.size(); i++)
	{
		for (int j=0; j < v1.size()-1; j++)
		{
			if (v1[j] > v1[j + 1])
			{
				swap(v1[j], v1[j + 1]);
			}
			else
				continue;
		}
	}
	return v1;
}

template <typename T>
void print(T v1)
{
	for (const auto& x : v1)
	{
		cout << x << " ";
	}
	cout << "\n";
}


int main()
{
	vector<int> v2{ 5, 6, 8,1, 3, 9, 10, 12, 2 };
	BubbleSort(v2);
	print(v2);

	vector<double> v3 { 10.5, 9.1, 2.3 , 1.4, 7.8, 6.0, 8.5, 3.3, 5.5, 3.5};
	BubbleSort(v3);
	print(v3);
}
