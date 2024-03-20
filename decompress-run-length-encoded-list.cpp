class Solution {
public:
  vector<int> decompressRLElist(vector<int> &nums) {
    vector<int> ans;

    for (auto i = 0; i < nums.size(); i += 2) {
      const int freq = nums[i];
      const int val = nums[i + 1];
      for (auto j = 0; j < freq; j++) {
        ans.push_back(val);
      }
    }

    return ans;
  }
};