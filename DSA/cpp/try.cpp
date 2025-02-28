#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int binary_search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;
}
vector<int> removeDuplicates(vector<int>& nums) {
    vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        if(i == 0 || nums[i] != nums[i-1]) {
            result.push_back(nums[i]);
        }
    }
    return result;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums = removeDuplicates(nums);
        return nums[nums.size() - k];

    }
    
};

int main(){

    vector<int> nums = {1,1,3, 4,4};
    Solution sol;
    cout << sol.findKthLargest(nums, 2) << endl;
    return 0;
}