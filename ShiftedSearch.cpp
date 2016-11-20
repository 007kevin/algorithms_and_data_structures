#include <iostream>
#include <vector>
using namespace std;

int findShifted(vector<int> &arr){
  int l=0, r=arr.size()-1;
  if (arr[l] < arr[r]) return 0;
  while (l <= r){
    int mid = (l+r)/2;
    if (arr[mid] > arr[mid+1])
      return mid+1;
    if (arr[mid+1] > arr[r])
      l = mid;
    else
      r = mid;
  }
  return -1;
}

int binarySearch(vector<int> &arr,int num){
  int l = 0, r = arr.size()-1, n = arr.size();
  int offset = findShifted(arr);
  
  while (l <= r){
    int mid = (l+r)/2;
    if (arr[(mid+offset)%n] == num)
      return (mid+offset)%n;
    if (num < arr[(mid+offset)%n])
      r = mid-1;
    else
      l = mid+1;
  }
  return -1;
}

                

int main(){
  int n;          // 0 1 2 3 4 5 6  7 8 9
  vector<int> arr = {3,4,5,6,1,2};
  for (auto num : arr)
    cout << num << '\t';
  cout << endl;
  cout << "The beginning of array starts at index at: " << findShifted(arr) << endl;
  cout << "Enter number to search for: ";
  cin>>n;
  int r = binarySearch(arr,n);
  if (r < 0)
    cout << "Number not found" << endl;
  else
    cout << "Number found at index: " << r << endl;
  
}
