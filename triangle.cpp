class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> steps = triangle[0];
        for (int i = 1; i < triangle.size(); i++) {
            vector<int> curr = triangle[i];
            curr[0] += steps[0];
            curr[i] += steps[i-1];
            for(int j = 1; j < i; j++) {
                curr[j] += min(steps[j], steps[j-1]);
            }
            steps = curr;
        }
        return *min_element(steps.begin(), steps.end());
    }
};
