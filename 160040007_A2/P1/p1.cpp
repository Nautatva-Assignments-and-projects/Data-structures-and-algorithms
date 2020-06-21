#include <iostream>
#include <string>
using namespace std;

struct stack
{
  stack()
  {
    size = 0;
  }
  char pop()
  {
    size--;
    return unbalanced[size];
  }
  char peek()
  {
    return unbalanced[size - 1];
  }
  char push(char brac)
  {
    if (size > 500)
    {
      return '0';
    }
    unbalanced[size] = brac;
    size++;
    return unbalanced[size - 1];
  }
  bool isempty() { return !size; }

private:
  char unbalanced[500];
  int size; //size will be 1 ahead of the array index
};

char reverse(char brac)
{
  if (brac == ')')
  {
    return '(';
  }
  else if (brac == '}')
  {
    return '{';
  }
  return '[';
}

int main()
{
  int numberOfChar = 0;
  cin >> numberOfChar;
  stack unbalanced;
  bool output = 1;
  string test;
  cin >> test;

  // cout << "test length: " << test.length() << endl;
  if (numberOfChar % 2 == 1)
  {
    output = 0;
  }

  else
    for (size_t i = 0; i < numberOfChar; i++)
    {
      // cout << test[i] << endl;
      if (test[i] == '(' || test[i] == '{' || test[i] == '[')
      {
        if (!unbalanced.push(test[i]))
        {
          output = 0;
          // cout << "**break at push**" << endl;
          break;
        }
        else
        {
          // cout << "**continue**" << endl << endl;
          continue;
        }
      }
      else if (unbalanced.isempty())
      {
        output = 0;
        // cout << "**break at isEmpty**" << endl;
        break;
      }

      else
      {
        char rev = reverse(test[i]);
        // cout << "rev: " << rev << endl;

        if (unbalanced.peek() != rev)
        {
          // cout << "wrong character" << endl;
          output = 0;
          break;
        }
        else
        {
          // cout << "popped: " << unbalanced.peek() << endl << endl;
          unbalanced.pop();
        }
      }
    }
  // cout << unbalanced.isempty() << endl << endl;
  if (!unbalanced.isempty())
  {
    output = 0;
  }

  cout << output << endl;
}

// []()()(((([]))) FALSE
// [](){{{[]}}} TRUE

//Done