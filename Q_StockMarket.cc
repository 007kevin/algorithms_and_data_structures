#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void knuth_shuffle(vector<int> &L){
  srand(time(NULL));
  int m = L.size()-1;
  while (m){
    int i = rand()%m;
    int tmp = L[i];
    L[i] = L[m];
    L[m] = tmp;
    m--;
  }
}
int main(){
  vector<int> L = {1,2,3,4,5,6,7,8,9};
  knuth_shuffle(L);
  for (int i = 0; i < L.size(); ++i)
    cout << L[i] << " ";
  cout<<endl;
  int min = L[0];
  int max = 0;
  for (int i = 1; i < L.size(); ++i){
    if (min <= L[i])
      max = max < L[i]-min ? L[i]-min : max;
    else
      min = L[i];
  }
  cout << max << endl;
  return 0;
  }
