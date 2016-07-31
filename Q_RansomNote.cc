#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool canWrite(const string &s,const string &t){
  char pool[1<<8];
  memset(pool,0,sizeof(pool));
  for (int i = 0; i < s.size(); ++i)
    if (s[i] != ' ')
      pool[s[i]]++;
  for (int i = 0; i < t.size(); ++i)
    if (t[i] != ' '){
      if (pool[t[i]])
        pool[t[i]]--;
      else
        return false;
    }
  return true;
}

int main(){
  string source = "programming interviews are weird";
  string target = "no scheme";
  cout << canWrite(source,target) << endl;
  return 0;
}
