class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            int j = i+1;
            while (j < n && arr[j-1] < arr[j]) j++;
            if (j-i >= 2 && j < n && arr[j-1] > arr[j]) { //  / / \
                //  / / /  / \ \   /
                while (j < n && arr[j-1] > arr[j]) j++;
                j--;
                ans = max(ans, j-i+1);
            }
            i = j-1;
        }
        return ans;
    }
};