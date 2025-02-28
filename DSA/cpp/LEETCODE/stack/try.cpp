#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;


class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data =data;
        this->next = NULL;

    }
};

class linklist{
    public:
    Node* root;

    linklist(){
        this->root = NULL;
    }

    void push_back(int data){
        Node* temp = root;
        while(temp->next){
            temp = temp->next;
        }
        temp    
    }
};


int main(){

    

    return 0;
}