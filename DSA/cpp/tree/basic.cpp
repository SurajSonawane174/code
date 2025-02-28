#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    node(int data){
        this->data = data;
    }
};
class Info{
public:    
    bool isBst;
    int min;
    int max;
    int size;
    Info(bool isbst, int min, int max, int size){
        this->isBst = isbst;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

node* build_tree(vector<int>& v, int& idx) {
    if (idx >= v.size() || v[idx] == -1) return NULL;
    node* newnode = new node(v[idx]);
    idx++;
    newnode->left = build_tree(v, idx);
    idx++;
    newnode->right = build_tree(v, idx);
    return newnode;
}

void preorder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->right);
    preorder(root->left);
}
void inorder(node* root){
    if(root == NULL) return;
    inorder(root->right);
    cout<<root->data<<" ";
    inorder(root->left);
}
void postorder(node* root){
    if(root == NULL) return;
    postorder(root->right);
    postorder(root->left);
    cout<<root->data<<" ";
}

void level_order(node* root){
    node* queue[100];
    int front = 0, rear = 0;
    queue[rear ++] = root;
    queue[rear++] = NULL;
    while(front< rear){
        node* curr = queue[front++];
        if(curr == NULL){
            cout<< endl;
            if(front < rear){
                queue[rear++] = NULL;
            }
        }else{
            cout<<curr->data<<" ";
            if(curr->left) queue[rear++] = curr->left;
            if(curr->right) queue[rear++] = curr->right;
        }

    }
    cout<<endl;
    return;
}

int height(node* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return(max(left + 1, right + 1));
}
int count(node* root){
    if(root == NULL) return 0;
    return count(root->left) + count(root->right) + 1;
}
int sum(node* root){
    if (root == NULL) return 0;
    int left = sum(root->left);
    int right = sum(root->right);
    return left + right + root->data;
}
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long long numTrees(int n) {
    unsigned long long result = 1;
    for (int i = 0; i < n; i++) {
        result = result * (2 * n - i) / (i + 1);  
    }
    return result / (n + 1);  
}
vector<vector<int>> zigzag_level_order(node* root){

    vector<vector<int>> result;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> temp ;
    bool zigzag = false;
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(zigzag){
                reverse(temp.begin(), temp.end());
            }
            result.push_back(temp);
            temp.clear();
            if(!q.empty()){
                q.push(NULL);
            }
            zigzag = !zigzag;
        }else{
            temp.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return result;
}
void print(vector<vector<int>> result){
     // Print the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int diameter(node* root){
    if(root == NULL) return 0;
    int curr = height(root->left) + height(root->right) + 1;
    int left = diameter(root->left);
    int right = diameter(root->right);
    return max(curr, max(left, right));
     
}
pair<int , int> dia(node* root){
    if(root == NULL) return make_pair(0, 0);
    pair<int, int> leftinfo = dia(root->left);
    pair<int, int> rightinfo = dia(root->right);
    int curr = leftinfo.first + rightinfo.first + 1;
    int final = max(curr, max(leftinfo.second, rightinfo.second));
    int height = max(leftinfo.first, rightinfo.first) + 1;
    return make_pair(height, final);

}
bool isidentical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;
    return (root1->data == root2->data) && isidentical(root1->left, root2->left) && isidentical(root1->right, root2->right);
}
bool issubtree(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;
    if(root1->data == root2->data){
        //identicall comdition checking
        if(isidentical(root1, root2)) return true;
    }
    bool isleftsubtree = issubtree(root1->left, root2);
    if(!isleftsubtree){
        return issubtree(root1->right, root2);
    }
    return true;
}
void kth_level(node* root, int k){
    node* queue[100];
    int count = 0;
    int front = 0, rear = 0;
    queue[rear ++] = root;
    queue[rear++] = NULL;
    while(front< rear){
        node* curr = queue[front++];
        
        if(curr == NULL){
            count++;
            if(front < rear){
                queue[rear++] = NULL;
            }
        }else{
            if(count == k) cout<<curr->data<<" ";


            if(curr->left) queue[rear++] = curr->left;
            if(curr->right) queue[rear++] = curr->right;
        }

    }
    cout<<endl;
    return;
}
void kth_levelLrecursive(node* root, int k, int count){
    if(root == NULL || count == k){
        cout<<root->data<<" ";
        return;
    }
    if(root->left) kth_levelLrecursive(root->left, k, count + 1);
    if(root->right) kth_levelLrecursive(root->right, k, count + 1);
}
void print_path(vector<int> path){
    for(int i = 0; i < path.size(); i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}   
void find_path(node* root, vector<int>& path){
    if(root == NULL) return;
    path.push_back(root->data);
    find_path(root->left, path);
    find_path(root->right, path);
}
void lca(node* root){
    vector<int> path;
    find_path(root, path);
    print_path(path);
    
}
// size of the largest bst in bt
static int max_size ; 
Info* find_largest_bst(node* root){
    if(root == NULL){
        return new Info(true, INT32_MAX, INT32_MIN, 0);
    }
    
    Info* left = find_largest_bst(root->left);
    Info* right = find_largest_bst(root->right);    
    bool isbst = left->isBst && right->isBst && root->data < right->min && root->data > left->max;
    int maximum =max(root->data, max(left->max, right->max));
    int mini =  min(root->data, min(left->min, right->min));
    int size = right->size + left->size + 1;
    if(isbst){
        if(size > max_size) max_size = size;
    }
   
    return new Info(isbst, mini, maximum, size);
    
}
int main() { 
    vector<int> v = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int idx = 0;
    node* root = build_tree(v, idx);

    // Basic Traversals
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nLevel Order:\n";
    level_order(root);

    // Other Operations
    cout << "Height: " << height(root) << endl;
    cout << "Node Count: " << count(root) << endl;
    cout << "Sum of Nodes: " << sum(root) << endl;

    // Zigzag Traversal
    auto result = zigzag_level_order(root);
    cout << "Zigzag Level Order:\n";
    print(result);

    // Diameter
    cout << "Diameter: " << diameter(root) << endl;

    // Largest BST
    vector<int> bst = {50, 30, 5, -1, -1, 20, -1, -1, 60, 45, -1, -1,  70, 65, -1, -1, 80, -1, -1};
    idx = 0;
    node* largest_bst = build_tree(bst, idx);
    level_order(largest_bst);
    find_largest_bst(largest_bst);
    cout << "Size of Largest BST: " << max_size << endl;

    return 0;
}
