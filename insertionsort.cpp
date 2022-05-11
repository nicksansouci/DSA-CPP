#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
T InsertionSort(T& v1)
{
	for (int i =1; i < v1.size(); i++)
	{
		int key = v1[i];
		int j = i - 1;
		while (j >= 0 && v1[j] > key)
		{
			v1[j + 1] = v1[j];
			j = j - 1;
		}
		v1[j + 1] = key;
	}
	return v1;
}

template <typename T>
void print(T value)
{
	for (const auto& x : value)
	{
		cout << x << " ";
	}
	cout << "\n";
}

int main()
{
	vector<int> v2{ 5, 6, 8,1, 3, 9, 10, 12, 2 };
	InsertionSort(v2);
	print(v2);
}