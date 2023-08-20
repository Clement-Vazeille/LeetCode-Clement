class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        result.reserve(2);

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = map.find(complement);
            if (it != map.end()) {
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return result;
    }
};