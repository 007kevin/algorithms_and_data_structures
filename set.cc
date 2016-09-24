#include <iostream>
#include <set>
using namespace std;

int main(){
  set<int> S;
  for (int i = 0; i < 10; ++i)
    S.insert(i);
  set<int>::iterator lower = S.lower_bound(3);
  set<int>::iterator upper = S.upper_bound(7);
  while (lower != upper){
    cout << *lower << endl;
    lower++;
  }

  return 0;
}
