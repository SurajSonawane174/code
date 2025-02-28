#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class TrieNode{
public:
        
    unordered_map<char, TrieNode*> child;
    bool endofword;

    TrieNode(){
        endofword = false;
    }

};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string key){
        TrieNode* temp = root; 
        for(int i = 0; i < key.size(); i++){
            if(temp->child.count(key[i]) == 0){
                temp->child[key[i]] = new TrieNode();// insert;
            }
            temp = temp->child[key[i]];
        }
        temp->endofword = true;
    }
    bool search(string key){
        TrieNode* temp = root;
        for(int i = 0; i < key.size();i ++){
            if(temp->child.count(key[i]) == 0){
                return false;
            }
            temp = temp->child[key[i]];
        }
        if(temp->endofword){
            return true;
        }
        return false;
    }
};
bool helper(Trie trie, string key){
    for(int i = 0; i< key.size(); i++){
        string first = key.substr(0, i + 1);
        string second = key.substr(i+1);
        
        if(trie.search(first)){
            
        }
    }
}

void wordbreak(vector <string> dict, string key){
    Trie trie;
    for(int i =0; i < dict.size(); i++){
        trie.insert(dict[i]);
    }
}


int main(){

    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    

    return 0;
}