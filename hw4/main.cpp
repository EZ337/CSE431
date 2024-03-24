#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    // n = number of things, m = amount of enemies at this loc
    int n, m;
    std::cin >> n;

    std::vector<int> monsters;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> m;
        monsters.push_back(m);
    }

    

    std::cout << "Hello World!" << std::endl;



}