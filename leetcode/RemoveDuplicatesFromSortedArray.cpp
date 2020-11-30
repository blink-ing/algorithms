class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            vector<int> tmp;
            int preNumber = -105;
            for (vector<int>::iterator it = nums.begin(); it != nums.end(); ) {
                if (preNumber == *it) {
                    nums.erase(it);
                }
                else {
                    preNumber = *it;
                    it++;
                }
            }

            return nums.size();
        }
};
