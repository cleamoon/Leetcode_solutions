class Solution {
public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> ans;
    unsigned curr = start;
    const int size = 1 << n;
    for (int i = 0; i < size; i++) {
      ans.push_back(curr);
      unsigned gray = curr;
      unsigned mask = gray;
      while (mask) {
        mask >>= 1;
        gray ^= mask;
      }
      gray = (gray + 1) % size;
      curr = gray ^ (gray >> 1);
    }
    return ans;
  }
};