#include <iostream>
using namespace std;

int findNumber(int array[], int number, int size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] == number)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  int integer;
  int key[n], count[n], sizeOfkey = 0;
  int minRequired = n / 2;
  int ans = -1;
  while (n--)
  {
    cin >> integer;
    int index = findNumber(key, integer, sizeOfkey);
    if (index == -1)
    {
      key[sizeOfkey] = integer;
      count[sizeOfkey] = 1;
      sizeOfkey++;
    }
    else
    {
      if (++count[index] > minRequired)
      {
        ans = integer;
        break;
      }
    }
  }
  cout << ans << endl;
}