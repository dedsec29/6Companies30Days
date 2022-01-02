class Solution{
  public:
        vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<vector<int>, vector<int>> mp;
        int sz = string_list.size();
        for (int i = 0; i < sz; i++) {
            vector<int> freq(26);
            for (char c: string_list[i])
                freq[c-'a']++;
            mp[freq].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto i: mp) {
            ans.emplace_back();
            for (auto j: i.second)
                ans.back().push_back(string_list[j]);
        }
        return ans;
    }
};