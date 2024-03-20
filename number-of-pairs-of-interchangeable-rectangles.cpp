class Solution {
public:
  int lcd(int a, int b) {
    if (a > b)
      return lcd(b, a);
    int r = b % a;
    if (r == 0)
      return a;
    return lcd(r, a);
  }

  long long interchangeableRectangles(vector<vector<int>> &rectangles) {
    map<pair<int, int>, long long> m;

    for (auto i = 0; i < rectangles.size(); i++) {
      int upper = rectangles[i][0];
      int lower = rectangles[i][1];
      int divider = lcd(upper, lower);
      pair<int, int> p = make_pair(upper / divider, lower / divider);
      auto jt = m.find(p);
      if (jt != m.end()) {
        jt->second++;
      } else {
        m.insert(make_pair(p, 1));
      }
    }

    long long ans = 0;
    for (auto jt = m.begin(); jt != m.end(); jt++) {
      if (jt->second > 0) {
        ans += jt->second * (jt->second - 1) / 2;
      }
    }
    return ans;
  }
};