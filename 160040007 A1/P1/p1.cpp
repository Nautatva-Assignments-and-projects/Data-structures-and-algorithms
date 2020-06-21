#include <iostream>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  int number, count = 0;
  int minRequired = n / 2;
  while (n--)
  {
    cin >> number;
    if (number == x)
    {
      count++;
    }
  }

  if (count > minRequired)
  {
    cout << "1" << endl;
  }
  else
  {
    cout << "0" << endl;
  }
}