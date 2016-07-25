#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bsearch(const vector<int> &list, int n, int L, int R){
  if (L== R){
    if (list[L] == n)
      return list[L];
    else
      return -1;
  }
  int mid = (L+R)/2;
  if (list[mid] == n) return list[mid];
  if (n < list[mid])
	return bsearch(list,n,L,mid-1);
  else
	return bsearch(list,n,mid+1,R);
}

int main(){
  vector<int> sorted;
  int n;
  cout<<"Enter values to be inserted into sorted array: "<< endl;
  while (cin.peek()!='\n' && cin>>n)
    sorted.push_back(n);
  cout<<"Enter value to be found: ";
  cin>>n;
  sort(sorted.begin(),sorted.end());
  int ans = bsearch(sorted,n,0,sorted.size()-1);
  if (ans != -1)
    cout << "Found: " << ans << endl;
  else
    cout << "Not Found" << endl;
  return 0;
}
