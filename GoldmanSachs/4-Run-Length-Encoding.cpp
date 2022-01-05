string encode(string src) {     
    int n = src.size();
    string ans = "";
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && src[j] == src[i]) j++;
        j--;
        ans += src[j];
        ans += to_string(j-i+1);
        i = j;
    }
    return ans;
} 