#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Node{
public: 
    int data;
    Node* next;
    string key;

    Node(int data, string key){
        this->key = key;
        this->data = data;
        this->next = NULL;
    }
    void insert(int data){
        
    }
};

class HashTable{
private: 
   

public:
    int totalsize;
    int currsize;
    Node** table;
    HashTable(int size){
        this->totalsize = size;
        this->currsize = 0;
        this->table = new Node*[totalsize];
       for(int i = 0; i < size; i++){
            table[i] = NULL;
       }
    }
    int hashing(string key){
        int idx = 0;
        for(int i = 0; i < key.size(); i++){
            idx += int (key[i]) * (int) key[i];
        }
        idx = idx % totalsize;
        return idx;
    }
   
    void insert(string key, int val){
        int idx = hashing(key);
        Node* newnode = new Node(val, key);
        Node* temp = table[idx];
        newnode->next = temp;
        temp = newnode;
        currsize ++;
        double lambda = currsize / (double)totalsize;
        if(lambda > 1){
            rehash();
        }
    }

    // O(n) 
    void rehash(){
        Node** oldtable = table;
        int oldsize = totalsize;
        totalsize = 2 * totalsize;

        table = new Node*[totalsize];
        for(int i = 0; i < totalsize; i++){
            table[i] = NULL;
        }
        for(int i = 0; i < oldsize; i++){
            Node * temp = oldtable[i];
            insert(temp->key, temp->data);
            temp = temp->next;
            if(oldtable[i] == NULL){
                delete(oldtable[i]);
            }
            
        }

    } 
    
    void remove(string key){

    }
    
    void search(){
        
    }
};

int main(){

    HashTable ht();

    return 0;
}