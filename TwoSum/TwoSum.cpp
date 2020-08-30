// 99.79% faster than C++ solutions
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> compliments;
        for (int i = 0; i < nums.size(); i++) {
            if (compliments.find(target - nums[i]) != compliments.end())
                return vector<int> {compliments[target - nums[i]], i};
            else
                compliments[nums[i]] = i;
        }
        return vector<int> {-1, -1};
    }
};