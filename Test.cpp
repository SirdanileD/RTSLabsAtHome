#include "RTSLabsAtHome.h"
#include <iostream>

int main(int argc, char* argv[])
{
    RTSLabsAtHome test;
    //aboveBelow
    std::list<int> list;
    int compVal;

    //stringRotation
    std::string OG;
    int rotationDegree;
    if (argc < 3)
    {
        std::cout << "Insufficient cmd args\n";
        
        std::getchar(); //Delays closing of window to see output
        return 1;
    }
    //Parse first input to determine function type and function arguments for ease of testing, not robust but usable
    if ((std::string)argv[1] == "--aboveBelow" || (std::string)argv[1] == "-a")
    {
        compVal = atoi(argv[2]);
        std::cout << "Call aboveBelow with args compVal = " << compVal << " && unordered set of ints = ";
        for (int i = 3; i < argc; i++)
        {
            list.push_front(atoi(argv[i]));
            std::cout << atoi(argv[i]) << " ";
        }
        RTSLabsAtHome::MyHash hash = test.aboveBelow(list, compVal);
        std::cout << "\n" << "Result is: " << "above = " << hash("above") << " | below = " << hash("below") << "\n";
    }
    else if ((std::string)argv[1] == "--stringRotation" || (std::string)argv[1] == "-s")
    {
        rotationDegree = atoi(argv[2]);
        OG = (std::string)argv[3];
        std::cout << "Call stringRotation with args rotationDegree = " << rotationDegree << " && string = " << OG << "\n";
        std::cout << "After Function call " << test.stringRotation(OG, rotationDegree) << "\n";
    }
    else
    {
        //spit out minimal help text
        std::cout << "argv1 =  {--aboveBelow or -a}       || {--stringRotation = -s}\n";
        std::cout << "argv2 =  {compVal}                  || {rotationDegree}\n";
        std::cout << "argv3+ = {arbitrary number of ints} || {a string to rotate}\n";
    }
    
    std::getchar(); //Delays closing of window to see output
    return 0;
}

