#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permutationWithRepition(vector<int>&arr,int target,int sum,string ans){
  if(sum==target){
    cout<<ans<<"\n";
    return;
  }
  for(int ele: arr){
    if(sum+ele<=target){
      permutationWithRepition(arr,target,sum+ele,ans+to_string(ele)+" ");
    }
  }
}
void combinationWithRepition(vector<int>&arr,int target,int sum,string ans,int id){
  if(sum==target){
    cout<<ans<<"\n";
    return;
  }
  for(int i=id;i<arr.size();i++){
    if(sum+arr[i]<=target){
      combinationWithRepition(arr,target,sum+arr[i],ans+to_string(arr[i])+" ",i);
    }
  }
}
void combinationWithoutRepition(vector<int>&arr,int target,int sum,string ans,int id){
  if(sum==target){
    cout<<ans<<"\n";
    return;
  }
  for(int i=id;i<arr.size();i++){
    if(sum+arr[i]<=target){
      combinationWithoutRepition(arr,target,sum+arr[i],ans+to_string(arr[i])+" ",i+1);
    }
  }
}
void permutationWithoutRepition(vector<int>&arr,int target,int sum, string ans,vector<int>&vis){
  if(sum==target){
    cout<<ans<<"\n";
    return;
  }
  for(int i=0;i<arr.size();i++){
    if(sum+arr[i]<=target&&vis[i]==0){
      vis[i]=1;
      permutationWithoutRepition(arr,target,sum+arr[i],ans+to_string(arr[i])+" ",vis);
      vis[i]=0;
    }
  }
}
void fourSpecialQuestions(){
  vector<int>arr={1,2,3,4};
  int target= 4;

  // permutationWithRepition(arr,target,0,"");
  // combinationWithRepition(arr,target,0,"",0);
  // combinationWithoutRepition(arr,target,0,"",0);
  vector<int>vis(arr.size(),0);
  permutationWithoutRepition(arr,target,0,"",vis);
}

int main(){

  // string str;
  // cin>>str;
  // cout<<str;

  // getline(cin,str);
  // cout<<str<<"\n";

  // cout<<"hii";
  // string s="abcfdgfgh";
  // cout<<s.size()<<"\n";
  // s=s+"677878";
  // s=s+to_string(100);
  // cout<<s<<"\n";


  // string Comparison
  // string s1="abaaaa";
  // string s2="aazzzzzz";
  // if(s1>s2){
  //   cout<<"s1 is greater than s2"<<"\n";
  // }
  // else if(s1<s2){
  //   cout<<"s1 is less than s2"<<"\n";
  // }
  // else{
  //   cout<<"s1 is equal than s2"<<"\n";
  // }


  // if(s1.compare(s2)>0){
  //   cout<<"s1 is greater than s2"<<"\n";
  // }
  // else if(s1.compare(s2)<0){
  //   cout<<"s1 is less than s2"<<"\n";
  // }
  // else{
  //   cout<<"s1 is equal than s2"<<"\n";
  // }


  // string st2="abcdefghi";
  // st2= st2.substr(2,6);
  // cout<<st2<<"\n";

  fourSpecialQuestions();
}