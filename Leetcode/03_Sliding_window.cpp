
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;




/// <summary>
/// 滑动窗口的四种情况
/// </summary>
/// 1.同向交替移动的两个变量



/// <summary>
/// 子数组最大平均数 I
/// </summary>
double findMaxAverage(vector<int>& nums, int k) {
	int n = nums.size();
	int a = 0;
	int b = 0;
	int sum = 0;

	for (int i = 0; i < k; i++)
	{
		sum += nums[i];
	}

	int maxSum = sum;
	// 滑动窗口
	for (b = k; b < n; b++) {
		sum += nums[b] - nums[a];  // 将新元素加入窗口，同时将旧元素移出窗口
		maxSum = max(maxSum, sum);
		a++;
	}

	return static_cast<double>(maxSum) / k;

}

//int main() {
//	vector<int>nums = {0,1,1,3,3};
//	int k = 4;
//	double ans = findMaxAverage(nums,k);
//	cout << ans << endl;
//	return 0;
//}



/// <summary>
/// 爱生气的书店老板
/// </summary>
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

	int n = grumpy.size();
	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		if (grumpy[i] == 0) 
		{ 
			sum += customers[i]; 
		}
	}
	for (int i = 0; i < minutes; ++i) 
	{
		if (grumpy[i]) 
		{
			sum += customers[i];
		}
	}
	int sum1 = sum;

	for (int i = minutes; i < n; i++) 
	{
		if (grumpy[i]) 
		{ 
			sum += customers[i]; 
		}
		if (grumpy[i - minutes])
		{ 
			sum -= customers[i - minutes];
		}
		sum1 = max(sum, sum1);
	}
	return sum1;

}

//int main()
//{
//	vector<int>customers = { 1,0,1,2,1,1,7,5 };
//	vector<int>grumpy = { 0,1,0,1,0,1,0,1 };
//	int minutes = 3;
//	int ans = maxSatisfied(customers, grumpy, minutes);
//	cout << "最大满意顾客为:" << ans << endl;
//}


/// <summary>
/// 可获得的最大点数
/// </summary>
int maxScore(vector<int>& cardPoints, int k) {
	int l = 0;
	int n = cardPoints.size();
	int sum = 0;


	for (int i = n-k; i < n; i++)
	{
		sum += cardPoints[i];
	}
	int ans = sum;
	for (int i = n - k; i < n; i++)
	{
			sum -= cardPoints[(i)%n];
			sum += cardPoints[(i+k)%n];
			ans = max(ans, sum);
	
	}
	return ans;
}


//int main() {
//	vector<int>nums = { 1,2,3,4,5,6,1 };
//	int ans = maxScore(nums, 3);
//	cout << ans << endl;
//
//
//}


/// <summary>
/// 定长子串中元音的最大数目
/// </summary>
int maxVowels(string s, int k) {
	int n = s.size();
	int count = 0;
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			count++;
	}
	ans = count;
	for (int i = 1; i < n - k + 1; i++)
	{

		if (s[i - 1] == 'a' || s[i - 1] == 'e' || s[i - 1] == 'i' || s[i - 1] == 'o' || s[i - 1] == 'u')
			count--;
		if (s[k + i - 1] == 'a' || s[k + i - 1] == 'e' || s[k + i - 1] == 'i' || s[k + i - 1] == 'o' || s[k + i - 1] == 'u')
			count++;
		ans = max(count, ans);
	}
	return ans;
}


//int main() {
//	string s = { "abciiidef " };
//	int ans = maxVowels(s, 3);
//	cout << ans << endl;
//  return 0;
//}



/// <summary>
/// 将 x 减到 0 的最小操作数
/// </summary>
/// <param name="nums"></param>
/// <param name="x"></param>
/// <returns></returns>
int minOperations(vector<int>& nums, int x) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}
	if (x > sum) return -1;
	int target = sum - x; // 求得target的值
	sum = 0;
	int ans = -1;
	int left = 0, right = 0;
	// 使用滑动窗口寻找最大的序列
	for (; right < nums.size(); ++right) {
		sum += nums[right];
		while (sum > target) {
			sum -= nums[left];
			left++;
		}
		if (sum == target) {
			ans = max(ans, right - left + 1);
		}
	}
	// 如果没找到，则返回-1
	if (ans == -1) return -1;
	else return nums.size() - ans;

}





