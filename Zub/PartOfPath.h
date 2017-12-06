#include <string>

enum Direction
{
	up = -3,
	right = 1,
	down = 3,
	left = -1
};

class PartOfPath
{

public:
	PartOfPath(std::string, int, int);
		
	PartOfPath* up;
	PartOfPath* right;
	PartOfPath* down;
	PartOfPath* left;

	std::string valueOfZub;
	int lengthOfWay;
	int placeForSpace;

	int findPlaceForSpace();
	PartOfPath* createState(Direction);

	~PartOfPath();
	

};


