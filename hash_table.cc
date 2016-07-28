#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;
#define LEN 11
template <typename T>
struct node {
  T data;
  node<T> *next;
  node(T d): next(NULL) {
    data = d;
  }
};

template <typename K>
struct Hash {
  unsigned operator()(const int key){
    int v = 0;
    unsigned char byte_array[sizeof(key)];
    memcpy(byte_array,&key,sizeof(key));
    for (int i = 0; i < sizeof(key); ++i){
      cout << byte_array[i] << endl;
      v+=byte_array[i];
    }
    return v;
  }
  unsigned operator()(const string key){
    int v = 0;
    for (int i = 0; i < key.size(); ++i)
      v+=key[i];
    return v;
  }
};

template <typename K, typename V, typename F = Hash<K> >
class HashTable {
  node<V> **arr;
  F Hashfunc;
public:
  HashTable(){
    arr = (node<V>**) malloc(sizeof(node<V>*) * LEN);
    assert(arr != NULL);
    for (int i = 0; i < LEN; ++i)
      arr[i] = NULL;
  }
  int hash_function(K key){
    return Hashfunc(key)%LEN;
  }
  void insert(K key, V value){
    int index = hash_function(key);
    node<V> *cur = arr[index];
    if (cur == NULL)
      


  }
};

int main(){
  HashTable<string,string> H;
  cout << H.hash_function("Kevin") << endl;
  return 0;
}
