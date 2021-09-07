#include<iostream>
#include<vector>
using namespace std;
class customMap{
  public:
  class node{
    public:
    int key;
    int value;
    node(int key,int value){
      this->key=key;
      this->value=value;
    }
    node(){

    }
  };
  vector<node*> *arr;
  int defaultSize=10;
  int size;
  customMap(){
    arr= new vector<node*>[defaultSize];
    for(int i=0;i<defaultSize;i++){
      arr[i]= vector<node*>();
    }
    size=0;
  }
  int hashing(int data){
    return data%defaultSize;
  }
  vector<node*> *rehash(){
     defaultSize= defaultSize*2;
    vector<node*> *newArray= new vector<node*>[defaultSize];
    for(int i=0;i<defaultSize;i++){
      newArray[i]= vector<node*>();
    }
    for(int i=0;i<defaultSize/2;i++){
      for(int j=0;j<arr[i].size();j++){
        int hash= hashing(arr[i][j]->key);
        int idx= hash%defaultSize;
        newArray[idx].push_back(new node(arr[i][j]->key,arr[i][j]->value));
      }
    }
    return newArray;
  }
  void insert(int key,int value){
    int hash= hashing(key);
    int idx=hash%defaultSize;
    vector<node*>bucket= arr[idx];
    for(int i=0;i<bucket.size();i++){
      if(bucket[i]->key==key){
        bucket[i]= new node(key,value);
        arr[idx]=bucket;
        return;
      }
    }
    bucket.push_back(new node(key,value));
    arr[idx]= bucket;
    size++;
    double loadFactor=0.75;
    if(size/defaultSize>loadFactor){
     arr= rehash();
    }
  }
  bool find(int key){
    int hash= hashing(key);
    int idx=hash%defaultSize;
    vector<node*>bucket= arr[idx];
    for(int i=0;i<bucket.size();i++){
      if(bucket[i]->key==key){
        return true;
      }
    } 
    return false;
  }
  void remove(int key){
    int hash= hashing(key);
    int idx=hash%defaultSize;
    vector<node*>bucket= arr[idx];
    for(int i=0;i<bucket.size();i++){
      if(bucket[i]->key==key){
        bucket.erase(bucket.begin()+i);
      }
    }
    arr[idx]= bucket;
  }
  void display(){
    for(int i=0;i<defaultSize;i++){
      for(int j=0;j<arr[i].size();j++){
        cout<<arr[i][j]->key<<" "<<arr[i][j]->value <<"\n";
      }
    }
  }
  int get(int key){
    int hash= hashing(key);
    int idx=hash%defaultSize;
    vector<node*>bucket= arr[idx];
    for(int i=0;i<bucket.size();i++){
      if(bucket[i]->key==key){
        return bucket[i]->value;
      }
    }
    return 0;
  }
};
int main(){
  // cout<<"Hii";
  customMap cm1;
  cm1.insert(10,12);
  cm1.insert(15,165);
  cm1.insert(85,87);
  cm1.insert(15,165);
  cm1.insert(16,165);
  cm1.insert(65,52);
  cm1.insert(4,2);
  cm1.insert(15,87);
  cm1.insert(10,18);
  cout<<cm1.get(15)<<"\n";
  cout<<cm1.find(10)<<"\n";
  cm1.remove(15);
  cm1.display();
  return 0;
}