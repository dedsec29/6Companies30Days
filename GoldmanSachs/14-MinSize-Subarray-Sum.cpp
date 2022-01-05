class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long curr = 0;
        int n = nums.size();
        int ans = n+1;
        int l = 0, r = 0;
        while (r < n) {
            curr += (long long) nums[r];
            while (curr >= target) {
                ans = min(ans, r-l+1);
                curr -= nums[l++];
            }
            r++;
        }
        if (ans == n+1) ans = 0;
        return ans;
    }
};