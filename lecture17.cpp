#include <iostream>
using namespace std;



// class Solution {
// public:
//     void reverse(vector<int>&ans){
//         int l=0,h= ans.size()-1;
//         while(l<h){
//             int temp= ans[l];
//             ans[l]= ans[h];
//             ans[h]= temp;
//             l++;
//             h--;
//         }
    
//     }
//     vector<int> asteroidCollision(vector<int>& ast) {
//      stack<int>st;
//         for(int ele: ast){
//             if(ele>0){
//                 st.push(ele);
//             }
//             else{
// //                 i m negative
//                 while(st.size()!=0&&st.top()>0&&abs(ele)>st.top()){
//                     st.pop();
//                 }
//                 if(st.size()==0||st.top()<0){
//                     st.push(ele);
//                 }
//                 else if(abs(ele)==st.top()){
//                     st.pop();
//                 }
//             }
//         }
//         vector<int>ans;
//         while(st.size()!=0){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         reverse(ans);
//         return ans;
//     }
     
// };


// 42. Trapping Rain Water
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         vector<int>left(height.size(),0);
//         vector<int>right(height.size(),0);
      
//         for(int i=1;i<height.size();i++){
//             left[i]= max(left[i-1],height[i-1]);
//         }
//         for(int i=height.size()-2;i>=0;i--){
//             right[i]=max(right[i+1],height[i+1]);
//         }
//         int ans=0;
//         for(int i=0;i<height.size();i++){
//             int val= min(left[i],right[i])-height[i];
//             if(val>0) ans= ans+val;
//         }
//         return ans;
//     }
// };



// 856. Score of Parentheses
// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         stack<int>st;
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='('){
//                 st.push(0);
//             }
//             else{
//                 int cnt=0;
//                 while(st.top()!=0){
//                     cnt+=st.top();
//                     st.pop();
//                 }
//                 st.pop();
//                 if(cnt==0) cnt=1;
//                 else cnt=cnt*2;
//                 st.push(cnt);
//             }
//         }
//         int ans=0;
//         while(st.size()!=0){
//             ans= ans+st.top();
//             st.pop();
//         }
//         return ans;
//     }
// };




// 921. Minimum Add to Make Parentheses Valid
// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char>st;
//         for(int i=0;i<s.length();i++){
//             if(st.size()!=0&&s[i]==')'&&st.top()=='('){
//                 st.pop();
//             }
//             else st.push(s[i]);
//         }
//         return st.size();
//     }
// };





// 1021. Remove Outermost Parentheses
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         int count=0;
//         int k=1;
//         string ans="";
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='('){
//                 count++;
//             }
//             else{
//                 count--;
//             }
//             if(count==0){
//                 ans= ans+s.substr(k,i-k);
//                 k=i+2;
//             }
//         }
//         return ans;
//     }
// };





// 1047. Remove All Adjacent Duplicates In String
// class Solution
// {
// public:
//   string removeDuplicates(string s)
//   {
//     stack<char> st;
//     for (int i = 0; i < s.length(); i++)
//     {
//       if (st.size() == 0)
//       {
//         st.push(s[i]);
//         continue;
//       }
//       if (s[i] == st.top())
//       {
//         st.pop();
//       }
//       else
//       {
//         st.push(s[i]);
//       }
//     }
//     string ans = "";
//     while (st.size() != 0)
//     {
//       ans = st.top() + ans;
//       st.pop();
//     }
//     return ans;
//   }
// };

int main()
{
  return 0;
}