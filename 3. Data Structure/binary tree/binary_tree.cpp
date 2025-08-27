#include <iostream>
#include <queue>
#include<algorithm>

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



int main()
{
    // node* root=new node(10);
    // node* a = new node(20);
    // node* b = new node(30);
    // node* c = new node(40);
    // node* d = new node(50);
    // node* e = new node(60);

    // // make connection 
    // root->left = a;
    // root->right = b;

    // a->left = c;

    // b->left = d;
    // b->right = e;


    // pre_order(root);
    // in_order(root);
    // pre_order(root);
    // cout << endl;
    // in_order(root);
    // cout << endl;
    // post_order(root);

    // level_order(root);
    node* root = input();
    pre_order(root);
    // level_order(root);

   

    
    
}