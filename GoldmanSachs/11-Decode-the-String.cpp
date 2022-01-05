class Solution{
public:
    string decodedString(string s){
        stack<int> cnt;
        stack<string> st;
        string curr = "";
        int num = 0;
        for (char c: s) {
            if ('0' <= c && c <= '9') {
                num *= 10;
                num += c-'0';
            }
            else if ('a' <= c && c <= 'z') 
                curr += c;
            else if (c == '[') {
                cnt.push(num);
                st.push(curr);
                num = 0;
                curr = "";
            }
            else {
                int x = cnt.top();
                string d = st.top();
                while (x--)
                    d += curr;
                curr = d;
                cnt.pop();
                st.pop();
            }
        }
        return curr;
    }
};