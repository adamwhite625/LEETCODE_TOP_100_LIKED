class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        if(n <= 1) return s;

        int start = 0, maxLen = 1;
        for(int i = 0; i < n; i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);

            if(len > maxLen){
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

private:
    int expand(const string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};
