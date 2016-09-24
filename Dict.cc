#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class ValidWordAbbr {
    struct W {
        string w;
        bool uniq;
      W() : uniq(true) {};
        W(string word) : w(word), uniq(true) {}; 
    };
    unordered_map<string, W> A;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        vector<string>::iterator it = dictionary.begin();
        while (it != dictionary.end()){
            string a = to_abbrev(*it);
            if (A.find(a) == A.end())
                A.emplace(a,W(*it));
            else
                A[a].uniq = false;
            it++;
        }
    }
    
    string to_abbrev(string word){
        if (word.size() <= 2)
            return word;
        return word[0]+to_string(word.size()-2)+word[word.size()-1];
    }

    bool isUnique(string word) {
        if (A.find(to_abbrev(word)) == A.end())
            return true;
        return A[to_abbrev(word)].w == word && 
               A[to_abbrev(word)].uniq;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");

int main(){

  return 0;
}
