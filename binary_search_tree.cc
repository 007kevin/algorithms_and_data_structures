#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

struct node {
  int data;
  node *left, *right;
  node(int d):left(NULL),right(NULL){
    data = d;
  }
};

class BST {
  node *head;
  void destroy(node *cur){
    if (cur == NULL)
      return;
    destroy(cur->left);
    destroy(cur->right);
    delete cur;
  }
  node* insert(node *cur, int d){
    if (cur == NULL)
      return new node(d);
    if (d < cur->data)
      cur->left = insert(cur->left,d);
    else
      cur->right = insert(cur->right,d);
    return cur;
  }
  // inorder print
  void print(node *cur){
    if (cur == NULL) return;
    print(cur->left);
    cout << cur->data << " ";
    print(cur->right);
  }
  /*
    Three possible cases to consider when deleting from BST.
    1) Deleting node with no children: simply remove node from the tree
    2) Deleting node with one child: remove node and replace with its child
    3) Deleteing node with two children: copy the inorder-successor or inorder-predecessor
       node value R into the node, then recursively delete on the node with R
   */
  node* remove(node *cur, int d){
    if (cur == NULL)
      return cur;
    if (cur->data == d){
      if (cur->left == NULL && cur->right == NULL){
        delete cur;
        return NULL;
      }
      if (cur->left != NULL && cur->right == NULL){
        node *__n = cur->left;
        delete cur;
        return __n;
      }
      if (cur->left == NULL && cur->right != NULL){
        node *__n = cur->right;
        delete cur;
        return __n;
      }
      if (cur->left != NULL && cur->right != NULL){
        int n = find_predecessor(cur->left);
        cur->data = n;
        remove(cur->left,n);
        return cur;
      }
    }
    if (d < cur->data)
      cur->left = remove(cur->left,d);
    else
      cur->right = remove(cur->right,d);
    return cur;
  }
  
  int find_predecessor(node *cur){
    if (cur->right == NULL)
      return cur->data;
    return find_predecessor(cur->right);
  }
  
  bool isBST(node *cur,int LMAX, int RMAX){
    if (cur == NULL) return true;
    if (LMAX < cur->data && cur->data <= RMAX){
      return isBST(cur->left, LMAX, cur->data) &&
        isBST(cur->right,cur->data,RMAX);
    }
    return false;
  }
public:
  BST():head(NULL){}
  ~BST(){
    destroy(head);
  }
  void insert(int d){
    head = insert(head,d);
  }
  void print(){
    print(head);
    cout << endl;
  }
  void remove(int d){
    remove(head,d);
  }
  bool isBST(){
    return isBST(head,INT_MIN,INT_MAX);
  }
  
};

void knuth_shuffle(vector<int> &L){
  srand(time(NULL));
  int tmp,i,m = L.size()-1;
  while(m){
    i = rand()%m;
    tmp = L[i];
    L[i] = L[m];
    L[m] = tmp;
    m--;
  }
}

int main(){
    BST T;
    vector<int> list;
    int input;
    for (int i = 0; i < 20; ++i)
      list.push_back(i);
    knuth_shuffle(list);
    cout << "before:" << endl;
    for (int i = 0; i < list.size(); ++i)
      cout << list[i] << " ";
    cout << endl;
    cout << "tree:" << endl;
    for (int i = 0; i < list.size(); ++i)
      T.insert(i);
    T.print();
    cout << "Enter node to delete: ";
    cin>>input;
    T.remove(input);
    T.print();
    cout << T.isBST() << endl;
    return 0;
  }
