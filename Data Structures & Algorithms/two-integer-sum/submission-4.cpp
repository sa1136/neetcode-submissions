class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){
            int needed = target - nums[i]; // Find the number needed to reach target

            if(mpp.find(needed) != mpp.end()){
                return {mpp[needed], i}; // Return indices of the two numbers
            }

            mpp[nums[i]] = i; // Store current number and its index
        }

        return {}; // No valid pair found
    }
};

// TC: O(n) average, because we traverse the array once with O(1) average hash-map operations.
// SC: O(n), because the hash map can store up to n elements.