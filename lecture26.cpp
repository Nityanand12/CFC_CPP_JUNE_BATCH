#include<iostream>
using namespace std;

// 337. House Robber III
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         vector<int>ans= fun(root);
//         return max(ans[0],ans[1]);
//     }
//     vector<int> fun(TreeNode* root){
//         if(root==nullptr){
//             vector<int>base(2,0);
//             return base;
//         }
//         vector<int>left= fun(root->left);
//         vector<int>right= fun(root->right);
//         vector<int>ans(2,0);
//         ans[0]=left[1]+right[1]+root->val;
//         ans[1]=max(left[0],left[1])+max(right[0],right[1]);
//         return ans;
//     }
// };


// 669. Trim a Binary Search Tree
// class Solution {
// public:
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
//         if(root==nullptr){
//             return nullptr;
//         }
//         if(root->val<low){
//             return trimBST(root->right,low,high);
//         }
//         else if(root->val>high){
//             return trimBST(root->left,low,high);
//         }
//         else{
//             root->left= trimBST(root->left,low,high);
//             root->right= trimBST(root->right,low,high);
//         }
//         return root;
//     }
// };



// 235. Lowest Common Ancestor of a Binary Search Tree
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // TreeNode* ans= nullptr;
//         if(p->val>q->val){
//            return fun(root,q,p);
//         }
//         else{
//             return fun(root,p,q);
//         }
//         // return ans;
//     }
//     TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q){
//         while(root!=nullptr){
//             if(p->val<root->val&&q->val<root->val){
//                 root=root->left;
//             }
//             else if(p->val>root->val&&q->val>root->val){
//                 root=root->right;
//             }
//             else{
//                 break;
//             }
//         }
//         return root;
//     }
// };



//  236. Lowest Common Ancestor of a Binary Tree
// class Solution {
// public:
//     vector<TreeNode*> fun(TreeNode* root, TreeNode* p){
//         if(root==nullptr){
//             vector<TreeNode*>base;
//             return base;
//         }
//         if(root==p){
//             vector<TreeNode*>base;
//             base.push_back(p);
//             return base;
//         }
//         vector<TreeNode*>left= fun(root->left,p);
//         if(left.size()!=0){
//             left.push_back(root);
//         }
//         vector<TreeNode*>right= fun(root->right,p);
//         if(right.size()!=0){
//             right.push_back(root);
//         }
//         if(right.size()!=0) return right;
//         return left;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//       vector<TreeNode*>path1= fun(root,p);
//       vector<TreeNode*>path2= fun(root,q);
//         int x= path1.size()-1;
//         int y= path2.size()-1;
//         TreeNode *ans=nullptr;
//         while(x>=0&&y>=0&&path1[x]->val==path2[y]->val){
//             ans= path2[y];
//             x--;
//             y--;
//         }
//         return ans;
//     }
    
// };


// 450. Delete Node in a BST
// class Solution {
// public:
//     int minimum(TreeNode* root){
//         if(root->left==nullptr){
//             return root->val;
//         }
//         return minimum(root->left);
//     }
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root==nullptr){
//             return root;
//         }
//         if(root->val==key){
//             if(root->left==nullptr&&root->right==nullptr){
//                 return nullptr;
//             }
//             else if(root->left!=nullptr&&root->right!=nullptr){
//                 int minimumVal=minimum(root->right);
//                 root->val=minimumVal;
//                 root->right= deleteNode(root->right,minimumVal);
//             }
//             else if(root->left!=nullptr){
//                 return root->left;
//             }
//             else{
//                 return root->right;
//             }
//         }
//         if(root->val>key){
//             root->left=deleteNode(root->left,key);
//         }
//         else{
//             root->right=deleteNode(root->right,key);
//         }
//         return root;
        
//     }
// };

int main(){

  return 0;
}