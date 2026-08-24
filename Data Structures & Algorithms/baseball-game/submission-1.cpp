class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(string s : operations){
            if(s == "+" && !st.empty()){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);

                st.push(a+b);
            } 
            else if(s == "C" && !st.empty()){
                st.pop();
            }
            else if(s == "D" && !st.empty()){
                int a = st.top();
                st.push(2*a);
            }
            else{
                st.push(stoi(s));
            }
        }
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};