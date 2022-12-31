#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int nums[N][N], n, m, dp[N][N];
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cin >> nums[i][j];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + nums[i][j];
    cout << dp[n][m] << endl;
  }
  return 0;
}