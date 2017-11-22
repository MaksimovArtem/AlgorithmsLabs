#include <fstream>
#include <iostream>
#include <vector>

const int N = 13;
int matrix[N][N];
int matrix2[N][N];

int fromFile(std::string path)
{
	std::ifstream file;
	file.open(path);
	int first = 0, second = 0, countOfV = 0, countOfE = 0;
	
	if (file.is_open())
	{
		std::cout << "Reading\n" << std::endl;
		file >> countOfV >> countOfE;
		std::cout << "V: " << countOfV << " E: " << countOfE << std::endl;
		for (int i = 0; i < countOfE; i++)
		{
			file >> first >> second;
			matrix[first-1][second-1] = 1;
			matrix[second-1][first-1] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N;j++)
		{
			std::cout << matrix[i][j] <<"  "<< std::flush;
		}
		std::cout << std::endl;	
	}
	
	return countOfE;
}

bool Dijkstra()
{
	int distance[N];
	bool alreadyVisited[N];
	for (int i = 0; i < N; i++)
	{	
		distance[i] = INT_MAX;
		alreadyVisited[i] = false;
	}
	distance[0] = 0;
	int numberOfV = 0, index=0;

	for (int i = 0; i < N; i++)
	{
		int minPath = INT_MAX;
		for (int j = 0; j < N; j++)
		{
			if (!alreadyVisited[j] && distance[j] < minPath)
			{
				minPath = distance[j];
				numberOfV = j;
			}
		}
		index = numberOfV;
		alreadyVisited[index] = true;
		for (int k = 0; k < N; k++)
		{
			if (!alreadyVisited[k] && matrix2[index][k] != 0 && distance[index] !=INT_MAX
				&& distance[index] + matrix2[index][k] < distance[k])
			{
				distance[k] = distance[index] + matrix2[index][k];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (distance[i] != INT_MAX)
		{
			std::cout << "1" << " => "<<i+1<<" = " << distance[i] << std::endl;
		}
		else
		{
			std::cout << "1" << " => " << i + 1 << " = NO FUCKING WAY" << std::endl;
			return true;
		}
		
	}

	return false;
}

std::pair<int,int> changeMatrix(int count)
{
	std::pair<int,int> result;
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix2[i][j] = matrix[i][j];
			if (i > j)
			{
				if (matrix[i][j] == 1)
				{
					counter++;
					if (counter == count)
					{
						matrix2[i][j] = 0;
						matrix2[j][i] = 0;
						result.first = i;
						result.second = j;
					}
				}
			}
		}
	}
	
	return result;
}

int main()
{
	int countOfE = fromFile("map.txt");
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << matrix[i][j] << std::flush;
		}
		std::cout << std::endl;
	}*/
	int counterOfBridges = 0;
	for (int i = 1; i <= countOfE; i++)
	{
		std::pair<int,int>edge = changeMatrix(i);
		std::cout << std::endl;
		bool D = Dijkstra();
		if (D == true)
		{
			std::cout << "Edge: [" << edge.first << "," << edge.second << "] is a bridge!" << std::endl;
			counterOfBridges++;
		}
		
		std::cout << std::endl;

	}
	std::cout << "There are " << counterOfBridges << " bridges here" << std::endl;
	

	std::cin.get();
	std::cin.get();
}