class Solution {
public:  
    string gcdOfStrings(string str1, string str2) {
        if ((int) str1.size() < (int) str2.size())
            swap(str1, str2);
        string ans = "";
        if (str1 + str2 == str2 + str1) {
            int g = __gcd(str1.size(), str2.size());
            for (int i = 0; i < g; i++)
                ans += str2[i];
        }
        return ans;
    }
};