class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int x:nums){
            freq[x]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto it :freq){
            int element = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(element);
        }

        vector<int> res;
        for(int frequency = nums.size();frequency>=1;frequency--){
            for(int element :bucket[frequency]){

                res.push_back(element);
                if(res.size()==k){
                    return res;
                }

            }
        }

        return res;

    }
    
};
