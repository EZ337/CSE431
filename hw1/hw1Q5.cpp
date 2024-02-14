#include <iostream>

int main()
{
    int T, leaves, ratio, fragmentRatio;

    std::cin >> T;

    for(int i = 0; i < T; ++i)
    {
        std::cin >> leaves >> ratio >> fragmentRatio;
        int fragments = 0, distance = 0, wings = leaves/ratio;

        do
        {
            // wings = leaves/ratio;
            distance += wings;
            fragments += wings;
            // leaves = fragments/fragmentRatio;
            wings = fragments/fragmentRatio;
            fragments = fragments%fragmentRatio;
        } 
        while (wings > 0);
        

        std::cout << distance << std::endl;
    }
}