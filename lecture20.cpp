#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int unboundedKnapSackWithRecursion(vector<int> &wt, vector<int> &val, int cap)
{
  if (cap == 0)
    return 0;
  int ans = 0;
  for (int i = 0; i < wt.size(); i++)
  {
    if (cap - wt[i] >= 0)
    {
      ans = max(ans, unboundedKnapSackWithRecursion(wt, val, cap - wt[i]) + val[i]);
    }
  }
  return ans;
}
int unboundedKnapSackWithMemoization(vector<int> &wt, vector<int> &val, int cap, vector<int> &dp)
{
  if (cap == 0)
    return dp[cap] = 0;
  int ans = 0;
  if (dp[cap] != 0)
    return dp[cap];
  for (int i = 0; i < wt.size(); i++)
  {
    if (cap - wt[i] >= 0)
    {
      ans = max(ans, unboundedKnapSackWithMemoization(wt, val, cap - wt[i], dp) + val[i]);
    }
  }
  return dp[cap] = ans;
}
int unboundedKnapSackWithTabulation(vector<int> &wt, vector<int> &val, vector<int> &dp)
{

  for (int cap = 0; cap < dp.size(); cap++)
  {
    if (cap == 0){
      dp[cap] = 0;
      continue;
    }
    int ans = 0;
    for (int i = 0; i < wt.size(); i++)
    {
      if (cap - wt[i] >= 0)
      {
        ans = max(ans, dp[cap-wt[i]]+ val[i]);
      }
    }
     dp[cap] = ans;
  }
  return dp[dp.size()-1];
}
int main()
{
  vector<int> wt = {2, 5, 1, 3, 4};
  vector<int> val = {15, 14, 10, 45, 30};
  int cap = 7;
  // cout<<unboundedKnapSackWithRecursion(wt,val,cap)<<"\n";

  vector<int> dp(cap + 1, 0);
  // cout<<unboundedKnapSackWithMemoization(wt,val,cap,dp)<<"\n";
  // for(int i=0;i<dp.size();i++){
  //   cout<<dp[i]<<" ";
  // }

  cout << unboundedKnapSackWithTabulation(wt, val, dp) << "\n";
  for(int i=0;i<dp.size();i++){
    cout<<dp[i]<<" ";
  }
  return 0;
}