class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++)
        {
            if (dic.find(target - nums[i]) != dic.end())
            {
                ret.push_back(dic[target - nums[i]]);
                ret.push_back(i);
                return ret;
            }
            else
            {
                dic[nums[i]] = i;
            }
        }

        return ret;
    }
};
