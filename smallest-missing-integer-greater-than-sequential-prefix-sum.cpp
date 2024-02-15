class Solution {
public:
  int missingInteger(vector<int> &nums) {
    unsigned sum = nums[0];
    for (unsigned i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1] + 1) {
        break;
      } else {
        sum += nums[i];
      }
    }
    set<int> s(nums.begin(), nums.end());
    for (unsigned ans = sum;; ans++) {
      auto it = s.find(ans);
      if (it == s.end()) {
        return ans;
      }
    }
  }
};