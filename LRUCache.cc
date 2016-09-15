// We use a hash table with doubly linked list
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache{
    struct node{
        node() : k(0), v(0), next(NULL), prev(NULL) {}
        node(int key, int val) : k(key), v(val), next(NULL), prev(NULL) {}
        node* next;
        node* prev;
        int k,v;
    };
    node HEAD, TAIL;
    unordered_map<int,node*> cache;
    int c;
public:
    LRUCache(int capacity) : c(capacity) {
        HEAD.next = &TAIL;
        TAIL.prev = &HEAD;
    }
    
    int get(int key) {
        unordered_map<int, node*>::iterator it;
        it = cache.find(key);
        if (it == cache.end())
            return -1;
        // Make most recent by putting node at end of DLL
        node *n = it->second;
        n->prev->next = n->next;
        n->next->prev = n->prev;
        TAIL.prev->next = n;
        n->prev = TAIL.prev;
        TAIL.prev = n;
        n->next = &TAIL;
        return n->v;
    }
    
    // When setting, we have to look for the case of setting an existing key
    // because in that case, only the value is updated and Least Recently Used
    // does not have to be deleted (don't forget to update position in DLL as well)
    void set(int key, int value) {
        unordered_map<int, node*>::iterator it;
        it = cache.find(key);
        if (it != cache.end()){
            it->second->v = value;
            get(key); // Get itself to position itself at the end of DLL
            return;
        }
        if (cache.size() >= c){
            node *lru = HEAD.next;
            cache.erase(lru->k);
            lru->prev->next = lru->next;
            lru->next->prev = lru->prev;
            delete lru;
        }
        node *new_node = new node(key,value);
        cache[key] = new_node;
        TAIL.prev->next = new_node;
        new_node->prev = TAIL.prev;
        TAIL.prev = new_node;
        new_node->next = &TAIL;
    }
    
};

int main(){

  return 0;
}
