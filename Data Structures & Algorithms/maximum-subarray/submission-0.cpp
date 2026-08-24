class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curr = nums[0];
        int maxSum =nums[0];

        for(int i =1;i<nums.size();i++){
            curr = max(nums[i],nums[i]+curr);
            maxSum=max(curr,maxSum);
        }
        return maxSum;



        }

    
};
