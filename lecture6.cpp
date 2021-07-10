#include <vector>
#include <iostream>
using namespace std;
void insertionSort(vector<int>&arr){
  for(int i=1;i<arr.size();i++){
    int key = arr[i];
    int j = i-1;
    while(j>=0&&arr[j]>key){
      arr[j+1]= arr[j];
      j--;
    }
    arr[j+1]= key;
  }
  for(int ele:arr){
    cout<<ele<<"\n";
  }
}
void bubbleSort(vector<int>&arr){
  for(int i=0;i<arr.size();i++){
    bool swaped=false;
    for(int j=0;j<arr.size()-i-1;j++){
      if(arr[j]>arr[j+1]){
        swaped= true;
        int t= arr[j+1];
        arr[j+1]= arr[j];
        arr[j]= t;
      }
    }
    if(swaped==false){
      break;
    }
  }
   for(int ele:arr){
    cout<<ele<<" ";
  }
  cout<<"\n";
}
void selectionSort(vector<int>&arr){
  for(int i=0;i<arr.size()-1;i++){
    int id=i;
    for(int j=i+1;j<arr.size();j++){
      if(arr[j]<arr[id]){
        id= j;
      }
    }
    if(id!=i){
      int t= arr[id];
      arr[id]= arr[i];
      arr[i]= t;
    }
  }
  for(int ele:arr){
    cout<<ele<<" ";
  }
  cout<<"\n";
}
int main(){
  vector<int>arr={30,20,10,76,8,87,45,65,67,2,4,5,45,6};
  // insertionSort(arr);
  // bubbleSort(arr);
  selectionSort(arr);
}