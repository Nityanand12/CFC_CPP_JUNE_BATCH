#include<iostream>
#include<vector>
using namespace std;
void onBit(){
  int n=11,m=2;
  int mask=(1<<(m-1));
  int ans= (n|mask);
  cout<<ans<<"\n";
}
void offBit(){
  int n=13,m=3;
  int mask=(1<<(m-1));
  int ans= (n&(~mask));
  cout<<ans<<"\n";
}
void toggleBit(){
  int n=9,m=3;
  int mask=(1<<(m-1));
  int ans= (n^mask);
  cout<<ans<<"\n";
}
void checkBit(){
  int n=13,m=3;
  int mask=(1<<(m-1));
  if((n&mask)!=0){
    cout<<"On bit"<<"\n";
  }
  else{
    cout<<"Off bit"<<"\n";
  }
}
void q1(){
  vector<int>arr={2,45,65,45,8,65,2};
  int ans=0;
  for(int ele: arr){
    ans= ans^ele;
  }
  cout<<ans<<"\n";
}
void q2(){
  vector<int>arr={2,45,65,45,8,65,2,12};
  int ans=0;
  for(int ele: arr){
    ans=(ans^ele);
  }
  int a= ans;
  int cnt=0;
  while(a%2!=1){
    a=a/2;
    cnt++;
  }
  int mask=(1<<cnt);
  int ans1=0;
  for(int ele: arr){
    if((mask&ele)!=0){
      ans1=(ans1^ele);
    }
  }
  int ans2= (ans^ans1);
  cout<<ans1<<" "<<ans2<<"\n";
}
int main(){
  // onBit();
  // offBit();
  // toggleBit();
  // checkBit();
  // q1();
  q2();
}