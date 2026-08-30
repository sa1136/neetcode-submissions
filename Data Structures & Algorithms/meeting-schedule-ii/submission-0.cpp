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
    int minMeetingRooms(vector<Interval>& intervals) {

        int n = intervals.size();

        if (n == 0) return 0;

        vector<int> starts;
        vector<int> ends;

        // Store start and end times
        for (auto interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        // Sort both arrays
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int i = 0;
        int j = 0;
        int rooms = 0;

        while (i < n) {

            // Need a new room
            if (starts[i] < ends[j]) {
                rooms++;
                i++;
            }
            else {
                // Reuse a room
                j++;
                i++;
            }
        }

        // TC: O(n log n)
        // SC: O(n)

        return rooms;
    }
};
