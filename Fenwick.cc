#include <iostream>
#define MAXN 1000
using namespace std;
int n=10,a[MAXN];

void update(int k, int v){
  for (int i = k; i <= n; i+=i&-i){
    a[i]+=v;
  }
}

int sum(int k){
  int s = 0;
  for (int i = k;i;i-=i&-i)
    s+=a[i];
  return s;
}

int main(){
  for (int i = 1; i <= n; ++i)
    update(i,i);

  for (int i = 1; i <= n; ++i)
    cout << a[i] << '\t';
  cout << endl;

  int idx;
  while(cin>>idx){
    for (int i = 1; i <= n; ++i)
      cout << a[i] << '\t';
    cout << endl;
    cout << "Sum at index: " << idx << " is " << sum(idx) << endl;
  }




  
  return 0;
}
