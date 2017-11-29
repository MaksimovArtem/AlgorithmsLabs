#pragma once
#include <string>
#include <vector>
#include <list>
class Table
{
	std::vector<std::string> map;
	std::vector<std::pair<std::string, int>> hashMap;

public:
	Table(std::string, const int);

	std::vector<std::pair<std::string, int>> afterHashFunction(std::vector<std::string>);
	int hashFun(std::string, int);
	int secondHash(std::string);
	std::vector<std::string> fromFile(const std::string, const int);
	int countOfCollision();
	int searhInHash(std::string);
	~Table();
};
