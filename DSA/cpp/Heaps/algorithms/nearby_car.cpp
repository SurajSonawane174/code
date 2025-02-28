#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class car {
public:
    int idx;
    int distSQ;

    car(int idx, int distsq){
        this->distSQ = distsq;
        this->idx = idx;
    } 
    bool operator < (const car &obj) const{
        return this->distSQ > obj.distSQ;
    }
};
void nearByCars(vector<pair<int, int>> pos, int k){
    vector<car> cars;
    for(int i = 0; i< pos.size(); i++){   // O(n)
        cars.push_back(car(i, pos[i].first * pos[i].first + pos[i].second * pos[i].second));
    }
    priority_queue<car> pq(cars.begin(), cars.end());   //O(n)
    for(int i = 0; i < k; i++){// O(k * logn)
        cout<<"car: "<<pq.top().idx<<endl;
        pq.pop();//O(logn)
    }

}

int connect_ropes(vector<int> ropes){
    priority_queue<int, vector<int>,greater<int>> pq (ropes.begin(), ropes.end());

    int cost = 0;
    while(pq.size()> 1){
        int rope1 = pq.top();
        pq.pop();
        int rope2 = pq.top();
        pq.pop();
        pq.push(rope1 + rope2);
        cost += rope1 + rope2;
    }
    return cost;
}


int main(){

    vector<pair<int, int>> position;
    position.push_back(make_pair(3, 3));
    position.push_back(make_pair(5, -1));
    position.push_back(make_pair(-2, 4));
    int k = 2;
    nearByCars(position, k);
    vector<int>ropes = {4, 3, 2, 6};
    cout<<"the min cost is : "<<connect_ropes(ropes)<<endl;
    return 0;
}