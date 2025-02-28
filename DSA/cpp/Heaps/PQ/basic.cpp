#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){

    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.push(3);
    cout<<"the top elemnt of the pq : "<<pq.top()<<endl;

    return 0;
}