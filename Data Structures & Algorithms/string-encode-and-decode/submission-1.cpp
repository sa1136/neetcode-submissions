class Solution {
public:

    // ENCODE:
    // Convert multiple strings into one single string
    string encode(vector<string>& strs) {

        // This will store our final encoded string
        string res = "";

        // Go through each string one by one
        for (const string& s : strs) {

            // Add the length of the string
            // Example: "hello" -> "5"
            res.append(to_string(s.size()));

            // Add '#' to separate the length from the actual string
            // Example: "5#"
            res.push_back('#');

            // Add the actual string
            // Example: "5#" + "hello" -> "5#hello"
            res.append(s);
        }

        // Return the complete encoded string
        return res;
    }


    // DECODE:
    // Convert the single encoded string back into multiple strings
    vector<string> decode(string s) {

        // This will store all the decoded strings
        vector<string> res;

        // i tells us where the current string starts
        int i = 0;

        // Continue until we reach the end of the encoded string
        while (i < s.size()) {

            // j starts from i
            int j = i;

            // Move j until we find '#'
            // The number before '#' tells us the string length
            while (s[j] != '#') {
                j++;
            }

            // Get the length written before '#'
            // Example: "5#hello" -> "5" -> 5
            int length = stoi(s.substr(i, j - i));

            // Move i past '#'
            // Now i points to the beginning of the actual string
            i = j + 1;

            // j becomes the ending position of the current string
            j = i + length;

            // Take 'length' characters and add them to the result
            // Example: take 5 characters -> "hello"
            res.push_back(s.substr(i, length));

            // Move i to the beginning of the next encoded string
            i = j;
        }

        // Return all decoded strings
        return res;
    }
};