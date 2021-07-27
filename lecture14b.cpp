#include<iostream>
using namespace std;
class Node{
  public:
  int val;
  Node *next;
  Node(int val){
    this->val=val;
    this->next=nullptr;
  }
};
class customLinkedList{
  public:
  Node *head, *tail;
  int size=0;
  customLinkedList(){
    size=0;
    head=nullptr;
    tail= nullptr;
  }
  void addLast(int value){
    Node *node= new Node(value);
    if(size==0){
      size++;
      head=node;
      tail=node;
      return;
    }
    tail->next=node;
    tail= node;
    size++;
  }
  void addFirst(int value){
    Node *node= new Node(value);
    if(size==0){
      addLast(value);
      return;
    }
    node->next= head;
    head= node;
    size++;
  }
  void removeLast(){
    if(size==0){
      cout<<"MY Linedlist is empty"<<"\n";
      return ;
    }
    if(size==1){
      size--;
      head= nullptr;
      tail= nullptr;
      return;
    }
    size--;
    Node *p= head;
    while(p->next!=tail){
      p=p->next;
    }
    p->next=nullptr;
    tail= p;
  }
  void removeFirst(){
    if(size==0){
      cout<<"MY Linedlist is empty"<<"\n";
      return;
    }
    if(size==1){
      removeLast();
      return;
    }
    size--;
    head= head->next;
  }
  void display(){
    Node *p= head;
    while(p!=nullptr){
      cout<<p->val<<"\n";
      p=p->next;
    }
  }
};
int main(){
  customLinkedList *c1= new customLinkedList();
  c1->addLast(10);
  c1->addLast(20);
  c1->addLast(15);
  c1->addFirst(25);
  c1->addFirst(30);
  cout<<" My size "<<c1->size<<"\n";
  c1->removeLast();
  c1->removeFirst();
  c1->display();
cout<<" My size "<<c1->size<<"\n";
  return 0;
}