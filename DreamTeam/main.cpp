#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

const int N = 100000;

int main()
{
	srand(time(0));
	std::vector<int> players(N+2);
	unsigned int start_time = clock();
	for (int i = 0; i <= N+1 ;i++)
	{
		players[i] = rand() % 1000;
		//std::cout << players[i]<<" " << std::flush;
	}
	players[N] = 0;
	
	sort(players.begin(), players.end());
	/*
	std::cout << "After sort " << std::endl;
	for (int i = 1; i <= N; i++)
	{
	std::cout << players[i]<<" " << std::flush;
	}
	*/
	int sumPart = 0;
	players[0] = 0;
	players[N + 1] = INT_MAX;
	for (int i = 1; i <= N+1 ;i++)
	{
		sumPart += players[i-1];
		players[i-1] = sumPart;
	}
	/*
	std::cout << "\nAfter sum " << std::endl;
	for (int i = 1; i <= N; i++)
	{
		std::cout << players[i] << " " << std::flush;
	}
	*/
	int k = rand() % 1000;
	std::cout << "\nK: " << k << std::endl;

	int sumResult = 0;

	for (int i = 1, breakPoint = 2; breakPoint <= N; )
	{
		//std::cout << "i= " << i <<" pB= "<<breakPoint<<std::endl;

		while (breakPoint <= N && players[i+1] - players[i - 1] + k //cумма [i+1] и [i] и К
			>=
			players[breakPoint] - players[breakPoint - 1])//значение в breakPoint
		{
			//std::cout << "sum " << players[i+1] - players[i-1] + k << std::endl;
			//std::cout << " pl(pB)" << players[breakPoint] - players[breakPoint - 1] << std::endl;
			++breakPoint;
		}
		//std::cout << "sum " << players[i+1] - players[i - 1] + k << std::endl;
		//std::cout << " pl(pB)" << players[breakPoint] - players[breakPoint - 1] << std::endl;

		if (sumResult < players[breakPoint - 1] - players[i - 1])
		{
			sumResult = players[breakPoint - 1] - players[i - 1];
		}

		while (players[i+1] - players[i - 1] + k < players[breakPoint] - players[breakPoint - 1] && (i < breakPoint))
		{
			++i;
		}
	}
	std::cout << "Result: " << sumResult;
	unsigned int end_time = clock();
	std::cout << "\nTime: " << (end_time - start_time) / 1000.0 << std::endl;
	std::cin.get();
	std::cin.get();
}


