#include<iostream>

// Constants
int MIL = 1000000;

int main()
{
  int T; // Number of test cases
  
  std::cin >> T;
  
  for (int i = 0; i < T; i++)
  {
    int S; // Starting bet
    int k; // Number of rounds
    
    std::cin >> S >> k;
    
    // Your code
    for (int j = 0; j < k; ++j)
    {
      // If S is even
      if (!(S%2) )
      {
        S -= 99;
        if (S < 0)
        {
          S = MIL + S;
        }

        S *= 3;

      }

      else
      {

        S -= 15;
        if (S < 0)
        {
          S = MIL + S;
        }

        S *= 2;
      }

      if (S > MIL)
      {
        S %= MIL;
      }     
    }
      
    std::cout << S << std::endl;
    
  }
}

/*
  if odd cc -15, *2
  if even cc -99 *3
  if cc > 1,000,000, cc%1,000,000
  if cc <  0, cc = 1,000,000 + cc
*/

/*
If your have an odd number of CloudCoinsTM, you lose 15 CloudCoinsTM and the remaining amount of CloudCoinsTM is doubled.

If your have an even number of CloudCoinsTM, you lose 99 CloudCoinsTM but the amount you have remaining is tripled.

If you have more than 1,000,000 CloudCoinsTM your total loops back around (so 1,000,007 CloudCoinsTM  becomes just 7 CloudCoinsTM). Likewise, if your total goes below 0 CloudCoinsTM it ALSO loops around (so -7 CloudCoinsTM would become 999,993 CloudCoinsTM).
*/