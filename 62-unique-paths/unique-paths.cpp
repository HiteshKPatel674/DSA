class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if (m > n) swap(m, n);

        long long result = 1;
        int N = m + n - 2;  // Total number of steps (right + down)
        int K = m - 1;      

        // Calculate C(N, K) = (N * (N-1) * ... * (N-K+1)) / (1 * 2 * ... * K)
        for (int i = 1; i <= K; ++i) {
            result = result * (N - K + i) / i;
        }
        //combination ka hi optimised version hai

        return (int)result;
    }
};