//int main() {
//	vector<int> nums = { 1,1,4,2,3 };
//	int ans = minOperations(nums, 5);
//	cout << ans << endl;
//	return 0;
//}



///滑动窗口 2----不定长度的滑动窗口
//先思考暴力解法，分析暴力解法的缺点（一般而言暴力解法的缺点是重复计算），然后 结合问题的特点，使用「双指针」技巧对暴力解法进行剪枝。



/// <summary>
/// 最小覆盖字串
/// 滑动窗口加哈希表
/// </summary>
string minWindow(string s, string t) {

	int left = 0; // 滑动窗口的左边界
	int minLen = INT_MAX; // 最小覆盖子数组的长度
	int minLeft = 0; // 最小覆盖子数组的左边界
	int count = t.length(); // 当前窗口内需要匹配的字符数
	string result = "";

	unordered_map<char, int>map;
	for (char c : t) {
		map[c]++;
	}
	for (int right = 0; right < s.size(); right++)
	{
		if (map.find(s[right]) != map.end()) {
			map[s[right]]--;
			if (map[s[right]] >= 0) {
				count--;
			}
		}
		while (count == 0) {
			// 更新最小覆盖子数组的信息
			if (right - left + 1 < minLen) {
				minLen = right - left + 1;
				minLeft = left;
			}
			// 缩小窗口的左边界，尝试找到更小的覆盖子数组
			if (map.find(s[left]) != map.end()) {
				map[s[left]]++;
				if (map[s[left]] > 0) {
					count++;
				}
			}
			left++;
		}

	}
	if (minLen == INT_MAX) {
		return ""; // 未找到符合条件的覆盖子数组，返回空字符串
	}

	return s.substr(minLeft, minLen); // 返回最小覆盖子数组的字符串
}




//int main() {
//	string s = "ADOBECODEBANC";
//	string t = "ABC";
//
//	string result = minWindow(s, t);
//
//	if (result.empty()) {
//		cout << "未找到符合条件的覆盖子数组" << endl;
//	}
//	else {
//		cout << "最小覆盖子数组：" << result << endl;
//	}
//
//	return 0;
//}


/// <summary>
/// 替换后的最长重复字符
/// </summary>
int characterReplacement(string s, int k) {
	
	unordered_map<char, int>map; 
	int l = 0;
	int maxCount = 0; 
	int res = 0;


	for (int r = 0; r < s.size(); r++)
	{

		map[s[r]]++;
		maxCount = max(maxCount, map[s[r]]);
		while ((r-l- maxCount+1) >k)
		{
			map[s[l]]--;
			l++;
		}
		res = max(res, r - l+1);
	}
	return res;
}


//int main() {
//	string s = "AAAA";
//	int k = 0;
//
//	int result = characterReplacement(s, k);
//
//	cout << "最长相同字母子串的长度是: " << result << endl;
//
//	return 0;
//}




/// <summary>
/// 无重复字符的最小子串
/// 
/// </summary>

int lengthOfLongestSubstring(string s) {

	int l = 0;
	int ans = 0;
	unordered_map<char, int>map;
	for (int i = 0; i < s.size(); i++)
	{
		map[s[i]]++;
		while (map[s[i]] != 1)
		{
			map[s[l]]--;
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	return ans;
}

/// <summary>
/// 长度最小的子数组
/// </summary>
int minSubArrayLen(int target, vector<int>& nums) {
	int l = 0;
	int sum = 0;
	int ans = INT_MAX;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		while (target <= sum)
		{
			ans = min(ans, i - l + 1);
			sum -= nums[l];
			l++;
		}

	}
	return ans == INT_MAX ? 0 : ans;
}


///后续类似的习题太多了，先记录一下
/// 一.简单题
/// 删除子数组的最大得分
/// 找到字符串中所有字母异位词
/// 字符串的排列
/// 最大连续1的个数 II
/// 最大连续 1 的个数 III
/// 尽可能使字符串相等
/// 删掉一个元素以后全为 1 的最长子数组
/// 最长湍流子数组
/// 
/// 
/// 二.进阶题
/// K 连续位的最小翻转次数
/// 最小窗口子序列
/// 长度为 K 的无重复字符子串
/// 最少交换次数来组合所有的 1
/// 健身计划评估
/// 
/// 
/// 有时间的话练一个！