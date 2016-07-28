/*
  Without using a calculator, how many zeros are at the end of 100! ?

  A: For a number to end in 0 means it is a multiple of 2 and 5. Therefore
     we can see how many 2's and 5's divide into n!. Supposse a is number of 
    2's and b is number of 5's. Then answer is min(a,b)
  
  Analysis: Better solution would be to just check how many 5's divide into n!
            since there are a lot more 2's than 5's
*/
#include <iostream>
#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;
int N,a,b;
int main(){
  N = 100;
  for (int i = 1; i <= 100; ++i){
    int n = i;
    while (n!=0&&n%2==0){
      a++;
      n/=2;
    }
    n = i;
    while (n!=0&&n%5==0){
      b++;
      n/=5;
    }
  }
  cout << min(a,b) << endl;
  return 0;
}


