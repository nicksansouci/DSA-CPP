#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

// Non recursive approach
int binary_search(vector<int>& v, int target)
{
	int left = 0;
	int right = v.size() - 1;
	int middle = (left + right) / 2;
	while (left <= right)
	{
		
		if (v[middle] == target)
		{
			cout << "The index with target value is " << middle << '\n';
			return middle;
		}
		if (v[middle] > target)
		{
			right = middle - 1;
			middle = (left + right) / 2;
		}
		if (v[middle] < target)
		{
			left = middle + 1;
			middle = (left + right) / 2;
		}
	}
	cout << "There is no value in the vector equal to " << target << "\n";
	return -1;
}

// Recursive Approach

int binary_recursive(vector<int> v, int left, int right, int target)
{
	if (left <= right)
	{
		int middle = (right + left) / 2;

		if (v[middle] == target)
		{
			cout << "The index with target value is " << middle << '\n';
			return middle;
		}
		if (v[middle] < target)
			return binary_recursive(v, middle + 1, right, target);
		if (v[middle] > target)
			return binary_recursive(v, left, middle - 1, target);
	}
	cout << "There is no value in the vector equal to " << target << "\n";
	return -1;
}

int main()
{
	vector <int> v1{ 3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50 };
	auto t0 = chrono::high_resolution_clock::now();
	binary_recursive(v1, 0, v1.size()-1, 23);
	auto t1 = chrono::high_resolution_clock::now();
	cout << "Completed search in " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << " microseconds\n";




}