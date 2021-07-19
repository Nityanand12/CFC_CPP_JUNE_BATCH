#include<iostream>
#include<vector>
using namespace std;
void printIncreasing(int n){
  if(n==0){
    return;
  }
  printIncreasing(n-1);
  cout<<n<<" ";
}
void printDecreasing(int n){
  if(n==0){
    return;
  }
  // if(n>0){
  cout<<n<<" ";
  printDecreasing(n-1);
  // }
}
void fun(int n,int level){
  if(n<=2){
    cout<<"Base "<<n<<" @ "<<level<<"\n";
    return;
  }
  cout<<"Pre "<<n<<" @ "<<level<<"\n";
  fun(n-1,level+1);
  cout<<"In "<<n<<" @ "<<level<<"\n";
  fun(n-2,level+1);
  cout<<"Post "<<n<<" @ "<<level<<"\n";
}
int factorial(int n){
  if(n==0) return 1;
   return n*factorial(n-1);
}
int fibonacci(int n){
  if(n<=1) return n;
  int left= fibonacci(n-1);
  int right= fibonacci(n-2);
  int ans= left+right;
  return ans;
} 
void allSubsetWithoutReturnType(vector<int>&arr,int id,string ans){
  if(id==arr.size()){
    cout<<ans<<"\n";
    return ;
  }
  allSubsetWithoutReturnType(arr,id+1,ans);
  allSubsetWithoutReturnType(arr,id+1,ans+to_string(arr[id])+" ");
}
vector<string> allSubsetWithReturnType(vector<int>arr,int id){
  if(id== arr.size()){
    vector<string>base;
    base.push_back("");
    return base;
  }
  vector<string> ans = allSubsetWithReturnType(arr,id+1);
  vector<string> myAns;
  for(string ele: ans){
    myAns.push_back(ele);
  }
  for(string ele: ans){
    myAns.push_back(to_string(arr[id])+" "+ele);
  }
  return myAns;
}

void allSubset(){
  vector<int>arr={1,2,3};
  // allSubsetWithoutReturnType(arr,0,"");
  vector<string>ans= allSubsetWithReturnType(arr,0);
  for(string ele: ans){
    cout<<ele<<"\n";
  }
}
int main(){
  int n=5;
  // printIncreasing(n);
  // cout<<"\n";
  // printDecreasing(n);
  // fun(n,0);
//  cout<<factorial(n)<<"\n";
  // cout<<fibonacci(7)<<"\n";
  allSubset();
  return 0;
}