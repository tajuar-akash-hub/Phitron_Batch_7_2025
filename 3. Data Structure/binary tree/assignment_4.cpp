#include <iostream>
#include <queue>
#include<algorithm>
#include <math.h>

using namespace std;

class node{
    public:
        int val ;
        node* left;
        node* right;
        // constructor 

        node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
    void display(){
        cout << val <<" " << left->val <<" " << right->val <<endl ;
    }

};

void pre_order(node* root){

    /*
    order : root , left , right 
    */
    // base case 
    if(root== NULL) return;

    cout << root->val<<" ";

    pre_order(root->left);  
    pre_order(root->right);
}

void in_order(node* root){
    /*
    left, root , right 
    */
   if(root == NULL) return;
    
    in_order(root->left);  
    cout << root->val <<" " ;
    in_order(root->right);

}

void post_order(node* root){
    /*
    left, right, root 
    */
     if(root == NULL) return;
    post_order(root->left);  
    post_order(root->right);
    cout << root->val <<" " ;

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
int count_with_level_order(node* root){

    int count = 0;
    queue<node*> q;

    if(root!=NULL) q.push(root);
    else return count;

    while(!q.empty()){
        node* temp = q.front();
        if (temp->left ) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
        
        // cout << temp->val <<" ";
        count++;
    }
    return count ;

}

int count_node_using_recursion(node* root){
      if (root==NULL) return 0;
      int l = count_node_using_recursion(root->left);
      int r = count_node_using_recursion(root->right);
      return l+r+1;
}

int count_leaf_node(node * root){
     if (root==NULL) return 0;
     if(root->left == NULL && root->right == NULL) return 1;
      int l = count_node_using_recursion(root->left);
      int r = count_node_using_recursion(root->right);
      return l+r;
}
int max_height(node * root){
     if (root==NULL) return 0;
     if(root->left == NULL && root->right == NULL) return 0;
      int l = max_height(root->left);
      int r = max_height(root->right);
      return max(l,r)+1;
}

int max_depth(node * root){
     if (root==NULL) return 0;
     if(root->left == NULL && root->right == NULL) return 1;
      int l = max_depth(root->left);
      int r = max_depth(root->right);
      return max(l,r)+1;
}

void Level_order_with_level_tracks(node *root)
{
    vector<pair<node *, int>> v;
    queue<pair<node *, int>> q;
    if (root)
    {
        q.push({root, 0});
        v.push_back({root, 0});
    }

    while (!q.empty())
    {
        pair<node *, int> current = q.front();
        q.pop();
        // separate them
        node *node = current.first;
        int level = current.second;

        if (node->left)
        {
            q.push({node->left, level + 1});
            v.push_back({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
            v.push_back({node->right, level + 1});
        }
    }
    // print it
 
    for (pair<node *, int> val : v)
    {
        cout << val.first->val << " " << val.second << " " << endl;
    }
}

void Perfect_Binary_Tree(node* root){

    int number_of_nodes =  count_node_using_recursion(root);
    int depth = max_depth(root);

    int answer = pow(2,depth) -1 ; 
    
    if(answer == number_of_nodes) cout << "YES" ; 
    else cout <<"NO";

}

void go_left(node* root,vector<int> &v){

   if(root == NULL) return;
//    cout <<"from go left";

//    if(root->left == NULL && root->right == NULL) return;
   if(root->left) go_left(root->left,v);
   else go_left(root->right,v) ;
//    cout << root->val<<endl;
    v.push_back(root->val);

}

void go_right(node* root,vector<int> &v){
    // cout <<"from go right";

   if(root == NULL) return;
//    if(root->left == NULL && root->right == NULL) return;
//    cout << root->val<<endl;
    v.push_back(root->val);
   if(root->right) go_right(root->right,v);
   else go_right(root->left,v) ;
}

void go_leaf_nodes(node* root){
   if(root == NULL) return;

   if(root->left == NULL && root->right == NULL) {
    cout << root->val<<endl;
    return;
   }

   if(root->left) go_leaf_nodes(root->left);
   if(root->right) go_leaf_nodes(root->right);
   
}

void Print_Outer_Tree(node* root,vector<int> &v){

     if (root->right && root->left == NULL)
      {
         
          go_right(root, v);

          for (int val : v)
          {
              cout << val << " ";
              
          }
          return;
      }
     if (root->left && root->right == NULL)
      {
         
          go_left(root, v);

          for (int val : v)
          {
              cout << val << " ";
              
          }
          return;
      }
     if (root->left == NULL && root->right == NULL)
      {
         
          cout << root->val;
          return;
      }


      if(root->left) go_left(root,v);

      if(root->right) go_right(root->right,v);

     

      // print 

      for(int val:v){
        cout << val <<" ";
      }



    //   cout << "leaf nodes " <<endl;
    //   go_leaf_nodes(root);
      
}
   
int main()
{
   
    node* root = input();
    vector<int> v;
    Print_Outer_Tree(root,v);

}