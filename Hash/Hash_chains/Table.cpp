#include "Table.h"
#include <fstream>
#include <iostream>



Table::Table(std::string path, const int count)
{
	map = fromFile(path, count);
	hashMap = afterHashFunction(map);
}

int Table::hashFun(std::string string)
{
	int result = 0;
	for (auto &item : string)
	{
		result += (int)item;
	}
	return result % map.size();
}

std::vector<std::list<std::string>> Table::afterHashFunction(std::vector<std::string> myMap)
{
	std::vector<std::list<std::string>> result(myMap.size());
	std::cout << "\nHashTable:\n" << std::endl;
	for (auto &i : myMap)
	{
		std::vector<std::list<std::string>>::iterator it = result.begin() + hashFun(i);
		it->push_back(i);
	}

	for (auto &j : result)
	{
		if (j.size() == 0)
		{
			std::cout << "0" << std::endl;
		}
		else
		{
			for (auto &q : j)
			{
				std::cout << q << " " << std::flush;
			}
			std::cout << std::endl;
		}
	}
	return result;
}

std::vector<std::string> Table::fromFile(const std::string filePath, const int count)
{
	std::vector<std::string> myMap;
	std::fstream file;
	int i = 0;
	std::string string;

	file.open(filePath);
	if (file.is_open())
	{
		std::cout << "\nReading:\n" << std::endl;
		while (i < count)
		{

			file >> string;
			myMap.push_back(string);
			std::vector<std::string>::iterator it = myMap.begin() + i;
			std::cout << *it << std::endl;
			i++;
		}
	}
	return myMap;
}

int Table::countOfCollision()
{
	int count = 0;
	for (auto& i : hashMap)
	{
		if (i.size() > 1)
		{
			count += i.size() - 1;
		}
	}
	return count;
}

int Table::searhInHash(std::string string)
{
	std::vector<std::list<std::string>>::iterator it = hashMap.begin() + hashFun(string);
	int count = 0;
	for (auto &i : *it)
	{

		if (i == string)
		{
			return count;
		}
		++count;
	}
	return -1;
}

Table::~Table()
{
}
