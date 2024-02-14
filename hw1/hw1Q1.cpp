#include <iostream>

int adder(int a, int b)
{
  return a+b;
}

int main()
{
  int val_a;
  std::cin >> val_a;
  int val_b; 
  std::cin >> val_b;
  
  std::cout << adder(val_a, val_b) << std::endl;
}