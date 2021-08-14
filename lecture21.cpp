#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int knapsackWithRecursion(vector<int> &wt, vector<int> &val, int cap, int pos)
{
  if (cap == 0 || pos == 0)
  {
    return 0;
  }
  int left = 0, right = 0;
  left = knapsackWithRecursion(wt, val, cap, pos - 1);
  right = knapsackWithRecursion(wt, val, cap - wt[pos - 1], pos - 1) + val[pos - 1];
  return max(left, right);
}

int knapsackWithMemoization(vector<int> &wt, vector<int> &val, int cap, int pos, vector<vector<int>> &dp)
{
  if (cap == 0 || pos == 0)
  {
    return dp[pos][cap] = 0;
  }
  if (dp[pos][cap] != 0)
  {
    return dp[pos][cap];
  }
  int left = 0, right = 0;
  left = knapsackWithMemoization(wt, val, cap, pos - 1, dp);
  if(cap-wt[pos-1]>=0)
  right = knapsackWithMemoization(wt, val, cap - wt[pos - 1], pos - 1, dp) + val[pos - 1];
  return dp[pos][cap] = max(left, right);
}

int knapsackWithTabulation(vector<int> &wt, vector<int> &val, int cap, int pos, vector<vector<int>> &dp)
{

  for (int i = 0; i <= wt.size(); i++)
  {
    for (int j = 0; j <= cap; j++)
    {
      if (j == 0 || i == 0)
      {
         dp[i][j] = 0;
         continue;
      }
      int left = 0, right = 0;
      left = dp[i-1][j];
      if(j-wt[i-1]>=0)
      right = dp[i-1][j - wt[i - 1]]+val[i-1];
      dp[i][j] = max(left, right);
    }
  }
  return dp[dp.size()-1][dp[0].size()-1];
}
void knapsack(){
  vector<int> wt = {3, 2, 5, 2};
  vector<int> val = {6, 7, 5, 10};
  int cap = 7;
  // cout<<knapsackWithRecursion(wt, val, cap, wt.size())<<"\n";
  vector<vector<int>> dp(wt.size() + 1, vector<int>(cap + 1, 0));
  // cout << knapsackWithMemoization(wt, val, cap, wt.size(), dp) << "\n";
  // for(int i=0;i<dp.size();i++){
  //   for(int j=0;j<dp[0].size();j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  // cout << knapsackWithTabulation(wt, val, cap, wt.size(), dp) << "\n";
  // for(int i=0;i<dp.size();i++){
  //   for(int j=0;j<dp[0].size();j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
}
int lcs_Recursion(string x,string y,int xPos,int yPos){
  if(xPos==0||yPos==0){
    return 0;
  }
  if(x[xPos-1]==y[yPos-1]){
    return lcs_Recursion(x,y,xPos-1,yPos-1)+1;
  }
  else{
    return max(lcs_Recursion(x,y,xPos-1,yPos),lcs_Recursion(x,y,xPos,yPos-1));
  }
}


int lcs_Memoization(string x,string y,int xPos,int yPos,vector<vector<int>>&dp){
  if(xPos==0||yPos==0){
    return dp[xPos][yPos]= 0;
  }
  if(dp[xPos][yPos]!=-1){
    return dp[xPos][yPos];
  }
  if(x[xPos-1]==y[yPos-1]){
    return dp[xPos][yPos]= lcs_Memoization(x,y,xPos-1,yPos-1,dp)+1;
  }
  else{
    return dp[xPos][yPos]= max(lcs_Memoization(x,y,xPos-1,yPos,dp),lcs_Memoization(x,y,xPos,yPos-1,dp));
  }
}
int lcs_tabulation(string x,string y,int xPos,int yPos,vector<vector<int>>&dp){
  for(int i=0;i<=x.length();i++){
    for(int j=0;j<=y.length();j++){
      if(i==0||j==0){
        dp[i][j]=0;
        continue;
      }
      if(x[i-1]==y[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
      }
      else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[dp.size()-1][dp[0].size()-1];
}

void lcs(){
  string x="Sunday";
  string y="Saturday";
  // cout<<lcs_Recursion(x,y,x.length(),y.length())<<"\n";
  vector<vector<int>>dp(x.length()+1,vector<int>(y.length()+1,-1));
  // cout<<lcs_Memoization(x,y,x.length(),y.length(),dp)<<"\n";

  // for(int i=0;i<dp.size();i++){
  //   for(int j=0;j<dp[0].size();j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  cout<<lcs_tabulation(x,y,x.length(),y.length(),dp)<<"\n";
  for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[0].size();j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
  }


}
int main()
{
  knapsack();
  lcs();
  return 0;
}