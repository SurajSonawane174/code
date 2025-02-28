#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

class Student {
    // operatror overloading    
public:
    string Name;
    int marks;

    Student(string name, int marks){
        this->Name = name;
        this->marks = marks;
    }   
    bool operator < (const Student &obj) const{
        return this->marks < obj.marks;
    }


};

int main(){

    priority_queue <Student> pq;
    pq.push(Student("aman", 66));
    pq.push(Student("astha", 90));
    pq.push(Student("bhumika", 86));
    while(!pq.empty()){
        cout<<"Name : "<<pq.top().Name<<"  marks : "<<pq.top().marks<<endl;
        pq.pop();
    }

    
    while(!pq.empty()){

    }
 
    return 0;
}