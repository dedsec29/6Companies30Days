class Solution {
	public:
		int CountWays(string str){
		    long long mod = 1e9+7;
	        int n = str.size();
	        long long f0 = ('1' <= str[0] && str[0] <= '9');
	        long long f1 = 0;
	         
	        for (int i = 1; i < n; i++) {
	            int d = str[i] - '0';
	            int num = (str[i-1]-'0')*10 + d;
	            long long preva = f0, prevb = f1;
	            long long curra = 0, currb = 0;
	            if (1 <= d  && d <= 9)
	                curra = (preva + prevb) % mod;
	            if (10 <= num && num <= 26)
	                currb = preva;
	            f0 = curra;
	            f1 = currb;
	        }
	        return (f0 + f1) % mod;
		}
};