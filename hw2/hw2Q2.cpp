#include <iostream>
#include <istream>
#include <stack>

int main()
{
    int N;
    std::cin >> N;
    int val, importance;
    
    std::stack<int> mainStack;
    std::stack<int> maxStack;
    int max = -1;

    for (int i = 0; i < N; ++i)
    {
        // Gather input
        std::cin >> val;
        if (val == 1)
        {
            std::cin >> importance;
            if (importance > max)
            {
                max = importance;
            }

            mainStack.push(importance);
            maxStack.push(max);

        }
        else if (val == 2)
        {
            mainStack.pop();
            maxStack.pop();
            max = (maxStack.empty()) ? 0 : maxStack.top();
        }
        else if (val == 3)
        {
            std::cout << maxStack.top() << std::endl;
        }
    }


}