/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        // Sort by start time
        sort(intervals.begin(), intervals.end(),
             [](Interval a, Interval b) {
                 return a.start < b.start;
             });

        // Check for conflicts
        for (int i = 1; i < intervals.size(); i++) {

            // Current starts before previous ends
            if (intervals[i].start < intervals[i - 1].end) {
                return false;
            }
        }

        // No conflicts
        return true;

        // TC: O(n log n)
        // SC: O(1) excluding sorting space
    }
};
