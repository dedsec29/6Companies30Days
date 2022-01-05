class Solution{
  public:
    bool safe(long long curr,long long a,long long k) {
        if (curr == -1) 
            return (a <= k);
        return k/curr >= a;
    }
  
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int l = 0, r = 0;
        k--;
        int ans = 0;
        long long curr = -1;    // not chosen yet
        while (r < n) {
            while (!safe(curr, a[r], k) && l <= r) {
                if (l == r)
                    curr = -1;
                else if (curr != -1)
                    curr /= a[l];
                l++;
            }
            if (l > r)
                curr = -1;
            if (safe(curr, a[r], k)) {
                ans += r-l+1;
                if (curr != -1)
                    curr *= (long long) a[r];
                else
                    curr = a[r];
            }
            r++;
        }
        return ans;
    }
};