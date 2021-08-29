#include<iostream>
using namespace std;



// 102. Binary Tree Level Order Traversal
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>>ans;
//         if(root==nullptr){
//             return ans;
//         }
//         queue<TreeNode*>que;
//         que.push(root);
//         int d=1;
//         while(que.size()!=0){
//             int cnt=0;
//             ans.push_back(vector<int>());
//             for(int i=0;i<d;i++){
//                 TreeNode* rem= que.front();
//                 que.pop();
//                 ans[ans.size()-1].push_back(rem->val);
//                 if(rem->left!=nullptr){
//                     que.push(rem->left);
//                     cnt++;
//                 }
//                 if(rem->right!=nullptr){
//                     que.push(rem->right);
//                     cnt++;
//                 }
//             }
//             d= cnt;
//         }
//         return ans;
//     }
// };



// 101. Symmetric Tree
// class Solution {
// public:
//     bool fun(TreeNode* root1,TreeNode* root2){
//         if(root1==nullptr&&root2==nullptr){
//             return false;
//         }
//         if(root1==nullptr||root2==nullptr){
//             return true;
//         }
//         if(root1->val!=root2->val){
//             return true;
//         }
//         bool res= false;
//         res= res||fun(root1->left,root2->right);
//         res=res|| fun(root1->right,root2->left);
//         return res;
//     }
//     bool isSymmetric(TreeNode* root) {
//         return fun(root,root)==false;
//     }
// };



// 543. Diameter of Binary Tree
// class Solution {
// public:
//     int ans=0;
//     int diameterofBt(TreeNode* root){
//         if(root==nullptr){
//             return -1;
//         }
//         int left= diameterofBt(root->left);
//         int right= diameterofBt(root->right);
//         ans=max(ans,left+right+2);
//         return max(left,right)+1;
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==nullptr){
//             return 0;
//         }
//         diameterofBt(root);
//         return ans;
//     }
// };


class binarySearchTree{
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
  Node *insert(Node *myNode,int value){
    if(myNode==nullptr){
      Node *baseCase = new Node(value);
      return baseCase;
    }
    if(myNode->val<=value){
      myNode->right= insert(myNode->right,value);
    }
    else{
      myNode->left= insert(myNode->left,value);
    }
    return myNode;
  }
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
  bool find(int data,Node *myNode){
    if(myNode==nullptr){
      return false;
    }
    if(myNode->val==data){
      return true;
    }
    if(myNode->val<data){
     return find(data,myNode->right);
    }
    else{
      return find(data,myNode->left);
    }
  }
  public:
  void display(){
    display(root);
  }
  void insert(int value){
    this->root=insert(root,value);
  }
  bool find(int data){
    return find(data,root);
  }

};

int main(){
  binarySearchTree bst1;
  bst1.insert(12);
  bst1.insert(16);
  bst1.insert(18);
  bst1.insert(5);
  bst1.insert(6);
  bst1.insert(9);
  bst1.insert(11);
  bst1.insert(8);
  bst1.insert(17);
  bst1.insert(4);
  bst1.display();
  cout<<bst1.find(20)<<"\n";
  return 0;
}