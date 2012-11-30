class Solution {
public:
    int findClosest ( int n , const vector<int>& num, int start ) {
        int lower = start, upper = num.size()-1;
        int idx = (lower+upper)/2;
        int mid;
        while ( lower<upper ) {
            mid = (lower+upper)/2;
            if ( abs(num[upper]-n) >= abs(num[mid]-n) ) {
                idx = mid;
                upper = mid-1;
            }
            else {
                lower = mid+1;
            }
            
        }
        return num[idx];
    }
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = num[0]+num[1]+num[2];
        sort(num.begin(), num.end());
        int tmp;
        for ( int i=0 ; i<num.size()-2 ; i++ ) {
            for ( int j=i+1 ; j<num.size()-1 ; j++ ) {
                tmp = num[i]+num[j]+findClosest(target-num[i]-num[j],num,j+1);
                if ( abs(tmp-target) < abs(ret-target) ) ret = tmp;
            }
        }
        return ret;
    }
};