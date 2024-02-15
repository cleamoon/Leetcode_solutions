class Solution {

public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    map<int, int> m;

    for (auto i = 0; i < trips.size(); i++) {
      auto it = m.find(trips[i][1]);
      if (it != m.end()) {
        it->second += trips[i][0];
      } else {
        m.insert(make_pair(trips[i][1], trips[i][0]));
      }
      it = m.find(trips[i][2]);
      if (it != m.end()) {
        it->second -= trips[i][0];
      } else {
        m.insert(make_pair(trips[i][2], -trips[i][0]));
      }
    }

    int cap = capacity;

    for (auto i = m.begin(); i != m.end(); i++) {
      cap -= i->second;
      if (cap < 0 || cap > capacity)
        return false;
    }

    return true;
  }
};