#include <iostream>

// function declaration
int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);

// function definition
int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  return x / y;
}

int main()
{
  int x = 10;
  int y = 5;
  int sum = add(x, y); // call the add function
  int difference = subtract(x, y);
  int product = multiply(x, y);
  int quotient = divide(x, y);
  std::cout << "The sum of " << x << " and " << y << " is " << sum << std::endl;
  std::cout << "The difference of " << x << " and " << y << " is " << difference << std::endl;
  std::cout << "The product of " << x << " and " << y << " is " << product << std::endl;
  std::cout << "The quotient of " << x << " and " << y << " is " << quotient << std::endl;

  return 0;
}