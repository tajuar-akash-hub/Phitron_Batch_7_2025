#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;

class node
{
public:
  int val;
  node *left;
  node *right;
  // constructor

  node(int val)
  {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
  void display()
  {
    cout << val << " " << left->val << " " << right->val << endl;
  }
};

node*  input(){
    // binary input works in level order 
    int value ; cin>>value;
    // cout << value;

    node* root ;
    if(value == -1) root = NULL;
    else root = new node(value);

    queue<node*> q;
    
    if(root!=NULL) q.push(root);

    while(!q.empty()){

        // 1 : take it out 
        node* temp = q.front();
        q.pop();

        // 2 . work with those nodes
        int l,r; cin >>l>>r;
        node* left_node , *right_node;

        if(l == -1) left_node = NULL;
        else left_node = new node(l);

        if(r == -1) right_node = NULL;
        else right_node= new node(r);

        temp->left = left_node;
        temp->right = right_node;


        // 3. push childrens 

        if(left_node!=NULL) q.push(left_node);
        if(right_node!=NULL) q.push(right_node);
    }
    return root;
}

void level_order(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        if (temp->left ) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
        
        cout << temp->val <<" ";
    }
}

bool search(node* root, int x){
   if (root == NULL ) return false;
   if(root->val == x) return true;
   if(x < root->val) return search(root->left,x);
   else return search(root->right,x);
}

void insert(node *&root, int x)
{
  node* new_node = new node(x);
  if (root == NULL) root = new_node;

  if (x < root->val)
  {
    if(root->left == NULL) root->left = new_node;
    else insert(root->left, x);
  }

  if( x > root->val) {
    if( root->right == NULL ) root->right = new_node;
    else insert(root->right,x);
  }
  
  
}

node *convert_array_to_bst(int a[], int size, int l, int r)
{
  // base case
  if (l > r)
    return NULL;

  int mid = (l + r) / 2;
  // new node
  node *root = new node(a[mid]);

  node *left_sub_tree = convert_array_to_bst(a,size, l, mid - 1);
  node *right_sub_tree = convert_array_to_bst(a,size,mid+1, r);

  root->left = left_sub_tree;
  root->right = right_sub_tree;

  return root;
}

int main(){
  // node* root = input();
  // int x ; cin >> x; 
  // bool result = search(root,x);
  // cout << ((result == true) ? "Found" : "Not found") << endl;

  //array input
  int size; cin >> size;
  int a[size];

  for (int i = 0; i < size; i++)
  {
    cin >> a[i];
  }
 

  node* root = convert_array_to_bst(a,size,0,size-1);

  level_order(root);

  return 0;

}