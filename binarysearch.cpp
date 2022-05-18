#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int binarysearch(vector<int>& v, int target)
{
	int left = 0;
	int right = v.size() - 1;
	int middle = (left + right) / 2;
	while (left <= right)
	{
		
		if (v[middle] == target)
		{
			cout << middle;
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
	return -1;
}

int main()
{
	vector <int> v1{ -1,0,3,5,9,12 };
	binarysearch(v1, 3);
	return 0;




}