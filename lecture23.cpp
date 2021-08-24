#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eggDropWithRecursion(int floor, int egg)
{
  if (floor == 0)
  {
    return 0;
  }
  if (egg == 1)
  {
    return floor;
  }
  int ans = 1000000000;
  for (int i = 1; i <= floor; i++)
  {
    int br = eggDropWithRecursion(i - 1, egg - 1);
    int nbr = eggDropWithRecursion(floor - i, egg);
    ans = min(ans, max(br, nbr) + 1);
  }
  return ans;
}

int eggDropWithMemoization(int floor, int egg, vector<vector<int>> &dp)
{
  if (floor == 0)
  {
    return dp[egg][floor] = 0;
  }
  if (egg == 1)
  {
    return dp[egg][floor] = floor;
  }
  if (dp[egg][floor] != -1)
  {
    return dp[egg][floor];
  }
  int ans = 1000000000;
  for (int i = 1; i <= floor; i++)
  {
    int br = eggDropWithMemoization(i - 1, egg - 1, dp);
    int nbr = eggDropWithMemoization(floor - i, egg, dp);
    ans = min(ans, max(br, nbr) + 1);
  }
  return dp[egg][floor] = ans;
}
int eggDropWithTabultion(int totalFloor, int totalEgg, vector<vector<int>> &dp)
{
  for (int egg = 1; egg <= totalEgg; egg++)
  {
    for (int floor = 0; floor <= totalFloor; floor++)
    {
      if (floor == 0)
      {
        dp[egg][floor] = 0;
        continue;
      }
      if (egg == 1)
      {
        dp[egg][floor] = floor;
        continue;
      }
      int ans = 1000000000;
      for (int i = 1; i <= floor; i++)
      {
        int br = dp[egg - 1][i - 1];
        int nbr = dp[egg][floor - i];
        ans = min(ans, max(br, nbr) + 1);
      }
      dp[egg][floor] = ans;
    }
  }
  return dp[dp.size() - 1][dp[0].size() - 1];
}

int mcmWithRecursion(vector<int> &arr, int i, int j)
{
  if (i + 1 == j)
  {
    return 0;
  }
  int l = arr[i];
  int r = arr[j];
  int ans = 1000000000;
  for (int cut = i + 1; cut < j; cut++)
  {
    int left = mcmWithRecursion(arr, i, cut);
    int right = mcmWithRecursion(arr, cut, j);
    ans = min(ans, left + right + l * r * arr[cut]);
  }
  return ans;
}

int mcmWithMemoization(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
  if (i + 1 == j)
  {
    return dp[i][j] = 0;
  }
  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }
  int l = arr[i];
  int r = arr[j];
  int ans = 1000000000;
  for (int cut = i + 1; cut < j; cut++)
  {
    int left = mcmWithMemoization(arr, i, cut, dp);
    int right = mcmWithMemoization(arr, cut, j, dp);
    ans = min(ans, left + right + l * r * arr[cut]);
  }
  return dp[i][j] = ans;
}
int mcmWithTabulation(vector<int> &arr, vector<vector<int>> &dp)
{
  for (int gap = 1; gap < arr.size(); gap++)
  {
    for (int i = 0, j = gap; j < arr.size(); j++, i++)
    {
      if (i + 1 == j)
      {
        dp[i][j] = 0;
        continue;
      }
      int l = arr[i];
      int r = arr[j];
      int ans = 1000000000;
      for (int cut = i + 1; cut < j; cut++)
      {
        int left = dp[i][cut]; 
        int right = dp[cut][j]; 
        ans = min(ans, left + right + l * r * arr[cut]);
      }
      dp[i][j] = ans;
    }
  }
  return dp[0][dp[0].size()-1];
}

int main()
{
  // int floor = 10, egg = 2;
  // cout<<eggDropWithRecursion(floor,egg)<<"\n";
  // vector<vector<int>> dp(egg + 1, vector<int>(floor + 1, -1));
  // cout << eggDropWithMemoization(floor, egg, dp) << "\n";
  // cout << eggDropWithTabultion(floor, egg, dp) << "\n";
  // for(int i=0;i<dp.size();i++){
  //   for(int j=0;j<dp[0].size();j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  vector<int> arr = {10, 20, 30, 40, 50};
  // cout<<mcmWithRecursion(arr,0,arr.size()-1)<<"\n";

  vector<vector<int>> dp2(arr.size(), vector<int>(arr.size(), -1));
  // cout<<mcmWithMemoization(arr,0,arr.size()-1,dp2)<<"\n";

  // for(int i=0;i<dp2.size();i++){
  //   for(int j=0;j<dp2[0].size();j++){
  //     cout<<dp2[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  cout << mcmWithTabulation(arr, dp2) << "\n";
   for(int i=0;i<dp2.size();i++){
    for(int j=0;j<dp2[0].size();j++){
      cout<<dp2[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}