class Solution {
public:
  deque<int> test;
  vector<vector<int>> ans;

  void calc(int min, int left, int sum, int target) {
    if (left == 0)
      return;

    for (int i = min; i <= 9; i++) {
      if (sum + i > target) {
        break;
      } else if (sum + i == target) {
        if (left == 1) {
          test.push_back(i);
          ans.push_back(vector<int>(test.begin(), test.end()));
          test.pop_back();
        }
        break;
      } else {
        if (left == 1)
          continue;
        else {
          test.push_back(i);
          calc(i + 1, left - 1, sum + i, target);
          test.pop_back();
        }
      }
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    calc(1, k, 0, n);
    return ans;
  }
};