class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false; // Different lengths cannot be anagrams

        vector<int> count(26, 0);

        for(char c : s) count[c - 'a']++; // Count each character in s
        for(char c : t) count[c - 'a']--; // Subtract each character in t

        for(int val : count){
            if(val != 0) return false; // Any non-zero count means characters differ
        }

        return true; // All character counts match
    }
};

// TC: O(n), because we scan both strings once.
// SC: O(1), because the count array always has 26 elements.