class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (s != "+" && s != "-" && s != "/" && s != "*") {
                st.push(stoi(s));
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if (s == "+")
                    st.push(a + b);
                else if (s == "-")
                    st.push(b - a);
                else if (s == "*")
                    st.push(a * b);
                else
                    st.push(b / a);
            }
        }
        return st.top();
    }
};
