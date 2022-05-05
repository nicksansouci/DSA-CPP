#include <iostream>
#include <unordered_map>
#include <string>


class HashTable
{
public:
	int value;
	std::list<int> *table;
	std::string key;
	HashTable() {
		std::unordered_map<std::string, int> hashmap({});
	}
	
	int __hash(std::string key)
	{
		int hash_value;
		for (auto x : key)
		{
			char c = x;
			hash_value = c % 23;
		}
		return hash_value;
	}

	void set_item(std::string key,int value)
	{
		int index = __hash(key);
		hashmap[index] = 
	}
	void print_table()
	{
		
	}
};


int main()
{
	HashTable my_table;
	my_table.set_item("Nick", 90);
	my_table.print_table();
}