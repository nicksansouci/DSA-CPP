#include <vector>
#include <iostream>

using namespace std;

//Non recursive approach
int interpolation_sort(vector<int>& v, int target)
{
	int left = 0;
	int right = v.size() - 1;
	int middle = left + ((target - v[left]) * (right - left) / (v[right] - v[left]));
	while (left <= right)
	{
		if (v[middle] == target)
		{
			cout << "The index with target value is " << middle << '\n';
			return middle;
		}
		if (v[middle] < target)
		{
			left = middle + 1;
			middle = left + ((target - v[left]) * (right - left) / (v[right] - v[left]));
		}
		if (v[middle] > target)
		{
			right = middle - 1;
			middle = left + ((target - v[left]) * (right - left) / (v[right] - v[left]));
		}
	}
	cout << "There is no value in the vector equal to " << target << "\n";
	return -1;
}

// Recursive Approach

int interpolation_recursive(vector<int>& v, int left, int right, int target)
{
	if (left <= right)
	{
		int middle = left + ((target - v[left]) * (right - left) / (v[right] - v[left]));

		if (v[middle] == target)
		{
			cout << "The index with target value is " << middle << '\n';
			return middle;
		}
		if (v[middle] < target)
			return interpolation_recursive(v, middle + 1, right, target);

		if (v[middle] > target)
			return interpolation_recursive(v, left, middle - 1, target);
	}
	cout << "There is no value in the vector equal to " << target << '\n';
	return -1;
}

int main()
{
	vector <int> v1{ 3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50 };
	interpolation_recursive(v1, 0, v1.size()-1, 16);
}