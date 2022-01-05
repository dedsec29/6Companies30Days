class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    vector<ull> ugly(n+1);   // stores ith ugly number
	    ugly[1] = 1;
	    int p2,p3,p5;
	    p2 = p3 = p5 = 1;
	    for (int i = 2; i <= n; i++) {
	        // ith ugly number will be derived from past ugly numbers
	        ull next_ugly = ugly[p2] * 2ull;
	        next_ugly = min(next_ugly, ugly[p3] * 3ull);
	        next_ugly = min(next_ugly, ugly[p5] * 5ull);
	        
	        ugly[i] = next_ugly;
	        if (next_ugly == ugly[p2] * 2ull) p2++;
	        if (next_ugly == ugly[p3] * 3ull) p3++;
	        if (next_ugly == ugly[p5] * 5ull) p5++;
	    }
	    return ugly[n];
	}
};