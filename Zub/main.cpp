#include <iostream>
#include <vector>
#include <string>
#include "PartOfPath.h"

void printTable(std::string valueOfZub)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << valueOfZub[3 * i + j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void main()
{
	std::string startZubValue = "SUPER_ZUB";
	std::string endZubValue = "USPERU_BZ";
	bool found = 0;

	PartOfPath last(endZubValue, 0, 0);
	last.placeForSpace = last.findPlaceForSpace();
	std::vector<PartOfPath*> allVariants;
	allVariants.push_back(&last);
	int currentlengthOfWay = 0;

	while (!found)
	{
		int N = allVariants.size();
		for (int i = 0; i < N; i++)
		{
			if ((allVariants[i]->lengthOfWay) == currentlengthOfWay)
			{
				Direction direction;
				if ((allVariants[i]->up == nullptr) && (allVariants[i]->placeForSpace > 2))
				{
					direction = up;
					PartOfPath* newState = (allVariants[i]->createState(direction));
					allVariants[i]->up = newState;
					newState->down = allVariants[i];
					allVariants.push_back(newState);

					if (newState->valueOfZub == startZubValue) { found = true; break; }
				}
				
				if ((allVariants[i]->right == nullptr) && (allVariants[i]->placeForSpace % 3 != 2))
				{
					direction = right;
					PartOfPath* newState = (allVariants[i]->createState(direction));
					allVariants[i]->right = newState;
					newState->left = allVariants[i];
					allVariants.push_back(newState);

					if (newState->valueOfZub == startZubValue) { found = true; break; }
				}

				if ((allVariants[i]->down == nullptr) && (allVariants[i]->placeForSpace < 6))
				{
					direction = down;
					PartOfPath* newState = (allVariants[i]->createState(direction));
					allVariants[i]->down = newState;
					newState->up = allVariants[i];
					allVariants.push_back(newState);

					if (newState->valueOfZub == startZubValue) { found = true; break; }
				}
				
				if ((allVariants[i]->left == nullptr) && (allVariants[i]->placeForSpace % 3 != 0))
				{
					direction = left;
					PartOfPath* newState = (allVariants[i]->createState(direction));
					allVariants[i]->left = newState;
					newState->right = allVariants[i];
					allVariants.push_back(newState);

					if (newState->valueOfZub == startZubValue) { found = true; break; }
				}
			}
		}
		currentlengthOfWay++;
	}

	std::cout << "Count of iterations:" << currentlengthOfWay + 1 <<"\n"<< std::endl;
	std::cin.get();

	std::vector <std::string> pathAtAll;
	pathAtAll.push_back(startZubValue);

	PartOfPath*  r = allVariants[allVariants.size() - 1];
	int st = currentlengthOfWay;
	while (st > 0)
	{
		if ((r->up != nullptr) && (r->up->lengthOfWay == st - 1))
		{
			pathAtAll.push_back(r->up->valueOfZub);
			st--;
			r = r->up;
			continue;
		}
		
		if ((r->right != nullptr) && (r->right->lengthOfWay == st - 1))
		{
			pathAtAll.push_back(r->right->valueOfZub);
			st--;
			r = r->right;
			continue;
		}

		if ((r->down != nullptr) && (r->down->lengthOfWay == st - 1))
		{
			pathAtAll.push_back(r->down->valueOfZub);
			st--;
			r = r->down;
			continue;
		}
		
		if ((r->left != nullptr) && (r->left->lengthOfWay == st - 1))
		{
			pathAtAll.push_back(r->left->valueOfZub);
			st--;
			r = r->left;
			continue;
		}
	}
	for (int i = pathAtAll.size() - 1; i >= 0; i--)
	{
		printTable(pathAtAll[i]);
	}

	std::cin.get();
	std::cin.get();
}