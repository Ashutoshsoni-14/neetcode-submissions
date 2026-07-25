class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin() , people.end());
        int left = 0;
        int right = people.size()-1;
        while(left <= right){
            int remaining = limit - people[right--];
            boats++;
            if(left <= right && remaining >= people[left]){
                left++;
            }
        }
        return boats;
    }
};