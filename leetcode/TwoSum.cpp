class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int numSize = nums.size();
        for (int i = 0; i < numSize - 1; i++) {
            for (int j = i + 1; j < numSize; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }   
            }
            
            if (result.size() > 0) {
                break;
            }
        }
        
        return result;
    }
};
