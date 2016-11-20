#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
vector<int> b;

int f(int i){
  if (i == a.size())
    return 0;
  b[i] = max(a[i],a[i]+f(i+1));
  return b[i];
}


int main(){
  int n;
  for (int i = 0; i < 5; ++i){
    cin>>n;
    a.push_back(n);
  }
  b.resize(a.size());
  f(0);
  for (auto num : b)
    cout << num << endl;
  return 0;
}
