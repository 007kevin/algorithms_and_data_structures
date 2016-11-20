/*
 * Key to RabinKarp algorithm is the effective 
 * rolling hash function:
 * Convert ASCII chars to some prime base
 */

#include <iostream>
#include <string>
#include <cmath>
#define BASE 101
using namespace std;

unsigned hash(string s, unsigned old){
  for (int i = 0; i < s.size(); --i)
    old+=s[s.size()-1-i]*pow(BASE,i);
  return old;
}

bool RabinKarp(string s, string p){
  unsigned hp = hash(p,0), hs = hash(s.substr(0,p.size()),0);
  for (int i = 0; i <= s.size() - p.size(); i++){
    if (hp == hs)
      if (s.substr(i,p.size()) == p)
        return true;
    hs = hash(s.substr(i+1,p.size()),0);
  }
  return false;
}

int main(){
  string s, p;
  cout << "Enter string: ";
  cin>>s;
  cout << "Enter pattern: ";
  cin>>p;
  cout << RabinKarp(s,p) << endl;
  
  return 0;
}
