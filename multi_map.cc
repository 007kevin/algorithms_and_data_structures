/*The  Skyline Problem - Leetcode 
  Note about multiset
  - Defined in <set> header
  - erase(key) delete all elements of that key!!
  - erase(iterator) deletes only that element
 */
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> MS;
        MS.insert(0);
        map<int,vector<int>> x;
        vector<pair<int,int>> sol;
        for (vector<int> &b : buildings){
            x[b[0]].push_back(b[2]);
            x[b[1]].push_back(-b[2]);
        }
        for (pair<int,vector<int>> c : x){
            for (int &h : c.second){
                if (h > 0) MS.insert(h);
                else MS.erase(MS.find(-h));
            }
            if (sol.empty() || sol.rbegin()->second != *MS.rbegin())
                sol.push_back({c.first,*MS.rbegin()});
        }
        return sol;
    }
};

int main(){

  return 0;
}
