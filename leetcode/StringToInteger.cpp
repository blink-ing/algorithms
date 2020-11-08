class Solution {
public:
    bool isNumber(char c) {
        if ('0' <= c && c <= '9') {
            return true;
        }
        return false;
    }
    
    bool isAllowedCharacter(char c) {
        if (c == ' ' || c == '-' || c == '+') {
            return true;
        }
        return false;
    }
    
    int makeStringToInt(string s, int sign) {
        int num = 0;
        const int stringSize = s.length();
        for (int i = 0; i < stringSize; i++) {
            if (sign == 1) {
                num = num * 10 + (s[i] - '0');
            }
            else if (sign == -1) {
                num = num * 10 - (s[i] - '0');
            }
        }
        return num;
    }
    
    string removeZeroFromString(string s) {
        string newS;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            if (*it != '0' || newS.size() != 0) {
                newS += *it;
            }
        }
        return newS;
    }
    
    int myAtoi(string s) {
        string newS;
        int sign = 0;
        int signCount = 0;
        for (string::iterator it = s.begin(); it != s.end(); it++) {
            if (isNumber(*it)) {
                newS += *it;
            }
            else if (isAllowedCharacter(*it)) {
                if (sign == 1 || sign == -1) {
                    if (*it == ' ') {
                        break;
                    }
                }
                
                if (newS.size() > 0 && *it == ' ') {
                    break;    
                }
                
                if (newS.size() == 0) {
                    if (*it == '-') {
                        sign = -1;
                    }
                    else if (*it == '+') {
                        sign = 1;
                    }
                }
                
                if (*it == '-' || *it == '+') {
                    if (newS.size() > 0) {
                        break;
                    }
                    
                    if (++signCount > 1) {
                        newS = "";
                        break;
                    }
                }
            }
            else {
                break;
            }
        }
        
        newS = removeZeroFromString(newS);
        if (sign == 0 && newS.size() > 0) {
            sign = 1;
        }
        
        string INT_MAX_NUM = "2147483647";
        string INT_MIN_NUM = "2147483648";
        if (newS.length() > 10) {
            if (sign == -1) {
                newS = INT_MIN_NUM;
            }
            else if (sign == 1) {
                newS = INT_MAX_NUM;
            }
        }
        else if (newS.length() == 10) {
            if (sign == 1) {
                if (newS > INT_MAX_NUM) {
                    if (newS > INT_MAX_NUM) {
                        newS = INT_MAX_NUM;
                    }
                }
            }
            else if (sign == -1) {
                if (newS > INT_MIN_NUM) {
                    newS = INT_MIN_NUM;
                }
            }
        }

        return makeStringToInt(newS, sign);
    }
};
