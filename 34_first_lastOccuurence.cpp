/*
 Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int result=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                result=mid;
                high=mid-1; }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        if(result!=-1){
            low=result;
            high=nums.size()-1;}
            int result2=-1;
          while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                result2=mid;
                low=mid+1; }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        ans[0]=result;
        ans[1]=result2;
        return ans;
    }
};
