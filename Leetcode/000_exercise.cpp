#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#include<unordered_map>
#include<unordered_set>
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


/// <summary>
/// 先用哈希表统计字母出现的次数，之后从打字母开始排序，oush到ans,每个字母最多可以push Limit次数个。
/// 如果多于限制，补充下一个更小的字母添加，如果多余限制的是最后一位字母，就直接不添加了
/// </summary>
string repeatLimitedString(string s, int repeatLimit) {
	int cnt[26]{};
	for (char& c : s) {
		++cnt[c - 'a'];
	}
	string ans;
	for (int i = 25, j = 24; ~i; --i) {
		j = min(j, i - 1);
		while (1) {
			for (int k = min(cnt[i], repeatLimit); k; --k) {
				ans += 'a' + i;
				--cnt[i];
			}
			if (cnt[i] == 0) {
				break;
			}
			while (j >= 0 && cnt[j] == 0) {
				--j;
			}
			if (j < 0) {
				break;
			}
			ans += 'a' + j;
			--cnt[j];
		}
	}
	return ans;
}

void setZeroes1(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int> row(m), col(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!matrix[i][j]) {
				row[i] = col[j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}

}

void printmatrix(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


//int main() {
//	vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
//	printmatrix(matrix);
//	cout << endl;
//	setZeroes1(matrix);
//	printmatrix(matrix);
//	return 0;
//}

/// <summary>
/// 拿出最少的魔法豆
/// </summary>
/// 这一看就是一个贪心或者动态规划的题目，先用动态规划做一下。dp[i]的定义是把第i个当作基准，需要拿出魔法豆的最少数目
/// 时间复杂度是O(n2) 居然超时了！！
/// 想想能否用其他方法解答，减少时间。
int minimumRemoval(vector<int>& beans) {
	int n = beans.size();
	vector<int>dp(n, 0);
	sort(beans.begin(), beans.end());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dp[i] += (beans[i] <= beans[j]) ? (beans[j] - beans[i]) : beans[j];

	}
	int ans = INT_MAX;
	for (auto d : dp) {
		ans = min(ans, d);
		cout << d;cout << endl;
	}
		
	return ans;

}
/// <summary>
/// 好吧，是一个比较简单的前缀和问题，思路和dp差不多
/// </summary>
//int minimumRemoval2(vector<int>& beans) {
//	int n = beans.size();
//	sort(beans.begin(), beans.end());
//	long long total = accumulate(beans.begin(), beans.end(), 0LL); // 豆子总数
//	long long res = total; // 最少需要移除的豆子数
//	for (int i = 0; i < n; i++) {
//		res = min(res, total - (long long)beans[i] * (n - i));
//	}
//	return res;
//}

//int main() {
//	vector<int>beans = {2,10,3,2 };
//	int ans = minimumRemoval(beans);
//	cout << ans;
//}





/// <summary>
/// 使数组和小于等于×的最少时间
/// </summary>
int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
	int sum2 = 0;
	int nummax = 0;
	for (auto num : nums2) {
	sum2 += num;
	nummax = max(nummax, num);
	}
	if (sum2 - nummax > x)  return -1;
	return 0;
}



//int removeElement(vector<int>& nums, int val) {
//	int k = 0;
//	while (k < nums.size())
//	{
//		if (nums[k] == val) {
//			int x = nums[nums.size() - 1];
//			nums[k] = x;
//			nums.pop_back();
//		}
//		else k++;
//	}
//	return nums.size();
//}

vector<int> sortedSquares(vector<int>& nums) {
	int l = 0, r = nums.size() - 1;
	int k = r;
	vector<int>ans;
	while (l <= r)
	{
		if (nums[l] * nums[l] >= nums[r] * nums[r]) {
			ans[k--] = nums[l] * nums[l];
			l++;
		}
		else {
			ans[k--] = nums[r] * nums[r];
			r--;
		}
	}
	return ans;
}



//int minSubArrayLen(int target, vector<int>& nums) {
//
//	int n = nums.size();
//	int i = j = 0;
//	int sum = 0;
//	while (i<n)
//	{
//		sum += nums[j];
//		if (sum < target) j++;
//	}
//
//}

/// <summary>
/// 
/// </summary>
/// 一道动态规划的题目
bool validPartition(vector<int>& nums) {
	return  1;
}


