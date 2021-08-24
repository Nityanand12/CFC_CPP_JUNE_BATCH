#include<iostream>
using namespace std;

// 145. Binary Tree Postorder Traversal
// class Solution {
// public:
//     void postorder(TreeNode* root,vector<int>&ans){
//         if(root==nullptr) return;
//         postorder(root->left,ans);
//         postorder(root->right,ans);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         postorder(root,ans);
//         return ans;
//     }
// };


// 94. Binary Tree Inorder Traversal
// class Solution {
// public:
//      void inorderTraversal(TreeNode* root,vector<int>&ans){
//         if(root==nullptr){
//             return;
//         }
//         inorderTraversal(root->left,ans);
//          ans.push_back(root->val);
//         inorderTraversal(root->right,ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//          vector<int>ans;
//         inorderTraversal(root,ans);
//         return ans;
//     }
// };


// 144. Binary Tree Preorder Traversal
// class Solution {
// public:
//     void preorderTraversal(TreeNode* root,vector<int>&ans){
//         if(root==nullptr){
//             return;
//         }
//         ans.push_back(root->val);
//         preorderTraversal(root->left,ans);
//         preorderTraversal(root->right,ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         preorderTraversal(root,ans);
//         return ans;
//     }
    
// };


// 111. Minimum Depth of Binary Tree
// class Solution {
// public:
//     int fun(TreeNode* root){
//         if(root==nullptr){
//             return INT_MAX;
//         }
//         if(root->left==nullptr&&root->right==nullptr){
//             return 1;
//         }
//         return min(fun(root->left),fun(root->right))+1;
//     }
//     int minDepth(TreeNode* root) {
//         if(root==nullptr){
//             return 0;
//         }
//        return fun(root);
//     }
    
// };



// 104. Maximum Depth of Binary Tree
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==nullptr){
//             return 0;
//         }
//         return max(maxDepth(root->left),maxDepth(root->right))+1;
//     }
// };




class binaryTree{
  public:
  class Node{
    public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
      this->val=val;
      left=nullptr;
      right=nullptr;
    }
  };
  private:
  Node *root=nullptr;
  Node *insert(Node *myNode,int idx,int value,string dir){
    if(myNode==nullptr){
      Node *baseCase = new Node(value);
      return baseCase;
    }
    if(idx==dir.length()){
      myNode->val=value;
      return myNode;
    }
    if(dir[idx]=='R'){
      myNode->right= insert(myNode->right,idx+1,value,dir);
    }
    else{
      myNode->left= insert(myNode->left,idx+1,value,dir);
    }
    return myNode;
  }
  public:
  void insert(int value,string dir){
    this->root=insert(root,0,value,dir);
  }
  private:
  void display(Node *myNode){
    if(myNode==nullptr){
      return;
    }
    if(myNode->left!=nullptr){
      cout<<myNode->left->val<<" -> ";
    }
    else{
      cout<<" -> ";
    }
    cout<<myNode->val;
    if(myNode->right!=nullptr){
      cout<<" <- "<<myNode->right->val;
    }
    else{
      cout<<" <- ";
    }
    cout<<"\n";
    display(myNode->left);
    display(myNode->right);
  }
  public:
  void display(){
    display(root);
  }
};
int main(){
  binaryTree bt;
  bt.insert(15,"");
  bt.insert(28,"R");
  bt.insert(86,"L");
  bt.insert(21,"LR");
  bt.insert(80,"RR");
  bt.insert(72,"RL");
  bt.insert(5,"L");
  bt.display();
  return 0;
}