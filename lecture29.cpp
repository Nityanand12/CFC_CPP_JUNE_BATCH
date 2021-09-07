#include<iostream>
using namespace std;



// 961. N-Repeated Element in Size 2N Array
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         unordered_map<int,int>map;
//         for(int ele: nums){
//             map[ele]++;
//         }
//         for(auto ele:map){
//             if(ele.second==nums.size()/2){
//                 return ele.first;
//             }
//         }
//         return -1;
//     }
// };



// 1684. Count the Number of Consistent Strings
// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string>& words) {
//        vector<int>arr(26,0);
//         for(int i=0;i<allowed.length();i++){
//             arr[allowed[i]-'a']++;
//         }
//         int ans=0;
//         for(int i=0;i<words.size();i++){
//             bool flag= true;
//             for(int j=0;j<words[i].length();j++){
//                 if(arr[words[i][j]-'a']==0){
//                     flag=false;
//                     break;
//                 }
//             }
//             if(flag) ans++;            
//         }
//         return ans;
//     }
// };



// Check Arithmetic Progression 
// class Solution{
//     public:
//     bool checkIsAP(int arr[], int n)
//     {
//         // code here
//         int maximum=INT_MIN,minimum=INT_MAX;
//         unordered_set<int>set;
//         for(int i=0;i<n;i++){
//             set.insert(arr[i]);
//             maximum=max(maximum,arr[i]);
//             minimum= min(minimum,arr[i]);
//         }
//         int diff=(maximum-minimum)/(n-1);
//         while(maximum!=minimum){
//             if(set.find(minimum)!=set.end()){
//                 minimum+=diff;
//             }
//             else{
//                 return false;
//             }
//         }
//         return true;
//     }

// };



// 954. Array of Doubled Pairs
// class Solution {
// public:
//     bool canReorderDoubled(vector<int>& arr) {
//         sort(arr.begin(),arr.end());
//         unordered_map<int,int>umap;
//         for(int ele: arr){
//             umap[ele]++;
//         }
//         for(int ele: arr){
//             if(umap[ele]==0){
//                 continue;
//             }
//             if(ele<0&&ele%2!=0){
//                 return false;
//             }
//             int num= 0;
//             if(ele>0){
//                 num=ele*2;
//             }
//             else{
//                 num=ele/2;
//             }
//             if(umap[num]==0){
//                 return false;
//             }
//             umap[ele]--;
//             umap[num]--;
//         }
//         return true;
//     }
// };

// 242. Valid Anagram
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//      vector<int>arr1(26,0);
//      vector<int>arr2(26,0);
//         for(int i=0;i<s.length();i++){
//             arr1[s[i]-'a']++;
//         }
//         for(int i=0;i<t.length();i++){
//             arr2[t[i]-'a']++;
//         }
//         for(int i=0;i<26;i++){
//             if(arr1[i]!=arr2[i]){
//                 return false;
//             }
//         }
//         return true;
        
//     }
// };
int main(){
  cout<<"Hii";
  return 0;
}