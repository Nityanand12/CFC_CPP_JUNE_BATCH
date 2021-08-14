#include <vector>
#include <iostream>
#include <stack>
using namespace std;



// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int low=0,high= height.size()-1;
//         int ans=0;
//         while(low<high){
//             ans=max(ans,min(height[low],height[high])*(high-low));
//             if(height[low]<height[high]){
//                 low++;
//             }
//             else{
//                 high--;
//             }
//         }
//         return ans;
//     }
// };


// 85. Maximal Rectangle
// class Solution {
// public:
//     int largestRectangleArea(vector<int> &heights)
// {
//   int finalAns = 0;
//   stack<int> st;
//   st.push(-1);
//   for (int i = 0; i < heights.size(); i++)
//   {
//     if (st.size() == 1 || heights[i] > heights[st.top()])
//     {
//       st.push(i);
//     }
//     else
//     {
//       while ((st.size() != 1) && heights[i] <= heights[st.top()])
//       {
//         int k = st.top();
//         st.pop();
//         int ans = (i - st.top() - 1) * heights[k];
//         finalAns = max(finalAns, ans);
//       }
//       st.push(i);
//     }
//   }
//   int len = heights.size();
//   while (st.size() != 1)
//   {
//     int k = st.top();
//     st.pop();
//     int ans = (len - st.top() - 1) * heights[k];
//     finalAns = max(finalAns, ans);
//   }
//   return finalAns;
// }
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if(matrix.size()==0) return 0;
//         int finalAns=0;
//         vector<int>heights(matrix[0].size(),0);
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]=='0'){
//                     heights[j]=0;
//                 }
//                 else{
//                     heights[j]+=1;
//                 }
//             }
//             int ans= largestRectangleArea(heights);
//             finalAns=max(finalAns,ans);
//         }
//         return finalAns;
//     }
    
// };




// 84. Largest Rectangle in Histogram
// int largestRectangleArea(vector<int> &heights)
// {
//   int finalAns = 0;
//   stack<int> st;
//   st.push(-1);
//   for (int i = 0; i < heights.size(); i++)
//   {
//     if (st.size() == 1 || heights[i] > heights[st.top()])
//     {
//       st.push(i);
//     }
//     else
//     {
//       while ((st.size() != 1) && heights[i] <= heights[st.top()])
//       {
//         int k = st.top();
//         st.pop();
//         int ans = (i - st.top() - 1) * heights[k];
//         finalAns = max(finalAns, ans);
//       }
//       st.push(i);
//     }
//   }
//   int len = heights.size();
//   while (st.size() != 1)
//   {
//     int k = st.top();
//     st.pop();
//     int ans = (len - st.top() - 1) * heights[k];
//     finalAns = max(finalAns, ans);
//   }
//   return finalAns;
// }



int main()
{
  return 0;
}