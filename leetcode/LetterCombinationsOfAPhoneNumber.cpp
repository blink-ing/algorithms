class Solution {
public:
    vector<string> nm;	// numberMap
    vector<string> rm;  // resultMap

    string numberToAlphabet(char num) {
        switch (num) {
            case '2' :
                return "abc";
            case '3' :
                return "def";
            case '4' :
                return "ghi";
            case '5' :
                return "jkl";
            case '6' :
                return "mno";
            case '7' :
                return "pqrs";
            case '8' :
                return "tuv";
            case '9' :
                return "wxyz";
            default :
                return "";
        }

        return "";
    }

    void mixNumberMap(string arr, int l, int n) {
        if (l == n) {
            rm.push_back(arr);
            return;
        }

        const int k = nm[l].size();
        for (int i = 0; i < k; i++) {
            string tmp = arr;
            mixNumberMap(tmp + nm[l][i], l + 1, n);
        }
    }

    vector<string> letterCombinations(string digits) {
        const int length = digits.size();
        for (int i = 0; i < length; i++) {
            nm.push_back(numberToAlphabet(digits.at(i)));
        }

        if (length != 0) {
            mixNumberMap("", 0, length);
        }

        return rm;
    }
};
