#include<iostream>
#include<queue>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

class graph{
private: 
    int v;
    list<int> * l;
public:
    graph(int v){
        this->v = v;
        l = new list<int> [v];
    }    

    void addedge(int u, int v){
        this->l[u].push_back(v);
        this->l[v].push_back(u);
    }
    void display(){
        for(int i =0; i < v; i++){
            cout<<"Vertex "<<i<<": ";
            for(int j: this->l[i]){
                cout<<" --> "<<j;
            }
            cout<<endl;
        }
    }
    void bfs(int idx){
        vector<bool> visited(v, false);
        queue<int> q;
        q.push(idx);
        visited[idx] = true;
        while(!q.empty()){
            int curr = q.front();
            cout<<curr<<"--> ";  
            q.pop();
            list<int> neighbour = this->l[curr];
            for(int neighbour : this->l[curr]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true; 
                }
            }
                
        }
        cout<<endl;
        
    }
    void dfs_helper(int src, vector<bool>&visited){
        if(visited[src]) return;
        visited[src] = true;
        cout<<src<<" ";
        for(int ele: this->l[src]){
            dfs_helper(ele, visited);
        }
    }

    void dfs(int src){
        vector<bool> visited(v, false);
        dfs_helper(src, visited);
        cout<<endl;
        
    }
    bool has_path_helper(int src, int dest, vector<bool> & visited){
        if(visited[src]) return false;
        visited[src] = true;
        if(src == dest) return true;
        for(int ele: this->l[src]){
            if(has_path_helper(ele, dest, visited)) return true;
        }
        return false;

    }
    bool has_path(int src, int dest){
        vector<bool> visited(v, false);
        return has_path_helper(src, dest, visited);
    }
    bool is_cycle(int src){

    }
    vector<int> kahns_algo(){
        vector<int> indegree(v, 0);
        vector<int> result;
        
        // Calculate indegree for each vertex
        for(int i=0; i<v; i++){
            for(int neighbour : l[i]){
                indegree[neighbour]++;
            }
        }
        
        // Add vertices with 0 indegree to queue
        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // Process vertices
        while(!q.empty()){
            int curr = q.front();
            result.push_back(curr);
            q.pop();
            
            // Reduce indegree of neighbours
            for(int neighbour : l[curr]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        
        return result;
    }

    bool bipartite(){
        vector<bool>visited(v, false);
        queue<int> q;
        vector<int> color(v, -1);
        q.push(0);
        visited[0] = true;
        color[0] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            // cout<<
            for(int ele: this->l[curr]){
                int curr_color = color[curr];
                if(!visited[ele]){
                    q.push(ele);
                    visited[ele] = true;
                    color[ele]  = 1-curr_color;
                }else{
                    if(curr_color == color[ele]) return false;
                }
            }
        }
        return true;
    }
    void all_path_helper(int s, int d,vector<bool>& visited, string path, vector<string>& allpaths){
        if(s == d){
            path += to_string(s);
            allpaths.push_back(path);
            return;
        } 
        visited[s] = true;
        path += to_string(s);
        for(int ele : this->l[s]){
            if(!visited[ele]){
                all_path_helper(ele, d, visited, path, allpaths);
            }
            
        }        
        path.pop_back();
        visited[s] = false;
    }
    vector<string> find_all_paths(int s, int d) {
        vector<bool> visited(v, false);  
        vector<string> allpaths;
        string path = "";
        all_path_helper(s, d, visited, path, allpaths);
        return allpaths;
    }
    void print_allpath(vector<string> allpaths){
        int i = 0;
        for(string path : allpaths){
            cout<<"path "<<i++<<" :"<<path<<endl;
        }
    }


};

int main(){

    // undirected unwighted graph using the adjancecny list
    graph g(5);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(4, 3);
    g.addedge(2, 4);
    g.display();
    g.bfs(0);
    g.dfs(0);
    cout<<g.has_path(1, 1)<<endl;
    cout<<g.bipartite()<<endl;
    g.print_allpath(g.find_all_paths(0, 3));



    return 0;
}