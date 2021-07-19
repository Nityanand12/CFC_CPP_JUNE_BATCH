#include<iostream>
#include<vector>
using namespace std;

void ratInMazeWithoutReturnType(int sr,int sc,int er,int ec,string ans){
  if(sc==ec&&sr==er){
    cout<<ans<<"\n";
    return;
  }
  if(sc+1<=ec){
    ratInMazeWithoutReturnType(sr,sc+1,er,ec,ans+"H");
  }
  if(sr+1<=er){
    ratInMazeWithoutReturnType(sr+1,sc,er,ec,ans+"V");
  }
}

void ratInMazeWithoutReturnTypeDiagonally(int sr,int sc,int er,int ec,string ans){
  if(sc==ec&&sr==er){
    cout<<ans<<"\n";
    return;
  }
  if(sc+1<=ec){
    ratInMazeWithoutReturnTypeDiagonally(sr,sc+1,er,ec,ans+"H");
  }
  if(sr+1<=er){
    ratInMazeWithoutReturnTypeDiagonally(sr+1,sc,er,ec,ans+"V");
  }
  if(sc+1<=ec&&sr+1<=er){
    ratInMazeWithoutReturnTypeDiagonally(sr+1,sc+1,er,ec,ans+"D");
  }
}
void ratInMazeWithoutReturnType(){
  int sr=0,sc=0,er=2,ec=2;
  ratInMazeWithoutReturnType(sr,sc,er,ec,"");
  ratInMazeWithoutReturnTypeDiagonally(sr,sc,er,ec,"");
}

vector<string> ratInMazeWithReturnType(int sr,int sc,int er,int ec){
  if(sr==er&&sc==ec){
    vector<string>base;
    base.push_back("");
    return base;
  }
  vector<string>myAns;
  if(sc+1<=ec){
    vector<string> left= ratInMazeWithReturnType(sr,sc+1,er,ec);
    for(int i=0;i<left.size();i++){
      myAns.push_back("H"+left[i]);
    }
  }
  if(sr+1<=er){
    vector<string> down= ratInMazeWithReturnType(sr+1,sc,er,ec);
    for(int i=0;i<down.size();i++){
      myAns.push_back("V"+down[i]);
    }
  }
  return myAns;
}

void ratInMazeWithReturnType(){
  int sr=0,sc=0,er=2,ec=2;
  vector<string>ans= ratInMazeWithReturnType(sr,sc,er,ec);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<"\n";
  }
}

void nokiaKeyPadWithoutReturnType(vector<string>&arr,string ans,string number,int id){
  if(id==number.length()){
    cout<<ans<<"\n";
    return;
  }
  char ch= number[id];
  int index= (int)(ch-'0');
  for(int i=0;i<arr[index].size();i++){
    nokiaKeyPadWithoutReturnType(arr,ans+arr[index][i],number,id+1);
  }
}
void nokiaKeyPadWithoutReturnType(){d
  vector<string>arr={"abc","def","ghi","jkl","mno","pqr","stu","vwx","yz",":;,"};
  string num="23";
  nokiaKeyPadWithoutReturnType(arr,"",num,0);
}

int main(){
  // ratInMazeWithoutReturnType();
  // ratInMazeWithReturnType();
  nokiaKeyPadWithoutReturnType();
}