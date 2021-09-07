#include <bits/stdc++.h>
using namespace std;
class max_heap{
  private:
  vector<int>arr;
  int parent(int idx){
    return (idx-1)/2;
  }
  int leftChild(int idx){
    return idx*2+1;
  }
  int rightChild(int idx){
    return idx*2+2;
  }
  void upheapify(int idx){
    if(idx==0){
      return ;
    }
    int par= parent(idx);
    if(arr[par]<arr[idx]){
      int temp= arr[par];
      arr[par]= arr[idx];
      arr[idx]= temp;
    }
    upheapify(par);
  }
  void downheapify(int idx){
    int maximum=idx;
    int l= leftChild(idx);
    int r= rightChild(idx);
    if(l<arr.size()&&arr[l]>arr[maximum]){
      maximum=l;
    }
    if(r<arr.size()&&arr[r]>arr[maximum]){
      maximum=r;
    }
    if(maximum!=idx){
      int temp= arr[idx];
      arr[idx]= arr[maximum];
      arr[maximum]=temp;
      downheapify(maximum);
    }
  }
  public:
  void insert(int data){
    arr.push_back(data);
    upheapify(arr.size()-1);
  }

  void remove(){
    if(arr.size()==0) return;
    if(arr.size()==1){
      arr.pop_back();
      return;
    }
    arr[0]= arr[arr.size()-1];
    arr.pop_back();
    downheapify(0);
  }
  int top(){
    if(arr.size()==0){
      return EXIT_FAILURE;
    }
    return arr[0];
  }
  int size(){
    return arr.size();
  }
};
int main()
{
  max_heap mh;
  mh.insert(10);
  mh.insert(8);
  mh.insert(11);
  mh.insert(17);
  mh.insert(20);
  mh.insert(6);
  mh.insert(124);
  mh.insert(82);
  mh.insert(1);
  mh.insert(117);
  mh.insert(201);
  mh.insert(64);
  mh.insert(121);
  while(mh.size()!=0){
    cout<<mh.top()<<" ";
    mh.remove();
  }
  
  return 0;
}