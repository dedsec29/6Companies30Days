class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>> dp(N+1, vector<int>(K+1));
        vector<int> arr(N+1);
        for (int i = 0; i < N; i++) arr[i+1] = A[i];
        vector<int> pre(N+1);
        for (int j = 1; j <= K; j++) {
            pre[1] = -arr[1];
            for (int i = 2; i <= N; i++) {
                dp[i][j] = max(dp[i-1][j], pre[i-1] + arr[i]);
                pre[i] = max(pre[i-1], dp[i-1][j-1] - arr[i]);
            }
        }
        int mx = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= K; j++)
                mx = max(mx, dp[i][j]);
        return mx;
    }
};