class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> isPal(s.size(),vector<int>(s.size(),0));
        
        //initial len = 1 and len = 2 
        for ( int i=0 ; i<s.size() ; i++ ) {
            isPal[i][i] = 1;
        }
        for ( int i=0 ; i<s.size()-1 ; i++ ) {
            if ( s[i]==s[i+1] ) isPal[i][i+1] = 1;
        }
        for ( int len = 3 ; len<=s.size() ; len++ )  {
            for ( int begin = 0 ; begin+len<=s.size() ; begin++ ) {
                if ( isPal[begin+1][begin+len-2] && s[begin] == s[begin+len-1] ) {
                    isPal[begin][begin+len-1]=1;
                }
            }
        }
        vector<vector<string>> ret;
        getPal(ret,vector<string>(), 0, s, isPal);
        return ret;
        
    }
    void getPal (vector<vector<string>>& ret, vector<string> one , int begin, string s, const vector<vector<int>> &isPal ) {
        for ( int i=begin ; i<s.size() ; i++ ) {
            if ( isPal[begin][i] ) {
                one.push_back(s.substr(begin,i-begin+1));
                if ( i==s.size()-1 ) {
                    ret.push_back(one);
                    return;
                }
                else {
                    getPal(ret,one,i+1,s,isPal);
                }
                one.pop_back();
            }
        }
    }
    
};