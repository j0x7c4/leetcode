class Solution {
public:
  int find_num ( int c, const vector<int> &num, int start ) {
    int lower = start, upper = num.size()-1;
    int mid;
    while ( lower<=upper ) {
      mid = (lower+upper)/2;
      if ( c==num[mid] ) return 1;
      if ( c<num[mid] ) upper = mid-1;
      else lower = mid+1;
    }
    return 0;
  }
	vector<vector<int> > threeSum(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	  vector<vector<int> > ret;
	  if ( num.size()<3 ) return ret;
	  vector<int> tmp(3,0);
	  sort(num.begin(), num.end());
	  int flag_i=0, flag_j=0;
	  for ( int i=0 ; i<num.size()-2 ; i++ ) {
	    for ( int j=i+1 ; j<num.size()-1 ; j++ ) {
	      flag_j = find_num(-num[i]-num[j], num, j+1);
	      if ( flag_j ) {
	        flag_i = 1;
	        tmp[0] = num[i], tmp[1] = num[j], tmp[2] = -num[i]-num[j];
	        ret.push_back(tmp);
	        while ( j+1 < num.size()-1 && num[j]==num[j+1] ) j++;
	      }
	    }
	    if ( flag_i ) {
	      while ( i+1 < num.size()-2 && num[i]==num[i+1] ) i++;
	    }
	 }
	 return ret;
	}
};