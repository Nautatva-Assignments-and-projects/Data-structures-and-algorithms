#include <iostream>
#include <typeinfo>
using std::cout;
using std::cin;
using std::endl;

struct rnadperson{
  char name;
  int age;
  int randomNo;
};

void swap(int i, int j){
  int tmp = i;
  i=j;
  j=tmp;

}
void swap(int* i, int* j){
  int*tmp = i;
  i=j;
  j=tmp;
}
void swap_ref(int&i, int&j){
  int tmp = i;
  i=j;
  j=tmp;
  
}

int main(){
  rnadperson p;
 int x=2,y=3;
 swap(x,y);
   const char* t = typeid(p).name();
   cout<<t<<endl;
 cout<<"x:"<<x <<endl<<"y:"<<y<<endl;
}