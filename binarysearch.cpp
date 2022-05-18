#include <vector>
#include <iostream>

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
	vector <int> v1{ -1,0,3,5,9,12 };
	binary_search(v1, 5);
	binary_recursive(v1, 0, v1.size()-1, 3);
	return 0;




}