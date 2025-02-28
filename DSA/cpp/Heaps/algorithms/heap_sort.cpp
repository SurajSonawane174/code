#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
void heapify(vector<int>& v, int i,int n){
    int maxi = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && v[left] > v[maxi]) maxi = left;
    if(right < n && v[right] > v[maxi]) maxi = right;
    if( maxi != i){
        swap(v[i], v[maxi]);
        heapify(v, maxi, n);
    }
}

void heapsort(vector<int>& v){
    int n = v.size();
    for(int i = n / 2 -1; i >= 0; i--){
        heapify(v, i, n);
    }
    for(int i = n-1; i >= 0; i--){
        swap( v[0], v[i]);
        heapify(v, 0, i);
    }
}

int main(){

    vector <int> data = {1, 4, 2, 5, 3};
    heapsort(data);
    for(int i: data){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}