#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void fun1(int num)
{
  num = num * 10;
  cout << num << "\n";
}

void fun2(int *p)
{
  *p = 50;
  cout << *p << "\n";
}
void fun3(int &p)
{
  p = p + 1;
  cout << p << "\n";
}
void pointer()
{
  // int a=15;
  // int *p= &a;
  // int *p;
  // p=&a;
  // cout<<p<<"\n";
  // cout<<*p<<"\n";
  // *p=75;
  // cout<<a<<"\n";

  // int **q=&p;

  // cout<<*q<<" "<<p<<"\n";
  // int ***r=&q;
  // cout<<**r<<" "<<*q<<" "<<p<<"\n";
  // cout<<***r<<" "<<**q<<" "<<*p<<"\n";

  // int arr[]={10,45,6,4,65};
  // cout<<*(arr+0)<<"\n";
  // cout<<*(arr+2)<<"\n";
  // int *k= arr;
  // cout<<*(k+3)<<"\n";

  // cout<<*(k+0)<<" "<<*(arr+0)<<" "<<arr[0]<<"\n";
  // cout<<*(k+1)<<" "<<*(arr+1)<<" "<<arr[1]<<"\n";
  // cout<<*(k+2)<<" "<<*(arr+2)<<" "<<arr[2]<<"\n";
  // cout<<*(k+3)<<" "<<*(arr+3)<<" "<<arr[3]<<"\n";
  // cout<<*(k+4)<<" "<<*(arr+4)<<" "<<arr[4]<<"\n";

  // int num =100;
  // fun1(num);
  // cout<<num<<"\n";
  // fun2(&num);
  // cout<<num<<"\n";

  // int &p= num;
  // fun3(num);
  // cout<<num<<"\n";

  // int arr2[]={10,256,6,65,4,2};
  // cout<<*(arr2+3)+2<<"\n";

  // vector<int>arr3={54,654,48,65,4,655,43};
  // int *p= arr3.data();
  // *(p+4)=87;
  // cout<<arr3[4]<<"\n";
}

class student
{
public:
  string name;
  int rollNo;
  int marks;
  void study()
  {
    cout << name << " can study"
         << "\n";
  }
  student(string name,int rollNo,int marks){
    this->name=name;
    this->rollNo= rollNo;
    this->marks= marks;
  }

  student(){
    cout<<"This is default constructor"<<"\n";
  }
  
};

bool comparison(student &a,student &b){
  return a.rollNo>b.rollNo;
}
int main()
{
  //  pointer();

  // student st1;
  // st1.name = "Jethalal";
  // st1.rollNo = 20;
  // st1.marks = 100;
  // cout<<st1.name<<" "<<st1.rollNo<<" "<<st1.marks<<"\n";

  // student st2("Jethalal",20,100);
  // or
   // student st2={"Jethalal",20,100};
  // cout<<st2.name<<" "<<st2.rollNo<<" "<<st2.marks<<"\n";


  vector<student>arr={{"Iyer",15,89},{"Jethalal",20,100},{"Bhide",3,97},{"Popatlal",25,92}};
  // for(student ele: arr){
  //   cout<<ele.name<<" "<<ele.rollNo<<" "<<ele.marks<<"\n";
  // }

  // sort(arr.begin(),arr.end(),[](student &a,student &b){
  //   return a.rollNo<b.rollNo;
  // });

  sort(arr.begin(),arr.end(),comparison);

  for(student ele: arr){
    cout<<ele.name<<" "<<ele.rollNo<<" "<<ele.marks<<"\n";
  }
  return 0;
}