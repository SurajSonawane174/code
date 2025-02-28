#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MaxActivity(vector<int>* selected, vector<int> start, vector<int> end){
    int count = 1;
    int currentend = end[0];
    selected->push_back(0);
    for(int i = 0; i < start.size(); i++){
        if(currentend <= start[i]){
            count++;
            currentend  = end[i];
            selected->push_back(i);
        }
    }
    return count;
}


int main(){

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    vector<int> selected;
    int count = MaxActivity(&selected, start, end);
    cout<<count<<endl;
    for(int i =0; i < count; i++){
        cout<<selected[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}