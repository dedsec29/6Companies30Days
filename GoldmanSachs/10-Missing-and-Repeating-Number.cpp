class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xarr = 0, x = 0;
        for (int i = 0; i < n; i++) {
            xarr ^= arr[i];
            x ^= (i+1);
        }
        int *ans = new int[2];
        
        int e = x ^ xarr;
        int lsb = e & -e;
        x = 0, xarr = 0;    // sb
        for (int i = 0; i < n; i++) {
            if (arr[i] & lsb)
                xarr ^= arr[i];
            if ((i+1) & lsb)
                x ^= (i+1);
        }
        
        ans[0] = x ^ xarr;  // occurs twice
        ans[1] = e ^ ans[0];    // never occurs
        for (int i = 0; i < n; i++) {
            if (ans[1] == arr[i]) {
                swap(ans[0], ans[1]);
                break;
            }
        }
        return ans;
    }
};