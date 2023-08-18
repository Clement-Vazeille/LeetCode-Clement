class Solution {
public:

    void backtrack(vector<vector<int>>& res,int n,int k,int current,vector<int>& vec){
        if(0==k){
            res.push_back(vec);
            return;
        }

        if(n-current>=k){backtrack(res,n,k,current+1,vec);}
        
        vec.push_back(current);
        backtrack(res,n,k-1,current+1,vec);

        vec.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        backtrack(res,n,k,1,vec);
        return res;
    }

    
};