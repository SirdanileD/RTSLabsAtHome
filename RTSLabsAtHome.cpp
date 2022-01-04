#include "RTSLabsAtHome.h"

RTSLabsAtHome::RTSLabsAtHome()
{
	//Empty initializer, class does not need to store info just transforms input
}

//Notes: std::unordered_set<int> doesn't allow for duplicate values, will use an array instead to contain the collection of ints.
RTSLabsAtHome::MyHash RTSLabsAtHome::aboveBelow(std::list<int> list, int compVal)
{
	MyHash hash;
	//For every value in the list
	for (auto& i : list)
	{
		//Compare with compVal and increment above or below count - In case the values match, no need to do anything
		if (compVal > i)
			hash.belowCount++;
		else if (compVal < i)
			hash.aboveCount++;
	}
	return hash;
}

std::string RTSLabsAtHome::stringRotation(std::string OG, unsigned int rotationDegree)
{
	//If string empty no need to consider rotations
	//Additionally if string is empty some operations on strings will fail, avoid those cases
	if (OG.empty())
	{
		//Returns empty string, rotations of any degree on empty will be empty still
		return OG;
	}

	//For every character we need to rotate
	for (unsigned int i = 0; i < rotationDegree; i++)
	{
		//Insert the back character in the string into the front
		OG.insert(OG.begin(), OG.back());
		//Erase the back character that has been inserted, c++ std::string pop_back doesn't return the popped char unlike a queue
		OG.pop_back();
	}
	//Returns string with rotationDegree number of characters rotated
	return OG;
}	
