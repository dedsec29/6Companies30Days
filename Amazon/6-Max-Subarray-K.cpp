class Solution {
  public:
    //author: @dedsec_29
    template <typename T>
    struct maximum_queue {
        stack<pair<T,T>> s2, s1; // ---(s2----||s1---)---
        //add new elements to s1, remove elements from s2
        maximum_queue() {
            s1 = stack<pair<T,T>>();
            s2 = stack<pair<T,T>>(); 
        }
    
        T getMaximum() {
            T maximum;
            if (s1.empty() || s2.empty())
                maximum = s1.empty() ? s2.top().second : s1.top().second;
            else
                maximum = max(s1.top().second, s2.top().second);
            return maximum;
        }
    
        void push(T new_element) {
            T maximum = s1.empty() ? new_element : max(new_element, s1.top().second);
            s1.push({new_element, maximum});
        }
    
        void pop() {
            if (s2.empty()) {
                assert(!s1.empty());
                while (!s1.empty()) {
                    T element = s1.top().first;
                    s1.pop();
                    T maximum = s2.empty() ? element : max(element, s2.top().second);
                    s2.push({element, maximum});
                }
            }
            s2.pop();
        }
    };
  
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        maximum_queue<int> Q_max;
        for (int i = 0; i < k-1; i++)
            Q_max.push(arr[i]);
        vector<int> ans;
        for (int i = k-1; i < n; i++) {
            Q_max.push(arr[i]);
            ans.push_back(Q_max.getMaximum());
            Q_max.pop();
        }
        return ans;
    }
};