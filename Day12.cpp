// Question -   Single Element in a Sorted Array


/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.



Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10


Note: Your solution should run in O(log n) time and O(1) space.

*/

// Solution

class Solution {

    int helper(vector<int>& nums , int low , int high) {
        if(low > high) {
            return -1;
        }

        if(high == low) {
            return nums[low];
        }

        int mid = (low + high) / 2;
        int ans = 0;

            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid + 1]) {
                   ans =  helper(nums , mid + 2 , high);
                }
                else{
                    ans = helper(nums , low , mid);
                }
            }

            else {
                if(nums[mid] == nums[mid - 1]) {
                    ans = helper(nums , mid + 1 , high);
                }

                else{
                    ans = helper(nums , low , mid - 1);
                }
            }

        return ans;

    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        return helper(nums , 0 , nums.size() - 1);
    }
};
