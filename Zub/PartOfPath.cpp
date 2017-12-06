#include "PartOfPath.h"

PartOfPath::PartOfPath(std::string ZubValue, int countOfSteps, int countOfSpaces)
	:up(nullptr), right(nullptr), down(nullptr), left(nullptr),
	valueOfZub(ZubValue), lengthOfWay(countOfSteps), placeForSpace(countOfSpaces) {};

int PartOfPath::findPlaceForSpace()
{
	{
		for (int i = 0; i < (valueOfZub.size()); i++)
		{
			if (valueOfZub[i] == '_')
			{
				return i;
			}
		}
		return -1;
	}
}

PartOfPath* PartOfPath::createState(Direction direction)
{
	std::string newValueOfZub = valueOfZub;
	std::swap(newValueOfZub[placeForSpace], newValueOfZub[placeForSpace + direction]);
	int newPlaceForSpace = placeForSpace + direction;
	return new PartOfPath(newValueOfZub, lengthOfWay + 1, newPlaceForSpace);
}



PartOfPath::~PartOfPath()
{

}
