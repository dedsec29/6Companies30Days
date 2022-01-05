class Solution {
  public:
    int findPosition(int N , int M , int K) {
        return (K-1 + M-1) % N + 1;
    }
};