#include <iostream>
#include <vector>
using namespace std;
void print_spiral(vector<vector<int> > M){
  int R = M.size();
  int C = M[0].size();
  int s = 0;
  int count = R*C;
  while (true){
    for (int i = s; i < C; ++i){
      cout << M[s][i] << " ";
      count--;
    }
    if (count <= 0) break;    
    --C;
    for (int i = s+1; i < R; ++i){
      cout << M[i][C] << " ";
      count--;      
    }
    --R;
    if (count <= 0) break;        
    for (int i = C-1; i >= s; --i){
      cout << M[R][i] << " ";
      count--;      
    }
    if (count <= 0) break;        
    for (int i = R-1; i > s; --i){
      cout << M[i][s] << " ";
      count--;      
    }
    if (count <= 0) break;        
    s++;
  }
  cout << endl;
}


int main(){
  // vector<vector<int> > M = {{ 1, 2, 3, 4, 5},
  //                           { 6, 7, 8, 9,10},
  //                           {11,12,13,14,15},
  //                           {16,17,18,19,20}};

  vector<vector<int> > M = {{ 1, 2, 3},
                            { 4, 5, 6},
                            { 7, 8, 9}};
  
  print_spiral(M);
  return 0;
}
