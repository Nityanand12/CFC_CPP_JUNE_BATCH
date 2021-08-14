#include<iostream>
#include<queue>
using namespace std;

class customQueue{
  public:
  int defaultSize=10;
  int *arr;
  int size;
  int front, rear;
  customQueue(){
    arr= new int[defaultSize];
    size=0;
    front=0;
    rear=-1;
  }
  int *resize(){
    int *newArr= new int[defaultSize*2];
    for(int i=0;i<defaultSize;i++){
      newArr[i]= arr[front%defaultSize];
      front=front+1;
    }
    front=0;
    rear=size-1;
    defaultSize=defaultSize*2;
    return newArr;
  }
  void push(int data){
    if(size==defaultSize){
      arr= resize();
    }
    size++;
    rear=(rear+1)%defaultSize;
    arr[rear]=data;
  }
   bool isEmpty(){
    if(size==0) return true;
    return false;
  }
  void pop(){
    if(isEmpty()){
      cout<<"Your Queue is empty"<<"\n";
      return;
    }
    size--;
    front= (front+1)%defaultSize;
  }
  int Front(){
    if(isEmpty()){
      cout<<"Your Queue is empty"<<"\n";
      return EXIT_FAILURE;
    }
    return arr[front];
  }
  int Rear(){
    if(isEmpty()){
      cout<<"Your Queue is empty"<<"\n";
      return EXIT_FAILURE;
    }
    return arr[rear];
  }
};

int main(){
  // customQueue cq1;
  // for(int i=1;i<=120;i++){
  //   cq1.push(i*10);
  // }
  // cout<<cq1.Front()<<"\n";
  // cq1.pop();
  // cout<<cq1.Front()<<"\n";
  // cout<<cq1.Rear()<<"\n";
  // cout<<cq1.size<<"\n";


  queue<int>que;
  for(int i=1;i<=20;i++){
    que.push(i*10);
  }
  cout<<que.front()<<"\n";
  cout<<que.back()<<"\n";
  que.pop();
  cout<<que.front()<<"\n";
  cout<<que.back()<<"\n";
  int j=10;
  if(++j==j){
    cout<<"Hii";
  }
  return 0;
}