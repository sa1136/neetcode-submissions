class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> results;

        results.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            int currentstart = intervals[i][0];
            int currentend =intervals[i][1];
            int lastend=results.back()[1];

            if(currentstart <=lastend){
                results.back()[1] = max(lastend,currentend);
            }
            else{
                results.push_back(intervals[i]);
            }
        }
        return results;

        
    }
};
