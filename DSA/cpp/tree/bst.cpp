#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

class node{
public: 
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
   
};
void insert(node*& root, int data){
    if(root == NULL) {
    root = new node(data);
        return;
    }
    if(data < root->data) insert(root->left, data);
    if(data > root->data) insert(root->right, data);

}

node* build(vector<int> v){
    node* root = NULL;
    for(int temp: v){
        insert(root, temp);
    }
    return root;
}
void level_order(node* root){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

    }
    cout<<endl;
    return;
}
void inorder(node* root){
    if(root ==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool search(node* root, int key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    if( root->left && key< root->data) return search(root->left, key);
    if(root->right && key > root->data) return search(root->right, key);
    return false;
    
}
node* inorder_successor(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node* delete_node(node* root, int key){
    if(root == NULL) return root;
    if(key < root->data){
        root->left = delete_node(root->left, key);
    }else if(key > root->data){
        root->right = delete_node(root->right, key);
    }else{
        if(root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
        }else if(root->left == NULL){
            node* temp = root->right;
            delete(root);
            return temp;
        }else if(root->right == NULL){
            node* temp = root->left;
            delete(root);
            return temp ;

        }else{
            node* IS = inorder_successor(root->right);
            root->data = IS->data;
            root->right =  delete_node(root->right, IS->data);
        }
    }
    return root;
}
void print_in_range(node* root, int start, int end){
    if(root == NULL) return;
    if(start < root->data) print_in_range(root->left, start, end);
    if (root->data >= start && root->data <= end) {
        cout << root->data << " ";
    }
    if(end > root->data) print_in_range(root->right, start, end);

}




int main(){

    vector<int> v = {34, 7, 23, 32, 5, 62, 17, 90, 12, 45};
    node* root = build(v);
    level_order(root);
    inorder(root);
    cout<<endl;
    cout<<search(root, 32)<<endl;
    cout<<search(root, 324)<<endl;
    root = delete_node(root, 32);
    level_order(root);
    cout<<search(root, 32)<<endl;
    print_in_range(root, 5, 45);


    return 0;
}