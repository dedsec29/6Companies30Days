class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        // f(n) = f(n-1) + (n+n-1) + (n-1 + n-1 -1) + ... (1+1 - 1)
        // f(n) = f(n-1) + n*n
        // f(n) = sum of squares
        return (((n * (n + 1ll))/2) * (2ll*n + 1ll)) / 3;
    }
};