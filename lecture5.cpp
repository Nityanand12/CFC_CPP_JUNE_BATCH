#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateArray(vector<int>&arr){
  int l=0,h= arr.size()-1;
  while(l<h){
   int temp= arr[l];
    arr[l]= arr[h];
    arr[h]= temp;
    l++;
    h--;
  }
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
}
void linearSearch(vector<int>&arr){
  int element=171;
  int ans=-1;
  for(int i=0;i<arr.size();i++){
    if(arr[i]==element){
      ans=1;
      cout<<"Element found"<<"\n";
      break;
    }
  }
  if(ans==-1){
    cout<<"Element Not found"<<"\n";
  }

}
void binarySearch(vector<int>&arr){
  sort(arr.begin(),arr.end());
  int element=17;
  int ans=-1;
  int l=0,h= arr.size()-1;
  while(l<=h){
    int mid= (l+h)/2;
    if(arr[mid]==element){
      ans=1;
      cout<<"Element found"<<"\n";
      break;
    }
    else if(arr[mid]<element){
      l= mid+1;
    }
    else{
      h= mid-1;
    }
  }

  if(ans==-1){
    cout<<"Element Not found"<<"\n";
  }
}
void productOfArrayExceptSelf(vector<int>&arr){
  vector<int>ans(arr.size(),1);
  for(int i=1;i<arr.size();i++){
      ans[i]= ans[i-1]*arr[i-1];
  }
  int prod=1;
  for(int i=arr.size()-1;i>=0;i--){
    ans[i]= ans[i]*prod;
    prod= prod* arr[i];
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  cout<<"\n";

}
int main(){
  vector<int>arr={2,3,5,4};
  // rotateArray(arr);
  // linearSearch(arr);
  // binarySearch(arr);
  productOfArrayExceptSelf(arr);
  
}