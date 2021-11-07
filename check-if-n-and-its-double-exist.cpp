class Solution {
public:
    bool find(vector<int>& arr, int begin, int end, int trg, int i) {
        if (begin > end) return false;
        int p = (begin + end) / 2;
        int m = arr[p];
        if (m == trg and p != i) return true;
        else if (m < trg) return find(arr, p + 1, end, trg, i);
        else return find(arr, begin, p - 1, trg, i);
    }
    
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            if (find(arr, 0, arr.size()-1, 2 * arr[i], i)) {
                
                return true;
            }
        }
        return false;
    }
};
