class Solution {
public:

    void backtrack(vector<vector<int>>& res,int n,int k,int current,vector<int>vec){
        if(0==k){
            res.push_back(vec);
            return;
        }
        for(int i=current;n-k+1>=i;i++)
        {
            vec.push_back(i);
            backtrack(res,n,k-1,i+1,vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        backtrack(res,n,k,1,vec);
        return res;
    }

    
};