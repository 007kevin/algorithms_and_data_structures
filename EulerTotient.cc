/*
  Euler totient based on the mathematical foruma
  φ(n) = n * (1 – 1/p1) * (1 – 1/p2) * … * (1 – 1/pk)
 */
#include <iostream>
using namespace std;

int fi(int n){
  int r = n;
  for (int i = 2; i*i <= n; ++i){
    if (n%i==0) r-=r/i;
    while (n%i==0) n/=i;
  }
  if (n>1) r-=r/n;
  return r;
}

int main(){
  cout << fi(616) << endl; // output 240
  return 0;
}
