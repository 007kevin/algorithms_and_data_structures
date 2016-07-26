#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &list, int a, int b){
  int tmp = list[a];
  list[a] = list[b];
  list[b] = tmp;
}

int quickselect(vector<int> &list, int k, int L, int R){
  cout << endl;
  if (L==R) return list[L];
  int mid = (L+R)/2;
  swap(list,L,mid);
  int last = L;
  for (int i = L+1; i <= R; ++i)
    if (list[L] > list[i]) // We want to move the last position if pivot is > cur
      swap(list,i,++last);
  swap(list,L,last);
  if (last == k)
    return list[last];
  else if (k < last)
    return quickselect(list,k,L,last-1);
  else
    return quickselect(list,k,last+1,R);
}

int main(){
  vector<int> list;
  int n,k;
  cout<<"Enter values: ";
  while(cin.peek()!='\n'&&cin>>n)
    list.push_back(n);
  cout<<"Enter kth (0-based index): ";
  cin>>k;
  cout<<quickselect(list,k,0,list.size()-1)<<endl;
  return 0;
}
