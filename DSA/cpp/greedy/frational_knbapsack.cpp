#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<double, int>p1, pair<double, int>p2){
    return p1.first > p2.first;
}
int kanpsack(vector<int> value, vector<int>weight, int w){
    vector <pair<double, int>> ratio(value.size( da), make_pair(0.0, 0));
    int val = 0;

    for(int i = 0; i < value.size(); i++){
        ratio[i] = make_pair(value[i] / (double)weight[i] , i);    
    }

    sort(ratio.begin(), ratio.end(), compare);
    for(int i = 0; i < value.size(); i++){
        int idx = ratio[i].second;
        if(w >= weight[idx]){
            val = val +value[idx];
            w = w - weight[idx];
        }else{
            val = val + ratio[i].first * w;
            w = 0;
            break;
        }
    
    }
    cout<<"max value is: "<<val<<endl;
    return val;
}

int main(){

    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int w = 50;
    int val = kanpsack(value,weight, w);
    return 0;
}