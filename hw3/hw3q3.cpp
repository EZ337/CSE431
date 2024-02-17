#include <queue>
#include <iostream>

int main()
{
    int N, k, value;
    std::cin >> N >> k;

    std::priority_queue<int> queue;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> value;
        queue.push(value);
    }

    for (int i = 0; i < k; ++i)
    {
        std::cout << queue.top() << std::endl;
        queue.pop();
    }
    
}