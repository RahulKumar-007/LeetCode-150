/*
 A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

 

Constraints:

    1 <= nums.length <= 1000
    -231 <= nums[i] <= 231 - 1
    nums[i] != nums[i + 1] for all valid i.

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid is a peak
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            // Move right if the right neighbor is greater
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            }
            // Otherwise, move left
            else {
                e = mid - 1;
            }
        }

        return -1; // This line should never be reached
    }
};


// Approach 2
//
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // Compare the mid element with the next element
            if (nums[mid] > nums[mid + 1]) {
                // You are in the decreasing part of the array
                // This means the peak element is to the left (including mid)
                e = mid;
            } else {
                // You are in the increasing part of the array
                // This means the peak element is to the right (excluding mid)
                s = mid + 1;
            }
        }

        // At the end of the while loop, s == e and pointing to the peak element
        return s;
    }
};
