#include <iostream>
using namespace std;

struct stack
{
  // stack()
  // {
  //   size = 0;
  // }
  void updatestack(int givenSize)
  {
    size = givenSize;
    for (size_t i = 0; i < givenSize; i++)
      cin >> numbers[i];
  }
  int pop()
  {
    size--;
    return numbers[size];
  }
  int peek()
  {
    return numbers[size - 1];
  }
  int push(int number)
  {
    numbers[size] = number; //add number to top of
    size++;
    return numbers[size - 1];
  }
  bool isempty() { return !size; }

private:
  int size;
  int numbers[100000];//should be 1000000 %%%%%%%%%%
};

struct collection
{
  stack number;
  stack index;
  int popped;
  int push(int small, int ind)
  {
    index.push(ind);
    return number.push(small);
  }
  int pop()
  {
    popped = index.pop();
    return number.pop();
  }
  int peek()
  {
    return number.peek();
  }
  int getIndex()
  {
    return index.peek();
  }
  int isempty(){
    return number.isempty();
  }
};

int main()
{
  stack entries;
  int size;
  cin >> size;
  entries.updatestack(size); //Takes the input and stores in entries stack
  collection smallNumber;

  int output[size];
  int pointer = size - 1;
  int current = entries.pop();
  smallNumber.push(current, pointer); //pushing current (last number) to smallNumber
  int history;
  output[pointer] = -1; //no number less than last number
  // cout << "history: "
  //      << "-" << endl;
  // cout << "current: " << current << endl;
  // cout << "pointer: " << pointer << endl;
  // cout << "stored Output: " << output[pointer] << endl
  //      << endl;

  for (pointer--; pointer > -1; pointer--)
  {
    history = current;
    current = entries.pop(); //revising current and history

    if (current > history)
    {
      smallNumber.push(history,pointer+1);
      // cout << "pushed: " << smallNumber.push(history, pointer + 1) << endl;
      output[pointer] = pointer + 1;
      // cout << "**current>history**" << endl;
    }
    else if (current > smallNumber.peek())
    {
      // cout << "peek: " << smallNumber.peek() << endl;
      output[pointer] = smallNumber.getIndex();
      // cout << "**current > smallNumber**" << endl;
    }
    else
    {
      int temp = smallNumber.pop();
      bool done = 0;
      while (temp > current)
      {
        // cout << "temp: " << temp << endl;
        if (smallNumber.isempty())
        {
          smallNumber.push(temp, smallNumber.popped);
          done = 1;
          output[pointer] = -1;
          // cout << "break" << endl;
          break;
        }
        temp = smallNumber.pop();
      }
      if (!done)
      {
        output[pointer] = smallNumber.popped;
        smallNumber.push(current, pointer);      
      }

      // cout << "**none**" << endl;
    }
    // cout << "history: " << history << endl;
    // cout << "current: " << current << endl;
    // cout << "pointer: " << pointer << endl;
    // cout << "stored Output: " << output[pointer] << endl
    //      << endl;
  }

  // cout << endl
  //      << "check: " << endl;
  // while (!smallNumber.isempty())
  // {
    // cout << smallNumber.pop() << " * ";
  // }
  // cout << endl
  //      << endl;

  for (size_t i = 0; i < size; i++)
  {
    cout << output[i] << " ";
  }
  cout << endl;
}

// add another stack for storing small integers; DONE
// remove the segmentation fault for 10^6