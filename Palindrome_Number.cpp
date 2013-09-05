class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( x<0 ) return false;
        char buf[20];
        sprintf(buf,"%d",x);
        string sbuf(buf);
        int n = sbuf.size();
        for ( int i =0 ; i<n/2 ; i++ ) {
            if ( sbuf[i]!=sbuf[n-i-1] ) return false;
        }
        return true;
        
    }
};