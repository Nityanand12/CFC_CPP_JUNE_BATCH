#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class customSet{
  public:
  vector<int> *arr;
  int defaultSize=10;
  int size;
  customSet(){
    arr= new vector<int>[defaultSize];
    for(int i=0;i<defaultSize;i++){
      arr[i]= vector<int>();
    }
    size=0;
  }
  int hashing(int data){
    return data%defaultSize;
  }
  vector<int> *rehash(){
     defaultSize= defaultSize*2;
    vector<int> *newArray= new vector<int>[defaultSize];
    for(int i=0;i<defaultSize;i++){
      newArray[i]= vector<int>();
    }
    for(int i=0;i<defaultSize/2;i++){
      for(int j=0;j<arr[i].size();j++){
        int hash= hashing(arr[i][j]);
        int idx= hash%defaultSize;
        newArray[idx].push_back(arr[i][j]);
      }
    }
    return newArray;
  }
  void insert(int data){
    int hash= hashing(data);
    int idx=hash%defaultSize;
    vector<int>bucket= arr[idx];
    for(int i=0;i<bucket.size();i++){
      if(bucket[i]==data){
        return;
      }
    }
    bucket.push_back(data);
    arr[idx]= bucket;
    size++;
    double loadFactor=0.75;
    if(size/defaultSize>loadFactor){
     arr= rehash();
    }
  }
  bool find(int data){
    int hash= hashing(data);
    int idx=hash%defaultSize;
    vector<int>bucket= arr[idx];
    for(int i=0;i<bucket.size();i++){
      if(bucket[i]==data){
        return true;
      }
    } 
    return false;
  }
  void remove(int data){
    int hash= hashing(data);
    int idx=hash%defaultSize;
    vector<int>bucket= arr[idx];
    for(int i=0;i<bucket.size();i++){
      if(bucket[i]==data){
        bucket.erase(bucket.begin()+i);
      }
    }
    arr[idx]= bucket;
  }
  void display(){
    for(int i=0;i<defaultSize;i++){
      for(int j=0;j<arr[i].size();i++){
        cout<<arr[i][j]<<" ";
      }
    }
  }
};
int main(){
  customSet cs1;
  cs1.insert(13);
  cs1.insert(11);
  cs1.insert(12);
  for(int i=1;i<=10;i++){
    cs1.insert(i+3);
  }
  cout<<cs1.find(15)<<"\n";
  cs1.remove(11);
  cs1.display();

  return 0;
}