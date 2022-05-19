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

T SelectionSort(T& v1)
{
	for (int i = 0; i < v1.size(); i++)
	{
		auto min_val = v1[i];
		int min_index = i;
		for (int j = i+1; j < v1.size(); j++)
		{
			if (v1[j] < min_val)
			{
				min_val = v1[j];
				min_index = j;
			}
		}
		swap(v1[i], v1[min_index]);
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
	BubbleSort(v2);
	print(v2);

	vector<double> v3 { 10.5, 9.1, 2.3 , 1.4, 7.8, 6.1, 8.5, 3.3, 5.5, 3.5};
	SelectionSort(v3);
	print(v3);

	return 0;
}
