class Solution {
public:
    bool isPalindrome(int x) {
   	    if (x < 0) {
   	    	return false;
   	    }
   
   	    vector<int> nums;
	    while (x != 0) {
	    	nums.push_back(x % 10);
	    	x /= 10;
	    }
		
	    const int numsSize = nums.size();
	    for (int i = 0; i < numsSize / 2; i++) {
		    if (nums[i] != nums[numsSize - i - 1]) {
		    	return false;
		    }
	    }
		
        return true;
    }
};
