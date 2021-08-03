#include<iostream>
#include<vector>
#include<stack>
using namespace std;
char openBracket(char ch){
  if(ch=='{') return '}';
  else if(ch=='[') return ']';
  else return ')';
}
void balancedParenthesis(){
  string s="[{}{]}(){([])}]";
  stack<int>st;
  for(int i=0;i<s.length();i++){
    if(s[i]=='('||s[i]=='['||s[i]=='{'){
      st.push(i);
    }
    else{
      if(st.size()==0||s[i]!=openBracket(s[st.top()])){
        cout<<"Not balanced Parenthesis"<<"\n";
        return;
      }
      else {
        st.pop();
      }
    }
  }
  if(st.size()==0){
    cout<<"Balanced Parenthesis"<<"\n";
  }
  else{
    cout<<"Not balanced Parenthesis"<<"\n";
  }
}
void nextGreaterElement1(){
  vector<int>arr={4,3,2,1,7,6,9,100,6,15,19,8,18};
  stack<int>st;
  for(int i=0;i<arr.size();i++){
    if(st.size()==0){
      st.push(arr[i]);
      continue;
    }
    while(st.size()!=0&&st.top()<arr[i]){
      cout<<"Next Greater element of "<<st.top()<<" is "<<arr[i]<<"\n";
      st.pop();
    }
    st.push(arr[i]);
  }
  while(st.size()!=0){
    cout<<"Next Greater element of "<<st.top()<<" is "<<-1<<"\n";
      st.pop();
  }
}
void nextGreaterElement(){
  vector<int>arr={4,3,2,1,7,6,9,100,6,15,19,8,18};
  vector<int>ans(arr.size(),-1);
  stack<int>st;
  for(int i=0;i<arr.size();i++){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]<arr[i]){
      ans[st.top()]= arr[i];
      // cout<<"Next Greater element of "<<st.top()<<" is "<<arr[i]<<"\n";
      st.pop();
    }
    st.push(i);
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Next Greater element of "<<arr[i]<<" is "<<ans[i]<<"\n";
    // cout<<ans[i]<<" ";
  }
}
void nextSmallerElement(){
  vector<int>arr={4,3,2,1,7,6,9,100,6,15,19,8,18};
  vector<int>ans(arr.size(),-1);
  stack<int>st;
  for(int i=0;i<arr.size();i++){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]>arr[i]){
      ans[st.top()]= arr[i];
      st.pop();
    }
    st.push(i);
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Next Smaller element of "<<arr[i]<<" is "<<ans[i]<<"\n";
    // cout<<ans[i]<<" ";
  }
}
void previousGreaterElement(){
  vector<int>arr={4,3,2,1,7,6,9,100,6,15,19,8,18};
  vector<int>ans(arr.size(),-1);
  stack<int>st;
  for(int i=arr.size()-1;i>=0;i--){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]<arr[i]){
      ans[st.top()]= arr[i];
      st.pop();
    }
    st.push(i);
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Previous Greater element of "<<arr[i]<<" is "<<ans[i]<<"\n";
    // cout<<ans[i]<<" ";
  }
}
void previousSmallerElement(){
  vector<int>arr={4,3,2,1,7,6,9,100,6,15,19,8,18};
  vector<int>ans(arr.size(),-1);
  stack<int>st;
  for(int i=arr.size()-1;i>=0;i--){
    if(st.size()==0){
      st.push(i);
      continue;
    }
    while(st.size()!=0&&arr[st.top()]>arr[i]){
      ans[st.top()]= arr[i];
      st.pop();
    }
    st.push(i);
  }
  for(int i=0;i<ans.size();i++){
    cout<<"Previous Smaller element of "<<arr[i]<<" is "<<ans[i]<<"\n";
    // cout<<ans[i]<<" ";
  }
}
int main(){
  // stack<int> st;
  // st.push(85);
  // st.push(65);
  // st.push(45);
  // st.push(34);
  // cout<<st.size()<<"\n";
  // st.push(71);
  // cout<<st.top()<<"\n";
  // st.pop();
  // balancedParenthesis();
  // nextGreaterElement1();

  // nextGreaterElement();
  // nextSmallerElement();
  // previousGreaterElement();
  // previousSmallerElement();
  return 0;
}