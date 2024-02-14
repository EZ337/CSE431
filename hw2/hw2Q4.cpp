#include <iostream>
#include <queue>
#include <utility>
#include <functional>

struct lengthCompare
{
    bool operator() (std::pair<long long, long long> t1, std::pair<long long, long long> t2)
    {
        return (t1.second > t2.second);
    }
};

struct arrivalCompare
{
    bool operator() (std::pair<long long, long long> t1, std::pair<long long, long long> t2)
    {
        return (t1.first > t2.first); // Store longer times in the front (back of pq) of array
    }
};

void ProcessInstruction(std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, arrivalCompare>& pq, 
                                                                    long long& prevTime,
                                                                    long long& totalTime,
                                                                    long long& sum)
{
    long long currTime, taskTime;
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, lengthCompare> processQueue;

    while (!processQueue.empty() || !pq.empty())
    {

        // Move all tasks that we have received by the time we were done with our last task
        // to processing queue
        while (!pq.empty() && (totalTime - pq.top().first) >= 0)
        {
            processQueue.push(pq.top());
            pq.pop();
        }

        if (processQueue.empty() && (totalTime - pq.top().first) < 0)
        {
            processQueue.push(pq.top());
            pq.pop();
        }

        auto currentTask = processQueue.top();
        taskTime = currentTask.second; // The task's length
        currTime = currentTask.first; // The time this task arrived


        if ((totalTime - currTime) >= 0) // We had an instruction arrive while processing a task
        {
            totalTime = prevTime + taskTime;
            sum += (totalTime - currTime);
        }
        else    // We were waiting on instructions
        {
            long long extraTime = currTime - prevTime;
            sum += taskTime;

            totalTime = prevTime + extraTime + taskTime;
        }

        prevTime = totalTime;

        processQueue.pop();
    }
}


int main()
{
    int N;
    long long arrival, length, sum = 0, prevTime = 0, totalTime = 0;
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, arrivalCompare> instructionQueue;
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, lengthCompare> processQueue;

    std::cin >> N;
    // Gather all input first
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arrival >> length;
        instructionQueue.push(std::make_pair(arrival, length)); // Collect all our info
    }

    // totalTime += instructionQueue.top().second + instructionQueue.top().first; // Process the first task
    // sum += instructionQueue.top().second;
    // instructionQueue.pop();

    ProcessInstruction(instructionQueue, prevTime, totalTime, sum);

    std::cout << (sum/N) << std::endl; //print avg time

}