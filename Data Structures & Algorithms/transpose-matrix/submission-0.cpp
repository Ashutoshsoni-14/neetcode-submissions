class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> T(n , vector<int>(m,0));

        for(int i = 0; i < m ;i++){
            for(int j = 0 ; j < n ;j++){
                T[j][i] = matrix[i][j] ;
            }
        }
        return T;
    }
};