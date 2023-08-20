class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> occMap;
        for(int elem:nums1)
        {
            occMap[elem]++;
        }

        for(int elem:nums2)
        {
            if(occMap.find(elem)!=occMap.end())
            {
                if(occMap[elem]-->0)ans.push_back(elem);
            }
            
        }
        return ans;
    }
};