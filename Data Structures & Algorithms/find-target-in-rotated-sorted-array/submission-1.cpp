class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Start with the entire array
        int low = 0;
        int high = nums.size() - 1;

        // Continue while there is a search range
        while (low <= high) {

            // Find the middle index
            int mid = low + (high - low) / 2;

            // We found the target
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the LEFT half is sorted
            if (nums[low] <= nums[mid]) {

                // Check if target lies inside the sorted left half
                if (nums[low] <= target && target < nums[mid]) {

                    // Target is on the left
                    high = mid - 1;
                }
                else {

                    // Target is on the right
                    low = mid + 1;
                }
            }

            // Otherwise, the RIGHT half is sorted
            else {

                // Check if target lies inside the sorted right half
                if (nums[mid] < target && target <= nums[high]) {

                    // Target is on the right
                    low = mid + 1;
                }
                else {

                    // Target is on the left
                    high = mid - 1;
                }
            }
        }

        // Target was not found
        return -1;
    }
};


// Time Complexity: O(log n) — We eliminate roughly half of the search space in every iteration.
// Space Complexity: O(1) — We only use a constant number of variables and no extra data structures.