class Solution {
public:
    int find(vector<int>& numbers, int begin, int end, int target) {
        if (begin >= end) {
            return -1;
        }
        int mid = (begin + end) / 2;
        if (numbers[mid] < target) {
            return find(numbers, mid + 1, end, target);
        } else if (numbers[mid] > target) {
            return find(numbers, begin, mid, target);
        } else {
            return mid;
        }
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int it = find(numbers, i + 1, numbers.size(), target - numbers[i]);
            if (it != -1) {
                return vector<int> {i + 1, it + 1};
            }
        }
        return vector<int> {0, 0};
    }
};
