class Solution {
public:

	int dp[11][2][2][(1 << 10)];


	int solve(int pos, bool bound, bool hasRepeated, int mask, string &s) {

		if (pos == s.length()) {
			return hasRepeated ? 1 : 0;
		}

		if (dp[pos][bound][hasRepeated][mask] != -1) return dp[pos][bound][hasRepeated][mask];

		int maxDigit = bound ? s[pos] - '0' : 9;
        int ans=0;

		for (int digit = 0; digit <= maxDigit; digit++) {

			/* if this is a leading zero, then hasRepeated for the the current guy (position) will obviously be false  */
			if (digit == 0 && mask == 0) ans += solve(pos + 1, bound && (digit == s[pos] - '0'), false, mask, s);

			/*
				if this particular has already come earlier in this digit, and it is not a leading zero, then clearly, there is a repitition
				and we have to pass true in hasRepeated
			*/
			else if ((mask & (1 << digit))) ans += solve(pos + 1, bound && (digit == s[pos] - '0'), true, mask, s);

			/*
				if this guy is coming for the first time, then hasRepeated will be whatever was for the previous guy
				and don't forget to switch on the bit corresponding to this digit in the mask
			*/
			else ans += solve(pos + 1, bound && (digit == s[pos] - '0'), hasRepeated, (mask | (1 << digit)), s);

		}

		return dp[pos][bound][hasRepeated][mask] = ans;

	}

	int numDupDigitsAtMostN(int n) {
		memset(dp, -1, sizeof(dp));
		string s = to_string(n);
		// return solve(0, true, false, false, 0, R);
		return solve(0, true, false, 0, s);
	}
};