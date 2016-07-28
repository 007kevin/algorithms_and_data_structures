#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#define min(a,b) ((a) < (b) ? (a) : (b))
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

  /*
    Checks to see if Tree is BST.
   */
  bool isBST(node *cur,int LMAX, int RMAX){
    if (cur == NULL) return true;
    if (LMAX < cur->data && cur->data <= RMAX){
      return isBST(cur->left, LMAX, cur->data) &&
        isBST(cur->right,cur->data,RMAX);
    }
    return false;
  }

  bool find_path_to_node(vector<int> &path, node *cur, int d){
    if (cur == NULL)
      return false; // Node not found
    if (cur->data == d){
      path.push_back(cur->data);
      return true;
    }
    path.push_back(cur->data);
    if (d < cur->data)
      return find_path_to_node(path,cur->left,d);
    else
      return find_path_to_node(path,cur->right,d);
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

  // We will find the path to s and path to e
  // and compare. The last common node between
  // the two paths is part of the path between s
  // and e. Any other common nodes are not part of the
  // path and every uncommon nodes are part of the path
  void find_path_between_nodes(int s, int e){
    vector<int> s_path;
    vector<int> e_path;
    if (!find_path_to_node(s_path,head,s)){
      cout << "No such path to: " << s << endl;
      return;
    }
    if (!find_path_to_node(e_path,head,e)){
      cout << "No such path to: " << e << endl;
      return;
    }
    // find last common
    int i;
    for (i = 0; i < min(s_path.size(),e_path.size())-1; ++i)
      if (s_path[i+1] != e_path[i+1])
        break;
    for (int s = s_path.size()-1; s >= i; --s)
      cout << s_path[s] << " ";
    for (int e = i+1; e < e_path.size(); ++e)
      cout << e_path[e] << " ";
    cout << endl;
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
    // TEST1
    /*
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
    */
    // TEST2
    BST T;
    vector<int> list = {10,15,19,13,11,14,16,17,18,
                        5,3,8,9,6,7,1,4};
    for (int i = 0; i < list.size(); ++i)
      T.insert(list[i]);
    T.find_path_between_nodes(15,20);
    return 0;
  }
