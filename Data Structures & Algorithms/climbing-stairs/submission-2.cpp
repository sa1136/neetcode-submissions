class Solution {
public:
    int climbStairs(int n) {

        // If n is 1, there is 1 way; if n is 2, there are 2 ways
        if(n <= 2){
            return n;
        }

        // dp[i] = number of ways to reach step i
        vector<int> dp(n + 1);

        // There is 1 way to reach step 1
        dp[1] = 1;

        // There are 2 ways to reach step 2: (1,1) or (2)
        dp[2] = 2;

        // For every step, we can come from 1 step before or 2 steps before
        for(int i = 3; i <= n; i++){

            // Ways to reach i = ways from i-1 + ways from i-2
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the number of ways to reach the top
        return dp[n];
    }
};

// TC: O(n) because we calculate each step once.
// SC: O(n) because the dp array stores n+1 values.