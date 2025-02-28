#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i=0, j = 0;
        int len1 =nums1.size();
        int len2 = nums2.size();
        while(i <len1 && j <len2){
            if(nums1[i] <  nums2[j]){
                result.push_back(nums1[i++]);
            }else{
                result.push_back(nums2[j++]);
            }
        }
        while(i < len1){
            result.push_back(nums1[i++]);
        }
        while(j < len2){
            result.push_back(nums2[j++]);
        }
        int n = result.size();
    if (n % 2 == 0) {
        return (result[n / 2 - 1] + result[n / 2]) / 2.0; 
    } else {
        return result[n / 2]; 
    }
        
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int start = 0;
        int end  = nums.size() - 1;

        vector<pair<int, int>> indexedNums;
    for (int i = 0; i < nums.size(); ++i) {
        indexedNums.push_back({nums[i], i}); // Store value and index
    }

    // Sort the array based on the value
    sort(indexedNums.begin(), indexedNums.end());
        while(start < end){
            int sum = nums[start] + nums[end];
            if(sum < target){
                start++;
            }else if(sum > target){
                end--;
            }
            else if(sum == target){
                result.push_back(start);
                result.push_back(end);
            }  
        }
        return result;
    }
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return mid;

            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }

int main(){

    vector<int> nums1 = {1,3};
    vector<int> nums2 = {4,5,6,7,0,1,2};
    // cout<<findMedianSortedArrays(nums1, nums2);
    // vector<int> result = twoSum(nums2, 9);
    // for(int i : result){
    //     cout<<i<<endl;
    // }
    cout<<search(nums2,0);


    return 0;
}