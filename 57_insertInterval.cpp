/*
 You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int start = newInterval[0], end = newInterval[1];

        // Add all intervals that come before the new interval
        while (i < intervals.size() && intervals[i][1] < start) {
            res.push_back(intervals[i]);
            i++;
        }

        // Merge Overlapping Intervals
        while (i < intervals.size() && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        res.push_back({start, end});

        // Add all intervals that come after the new interval
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
