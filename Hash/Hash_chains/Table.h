#pragma once
#include <string>
#include <vector>
#include <list>
class Table
{
	std::vector<std::string> map;
	std::vector<std::list<std::string>> hashMap;

public:
	Table(std::string, const int);
	int hashFun(std::string);
	std::vector<std::list<std::string>> afterHashFunction(std::vector<std::string>);
	std::vector<std::string> fromFile(const std::string, const int);
	int countOfCollision();
	int searhInHash(std::string);
	~Table();
};

