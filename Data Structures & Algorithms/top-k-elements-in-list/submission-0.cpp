class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. calculate frequency - 
        //2. sort map values according - higher freq
        unordered_map<int,int> freq;
        vector<int> res(k);
        for(int n : nums){
            freq[n]++;
        }
        // we can't do step 2. directly with map so first push it to vector
        // then sort it using custom comparator
        vector<pair<int,int>> v(freq.begin(),freq.end());
        sort(v.begin(),v.end() , [](pair<int,int> a , pair<int,int> b){
            return a.second > b.second;
        });

        for(int i = 0;i<k;i++){
            res[i] = v[i].first;
        }
        return res;
    }
};
