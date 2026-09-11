class Solution {
public:
    void solve(vector<int>& digits, int num, int pos, set<int>& s) {
        if (pos == 3) {
            if (num % 2 == 0)
                s.insert(num);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {

            if (pos == 0 && digits[i] == 0)
                continue;

            int x = digits[i];

            digits.erase(digits.begin() + i);

            solve(digits, num * 10 + x, pos + 1, s);

            digits.insert(digits.begin() + i, x);
        }
    }

    int totalNumbers(vector<int>& digits) {
        set<int> s;

        solve(digits, 0, 0, s);

        return s.size();
    }
};