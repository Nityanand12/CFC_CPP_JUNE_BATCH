#include<iostream>
#include<stack>
using namespace std;
template <typename k>

class customStack{
  public:
  int defaultSize=10;
  k *arr;
  int peek;
  customStack(){
    arr= new k[defaultSize];
    peek=-1;
  }
  k *resize(){
    k *newArray = new k[defaultSize*2];
     defaultSize *=2;
     for(int i=0;i<=peek;i++){
       newArray[i]=arr[i];
     }
     return newArray;
  }
  void push(k value){
    if(peek+1==defaultSize){
      // cout<<"Stack Overflow"<<"\n";
      arr = resize();
    }
    peek=peek+1;
    arr[peek]=value;
  }
  k pop(){
    if(peek==-1){
      cout<<"Stack is empty"<<"\n";
      return EXIT_FAILURE;
    }
    k ans= arr[peek];
    peek=peek-1;
    return ans;
  }
  int size(){
    return peek+1;
  }
  k top(){
    if(peek==-1){
      cout<<"Stack is empty"<<"\n";
      return EXIT_FAILURE;
    }
    return arr[peek];
  }
};
int main(){
  customStack<int> cs1;
  cs1.push(45);
  cs1.push(100);
  cs1.push(56);
  cs1.push(10);
  cs1.push(75);
  cout<<cs1.size()<<"\n";
  cout<<cs1.top()<<"\n";
  cout<<cs1.pop()<<"\n";
  cout<<cs1.size()<<"\n";
  cs1.push(45);
  cout<<cs1.top()<<"\n";
  cout<<cs1.size()<<"\n";
  for(int i=1;i<=1005;i++){
    cs1.push(i);
  }
  cout<<cs1.size()<<"\n";

}