/// <summary>
/// 缺失的第一个正数
/// </summary>
int firstMissingPositive(vector<int>& nums) {
	unordered_map<int, int>map;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {
			map[nums[i]]++;
		}
	}
	int m = 1;
	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second > 0) m++;
		else return m;
	}
	return m;
}

//int main() {
//	vector<int>nums = { 3,4,-1,1 };
//	int ans = firstMissingPositive(nums);
//	cout << ans;
//	return 0;
//}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int>set(nums1.begin(),nums1.end());
	vector<int>ans;

	for (auto num : nums2) {
		if (set.count(num) > 0) {
			ans.push_back(num);
			set.erase(num);
		}
	}
	return ans;
}

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int,int>hashset;
	vector<int>ans;
	for (auto num : nums1) {
		hashset[num]++;
	}

	for (auto num : nums2) {
		if (hashset[num] > 0) {
			ans.push_back(num);
			hashset[num]--;
		}
	}
	return ans;
}

//int main() {
//	std::vector<int> nums1 = {1,2,2,2,1 };
//	std::vector<int> nums2 = { 1,2,2};
//
//	std::vector<int> result = intersection(nums1, nums2);
//
//	std::cout << "Intersection: ";
//	for (int num : result) {
//		std::cout << num << " ";
//	}
//	std::cout << std::endl;
//
//	return 0;
//}

/// <summary>
/// 找出字符串的可整除数组
/// </summary>
vector<int> divisibilityArray(string word, int m) {
	vector<int>ans;
	string s = "";
	for (auto w : word) {
		s.push_back(w);
		int a = stoi(s);
		if (a % m == 0) ans.push_back(1);
		else  ans.push_back(0);
	}
	return ans;
}



/// <summary>
///  找出美丽数组的最小和
/// </summary>
/// 这道题如果直接暴力的话，时间复杂度太高，我猜应该用动态规划解答。我的思路是这样的
/// dp[i][j]代表数组中第i个和第j个元素的和是否为target。
/// 初始化数组为连续的自然数1，2，3，4.。。如果dp[i][j]==1的话，再接着增加一个自然数，如果为0，继续，直到循环完之后的全为0，这个时候，我们就得到了想要的数组。
/// 之后统计我们得到的新数组之和。
/// 
/// 436 / 575 个通过的测试用例......看了下答案，根本没这么复杂，用的是等差数列求和公式！！！我直接吐血，，
int minimumPossibleSum1(int n, int target) {
	vector<vector<int>> dp(2*n, vector<int>(2*n, 0));
	vector<int>nums;
	vector<int>wrong;
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i + 1);
	}
	int num = n;
	for (int i = 0; i < num; i++)
		for (int j = i+1; j < num; j++)
		{
			if (nums[i] + nums[j] == target) {
				dp[i][j] = 1;  num += 1; nums.push_back(num); wrong.push_back(j);
			}
			else dp[i][j] = 0;
		}
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	for (auto w : wrong) sum -= nums[w];

	return  sum;

}

int minimumPossibleSum(int n, int target) {
	const int mod = 1e9 + 7;
	int m = target / 2;
	if (n <= m) {
		return (long long)(1 + n) * n / 2 % mod;
	}
	return ((long long)(1 + m) * m / 2 +
		((long long)target + target + (n - m) - 1) * (n - m) / 2) % mod;
}
//int main() {
//	int ans = minimumPossibleSum(1, 1);
//	cout << ans;
//	return 0;
//}

/// <summary>
/// 合并后数组中的最大元素
/// </summary>
/// 我的思路是这样的，找到这个数组最后一对单调递增(或者相等)的两个数，然后执行操作。直到数组中没有递增的两个相邻数，此时得到最大值。
/// 比如说3，5，9我先操作3和5，或者先操作5和9，结果是一样的，但是如果是
/// 5，7，9 那么先操作5，7 变成12，9，就不行了，所以只能先操作7，9，保证递增。
/// 下面这个代码有几个示例通不过，是long long 的原因。。。
int maxArrayValue(vector<int>& nums) {

	for (int i = nums.size()-1; i >0; i--)
	{
		if (nums[i] >= nums[i - 1]) {
			nums[i - 1] += nums[i];
			int m = 0;
			while (i+m<nums.size()-1)
			{
				nums[i+m] = nums[i + m + 1];
				m++;
			}
			nums.pop_back();
		}
	}
	return nums[0];
}


//int main() {
//	vector<int>nums = { 5,3,3 };
//	int ans = maxArrayValue(nums);
//	cout << ans;
//	return 0;
//}



