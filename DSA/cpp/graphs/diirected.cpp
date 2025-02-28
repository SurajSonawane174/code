#include<iostream>
#include<queue>
#include<list>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    int v;
    list<int>* l;
public:
    Graph(int v){
        this->v = v;
        this->l = new list<int> [v];
    }
    void addedge(int u, int v){
        this->l[u].push_back(v);
    }
    void display(){
        for(int i = 0; i < v; i++){
            cout<<"Vertex "<<i<<" : ";
            for(int neighbour: this->l[i]){
                cout<<"->"<<neighbour;
            }
            cout<<endl;
        }
    }

    void bfs(int src){
        vector<bool> visited(v, false);
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";
            for(int neighbour : this->l[curr]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout<<endl;
    }
    void dfs_helper(int src, vector<bool>& visited){
        if(visited[src]) return;
        visited[src] = true;
        cout<<src<<" ";
        for(int neigh : this->l[src]){
            dfs_helper(neigh, visited);
        }
    }
    
    void dfs(int src){
        vector<bool> visited(v, false);
        dfs_helper(src, visited);

    }
    
    void topological_sort_dfs(int src, vector<bool> &visited, stack<int> &st){
        visited[src] = true;
        for(int neighbour : this->l[src]){
            if(!visited[neighbour]){
                topological_sort_dfs(neighbour, visited, st);
            }
        }
        st.push(src);
    }
    vector<int> topological_sort(){
        vector<bool> visited(v, false);
        stack<int> st;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                topological_sort_dfs(i, visited, st);
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;


    }


};
`

int main(){

    Graph g(6);
    g.addedge(0, 3);
    g.addedge(2, 3);
    g.addedge(1, 3);
    g.addedge(4, 0);
    g.addedge(4, 1);
    g.addedge(5, 0);
    g.addedge(5, 2);
    g.display();\
    vector<int> result = g.topological_sort();

    cout << "Topological Sort: ";
    for(int ele : result){
        cout<<ele<<" ";
    }
    return 0;
}