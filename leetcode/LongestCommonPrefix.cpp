class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string commonString = "";
            int minStrSize = 0;

            if (strs.size() > 0) {
                minStrSize = strs.at(0).size();
                for (int i = 1; i < strs.size(); i++) {
                    const int strSize = strs.at(i).size();
                    if (minStrSize > strSize) {
                        minStrSize = strSize;
                    }
                }
                if (minStrSize != 0) {
                    bool diffString = false;
                    for (int i = 0; i < minStrSize; i++) {
                        char commonChar = strs.at(0).at(i);
                        for (int j = 1; j < strs.size(); j++) {
                            if (commonChar != strs.at(j).at(i)) {
                                diffString = true;
                                break;
                            }
                        }

                        if (!diffString) {
                            commonString += strs.at(0).at(i);
                        }
                    }
                }
            }

            return commonString;
        }
};
