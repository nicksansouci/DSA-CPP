#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v1)
{
	for (auto& x : v1)
	{
		cout << x << " ";
	}
}

vector<int> RadixSort(vector<int>& v1)
{
	vector<int> buckets[10];

	int largestItem = v1[0];
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] > largestItem)
		{
			largestItem = v1[i];
		}
	}

	for (int exp = 1; largestItem / exp > 0; exp *= 10)
	{
		for (int i = 0; i < v1.size(); i++)
		{
			int bucket_index = v1.size() * v1[i];
			buckets[bucket_index].emplace_back(v1[i]);
		}
	}
	int bucketcounter = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		//Retrieve bucket items
		for (int j = 0; j < buckets[i].size(); j++)
		{
			v1[bucketcounter++] = buckets[i][j];
			
		}
	}
	return v1;
}

int main()
{
	vector<int> v{ 13, 10 ,102, 233, 90, 122, 10, 15, 60 };
	print(RadixSort(v));
}