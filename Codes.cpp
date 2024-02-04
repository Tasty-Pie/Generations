auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isAlphanumeric(char letter) {
        if('a' <= letter && letter <= 'z') {
            return true;
        }
        if('A' <= letter && letter <= 'Z') {
            return true;
        }
        if('0' <= letter && letter <= '9') {
            return true;
        }
        return false;
    }

    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(not isAlphanumeric(s[l])) {
                l++;
            } else if(not isAlphanumeric(s[r])) {
                r--;
            } else {
                if(tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
};
