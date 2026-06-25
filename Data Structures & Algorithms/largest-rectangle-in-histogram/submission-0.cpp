class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);

        stack<int> st;
        // right nearest element - 
        for(int i = n-1 ;i>=0 ;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        // empty the stack to reuse it : 
        while(!st.empty()){
            st.pop();
        }

        // left nearest element - 
        for(int i = 0 ;i<n ;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left[i] = (st.empty()) ? -1 : st.top() ;
            st.push(i);
        }

        int area = 0;
        int currArea = 0;
        for(int i = 0 ;i<n ;i++){
            int width = right[i] - left[i] - 1;
            currArea = heights[i] * width;
            area = max(area , currArea);
        }
        return area;

    }
};
