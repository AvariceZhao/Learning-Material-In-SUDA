#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int dp[N], n;
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> dp[i];
  int ans = dp[1];
  for (int i = 1; i <= n; i++)
  {
    dp[i] = max(dp[i - 1] + dp[i], dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}