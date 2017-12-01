#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <ctime>

const int N = 5;

int main()
{
	srand(time(0));
	std::vector<int> players(N+1);
	unsigned int start_time = clock();
	for (int i = 0; i <= N;i++)
	{
		players[i] = rand() % 10;
		std::cout << players[i]<<" " << std::flush;
	}
	players[N] = 0;
	sort(players.begin(), players.end());

	std::cout << "\nAfter sort " << std::endl;
	for (auto &item : players)
	{
	std::cout << item<<" " << std::flush;
	}

	int sumPart = 0;
	players[0] = 0;

	for (int i = 1; i <= N + 1;i++)
	{
		sumPart += players[i-1];
		players[i-1] = sumPart;
	}

	std::cout << "\nAfter sum " << std::endl;
	for (auto &item : players)
	{
		std::cout << item << " " << std::flush;
	}

	int k = rand() % 10;
	std::cout << "\nK: " << k << std::endl;

	int sumResult = 0;

	/*
	for (int i = 1, breakPoint = 2; breakPoint < N - 1;)
	{
		//std::cout << "i= " << i <<" pB= "<<breakPoint<<std::endl;

		while (breakPoint < N - 1 && sum(i, players, k) >= players[breakPoint])
		{
			++breakPoint;
		} //while (breakPoint <= N && sum(i, players, k) > sum(breakPoint, players, k));

		  //подвинули bP до точки, которая не входит в сумму

		if (sumAccumulated(0, breakPoint - 1, players) - sumAccumulated(0, i - 1, players) > sumResult)
		{
			sumResult = sumAccumulated(0, breakPoint - 1, players) - sumAccumulated(0, i - 1, players);
		}

		while (sum(i, players, k) < players[breakPoint] && (i < breakPoint))
		{
			++i;
		}
	}
	*/


	for (int i = 1, breakPoint = 2; breakPoint < N; )
	{
		std::cout << "i= " << i <<" pB= "<<breakPoint<<std::endl;

		while (breakPoint < N && players[i+1] - players[i - 1] + k //cумма [i-1] и [i] и К
			>=
			players[breakPoint] - players[breakPoint - 1])//значение в breakPoint
		{
			std::cout << "sum " << players[i+1] - players[i-1] + k << std::endl;
			std::cout << " pl(pB)" << players[breakPoint] - players[breakPoint - 1] << std::endl;
			++breakPoint;
		}
		std::cout << "sum " << players[i+1] - players[i - 1] + k << std::endl;
		std::cout << " pl(pB)" << players[breakPoint] - players[breakPoint - 1] << std::endl;

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



/*
for (int i = 2, breakPoint = 3; breakPoint < N-1;)
{
//std::cout << "i= " << i <<" pB= "<<breakPoint<<std::endl;

while (breakPoint < N - 1 && players[i-1] - players[i - 2] + k //cумма [i-1] и [i] и К
>=
players[breakPoint] - players[breakPoint - 1])//значение в breakPoint
{
++breakPoint;
}

/*
while (breakPoint < N-1 && sum(i, players, k) >= players[breakPoint])
{
++breakPoint;
}
подвинули bP до точки, которая не входит в сумму


if (players[breakPoint - 1] - players[i - 2] > sumResult)
{
	sumResult = players[breakPoint - 1] - players[i - 2] > sumResult;
}

/*
if (sumAccumulated(0, breakPoint-1, players) - sumAccumulated(0, i - 1, players) > sumResult)
{
sumResult = sumAccumulated(0, breakPoint-1, players) - sumAccumulated(0, i - 1, players);
}


while (players[i - 1] - players[i - 2] + k < players[breakPoint] - players[breakPoint - 1] && (i < breakPoint))
{
	++i;
}

/*
while (sum(i, players, k) < players[breakPoint] && (i < breakPoint) )
{
++i;
}
*/

	
	
