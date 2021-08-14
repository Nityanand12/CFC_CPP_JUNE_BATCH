#include <iostream>
#include <vector>
using namespace std;
int fibonacci_Recursion(int num)
{
  if (num <= 1)
  {
    return num;
  }
  int left = fibonacci_Recursion(num - 1);
  int right = fibonacci_Recursion(num - 2);
  return left + right;
}
int fibonacci_Memoization(int num, vector<int> &dp)
{
  if (num <= 1)
  {
    return dp[num] = num;
  }
  if (dp[num] != 0)
    return dp[num];
  int left = fibonacci_Memoization(num - 1, dp);
  int right = fibonacci_Memoization(num - 2, dp);
  return dp[num] = left + right;
}
int fibonacci_Tabulation(int number, vector<int> &dp)
{
  for (int num = 0; num <= number; num++)
  {
    if (num <= 1)
    {
       dp[num] = num;
       continue;
    } 
     dp[num] =  dp[num-1] + dp[num-2];
  }
  return dp[dp.size()-1];
}
void fibonacci(){
  int num = 6;
  // cout<<fibonacci_Recursion(num)<<"\n";
  // vector<int> dp(num + 1, 0);
  // cout << fibonacci_Memoization(num, dp) << "\n";
  // for(int i=0;i<dp.size();i++){
  //   cout<<dp[i]<<" ";
  // }
  // cout << fibonacci_Tabulation(num, dp) << "\n";

}
int permutation_Recursion(vector<int>&arr,int target){
  if(target==0){
    return 1;
  }
  int ans=0;
  for(int i=0;i<arr.size();i++){
    if(target-arr[i]>=0){
      ans+=permutation_Recursion(arr,target-arr[i]);
    }
  }
  return ans;
}



int permutation_Memoization(vector<int>&arr,int target,vector<int>&dp){
  if(target==0){
    return dp[target]= 1;
  }
  if(dp[target]!=0){
    return dp[target];
  }
  int ans=0;
  for(int i=0;i<arr.size();i++){
    if(target-arr[i]>=0){
      ans+=permutation_Memoization(arr,target-arr[i],dp);
    }
  }
  return dp[target]= ans;
}

int permutation_Tabulation(vector<int>arr,int target,vector<int>&dp){
  // for(int i=0;i<dp.size();i++){
    // if(i==0){
    //   dp[i]=1;
    // continue;
    // }
  //   int ans=0;
  //   for(int j=0;j<arr.size();j++){
  //     if(i-arr[j]>=0){
  //       ans= ans+dp[i-arr[j]];
  //     }
  //   }
  //   dp[i]= ans;
  // }
  // return dp[dp.size()-1];
  for(int tar=0;tar<dp.size();tar++){
    if(tar==0){
     dp[tar]= 1;
     continue;
  }
  int ans=0;
  for(int i=0;i<arr.size();i++){
    if(tar-arr[i]>=0){
      ans+=dp[tar-arr[i]];
    }
  }
   dp[tar]= ans;
  }
  return dp[dp.size()-1];

}
int combination(vector<int>&arr,int target,vector<int>&dp){
  dp[0]=1;
  for(int i=0;i<arr.size();i++){
    int ans=0;
    for(int j=0;j<=target;j++){
      if(j-arr[i]>=0)
      dp[j]= dp[j]+dp[j-arr[i]];
    }
  }
  return dp[dp.size()-1];

}
int main()
{
  // fibonacci();

  vector<int>arr={1,4,3,2};
  int target=5;                                                                           
  // cout<<permutation_Recursion(arr,target)<<"\n";
  vector<int>dp(target+1,0);
  // cout<<permutation_Memoization(arr,target,dp)<<"\n";
  // for(int i=0;i<dp.size();i++){
  //   cout<<dp[i]<<" ";
  // }

  // cout<<permutation_Tabulation(arr,target,dp)<<"\n";
  // for(int i=0;i<dp.size();i++){
  //   cout<<dp[i]<<" ";
  // }

  cout<<combination(arr,target,dp)<<"\n";
  return 0;
}