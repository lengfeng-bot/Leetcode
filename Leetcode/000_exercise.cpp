#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<unordered_set>
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
/// 找到所有字母异位词
/// </summary>
vector<int> findAnagrams(string s, string p) {

	int sLen = s.size(), pLen = p.size();

	if (sLen < pLen) {
		return vector<int>();
	}

	vector<int> ans;
	vector<int> sCount(26);
	vector<int> pCount(26);
	for (int i = 0; i < pLen; ++i) {
		++sCount[s[i] - 'a'];
		++pCount[p[i] - 'a'];
	}

	if (sCount == pCount) {
		ans.emplace_back(0);
	}
	for (int i = 0; i < sLen - pLen; ++i) {
		--sCount[s[i] - 'a'];
		++sCount[s[i + pLen] - 'a'];

		if (sCount == pCount) {
			ans.emplace_back(i + 1);
		}
	}

	return ans;

}


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