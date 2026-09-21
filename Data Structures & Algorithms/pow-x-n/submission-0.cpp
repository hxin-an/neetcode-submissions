class Solution {
public:
    double myPow(double x, int n) {
        vector<pair<long long, double>> table;

        long long N = n;
        bool negative = N < 0;

        if (negative)
            N = -N;

        double tmp = x;
        double ans = 1;

        for (long long i = 1; i <= N; i *= 2) {
            table.push_back({i, tmp});
            tmp *= tmp;

            // 避免 i *= 2 overflow
            if (i > N / 2)
                break;
        }

        long long remain = N;

        for (int i = table.size() - 1; i >= 0; i--) {
            if (remain >= table[i].first) {
                ans *= table[i].second;
                remain -= table[i].first;
            }
        }

        return negative ? 1 / ans : ans;
    }
};