#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int lis(vector<int> &arr)
{
  vector<int> dp(arr.size(), 0);
  for (int i = 0; i < arr.size(); i++)
  {
    int ans = 0;
    for (int j = 0; j < i; j++)
    {
      if (arr[j] < arr[i])
      {
        ans = max(ans, dp[j]);
      }
    }
    dp[i] = ans + 1;
  }
  int finalAns = 0;
  for (int ele : dp)
  {
    cout << ele << " ";
    finalAns = max(finalAns, ele);
  }
  cout << "\n";
  return finalAns;
}
int editDistanceWithRecursion(int s1Pos, int s2Pos, string s1, string s2)
{
  if (s1Pos == 0)
  {
    return s2Pos;
  }
  if (s2Pos == 0)
  {
    return s1Pos;
  }
  if (s1[s1Pos - 1] == s2[s2Pos - 1])
  {
    return editDistanceWithRecursion(s1Pos - 1, s2Pos - 1, s1, s2);
  }
  else
  {
    int a = editDistanceWithRecursion(s1Pos - 1, s2Pos - 1, s1, s2); //swap
    int b = editDistanceWithRecursion(s1Pos, s2Pos - 1, s1, s2);     //insertion
    int c = editDistanceWithRecursion(s1Pos - 1, s2Pos, s1, s2);     //delition
    return min(a,min(b,c))+1;
  }
}
int editDistanceWithMemoization(int s1Pos, int s2Pos, string s1, string s2,vector<vector<int>>&dp)
{
  if (s1Pos == 0)
  {
    return dp[s1Pos][s2Pos]= s2Pos;
  }
  if (s2Pos == 0)
  {
    return dp[s1Pos][s2Pos]= s1Pos;
  }
  if(dp[s1Pos][s2Pos]!=-1){
    return dp[s1Pos][s2Pos];
  }
  if (s1[s1Pos - 1] == s2[s2Pos - 1])
  {
    return dp[s1Pos][s2Pos]= editDistanceWithMemoization(s1Pos - 1, s2Pos - 1, s1, s2,dp);
  }
  else
  {
    int a = editDistanceWithMemoization(s1Pos - 1, s2Pos - 1, s1, s2,dp); //swap
    int b = editDistanceWithMemoization(s1Pos, s2Pos - 1, s1, s2,dp);     //insertion
    int c = editDistanceWithMemoization(s1Pos - 1, s2Pos, s1, s2,dp);     //delition
    return dp[s1Pos][s2Pos]= min(a,min(b,c))+1;
  }
}
int editDistanceWithTabulation(string s1,string s2,vector<vector<int>>&dp){
  for(int i=0;i<=s1.length();i++){
    for(int j=0;j<=s2.length();j++){
      if(i==0){
        dp[i][j]=j;
        continue;
      }
      if(j==0){
         dp[i][j]=i;
        continue;
      }
      if(s1[i-1]==s2[j-1]){
        dp[i][j]= dp[i-1][j-1];
      }
      else{
        dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
      }
    }
  }
  return dp[dp.size()-1][dp[0].size()-1];
}
int main()
{
  // vector<int>arr={11,2,8,3,9,101,5,20};
  // cout<<lis(arr)<<"\n";

  string s1 = "abcd";
  string s2 = "acebd";
  // cout << editDistanceWithRecursion(s1.length(), s2.length(), s1, s2) << "\n";
  vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
  // cout << editDistanceWithMemoization(s1.length(), s2.length(), s1, s2,dp) << "\n";

  // for(int i=0;i<dp.size();i++){
  //   for(int j=0;j<dp[0].size();j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  cout << editDistanceWithTabulation(s1, s2,dp) << "\n";
   for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[0].size();j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}