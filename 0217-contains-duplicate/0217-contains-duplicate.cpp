class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto e:nums)
        {
            if(s.count(e)==1)return true;
            s.insert(e);
        }
        return false;
    }
};