#include <iostream>
using namespace std;

struct petrolPump
{
  int petrol;
  int distance; //distance to next pump
};

int ans(petrolPump station[], int n)
{
  // int ans = -1;

  int start = 0; // first petrol pump starting point
  int end = 1;
  int curr_petrol = station[start].petrol - station[start].distance;

  // bool totalbreak = 0;
  while (end != start || curr_petrol < 0)
  {
    while (curr_petrol < 0 && start != end)
    {
      curr_petrol -= station[start].petrol - station[start].distance;
      start = (start + 1) % n;
      if (start == 0)
      {
        return -1;
      }
    }

    // if (totalbreak)
    // {
    //   break;
    // }

    curr_petrol += station[end].petrol - station[end].distance;
    end = (end + 1) % n;
  }
  return start;
}

int main()
{
  int n;
  cin >> n;
  struct petrolPump station[n];

  for (size_t i = 0; i < n; i++)
  {
    cin >> station[i].petrol;
    cin >> station[i].distance;
  }

  // if (!totalbreak)
  // {
  //   ans = start;
  // }

  cout << ans(station, n) << endl;
}

//try
//done
//complexity 2n :)