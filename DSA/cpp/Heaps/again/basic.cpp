#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap{
private:
    vector<int> arr;
public:
    void push(int data){
        // first push the data to the vector
        // reaarrange the heap
        arr.push_back(data);
        int childindex = arr.size()-1;
        int parent_idx = (childindex) / 2;
        while(parent_idx >= 0 & arr[parent_idx] < arr[childindex]){
            swap(arr[childindex], arr[parent_idx]);
            parent_idx  = childindex;
        }
    }
    void heapify(int i){
        if(arr.empty()) return;
        int maxidx = i;
        int right = 2 * i + 1;
        int left = 2 * i + 2;
        if(right < arr.size() && arr[maxidx] < arr[right]) maxidx = right;
        if(left < arr.size() && arr[maxidx] < arr[left]) maxidx = left;

        if(maxidx != i){
            swap(arr[maxidx], arr[i]);
            heapify(maxidx);
        }
    }
    void pop(){
        // swa[] the fist element with the last element 
        // heapify the heap tao arrange the heap
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        heapify(0);
        
    }
    int top(){
        return arr[0];
    }
    bool IsEmpty(){
        return arr.empty();
    }
};

int main(){

    

    return 0;
}