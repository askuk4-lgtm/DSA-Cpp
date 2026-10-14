class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, ans = 0;
        int last[256];
        fill(last, last + 256, -1);

        for (int right = 0; right < s.length(); right++) {
            if (last[(unsigned char)s[right]] >= left) {
                left = last[(unsigned char)s[right]] + 1;
            }

            last[(unsigned char)s[right]] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};