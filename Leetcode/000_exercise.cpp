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

int minLength(string s) {
	int n = s.size();
	int i = 0;

	while (i < n - 1) {
		if (s[i] == 'A' && s[i + 1] == 'B') {
			// Erase 2 characters starting from index i
			s.erase(i, 2);
			n = s.size();  // Update the size after erasing
			i = std::max(0, i - 1);  // Decrement i, but not below 0
		}
		else if (s[i] == 'C' && s[i + 1] == 'D') {
			// Erase 2 characters starting from index i
			s.erase(i, 2);
			n = s.size();  // Update the size after erasing
			i = std::max(0, i - 1);  // Decrement i, but not below 0
		}
		else {
			i++;
		}
	}

	return s.size();
}

///模拟一个栈似乎更方便，一般情况话，题目中要进行匹配字母或者括号的话，大部分都可以用栈解决
int minLength2(string s) {
	string stack;

	// 遍历字符串
	for (char ch : s) {
		// 当栈不为空，且当前字符与栈顶字符组成 "AB" 或 "CD" 子串时，弹出栈顶字符
		if (!stack.empty() && (stack.back() == 'A' && ch == 'B' || stack.back() == 'C' && ch == 'D')) {
			stack.pop_back();
		}
		else {
			// 否则，将当前字符压入栈
			stack.push_back(ch);
		}
	}

	// 栈中剩余字符的数量即为最终字符串的最小可能长度
	return stack.size();
}