#include <iostream>

using namespace std;

bool isDecrease(int n)
{
  int t = 0;
  while (n)
  {
    if (t > n % 10)
    {
      return false;
    }
    else
    {
      t = n % 10;
      n /= 10;
    }
  }
  return true;
}
int main()
{
  int n;
  cin >> n;
  if (isDecrease(n))
    cout << 1;
  else
    cout << 0;
  return 0;
}