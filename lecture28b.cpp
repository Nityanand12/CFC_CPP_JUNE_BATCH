#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;


// 1207. Unique Number of Occurrences
// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         unordered_map<int,int>umap;
//         for(int i=0;i<arr.size();i++){
//             umap[arr[i]]++;
//         }
//         unordered_set<int>s;
//         for(auto ele: umap){
//             if(s.find(ele.second)==s.end()){
//                 s.insert(ele.second);
//             }
//             else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };


// 560. Subarray Sum Equals K
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         if(nums.size()==0) return 0;
//         int ans=0;
//         vector<int>pre(nums.size(),0);
//         pre[0]= nums[0];
//         for(int i=1;i<nums.size();i++){
//             pre[i]=pre[i-1]+nums[i];
//         }
//         unordered_map<int,int>umap;
//         umap[0]=1;
//         for(int i=0;i<nums.size();i++){
//             int diff= pre[i]-k;
//             if(umap.find(diff)!=umap.end()){
//                 ans+= umap[diff];
//             }
//             umap[pre[i]]++;
//         }
//         return ans;
//     }
// };




// class Solution {
// public:
//     int firstUniqChar(string s) {
//         // vector<int>arr(26,0);
//         // for(int i=0;i<s.length();i++){
//         //     arr[s[i]-'a']++;
//         // }
//         // for(int i=0;i<s.length();i++){
//         //     if(arr[s[i]-'a']==1){
//         //         return i;
//         //     }
//         // }
//         unordered_map<char,int>umap;
//         for(int i=0;i<s.length();i++){
//             umap[s[i]]++;
//         }
//         for(int i=0;i<s.length();i++){
//             if(umap[s[i]]==1){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };



// 1. Two Sum
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int>umap;
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++){
//             int diff= target-nums[i];
//             if(umap.find(diff)!=umap.end()){
//                 ans.push_back(umap[diff]);
//                 ans.push_back(i);
//                 return ans;
//             }
//            umap[nums[i]]=i;
//         }
//         return ans;
//     }
// };


void unordered(){
  unordered_map<string,int>umap;
  umap.insert(make_pair("Ram",25));
  umap["Shyam"]=30;
  umap.insert({"Mohan",37});
  umap["Shiv"]=87;
  umap["Shiv"]=81;
  string key= "Ram";
  if(umap.find(key)==umap.end()){
    cout<<key<<" is not Found"<<"\n";
  }
  else{
    cout<<key<<" is  Found"<<"\n";
  }

  vector<int>arr={65,76,56,65,81,76,65};
  unordered_map<int,int>umap2;
  for(int ele: arr){
    umap2[ele]++;
  }
  umap2.erase(65);
  for(auto ele: umap2){
    cout<<ele.first<<" "<<ele.second<<"\n";
  }
}
ordered(){
   map<string,int>ordredMap;
  ordredMap.insert(make_pair("Ram",25));
  ordredMap["Shyam"]=30;
  ordredMap.insert({"Mohan",37});
  ordredMap["Shiv"]=87;
  ordredMap["Shiv"]=81;
  string key= "Ram";
  for(auto ele: ordredMap){
    cout<<ele.first<<" "<<ele.second<<"\n";
  }
}
set(){
  set<int>st;
  st.insert(87);
  st.insert(98);
  st.insert(77);
  st.insert(87);
  st.insert(100);
  for(auto ele: st){
    cout<<ele<<"\n";
  }
}
int main(){
  // unordered();
  // ordered();
  // set();


  return 0;
}