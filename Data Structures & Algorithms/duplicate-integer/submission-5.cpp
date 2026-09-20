class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num: nums){
            if(seen.count(num)){       // If number is already seen, duplicate exists
                return true;
            }
            seen.insert(num);          // Store the number for future checks
        }

        return false;                  // No duplicate found
    }
};

// TC: O(n) average, because we check and insert each number once.
// SC: O(n), because the unordered_set can store up to n numbers.