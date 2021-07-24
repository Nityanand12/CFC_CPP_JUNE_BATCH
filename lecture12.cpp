#include<vector>
#include<iostream>
using namespace std;
bool isSafeForSudoku(vector<vector<int>>&arr,int row,int col,int value){
  for(int i=0;i<arr.size();i++){
    if(arr[i][col]==value){
      return false;
    }
  }
  for(int i=0;i<arr[0].size();i++){
    if(arr[row][i]==value){
      return false;
    }
  }
  row= (row/3)*3;
  col= (col/3)*3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(arr[i+row][j+col]==value){
        return false;
      }
    }
  }
  return true;
}
void display(vector<vector<int>>&arr){
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr[0].size();j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void sudoku(vector<vector<int>>&arr,int row,int col){
  if(row==arr.size()-1&&col==arr.size()){
    display(arr);
    cout<<"\n";
    return;
  }
  if(col==arr[0].size()){
    row=row+1;
    col=0;
  }
  if(arr[row][col]!=0){
    sudoku(arr,row,col+1);
  }
  else{
    for(int value=1;value<=9;value++){
      if(isSafeForSudoku(arr,row,col,value)){
        arr[row][col]=value;
        sudoku(arr,row,col+1);
        arr[row][col]=0;
      }
    }
  }
}
void sudoku(){
  vector<vector<int>>arr={{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};
    sudoku(arr,0,0);
}
bool isSafeForNqueen(vector<vector<int>>&board,int row,int col){
  // row decrease krna
  for(int i=row;i>=0;i--){
    if(board[i][col]==1){
      return false;
    }
  }
  // row -> decrease and column-> increase
  for(int i=row,j=col;i>=0&&j<board[0].size();i--,j++){
    if(board[i][j]==1){
      return false;
    }
  }
  // row-> decrease and column-> decrease
  for(int i=row,j=col;i>=0&&j>=0;i--,j--){
    if(board[i][j]==1){
      return false;
    }
  }                                                       
  return true;
}
void nQueen(vector<vector<int>>&board,int row){
  if(row==board.size()){
    display(board);
    cout<<"\n";
    return;
  }
  for(int col=0;col<board[0].size();col++){
    if(isSafeForNqueen(board,row,col)){
      board[row][col]=1;
      nQueen(board,row+1);
      board[row][col]=0;
    }
  }
}

void nQueen(){
  int n=4;
  vector<vector<int>>board(n,vector<int>(4,0));
  nQueen(board,0);
}
void merge(vector<int>&arr,int low,int mid,int high){
  vector<int>left(mid-low+1,0);
  vector<int>right(high-mid,0);
  for(int i=low;i<=mid;i++){
    left[i-low]= arr[i];
  }
  for(int i=mid+1;i<=high;i++){
    right[i-(mid+1)]= arr[i];
  }
  int i=0,j=0;
  int p= low;
  while(i<left.size()&&j<right.size()){
    if(left[i]<=right[j]){
      arr[p]= left[i];
      i++;
      p++;
    }
    else{
      arr[p]= right[j];
      j++;
      p++;
    }
  }
  while(i<left.size()){
    arr[p]= left[i];
    i++;
    p++;
  }
  while(j<right.size()){
    arr[p]= right[j];
    j++;
    p++;
  }
}
void mergeSort(vector<int>&arr,int low,int high){
  if(low<high){
    int middle= (low+high)/2;
    mergeSort(arr,low,middle);
    mergeSort(arr,middle+1,high);
    merge(arr,low,middle,high);
  }
}

void mergeSort(){
  vector<int>arr={145,65,54,165,76,54,-65,2,1,5,7,45,75};
  mergeSort(arr,0,arr.size()-1);
  for(int ele: arr){
    cout<<ele<<" ";
  }
  cout<<"\n";
}
int main(){
  // sudoku();
  // nQueen();
  // mergeSort();
  return 0;
}