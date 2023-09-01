class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        int power=2;
        int taille=1;
        for(int i=1;i<=n;i++)
        {
            if(i%2==1)ans[i]=ans[i-1]+1;
            else if(i==power)
            {
                power*=2;
                ans[i]=1;
                taille++;
            }
            else 
            {
                ans[i]=2*ans[i&(i-1)]+ans[i^(i-1)]-ans[i-1];
            }
        }
        return ans;
    }
};