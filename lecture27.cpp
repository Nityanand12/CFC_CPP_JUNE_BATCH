#include<iostream>
#include<algorithm>
using namespace std;

class AVL{
  public:
  class Node{
    public:
    int val;
    Node *left;
    Node *right;
    int height;
    Node(int val){
      this->val=val;
      left=nullptr;
      right=nullptr;
      height=1;
    }
  };
  private:
  int height(Node *myNode){
    if(myNode==nullptr) return 0;
    return myNode->height;
  }
  Node *leftRotation(Node *myNode){
    Node *b= myNode->right;
    Node *c= b->left;
    b->left=myNode;
    myNode->right=c;
    b->height=max(height(b->left),height(b->right))+1;
    myNode->height=max(height(myNode->left),height(myNode->right))+1;
    return b;
  }
  Node *rightRotation(Node *myNode){
    Node *b= myNode->left;
    Node *c= b->right;
    b->right=myNode;
    myNode->left=c;
    b->height=max(height(b->left),height(b->right))+1;
    myNode->height=max(height(myNode->left),height(myNode->right))+1;
    return b;
  }
  Node *balance(Node *myNode){
    if(height(myNode->right)-height(myNode->left)>1){
      if(height(myNode->right->left)-height(myNode->right->right)>0){
      myNode->right =  rightRotation(myNode->right);
      }
     myNode = leftRotation(myNode);
    }
    if(height(myNode->left)-height(myNode->right)>1){
      if(height(myNode->left->right)-height(myNode->left->left)>0){
      myNode->left =  leftRotation(myNode->right);
      }
     myNode = rightRotation(myNode);
    }
    return myNode;
  }
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
    myNode->height=max(height(myNode->left),height(myNode->right))+1;
    myNode= balance(myNode);
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
  AVL av1;
  for(int i=1;i<=10;i++){
    av1.insert(i);
  }
  av1.display();
  // av1.insert();
  return 0;
}