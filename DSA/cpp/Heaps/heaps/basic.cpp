#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class heap{
public:
    vector<int> arr;
    void push(int data){
        //  step  1-> push the value to the vector
        arr.push_back(data);
        // step 2 -> fix the heap;
        int childI = arr.size()-1;
        int parI = (childI - 1) / 2;
        while( parI >= 0 && arr[childI] > arr[parI]){
            swap(arr[childI], arr[parI]);
            childI = parI;
            parI = (childI - 1) / 2;
        }   
    }
    void heapify(int i){
        if(arr.empty()) return; 
        int maxi = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < arr.size() && arr[left] > arr[maxi]) maxi = left;
        if(right < arr.size() && arr[right] > arr[maxi]) maxi = right;
        swap(arr[maxi], arr[i]);
        if(maxi != i){
            heapify(maxi);
        }
        return; 
    }
    void pop(){
        // step 1-> swap the root and the last element ;
        swap(arr[0],arr[arr.size()-1]);
        // step 2 -> delete the last element;
        arr.pop_back();
        // step 3-> fix the heap;
        // heapify function;
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

    heap h;
    h.push(10);
    h.push(100);
    h.push(1000);
    h.push(10000);
    cout<<"the top of the heap is : "<< h.top()<<endl;
    h.pop();
    cout<<"the top of the heap is : "<< h.top()<<endl;

    return 0;
}