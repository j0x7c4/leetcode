class Solution {
public:
    int find_num ( int n , const vector<int>& num , int start ) {
        int lower = start, upper = num.size()-1;
        int mid;
        while ( lower<=upper ) {
            mid = (lower+upper)/2;
            if ( num[mid]==n ) return 1;
            if ( num[mid]<n ) lower = mid+1;
            else upper = mid-1;
        }
        return 0;
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if ( num.size()<4 ) return ret;
        sort(num.begin(),num.end());
        vector<int> tmp(4,0);
        for ( int i=0 ; i<num.size()-3 ; i++ ) {
            for ( int j=i+1 ; j<num.size()-2 ; j++ ) {
                for (int k=j+1 ; k<num.size()-1 ; k++ ) {
                    if ( find_num(target-num[i]-num[j]-num[k],num,k+1) ) {
                        tmp[0] = num[i], tmp[1] = num[j], tmp[2] = num[k], 
                        tmp[3] = target-num[i]-num[j]-num[k];
                        ret.push_back(tmp);
                    }
                    while ( k+1<num.size()-1 && num[k] == num[k+1] ) k++;
                }
                while ( j+1<num.size()-2 && num[j] == num[j+1] ) j++;
            }
            while ( i+1<num.size()-3 && num[i] == num[i+1] ) i++;
        }
        return ret;
    }
};