class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        int res = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // If no overlap, move to the current interval
            if (start >= prevEnd) {
                prevEnd = end;
            } 
            else {
                // Overlap found, remove the interval that ends later
                res++;
                prevEnd = min(end, prevEnd);
            }
        }

        return res;
    }

    // Idea: When intervals overlap, remove the one with the larger end time so we leave more room for future intervals.
    // TC: O(n log n) for sorting | SC: O(1) extra space (excluding the sorting space)
};