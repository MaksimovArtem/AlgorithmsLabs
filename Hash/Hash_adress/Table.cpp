#include "Table.h"
#include <iostream>
#include <fstream>

Table::Table(std::string path, const int count)
{
	map = fromFile(path, count);
	hashMap = afterHashFunction(map);
}

std::vector<std::pair<std::string, int>> Table::afterHashFunction(std::vector<std::string> myMap)
{
	std::cout << "\nHashTable:\n" << std::endl;

	std::vector<std::pair<std::string, int>> result(map.size() * 2);

	for (auto &i : result)
	{
		i.first = "0";
		i.second = 0;
	}

	for (auto &i : myMap)
	{
		bool notPlaced = true;
		int counter = 0;
		while (notPlaced)
		{
			std::vector<std::pair<std::string, int>>::iterator it = result.begin() + hashFun(i, counter);
			if ((*it).first == "0")
			{
				(*it).first = i;
				(*it).second = counter;
				notPlaced = false;
			}
			else
			{
				counter++;
			}
		}
	}

	for (auto &j : result)
	{
		std::cout << j.first << "  " << j.second << std::endl;
	}

	return result;
}


int Table::hashFun(std::string string, int countOfCollision)
{
	int result = 0;
	for (auto &item : string)
	{
		if (!string.empty()) {
			result += ((int)item) * ((int)item) * (string.size() - 1) + string.size() * countOfCollision;
		}
	}
	return (result + countOfCollision * secondHash(string)) % (map.size() * 2);
	if (result % (map.size() * 2) != 0) {
		return (result + countOfCollision * secondHash(string)) % (map.size() * 2);
	}
	else
	{
		return (result + 1 + countOfCollision * secondHash(string)) % (map.size() * 2);
	}
}

int Table::secondHash(std::string string)
{
	int result = 0;
	for (auto &item : string)
	{
		if (!string.empty()) {
			result += ((int)item) * string.size() / (int)(*string.begin());
		}
	}
	if (result % (map.size() * 2) != 0) {
		return result % (map.size() * 2);
	}
	else
	{
		return (result + 1) % (map.size() * 2);
	}
	
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
	for (auto &i : hashMap)
	{
		count += i.second;
	}
	return count;
}

int Table::searhInHash(std::string string)
{
	for (auto &i : hashMap)
	{
		if (i.first == string)
		{
			//std::cout << "String " << string << " exist. Count of collision: " << i.second;
			return i.second;
		}
	}
	return -1;
}

Table::~Table()
{
}
