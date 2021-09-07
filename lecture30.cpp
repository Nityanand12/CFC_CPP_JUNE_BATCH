#include <bits/stdc++.h>
using namespace std;



// 347. Top K Frequent Elements
// class Solution {
// public:
//     class node{
//       public:
//         int val,freq;
//         node(int val,int freq){
//             this->val=val;
//             this->freq=freq;
//         }
//         node(){
            
//         }
//     };
//     class comparator{
//         public:
//         bool operator()(node &n1,node &n2){
//             return n1.freq<n2.freq;
//         }
//     };
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int>umap;
//         for(int ele: nums){
//             umap[ele]++;
//         }
//         vector<int>ans;
//         priority_queue<node,vector<node>,comparator>pq;
//         for(auto ele: umap){
//             pq.push({ele.first,ele.second});
//         }
//         while(ans.size()<k){
//             node rem= pq.top();
//             pq.pop();
//             ans.push_back(rem.val);
//         }
//         return ans;
//     }
// };




// 703. Kth Largest Element in a Stream
// class KthLargest {
// public:
//     priority_queue<int,vector<int>,greater<int>>pq;
//     int ele=0;
//     KthLargest(int k, vector<int>& nums) {
//         ele=k;
//         for(int i=0;i<k&&i<nums.size();i++){
//             pq.push(nums[i]);
//         }
//         for(int i=k;i<nums.size();i++){
//             if(nums[i]>pq.top()){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
//     }
    
//     int add(int val) {
//         if(pq.size()==ele&&val>pq.top()){
//             pq.pop();
//             pq.push(val);
//         }
//         else if(pq.size()<ele){
//             pq.push(val);
//         }
//         return pq.top();
//     }
// };




// 1046. Last Stone Weight
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         priority_queue<int>pq;v
//         for(int ele: stones){
//             pq.push(ele);
//         }
//         while(pq.size()>1){
//             int a= pq.top();
//             pq.pop();
//             int b= pq.top();
//             pq.pop();
//             if(a!=b){
//                 pq.push(abs(a-b));
//             }
//         }
//         if(pq.size()==0){
//             return 0;
//         }
//         return pq.top();
//     }
// };



class student{
  public:
  string name;
  int roll;
  int marks;
  student(string name,int roll,int marks){
    this->name=name;
    this->roll=roll;
    this->marks=marks;
  }
  student(){

  }
};
class comparator{
  public:
  bool operator()(student &s1,student &s2){
    return s1.marks<s2.marks;
  }
};

int main(){
  // priority_queue<int,vector<int>>pq1;
  // priority_queue<int>pq1;
  // pq1.push(8);
  // pq1.push(70);
  // pq1.push(11);
  // pq1.push(15);
  // pq1.push(19);
  // pq1.push(8);
  // pq1.push(100);
  // pq1.push(1);
  // while(pq1.size()!=0){
  //   cout<<pq1.top()<<" ";
  //   pq1.pop();
  // }

  // priority_queue<int,vector<int>,greater<int>>pq2;
  // pq2.push(8);
  // pq2.push(70);
  // pq2.push(11);
  // pq2.push(15);
  // pq2.push(19);
  // pq2.push(8);
  // pq2.push(100);
  // pq2.push(1);
  // while(pq2.size()!=0){
  //   cout<<pq2.top()<<" ";
  //   pq2.pop();
  // }


  priority_queue<student,vector<student>,comparator>pq3;
  pq3.push({"Ram",30,95});
  pq3.push({"Amit",6,85});
  pq3.push({"Shyam",35,92});
  pq3.push({"Vivek",37,86});
  while(pq3.size()!=0){
    student rem= pq3.top();
    pq3.pop();
    cout<<rem.name<<" "<<rem.marks<<" "<<rem.roll<<"\n";
  }

  return 0;
}