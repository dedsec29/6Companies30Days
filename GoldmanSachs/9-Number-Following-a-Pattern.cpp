class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n = s.size();
        char c = '1';
        string ans = "";
        for (int i = 0; i < n; i++) {   // only last index tricky
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            j--;
            int x = j-i+1;
            if (s[i] == 'I') {  // only map x blanks to Is
                while (x--) {
                    ans += c;
                    c++;
                }
            }
            else {  // map all x+1 to Ds
                x++;
                char p = c + x-1;
                c = p;
                while (x--) {
                    ans += p;
                    p--;
                }
                c++;
                j++;
            }
            i = j;
        }
        if (s[n-1] == 'I')
            ans += c;
        return ans;
    }
};