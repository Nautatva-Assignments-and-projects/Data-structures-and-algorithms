#include <iostream>
using namespace std;

int main()
{
  int n, k, ans = 0, maxDiff = 0;
  cin >> n >> k;
  int a[n + 1], awake;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
  {
    cin >> awake;
    if (awake)
    {
      ans += a[i];
      a[i] = 0;
    }
    a[i] = a[i - 1] + a[i];
  }
  for (int i = k; i <= n; i++)
    maxDiff = max(maxDiff, a[i] - a[i - k]);
  cout << ans + maxDiff << endl;
}