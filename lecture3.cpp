#include <bits/stdc++.h>
using namespace std;

int reverse(int num)
{
  int ans = 0;
  while (num != 0)
  {
    ans = ans * 10 + num % 10;
    num = num / 10;
  }
  return ans;
}
// int power(int a,int b){
//   int ans=1;
//   for(int i=1;i<=b;i++){
//     ans= ans*a;
//   }
//   return ans;
// }
int numOfDigits(int n)
{
  int count = 0;
  while (n != 0)
  {
    count++;
    n = n / 10;
  }
  return count;
}
int rotateByK(int num, int k)
{
  int d = numOfDigits(num);
  k = k % d;
  //-d<k<d
  if (k < 0)
  {
    k = k + d;
  }
  //0<=k<d
  int p = pow(10, k);
  int ans = num % p * pow(10, d - k) + num / p;
  return ans;
}

void pattern1(int n)
{
  int id = 1, nst = 1;
  while (id <= n)
  {
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    nst = nst + 1;
    id++;
  }
}
void pattern2(int n)
{
  int id = 1, nst = 1;
  while (id <= n)
  {
    int cst = 1;
    while (cst <= nst)
    {
      cout << cst;
      cst++;
    }
    cout << "\n";
    nst = nst + 1;
    id++;
  }
}
void pattern3(int n)
{
  int id = 1, nst = 1, nsp = n - 1;
  while (id <= n)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    nst = nst + 1;
    nsp = nsp - 1;
    id++;
  }
}
void pattern4(int n)
{
  int id = 1, nst = 1, nsp = n - 1;
  while (id <= n)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << cst;
      cst++;
    }
    cout << "\n";
    nst = nst + 1;
    nsp = nsp - 1;
    id++;
  }
}
void pattern5(int n)
{
  int id = 1, nst = 1, nsp = n - 1;
  while (id <= n)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    nst = nst + 2;
    nsp = nsp - 1;
    id++;
  }
}
void pattern6(int n)
{
  int id = 1, nst = 1, nsp = n - 1;
  while (id <= n)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << cst;
      cst++;
    }
    cout << "\n";
    nst = nst + 2;
    nsp = nsp - 1;
    id++;
  }
}
void pattern7(int n)
{
  int id = 1, nst = 1, nsp = n - 1;
  while (id <= 2 * n - 1)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    if (id < n)
    {
      nst = nst + 1;
      nsp = nsp - 1;
    }
    else{
      nst = nst - 1;
      nsp = nsp + 1;
    }
    id++;
  }
}
void pattern8(int n)
{
  int id = 1, nst = 1, nsp = n - 1;
  while (id <= 2 * n - 1)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    if (id < n)
    {
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
void pattern()
{
  // pattern1(5);
  // pattern2(5);
  // pattern3(5);
  // pattern4(5);
  // pattern5(5);
  // pattern6(5);
  // pattern7(5);
  // pattern8(5);
  
}

int main()
{
  // cout<<reverse(987854)<<"\n";
  // cout<<rotateByK(874562,-1)<<"\n";
  pattern();
  return 0;
}