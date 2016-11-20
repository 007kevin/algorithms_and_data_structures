#include<iostream>
#include<sstream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool cmp(const pair<string,int> &lhs, const pair<string,int> &rhs){
  return lhs.second > rhs.second;
}

vector<pair<string,int> > getCount(string s){
  for (int i = 0; i < s.size(); ++i)
    if (!isalpha(s[i])) s[i] = ' ';
  unordered_map<string,int> H;
  stringstream is(s);
  string w;
  while(is>>w){
    H[w]++;
  }
  vector<pair<string,int> > r(H.begin(),H.end());
  sort(r.begin(),r.end(),cmp);
  return r;
}

int main(){
  string s;
  getline(cin,s);
  auto r = getCount(s);
  for (auto p : r)
    cout << p.first << " " << p.second << endl;
  return 0;
}
