#include<iostream>
using namespace std;
// class student
// {
//   private:
//   string name;
//   int rollNo;
//   int marks;
//   public:
//   void setName(string myName){
//     name= myName;
//   }
//   void setRollNo(int myRollNo){
//     rollNo= myRollNo;
//   }
//   void setMarks(int myMarks){
//     if(marks<40) return;
//     marks= myMarks;
//   }
//   string getName(){
//     return name;
//   }
//   int getRollNo(){
//     return rollNo;
//   }
//   int getMarks(){
//     return marks;
//   }
//   void study()
//   {
//     cout << name << " can study"
//          << "\n";
//   }
//   student(string name,int rollNo,int marks){
//     this->name=name;
//     this->rollNo= rollNo;
//     this->marks= marks;
//   }

//   student(){
//     // cout<<"This is default constructor"<<"\n";
//   }
  
// };


class vehicle{
  public:
  int mileage;
  int door;
  vehicle(){

  }
  void tyre(int a,int b){
    cout<<"Vehicle has "<<a<<" black tyres "<<b<<" white tyres"<<"\n";
  }
   void tyre(int a){
    cout<<"Vehicle has "<<a<<" tyres"<<"\n";
  }
  virtual void move(){
    cout<<"Vehicle can move anywhere "<<"\n";
  }
};

class car : public vehicle{
  public:
  int seat;
  void move(){
    cout<<"Car can move anywhere "<<"\n";
  }
  void tyre(int a){
    cout<<"Car has "<<a<<" tyres"<<"\n";
  }
};
int main(){
  // student st1;
  // st1.setName("Jethalal");
  // st1.setMarks(100);
  // st1.setRollNo(20);
  // cout<<st1.getName()<<" "<<st1.getMarks()<<" "<<st1.getRollNo()<<"\n";

  // vehicle vc;
  // vehicle *vc1= new vehicle();
  // (*vc1).door=4;// or 
  // vc1->door=4;
  // (*vc1).mileage=60; or
  // vc1->mileage=60;
  // cout<<vc1->door<<" "<<vc1->mileage<<"\n";
  // vc1->tyre(3 ,2);

  // car *c1= new car();
  // c1->move();

  // vehicle *v1= new car();
  // v1->move();
  // vehicle *v2= new car();
  // v2->tyre(5);

  vehicle *vc= new vehicle();
  vc->tyre(2);
  return 0;
}