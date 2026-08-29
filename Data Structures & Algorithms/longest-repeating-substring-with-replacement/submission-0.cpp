class Solution {
public:
    int characterReplacement(std::string s, int k) {

        // Store the frequency of each character
        unordered_map<char, int> count;

        // Stores the length of the longest valid window
        int res = 0;

        // l = left pointer of the sliding window
        // maxf = highest frequency of any character in the current window
        int l = 0, maxf = 0;

        // r = right pointer of the sliding window
        for (int r = 0; r < s.size(); r++) {

            // Add the current character to our frequency map
            count[s[r]]++;

            // Update the maximum frequency
            maxf = max(maxf, count[s[r]]);

            // Window is invalid if:
            // window size - most frequent character > k
            //
            // Because that means we need more than k replacements
            while ((r - l + 1) - maxf > k) {

                // Remove the leftmost character from the window
                count[s[l]]--;

                // Move the left pointer to the right
                l++;
            }

            // Update the longest valid window length
            res = max(res, r - l + 1);
        }

        // Return the longest substring we can make
        // contain only one distinct character
        return res;
    }
};