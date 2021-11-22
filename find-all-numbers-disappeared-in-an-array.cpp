class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<bool> tab(n, true);
        for (auto i : nums) {
            tab[i] = false;
        }
        vector<int> res;
        for (int i = 1; i < n; i++) {
            if (tab[i]) res.push_back(i);
        }
        return res;
    }
};
