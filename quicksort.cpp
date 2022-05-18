#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> v1)
{
	for (auto& x : v1)
	{
		cout << x << " ";
	}
}

int partition(vector<int>& v1,int start_index,int end_index)
{
	int pivot = v1[start_index];
	int middle_index = start_index;
	for (int i = start_index + 1; i <= end_index; i++)
	{
		if (v1[i] < pivot)
		{
			middle_index++;
			swap(v1[i], v1[middle_index]);
		}
	}
	swap(v1[start_index], v1[middle_index]);
	return middle_index;
}



void QuickSort(vector<int>& v1, int start_index, int end_index)
{
	if (start_index < end_index)
	{
		int pivot_index = partition(v1, start_index, end_index);
		//Sort left sublist, recursively calling partition until i > end_index
		QuickSort(v1, start_index, pivot_index - 1);
		//Sort right sublist
		QuickSort(v1, pivot_index + 1, end_index);
	}
	
}



int main()
{
	vector<int> v{ 3, 10 ,102, 23, 90, 12, 1, 5, 6 };
	QuickSort(v, 0, v.size()-1);
	print(v);
}