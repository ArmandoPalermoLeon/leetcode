class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::unordered_set<char> window;
    int left{0};
    int max_len{0};
    for (int right = 0; right < s.length(); right++) {
      while (window.count(s[right])) {
        window.erase(s[left]);
        left++;
      }
      window.insert(s[right]);
      max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
  }
};
