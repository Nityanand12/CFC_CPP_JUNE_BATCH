#include<vector>
#include<iostream>
using namespace std;
void display(vector<vector<int>>&vec){
  for(int i=0;i<vec.size();i++){
    for(int j=0;j<vec[i].size();j++){
      cout<<vec[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void transpose(vector<vector<int>>&vec){
  for(int i=0;i<vec.size();i++){
    for(int j=i+1;j<vec[i].size();j++){
      int t= vec[i][j];
      vec[i][j]= vec[j][i];
      vec[j][i]= t;
    }
  }
}
void rotate90(vector<vector<int>>&vec){
  transpose(vec);
  for(int i=0;i<vec.size();i++){
    int low=0,high= vec[i].size()-1;
    while (low<high){
      int t= vec[i][low];
      vec[i][low]= vec[i][high];
      vec[i][high]= t;
      low++;
      high--;
    }
  }
}
void spiralClockWise(vector<vector<int>>&vec){
  int sr=0,sc=0,er=vec.size()-1,ec=vec[0].size()-1;
  int tle= vec.size()*vec[0].size();
  int dir=-1;
  while(tle!=0){
    dir=(dir+1)%4;
    if(dir==0){
      for(int i=sc;i<=ec;i++){
        cout<<vec[sr][i]<<" ";
        tle--;
      }
      sr++;
    }
    else if(dir==1){
      for(int i=sr;i<=er;i++){
        cout<<vec[i][ec]<<" ";
        tle--;
      }
      ec--;
    }
    else if(dir==2){
      for(int i=ec;i>=sc;i--){
        cout<<vec[er][i]<<" ";
        tle--;
      }
      er--;
    }
    else {
      for(int i=er;i>=sr;i--){
        cout<<vec[i][sc]<<" ";
        tle--;
      }
      sc++;
    }
  }
}
void exitPoint(vector<vector<int>>&vec){
  int dir=0;
  int sr=0,sc=0;
  while(true){
    dir=(dir+vec[sr][sc])%4;
    if(dir==0){
      sc++;
    }
    else if(dir==1){
      sr++;
    }
    else if(dir==2){
      sc--;
    }
    else {
      sr--;
    }
    if(sc==-1){
      sc++;
      break;
    }
    else if(sr==-1){
      sr++;
      break;
    }
    else if(sc==vec[0].size()){
      sc--;
      break;
    }
    else if(sr==vec.size()){
      sr--;
      break;
    }
  }
  cout<<sr<<" "<<sc<<"\n";
}
int main(){
  // int arr[4][3]={{1,2,3},{4,5,6},{8,9,10},{11,12,13}};
  // for(int i=0;i<4;i++){
  //   for(int j=0;j<3;j++){
  //     cout<<arr[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  vector<vector<int>>vec(5,vector<int>(3,-1));
  // display(vec);

  vector<vector<int>> vec2={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
  // display(vec2);
  // transpose(vec2);

  // rotate90(vec2);
  // spiralClockWise(vec2);
  vector<vector<int>>arr={{1,0,1},{0,1,0},{1,0,1}};
  exitPoint(arr);
  // display(vec2);
}