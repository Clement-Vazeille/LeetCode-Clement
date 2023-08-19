class Solution {
public:
    int len;
    vector<vector<int>> combine(int n, int k) {
        len = k;
        vector<vector<int>> output = {vector<int>(len)};
        generate(output, n, k, 1);
        output.pop_back();
        return output;
    }

    void generate(vector<vector<int>>& output, int n, int k, int start){
        if(k == 0){
            output.push_back(vector<int>(output.back().begin(), output.back().end()));
            return;
        }
        for(int i = start; i <= n-k+1; i++){
            output.back()[len-k] = i;
            generate(output, n, k-1, i+1);
        }
    }

};
