/*
 Given an array of numbers arr and a number S, find 4 different numbers in arr that sum up to S.

 Write a function that gets arr and S and returns an array with 4 indices of such numbers in arr,
 or null if no such combination exists. Explain and code the most efficient solution possible, 
 and analyze its runtime and space complexity.
 */
#include <iostream>
#include <vector>
using namespace std;

bool find_sol(vector<int> &N, vector<int> &I, int S, int sum){
  if (I.size() == 4){
    if (S == sum)
      return true;
    else
      return false;
  }
  for (int i = 0; i < N.size(); ++i){
    if (I.empty() || I[I.size()-1] < i){
      I.push_back(i);
      if (find_sol(N,I,S,sum+N[i]))
        return true;
      else {
        I.pop_back();
      }
    }
  }
  return false;
}

int main(){
  int S = 23;
  vector<int> numbers = {1,3,5,6,7,8,9};
  vector<int> indices;
  find_sol(numbers,indices,S,0);

  // prints 0, 2, 5, 6
  for (int i = 0; i < indices.size(); ++i)
    cout << indices[i] <<" ";
  cout<<endl;

  return 0;
}
