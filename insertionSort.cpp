#include <iostream>
#include <typeinfo>
using std::cin;
using std::cout;
using std::endl;

int sizeOfArray(int array[])
{
  int size = 0;
  while (array[size] != -1)
  {
    size++;
  }
  return size;
}

int swap(int &i, int &j)
{
  int temp = i;
  i = j;
  j = temp;
  return 1;
}

int main()
{
  int array[] = {1, 32, 2, 3, 8, 6, 4, 12, 78, 45, -1};
  int size = sizeOfArray(array);

  cout << "----------------" << endl;
  cout << "size of array is " << size << endl;
  cout << "----------------" << endl
       << endl;

  for (int arrayblock = size; arrayblock > 0; arrayblock--)
  {
    bool iterated = false;
    for (int j = 1; j < arrayblock; j++)
    {
      if (array[j - 1] > array[j])
      {
        cout << "swap(" << array[j - 1] << "," << array[j] << ")" << endl;
        swap(array[j - 1], array[j]);
        iterated = true;
      }

      else
      {
        cout << "no swap" << endl;
      }
    }
    cout << "----------------" << endl
         << endl;

    if (!iterated)
      break;
  }

  for (int i = 0; i < size; i++)
  {
    cout << array[i] << endl;
  }
}