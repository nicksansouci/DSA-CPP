#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int jump_search(vector<int>& v, int target)
{
	if (v.size() == 0)
		return -1;
	int step = sqrt(v.size());

	int block_index = 0;

	while (v[block_index] < target && block_index < v.size())
	{
		block_index += step;
	}
	block_index -= step;
	for (auto& p = v[block_index]; p != v[block_index + step]; ++p)
	{
		if (v[p] == target)
		{
			cout << "The target was found at index " << p << '\n';
			return p;
		}
		else
		{
			cout << "The target was not found within the vector." << '\n';
			return -1;
		}
			
	}
	return -1;
}





int main()
{
	vector <int> v1{ 3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50 };
	jump_search(v1, 15);
}