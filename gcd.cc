#include <iostream>
using namespace std;

int gcd(int a, int b){
  while (b){
    int c = b;
    b = b%a;
    a = c;  
  }
  return a;
}

int main(){
  cout << gcd(6,12) << endl;
  return 0;
}
