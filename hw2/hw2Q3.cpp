#include <iostream>
#include <iomanip>
#include <set>
#include <bits/stdc++.h>

void BalanceTree(std::multiset<int>& lower, std::multiset<int>& upper)
{
    // Unbalanced tree, balance them
    if (upper.size() > lower.size())
    {   
        lower.insert(*(upper.begin()));
        upper.erase(upper.begin());
    }
    else if (upper.size() + 1 < lower.size()) // if lower > upper by more than 1
    {
        // insert the greatest value of the lower tree into the right subtree
        upper.insert(*(--(lower.end())));
        lower.erase(--(lower.end()));
    }
}

void Add(std::multiset<int>& lower, std::multiset<int>& upper, double& median, int& value)
{

    // insert value into upper/lower if value is greater/less than median
    (value > median) ? upper.insert(value) : lower.insert(value);

    // else // Insert to lower tree otherwise
    // {
    //     lower.insert(value);
    // }

    BalanceTree(lower, upper);
}


void Remove(std::multiset<int>& lower, std::multiset<int>& upper, double& median, int& value)
{
    if (value > median)
    {
        upper.erase(upper.find(value));
    }
    else
        lower.erase(lower.find(value));

    BalanceTree(lower, upper);
    
}

bool CalculateMedian(std::multiset<int>& lower, std::multiset<int>& upper, double& median)
{
    // Calculate median
    
    if (lower.size()) // If we have any data
    {
        if ((lower.size() + upper.size())%2) // Odd amount
        {
            median = *(--lower.end());
        }
        else
        {
            median = (long(*(--lower.end())) + long((*upper.begin())))/2.0;
        }
        return true;
    }
    return false;

}






int main()
{
    std::cout << std::fixed << std::setprecision(1);

    int N;
    std::cin >> N;
    char action; // add or remove
    int load; // load = value associated with the action.
    double currMedian, intpart; //intpart = used for printing
    std::multiset<int> lower; // lower half of the data
    std::multiset<int> upper; // upper half of the data

    // Extract info and plug
    for (int i = 0; i < N; ++i)
    {
        std::cin >> action >> load;
        if (action == 'a') // Add operation
        {
            // later insertions
            if(lower.size() > 0)
            {
                Add(lower, upper, currMedian, load);
            }
            else // First insertion
            {
                lower.insert(load);
                currMedian = load;
            }


        }

        else // Remove operation
        {
            if (lower.find(load) != lower.end() || upper.find(load) != upper.end())
            {
                Remove(lower, upper, currMedian, load);
            }
            else
            {
                
                std::cout << "Wrong!" << std::endl;
                continue;
            }
        }

        // Print the current median
        if (CalculateMedian(lower, upper, currMedian))
        {
            
            if (std::modf(currMedian, &intpart) == 0.0)
                std::cout << (int) currMedian << std::endl;
            else
                std::cout << currMedian << std::endl;
        }
        else
            std::cout << "Wrong!" << std::endl;
    }
}

