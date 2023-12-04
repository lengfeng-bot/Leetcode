#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> findPeaks(vector<int>& mountain) {
	vector<int>ans;
	int n = mountain.size();
	for (int i = 1; i < n-1; i++)
	{
		if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
			ans.push_back(i);
	}
	return ans;
}

/// <summary>
/// 我以为这是道dp题目，没想到是个贪心题目
/// </summary>
/// 慢慢来吧，，，
int minimumAddedCoins(vector<int>& coins, int target) {
	int n = coins.size();
	vector<bool>dp(target + 1, 0);
	int count = 0;
	dp[0] = 1;
	int m = 0;
	for (int i = coins.size(); i >=0; i--) {
		for (int j = target; j >= coins[i]; j--)
		{
			dp[j] = dp[j - coins[i]];
		}

		for (int k = target; k >= 0; k--)
		{
			if (dp[k] == 0) {
			m = k;
			break;
		    }
		}
		if (dp[m] == 0) {
			coins.push_back(m);
			sort(coins.begin(), coins.end());
		}
		
	}
	return coins.size()-n;
}


//int main() {
//	vector<int> nums = { 1,4,10 };
//	int ans = minimumAddedCoins(nums,19);
//	cout << ans;
//}