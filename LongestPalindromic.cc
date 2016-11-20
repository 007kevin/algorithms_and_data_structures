#include <iostream>
#include <string>
using namespace std;

int longest(string &s, int i, int j){
  if (j-i <= 1) return j-i;
  if (s[i] == s[j])
    return 2 + longest(s,i+1,j-1);
  else
    return max(longest(s,i+1,j),longest(s,i,j-1));
}

int main(){
  string s;
  cin>>s;
  cout << longest(s,0,s.size()-1) << endl;
  return 0;
}
