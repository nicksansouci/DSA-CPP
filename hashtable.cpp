#include <iostream>
#include <string>
#include <list>
using namespace std;

class HashTable {
private:
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups]; //Seperate lists for different indexes.


public:
	bool isEmpty() const;
	int __hash(int key);
	void insert_item(int key, string value);
	void remove_item(int key);
	string search_table(int key);
	void print_table();
};

bool HashTable::isEmpty() const
{
	int sum{};
	for (int i{}; i < hashGroups; i++)
	{
		sum += table[i].size();
	}
	if (sum == 0);
	{
		return true;
	}
	return false;
}

int HashTable::__hash(int key)
{
	return key % hashGroups;
}

void HashTable::insert_item(int key, string value)
{
	
	int index = __hash(key);
	auto& block = table[index];
	auto front = begin(block);
	bool keyExists = false;
	for (; front != end(block); front++)
	{
		if (front->first == key)
		{
			// Replace the value associated with key if it already exists within the index.
			keyExists = true;
			front->second = value;
			cout << "This key already exists and the value has been replaced." << endl;
			break;
		}
	}
	// If key does not exist within the index, emplace back on table[index]
	if (!keyExists)
	{
		block.emplace_back(key, value);
	}
	return;
}

void HashTable::remove_item(int key)
{
	int index = __hash(key);
	auto& block = table[index];
	auto front = begin(block);
	bool keyExists = false;
	for (; front != end(block); front++)
	{
		if (front->first == key)
		{
			keyExists = true;
			front = block.erase(front);
			cout << "Pair removed from hash table." << endl;
			break;
		}
	}
	if (!keyExists)
	{
		cout << "Key not found in hash table." << endl;
	}
	return;
}

string HashTable::search_table(int key)
{
	int index = __hash(key);
	auto& block = table[index];
	auto front = begin(block);
	bool keyExists = false;

	for (; front != end(block); front++)
	{
		if (front->first == key)
		{
			keyExists = true;
			cout << "Found the key " << key << " in hash table with value "<<front->second << endl;
			return front->second;
		}
	}
	if (!keyExists)
	{
		cout << "Key not found in hash table." << endl;
		return "";
	}
	return "";
}

void HashTable::print_table()
{
	for (int i{}; i < hashGroups; i++)
	{
		if (table[i].size() == 0) continue;

		else
		{
			auto front = begin(table[i]);
			for (; front != end(table[i]); front++)
			{
				cout << "Key: " << front->first << " Value: " << front->second << endl;
			}
		}
	}
}


int main()
{
	HashTable my_table;
	my_table.insert_item(900, "Lumber");
	my_table.insert_item(47, "Silver");
	my_table.remove_item(900);
	my_table.print_table();
	my_table.search_table(900);
}