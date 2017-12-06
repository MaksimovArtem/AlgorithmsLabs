#include <vector>
#include <array>
#include <iostream>

struct Items {
	int weight;
	int value;
};
const int N = 10;

void Increment(std::array<bool, N>& bagpack)
{
	for (int i = N - 1; i > 0;)
	{
		if (bagpack[i] == 0)
		{
			bagpack[i]++;
			i--;
			break;
		}
		else
		{
			while (bagpack[i] != 0)
			{
				--i;
			};
			bagpack[i] = 1;
			for (int j = i + 1; j <= N - 1; j++)
			{
				bagpack[j] = 0;
			}
			break;
		}
	}
}

bool lastStep(std::array<bool, N>& bagpack)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += bagpack[i];
	}
	if (sum == N)
	{
		return true;
	}
	return false;
}

bool isEnd(std::array<bool, N>& bagpack)
{
	static bool oneoneone = false;
	for (int i=0;i<N;i++)
	{
		if (bagpack[i] == 0)
		{
			return true;
		}
	}
	if (!oneoneone)
	{
		oneoneone = true;
		return true;
	}
	return false;
}

int main()
{
	std::vector<Items*> bag;
	int CapacityOfBag = 50;
	int sum = 0;
	int realWeight = 0;
	std::cout << "Count of elements: " << N << std::endl;
	
	for (int i = 0; i < N; i++)
	{
		Items* newItem = new Items;
		newItem->weight = rand() % 10 + 1;
		newItem->value = rand() % 10 + 1;
		std::cout << "Item# " << i + 1 << " has " << newItem->weight << " as weight and " << newItem->value << " as value" << std::endl;
		bag.push_back(newItem);
	}

	std::array<bool, N> inBag;
	for (auto &i : inBag)
	{
		i = 0;
	}

	std::array<bool, N> theBestInBag;
	for (auto &i : theBestInBag)
	{
		i = 0;
	}

	while (isEnd(inBag))
	{
		int currentWeight = 0, currentSum = 0;
		for (int i = 0; i < N ; i++)
		{
			currentWeight += inBag[i] * bag[i]->weight;
			currentSum += inBag[i] * bag[i]->value;
		}

		if (currentWeight <= CapacityOfBag && currentSum > sum)
		{
			sum = currentSum;
			theBestInBag = inBag;
			realWeight = currentWeight;
		}
		if(!lastStep(inBag))
		Increment(inBag);
	}


	std::cout << "Capacity of Bag: " << CapacityOfBag << " weight in bag: " << realWeight << std::endl;
	std::cout << "Value in bag: " << sum << std::endl;
	std::cout << "Items in bag have numbers:";
	for (int i = 0; i <= N - 1; i++) 
	{
		if (theBestInBag[i] == 1)
		{
			std::cout << i + 1 <<", "<< std::flush;
		}
	}
	
	std::cin.get();
	std::cin.get();
}