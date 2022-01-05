class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_multiset<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int a = nums[i] % k;
            int b = (k - a) % k;
            if (s.find(b) != s.end()) 
                s.erase(s.find(b));
            else
                s.insert(a);
        }
        return s.empty();
    }
};