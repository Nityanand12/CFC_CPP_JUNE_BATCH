#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void pattern9(int n)
{
  int id = 1, nst = 1, nsp = n - 1;
  while (id <= 2 * n - 1){
    int csp = 1;
    while (csp <= nsp){
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst) {
      if(cst<=(nst+1)/2){
        cout<<cst;
      }
      else{
        cout<<nst-cst+1;
      }
      cst++;
    }
    cout << "\n";
    if (id < n){
      nst = nst + 2;
      nsp = nsp - 1;
    }
    else{
      nst = nst - 2;
      nsp = nsp + 1;
    }
    id++;
  }
}
int base10ToBase2(int num){
  int ans=0,p=0;
  while(num!=0){
    int rem = num%2;
    ans += pow(10,p)*rem;
    p++;
    num /=2;
  }
  return ans;
}
int base2ToBase10(int num){
  int ans=0,p=0;
  while(num!=0){
    int rem = num%10;
    ans += pow(2,p)*rem;
    p++;
    num /=10;
  }
  return ans;
}

void array(){
  // int arr[]={10,20,50,60,70};
  // int length= sizeof(arr)/sizeof(arr[0]);
  // for(int i=0;i<length;i++){
  //   cout<<arr[i]<<" ";
  // }
  // cout<<"\n";
  // for(int ele : arr){
  //   cout<<ele<<" ";
  // }


  // int n=5;
  // int arr[n];
  // for(int i=0;i<n;i++){
  //   cin>>arr[i];
  // }
  // for(int i=0;i<n;i++){
  //   cout<<arr[i]<<" ";
  // }


  vector<int>vec={10,20,30,40,50};
  //  cout<<vec.size()<<"\n";
  // for(int i=0;i<vec.size();i++){
  //   cout<<vec[i]<<" ";
  // }
  // cout<<"\n";
  vec.push_back(80);
  vec.push_back(100);
  // cout<<vec.size()<<"\n";
  // for(int i=0;i<vec.size();i++){
  //   cout<<vec[i]<<" ";
  // }
  // cout<<"\n";

  vec.pop_back();
  cout<<vec.size()<<"\n";
  for(int i=0;i<vec.size();i++){
    cout<<vec[i]<<" ";
  }
  cout<<"\n";




  // size and capacity


  //set
  // vec[2]= 70;
  // for(int i=0;i<vec.size();i++){
  //   cout<<vec[i]<<" ";
  // }
  // cout<<"\n";


  //insert
  // vec.insert(vec.begin()+3,70);
  // for(int i=0;i<vec.size();i++){
  //   cout<<vec[i]<<" ";
  // }
  // cout<<"\n";
  // cout<<vec.size()<<"\n";



  //erase
  // vec.erase(vec.begin()+3);
  // for(int i=0;i<vec.size();i++){
  //   cout<<vec[i]<<" ";
  // }
  // cout<<"\n";


  // vector<int>vec2(10,60);
  // for(int i=0;i<vec2.size();i++){
  //   cout<<vec2[i]<<" ";
  // }
  // cout<<"\n";
  // cout<<vec2.size()<<"\n";
  // vec2.push_back(100);
  // for(int i=0;i<vec2.size();i++){
  //   cout<<vec2[i]<<" ";
  // }
  // cout<<"\n";
  // cout<<vec2.size()<<"\n";


  vector<int>vec3={30,11,17,100,161,76,45,56};
  sort(vec3.begin(),vec3.end());
  for(int i=0;i<vec3.size();i++){
    cout<<vec3[i]<<" ";
  }
  cout<<"\n";








  // vector<int>arr;
  // for(int i=1;i<20;i++){
  //   arr.push_back(i);
  //   cout<<arr.size()<<" "<<arr.capacity()<<"\n";
  // }
}
int main(){
  // pattern9(5);
  // int ans = base10ToBase2(98);
  // cout<<ans<<"\n";
  // cout<<base2ToBase10(ans)<<"\n";

  array();

  return 0;
}