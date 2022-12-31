#include <iostream>
using namespace std;
int main()
{
  char c;
  int cntA = 0, cntB = 0, cntC = 0;
  while(cin>>c)
  {
    if (c == 'a')
      cntA++;
    else if (c == 'b')
      cntB++;
    else
      cntC++;
  }
  for (int i = 1; i <= cntB; i++)
    cout << "b";
  for (int i = 1; i <= cntA; i++)
    cout << "a";
  for (int i = 1; i <= cntC; i++)
    cout << "c";
  return 0;
}