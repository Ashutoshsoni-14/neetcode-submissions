class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int minr = 0;
        int minc = 0;
        int maxr = m-1;
        int maxc = n-1;

        vector<int> ans;

        while(minr <= maxr && minc <= maxc){
            // left -> right
            for(int col = minc ; col <= maxc ;col++){
                ans.push_back(matrix[minr][col]);
            }
            minr++;
            if(minr > maxr || minc > maxc){
                break;
            }
            // top -> down
            for(int row = minr ; row <= maxr ;row++){
                ans.push_back(matrix[row][maxc]);
            }
            maxc--;
            if(minr > maxr || minc > maxc){
                break;
            }
            // right -> left
            for(int col = maxc ; col >= minc ;col--){
                ans.push_back(matrix[maxr][col]);
            }
            maxr--;
            if(minr > maxr || minc > maxc){
                break;
            }
            // down -> up
            for(int row = maxr ; row >= minr ; row--){
                ans.push_back(matrix[row][minc]);
            }
            minc++;
        }
        return ans;
    }
};
