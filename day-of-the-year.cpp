class Solution {
public:
  int dayOfYear(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0) {
      days_in_month[1]++;
    } else if (year % 4 == 0 && year % 100 != 0) {
      days_in_month[1]++;
    }

    int ans = 0;
    for (int i = 1; i < month; i++) {
      ans += days_in_month[i - 1];
    }

    ans += day;

    return ans;
  }
};