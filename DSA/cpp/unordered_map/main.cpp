#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string, int> m;

    m["india"] = 200;
    m["china"] = 200;
    m["us"] = 200;
    m["france"] = 200;
    for(pair<string, int> country: m){
        cout<<country.first<<"-->"<<country.second<<endl;
    }

    return 0;
}