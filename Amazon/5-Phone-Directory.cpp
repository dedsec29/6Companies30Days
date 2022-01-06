class Trie {
private:
    static const int al = 26;
    struct node {
        bool isEnd;
        node* next[al];
        int id; // any word that ends here

        node() {
            for (int i = 0; i < al; i++)
                next[i] = NULL;
            isEnd = false;
            id = -1;
        } 
    };

    node root;

public:
    void insert(const string& s,int i) {
        node* temp = &root;
        for (char c: s) {
            if (temp->next[c-'a'] == NULL) 
                temp->next[c-'a'] = new node();
            temp = temp->next[c-'a'];
        }

        temp->id = i;
    }

    vector<int> query(const string& s) {
        vector<int> ans;
        node* temp = &root;
        for (char c: s) {
            if (temp->next[c-'a'] == NULL)
                return ans;
            temp = temp->next[c-'a'];
        }
        // dfs from temp;
        node* v = temp;
        dfs(v, ans);
        return ans;
    }

    void dfs(node* v, vector<int>& ans) {
        if (v->id != -1)
            ans.push_back(v->id);
        for (int i = 0; i < al; i++) {
            if (v->next[i] != NULL)
                dfs(v->next[i], ans);
        }
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie X;
        for (int i = 0; i < n; i++)
            X.insert(contact[i], i);
        string pf = "";
        int sz = s.size();
        vector<vector<string>> ans(sz);
        for (int i = 0; i < sz; i++) {
            pf += s[i];
            vector<int> q = X.query(pf);
            if (q.empty()) 
                ans[i] = {"0"};
            else {
                for (int j: q)
                    ans[i].emplace_back(contact[j]);
            }
        }
        return ans;
    }
};