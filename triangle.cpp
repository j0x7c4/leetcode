class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        vector<vector<int>> opt(2,vector<int>(triangle[n-1].size(),INT_MAX));
        opt[0][0] = triangle[0][0];
        
        for ( int i = 1; i<n ; i++ ) {
            opt[i%2][0] = opt[(i-1)%2][0]+triangle[i][0];
            for ( int j=1 ; j<i+1 ; j++ ) {
                opt[i%2][j] = min(opt[(i-1)%2][j-1],opt[(i-1)%2][j])+triangle[i][j];
            }
        }
        int ret = INT_MAX;
        for ( int j =0 ; j<n ; j++ ) {
            ret = min(ret,opt[(n-1)%2][j]);
        }
        return ret;
    }
};