#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <ctime>
#include "Table.h"

int main()
{
	std::cout << "Enter count: " << std::endl;
	int count;
	std::cin >> count;
	Table table("map.txt", count);

	std::cout << "\nCount of collision at all:\n" << table.countOfCollision() << std::endl;

	std::cout << "Enter string for check: " << std::endl;
	std::string stringForCheck;
	std::cin >> stringForCheck;
	if (table.searhInHash(stringForCheck) == -1)
	{
		std::cout << "There is no this string";
	}
	else
	{
		std::cout << "String " << stringForCheck << " exist in HashTable. " <<
			"Count of Collision:" << table.searhInHash(stringForCheck);
	}

	std::cin.get();
	std::cin.get();
}