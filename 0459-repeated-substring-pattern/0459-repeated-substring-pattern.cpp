class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i=1;i<=n/2;i++)
        {
            if(n%i==0)
            {
                bool test_i=true;
            for(int j=i;j<n;j++)
            {
                if(s[j]!=s[j%i])test_i=false;
            }
            if(test_i)return true;
            }
            
        }
        return false;
    }
};