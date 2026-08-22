class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int candidateMax = max({curr, maxSoFar * curr, minSoFar * curr});
            int candidateMin = min({curr, maxSoFar * curr, minSoFar * curr});

            maxSoFar = candidateMax;
            minSoFar = candidateMin;

            result = max(result, maxSoFar);
        }
        return result;
    }
};