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


int main(){

    vector<string> words = {"the", "a", "there", "their", "any", "the"};
    Trie trie;

    for(int i = 0; i < words.size(); i++){
        trie.insert(words[i]);
    }
    cout<<trie.search("the")<<endl;
    cout<<trie.search("thdfse")<<endl;                                                                                              
    return 0;
}  