#include <vector>
#include <iostream>
#include <map>
#include <string>

int main()
{
    int N, robotID;

    // Run it for every robot
    while (std::cin >> N)
    {
        std::cin >> robotID;

        std::map<std::string, int> colors;
        std::string colorName;
        std::vector<std::string> colorVector;

        // Collect colour info
        for (int i = 0; i < N; ++i)
        {
            std::cin >> colorName;
            colors[colorName] = i;

            // Used to print. Indexing is quicker than searching our map... 
            // log(n) isn't too bad tho. Sacrificing space for speed. But definitely
            // could've stuck with the map alone
            colorVector.push_back(colorName);
        }


        int value = 0;
        // Collect other robot's colours
        for (int i = 0; i < N - 1; ++i)
        {
            std::cin >> colorName;
            value += colors[colorName];
        }

        value = (((robotID - value)%N ) + N) % N;
        std::cout << colorVector[value] << std::endl;
    }
    
    
    


    
}