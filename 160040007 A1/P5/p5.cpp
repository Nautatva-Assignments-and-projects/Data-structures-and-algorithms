#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int queue[n];
  cin >> queue[0];
  int minimum = queue[0];
  for (size_t i = 1; i < n; i++)
  {
    cin >> queue[i];
    minimum = min(minimum, queue[i]);
    // cout << "queue[" << i << "]: " << queue[i] << endl << endl;
  }

  for (size_t i = 0; i < n; i++)
  {
    queue[i] -= minimum;
  }

  int waitingQueue = 0 + (minimum % n);
  int position = queue[waitingQueue] + 1;
  while (position > 1)
  {
    // cout << "Amit's position is " << position << " and waiting queue is " << waitingQueue << endl;
    for (size_t i = 0; i < n; i++)
    {
      if (queue[i] > 0)
      {
        queue[i] = queue[i] - 1;
      }
    }
    waitingQueue = (waitingQueue + 1) % n;
    position = queue[waitingQueue] + 1;
  }
  cout << waitingQueue + 1 << endl;
}