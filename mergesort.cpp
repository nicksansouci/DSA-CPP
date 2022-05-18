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

vector<int> merge(vector<int> left, vector<int> right)
{
	vector<int> result{};
	int i = 0;
	int j = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
		{
			result.emplace_back(left[i]);
			i += 1;
		}
		else
		{
			result.emplace_back(right[j]);
			j += 1;
		}
	}
	while (i < left.size())
	{
		result.emplace_back(left[i]);
		i += 1;
	}
	while (j < right.size())
	{
		result.emplace_back(right[j]);
		j += 1;
	}

	return result;
}

vector<int> merge_sort(vector<int> v1)
{
	if (v1.size() == 1)
		return v1;
	size_t middle = (v1.size() / 2);
	auto front = begin(v1);
	auto second_half = begin(v1) + middle;
	vector<int>left(front, second_half);
	vector<int> right(second_half, end(v1));
	return merge(merge_sort(left), merge_sort(right));
}

int main()
{
	vector<int> v1{ 6, 7, 8, 1, 2, 5, 3, 9 };
	print(merge_sort(v1));
	
}