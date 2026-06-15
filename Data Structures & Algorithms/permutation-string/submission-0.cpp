class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if (k > s2.length()) return false;
        vector<int> freq1(26,0);
        for(int i = 0;i<k;i++){
            freq1[s1[i]-'a']++;
        }
        vector<int> freq2(26,0);
        for(int i = 0;i<k;i++){
            freq2[s2[i]-'a']++;
        }
        for(int i = 0;i<=s2.length()-k;i++){
            if(freq2 == freq1) return true;
            if(i + k < s2.length()) {
                freq2[s2[i]-'a']--;
                freq2[s2[i+k]-'a']++;
            }
        }
        return false;
    }
};
