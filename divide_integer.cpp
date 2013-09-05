//use long long, because when calculate the abs, it maybe overflow

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long q,r;
        div(abs((long long)dividend),abs((long long)divisor),q,r);
        return ((dividend<0)^(divisor<0)) ? -q:q;
    
    }
    void div ( long long x, long long y, long long& q, long long& r ) {
        if ( x == 0 ) {
            q = r = 0;
            return;
        }
        div(x>>1,y,q,r);
        q<<=1;
        r<<=1;
        if (x&1) r+=1;
        if (r>=y) {
            r-=y;
            q+=1;
        }
        return;
    }
};