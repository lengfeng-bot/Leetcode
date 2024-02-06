#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <stack>
#include <queue>

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


int addMinimum(string word) {
	int n = word.size(), cnt = 1;
	for (int i = 1; i < n; i++) {
		if (word[i] <= word[i - 1]) {
			cnt++;
		}
	}
	return cnt * 3 - n;
}



bool searchMatrix(vector<vector<int>>& matrix, int target) {


	int m = matrix.size();
	int n = matrix[0].size();
	int num =0;
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] > target)
		{
			num = max(i - 1, 0);
			break;
		}

	}
	cout << "在第" << num+1 << "行查询" << endl;

	for (int i = 0; i < n; i++)
	{
		if (matrix[num][i] == target)	return true;
	}

//按列查询
	for (int i = 0; i < n; i++)
	{
		if (matrix[0][i] > target)
		{
			num = max(i - 1, 0);
			break;
		}

	}
	cout << "在第" << num+1 << "列查询" << endl;

	for (int i = 0; i < m; i++)
	{
		if (matrix[i][num] == target)	return true;
	}
	return false;
}

/// <summary>
/// 更神奇的做法
/// </summary>
/// 从右上角开始搜索，往左变小，往下变大，这个很关键
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	int x = 0, y = n - 1;
	while (x < m && y >= 0) {
		if (matrix[x][y] == target) {
			return true;
		}
		if (matrix[x][y] > target) {
			--y;
		}
		else {
			++x;
		}
	}
	return false;
}

//int main() {
//	vector<vector<int>> matrix = { {1,3,5} };
//	bool ans = searchMatrix(matrix, 4);
//	cout << ans;
//	return 0;
//
//}


/// <summary>
/// 石子游戏1
/// </summary>
bool stoneGame(vector<int>& piles) {
	int sumAlice = 0;
	int sumBob = 0;
	int count = 0;
	while (!piles.empty())
	{
		int n = piles.size();
		
		if (piles[0] >= piles[n - 1]) {
			if (count % 2 == 0)
				sumAlice += piles[0];
			else
				sumBob += piles[0];
			
			piles.erase(piles.begin());
			count++;

		}
		else
		{
			if (count % 2 == 0)
				sumAlice += piles[n - 1];
			else
				sumBob += piles[n - 1];
			piles.pop_back();
			count++;
		}
		


	}
	cout << "sum1:" << sumAlice << endl;
	cout << "sum2:" << sumBob << endl;
	return sumAlice>sumBob;
}

//int main() {
//	vector<int>nums = { 1,5,233,7 };
//	bool ans = stoneGame(nums);
//	cout << ans;
//	return 0;
//}


int returnToBoundaryCount(vector<int>& nums) {
	int n = nums.size();
	int sum = 0;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		sum += nums[i];
		if (sum == 0)
			num++;
	}
	return num;
}


int minimumTimeToInitialState(string word, int k) {
	int n = word.size();
	bool isconnect = false;
	int num = n / k;
	int yu = n % k;
	int ans1 = num;
	if (k == 1)
	{
		if(word[0]==word[n-1])
		isconnect = true;
	}
	if(yu!=0)
		if (word.substr(0, yu) == word.substr(n - yu, yu)) isconnect = true;
	cout << "isconnect:" << isconnect<<endl;
	if (isconnect) {
		for (int i = num; i > 0; i--)
		{
			if (k == 1) {
				if (word[0] == word[i]) {
					ans1--;
					cout << "操作+1" << endl;
				}
				else
				{
					break;
				}
			}
			else {
				if (word.substr(0, k) == word.substr(k * i, k)) {
					ans1--;
					cout << "操作+1" << endl;
				}
				else break;
			}
		}
		return max(ans1, 0);
	}
	else {
		if (yu == 0) return num;
		else return num + 1;
	}


}


//int main() {
//	string word = "aa";
//	int ans = minimumTimeToInitialState(word, 1);
//	cout << ans;
//	return 0;
//}

//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//	int m = matrix.size();
//	int n = matrix[0].size();
//	int x = 0; int y = n - 1;
//	while (x<m&&y>=0)
//	{
//		if (matrix[x][y] == target) return true;
//		else if (matrix[x][y] > target) y--;
//		else x++;
//	}
//	return false;
//}

/// <summary>
/// 魔塔游戏
/// </summary>
/// 我的思路是，每当sum小于等于0的时候，查找之前操作过的负数，把最小的负数移动到尾部，这应该算是一种贪心策略
/// 这样的话，我可能需要使用一个单调递减栈来实现,
/// 想了半天，单调栈不能实现，因为他总是会弹出之前更小的元素，这样导致数据不完整，需要一个其他的数据结构来实现这个功能，
/// 没错！就是优先队列！
int magicTower(vector<int>& nums) {

	int sum = 1;
	int  count = 0;
	int delay = 0;
	priority_queue<int, vector<int>, greater<int>> q;  //优先队列太好用了！
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		if (nums[i] < 0) {
			q.push(nums[i]);
		}
		if (sum<=0)
		{
			delay += q.top(); //先记账 现在你扛不住 最后再打你
			sum -= q.top();
			q.pop();
			count++;
		}

	}
	sum += delay;

	return sum>0?count:-1;
}