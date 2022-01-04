#pragma once
#include <functional>
#include <string>
#include <unordered_set>
#include <sstream>

class RTSLabsAtHome
{
private:
protected:
public:
	//Public constructor
	RTSLabsAtHome();

	//Create custom hashing object for use with aboveBelow
	//struct is public by default so no need for gets and sets of variable members
	struct MyHash
	{
		std::size_t aboveCount = 0;
		std::size_t belowCount = 0;

		std::size_t operator()(std::string const& hashString) const noexcept
		{
			if (hashString == "above")
			{
				return aboveCount;
			}
			else if (hashString == "below")
			{
				return belowCount;
			}
			else
			{
				return -1;
			}
		}
	};

	//aboveBelow
	//accepts two arguments:
	//An unsorted collection of integers(the list)
	//an integer(the comparison value)
	//returns a hash with the keys "above" and "below" with the corresponding count of integers from the list that are above or below the comparison value
	MyHash aboveBelow(std::list<int> list, int compVal);
	//cmd params for the given example: -a 6 1 5 2 1 10
	
	//stringRotation
	//accepts two arguments
	//a string(the original string)
	//a positive integer(the rotation amount)
	//returns a new string, rotating the characters in the original string to the right by the rotation amountand have the overflow appear at the beginning
	std::string stringRotation(std::string OG, unsigned int rotationDegree);
	//cmd params for the given example: -s 2 MyString
};

