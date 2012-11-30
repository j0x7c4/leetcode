class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( a.size() > b.size() ) swap(a,b);
        int flag = 0;
        int p1=a.size()-1 ,p2=b.size()-1;
        string ret="";
        int tmp;
        while ( p1>=0 && p2>=0 ) {
            tmp = flag + a[p1]-'0' + b[p2]-'0';
            if ( tmp==3 ) {
                ret="1"+ret;
                flag = 1;
            }
            else if ( tmp == 2 ) {
                ret = "0" + ret;
                flag = 1;
            }
            else if ( tmp == 0 ) {
                flag = 0;
                ret = "0" + ret;
            }
            else {
                flag = 0;
                ret = "1" + ret;
            }
            p1--;
            p2--;
        }
        while ( p2 >= 0 ) {
            tmp = flag + b[p2] - '0';
            if ( tmp > 1 ) {
                ret = "0" + ret;
                flag = 1;
            }
            else if ( tmp == 0 ) {
                ret = "0" +ret;
                flag = 0;
            }
            else {
                ret = "1" + ret;
                flag = 0;
            }
            p2--;
        }
        if ( flag ) ret = "1"+ret;
        return ret;
    }
};