#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int life[n];
  for (size_t i = 0; i < n; i++)
    life[i] = 1;
  int clawLength, person = 0;
  int lifeCount = n;
  while (person < n)
  {
    cin >> clawLength;
    // cout << "person " << person << " starts killing, clawLength: " << clawLength << endl;
    for (size_t i = max(person - clawLength, 0); i < person; i++)
    {
      if (life[i] != 0)
      {
        life[i] = 0;
        lifeCount--;
        // cout << "person " << i << " killed, lifecount: " << lifeCount << endl;
      }
      // else
      // {
      // cout << "person " << i << " already dead" << endl;
      // }
    }
    // cout << "---------" << endl;
    person++;
  }
  cout << lifeCount << endl;
}