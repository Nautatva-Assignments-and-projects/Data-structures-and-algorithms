#include <iostream>
#include <stack>
using namespace std;

struct queue
{
  queue()
  {
    mainSize = 0;
    tempSize = 0;
  }
  void enqueue(int number)
  {
    mainSize++;
    mainQueue.push(number);
    // cout << "enqueue: " << mainQueue.top() << " size: " << mainSize << endl;
  }

  int dequeue()
  {
    int ans;

    if (tempSize)
    {
      ans = tempQueue.top();
      tempQueue.pop();
      tempSize--;
      return ans;
    }
    else if (mainSize)
    {
      tempSize = --mainSize;
      // cout << endl
      //      << endl
      //      << tempSize << mainSize << endl
      //      << endl
      //      << endl;
      for (size_t i = 0; i < mainSize; i++)
      {
        tempQueue.push(mainQueue.top());
        mainQueue.pop();
      }
      ans = mainQueue.top();
      // cout << "dequeue: " << ans << endl;
      mainQueue.pop();
      mainSize = 0; //now mainQueue is empty
      return ans;
    }
    return -1; //both queues are empty
  }
  int print()
  {
    if (tempSize)
      return tempQueue.top();
    else if (mainSize)
    {
      for (size_t i = 0; i < mainSize; i++)
      {
        tempQueue.push(mainQueue.top());
        mainQueue.pop();
      }
      tempSize = mainSize;
      mainSize = 0;
      return tempQueue.top();
    }
    return -1;
  }

private:
  int mainSize;
  int tempSize;
  stack<int> mainQueue; //in
  stack<int> tempQueue; //out
};

int main()
{
  int n;
  cin >> n;
  int query;
  queue q;
  for (size_t i = 0; i < n; i++)
  {
    cin >> query;
    // cout << "**query: " << query << "**" << endl;
    if (query == 1)
    {
      int number;
      cin >> number;
      q.enqueue(number);
    }
    else if (query == 2)
    {
      q.dequeue();
    }
    else if (query == 3)
    {
      cout << q.print() << endl;
    }
    // cout << endl;
  }
}