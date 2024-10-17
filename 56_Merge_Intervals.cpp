/*
 Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();

        // edge cases
        if(n==0) return ans;
        if(n==1) return intervals;

        // sorting by first element
        sort(intervals.begin(), intervals.end());
        vector<int>temp;
        // intializing temp vector which will acts as current interval
        temp=intervals[0];

        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>temp[1])   // if the current element's lower bound is greater than uper bound of temp
            {
                ans.push_back(temp);     // insert the last interval
                temp=intervals[i];       // Update the interval
            }
            else
            {
                int bigger=(temp[1]>intervals[i][1])?temp[1]:intervals[i][1]; // merging intervals
                temp[1]=bigger;
            }
        }
        ans.push_back(temp);  // edge handling for last element
        return ans;
    }
};
