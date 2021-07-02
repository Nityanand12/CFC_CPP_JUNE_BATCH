#include <iostream>
using namespace std;
int main(){
  // int a;
  // cin>>a;
  // cout<<a<<"\n";
  // cout<<"Hello";
  // int a;
  // a=5;
  // cout<<sizeof(a)<<"\n";

  // char c='a';
  // cout<<sizeof(c)<<"\n";

  
  // int marks;
  // cin>>marks;
  // if(marks>=90){
  //   cout<<"A+ grade"<<"\n";
  // }
  // else if(marks>=80&&marks<90){
  //   cout<<"A grade"<<"\n";
  // }
  // else {
  //   cout<<"Marks ache nhi h"<<"\n";
  // }

  // int a,b,c;
  // cin>>a>>b>>c;
  // if(a>b){
  //   if(a>c){
  //     cout<<a<<"\n";
  //   }
  //   else{
  //     cout<<c<<"\n";
  //   }
  // }
  // else{
  //   if(b>c){
  //     cout<<b<<"\n";
  //   }
  //   else{
  //     cout<<c<<"\n";
  //   }
  // }

  //  int i=  1;
  // for(;;){
  //   cout<<i<<" ";
  //   i++;
  // }

  int count=0;
  int num=58764;
  while(num!=0){
    num=num/10;
    count++;
  }
  cout<<count<<"\n";

  return 0;
}