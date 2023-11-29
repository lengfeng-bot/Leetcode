


#include<iostream>
#include<vector>
#include <unordered_map>
#include<unordered_set>
using namespace std;



//动态规划的的四个解题步骤是：
//
//1.定义子问题
//2.写出子问题的递推关系
//3.确定 DP 数组的计算顺序
//4.空间优化(可选)

//1.确定dp数组（dp table）以及下标的含义
//2.确定递推公式
//3.dp数组如何初始化
//4.确定遍历顺序
//5.举例推导dp数组

/// <summary>
/// 先从最经典的爬楼梯开始
/// </summary>
int climbStairs(int n) {
	if (n <= 2) return n;

	vector<int>dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];

}


/// <summary>
/// 斐波那契数列
/// </summary>
/// 在代码中等价爬楼梯
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int first = 1;
	int second = 2;
	for (int i = 3; i <= n; i++)
	{
		int third = first + second;
		first = second;
		second = third;
	}
	return second;
}



/// <summary>
/// 第N个斐波那契数
/// </summary>
int tribonacci(int n) {
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;


	vector<int>dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] +dp[i-3];
	}

	return dp[n];
}


/// <summary>
/// 使用最小花费爬楼梯
/// </summary>
int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int>dp(n + 1, 0);
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = min(dp[i - 1]+cost[i-1], dp[i - 2]+cost[i-2]);
	}
	return dp[n];
}


/// <summary>
/// 打家劫舍1
///</summary>
int rob(vector<int>& nums){
	int n = nums.size();
	if (n == 1) return nums[0];

	vector<int>dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = nums[0];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
	}

	return dp[n];

}


/// <summary>
/// 删除并获得点数
/// </summary>
/// 数组 dp 中的每个元素 dp[i] 表示当选择数字 i 时可以获得的最大点数。
int deleteAndEarn(vector<int>& nums) {
	if (nums.empty()) return 0;

	int max_element = *std::max_element(nums.begin(), nums.end());
	vector<int> count(max_element + 1, 0);

	for (int num : nums) {
		count[num]++;
	}

	vector<int> dp(max_element + 1, 0);
	dp[0] = 0;
	dp[1] = count[1] * 1;

	for (int i = 2; i <= max_element; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + count[i] * i);
	}

	return max(dp[max_element], dp[max_element - 1]);
}

/// <summary>
/// 解法二，这题就是打家劫舍？！
/// </summary>
int deleteAndEarn2(vector<int>& nums) {
	int maxVal = 0;
	for (int val : nums) {
		maxVal = max(maxVal, val);
	}
	vector<int> sum(maxVal + 1);
	for (int val : nums) {
		sum[val] += val;
	}
	return rob(sum);
}


//int main() {
//
//	vector<int>nums = { 1,2,3,1 };
//	int ans = rob(nums);
//	cout << ans;
//	return 0;
//}

/// <summary>
/// 不同路径
/// </summary>
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = 0;
	for (int i = 0; i < m; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}

	//for (int i = 0; i < m; i++)
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}

	return dp[m - 1][n - 1];

}

/// <summary>
/// 最小路径和
/// </summary>
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];
	for (int i = 1; i < m; i++) {
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	for (int j = 1; j < n; j++) {
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << grid[i][j] << " ";
	//	}
	//	cout << endl;

	//}
	//cout << "************" << endl;

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;

	//}

}

/// <summary>
/// 不同路径2----有障碍物的情况
/// </summary>
/// 这个和普通的情况基本上一样，把有障碍物的地方设为0就行
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = 0;
	for (int i = 0; i < m&&obstacleGrid[i][0]==0; i++)
	{
		dp[i][0] = 1;
	}
	for (int j = 0; j < n&&obstacleGrid[0][j] == 0; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{	
			if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
			
		}

	//for (int i = 0; i < m; i++)
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}

	return dp[m - 1][n - 1];
}

/// <summary>
/// 三角形最小路径和
/// </summary>
/// 从上到下不行，这样找的是局部最小值，属于贪心算法，于是考虑从下到上
//int minimumTotal(vector<vector<int>>& triangle) {
//	int m = triangle.size();
//	int n = triangle[0].size();
//	vector<int>dp(m, 0);
//	dp[0] = triangle[0][0];
//	int j = 0;
//	for (int i = 1; i < m; i++)
//	{
//		if (triangle[i][j] > triangle[i][j + 1]) {
//		dp[i] = dp[i - 1] +triangle[i][j+1];
//		j = j + 1;
//		}
//		else
//			dp[i] = dp[i - 1] + triangle[i][j];
//
//	}
//	for (int i = 0; i < m; i++)
//	{
//		cout << dp[i] << " ";
//	}
//	return dp[m - 1];
//}

/// <summary>
/// dp[0]是不断更新的，dp数组代表第i层到达最后一层的最短路径
/// </summary>
/// <param name="triangle"></param>
/// <returns></returns>
int minimumTotal(vector<vector<int>>& triangle) {
	int m = triangle.size();
	vector<int>dp(triangle.back());
	for (int i = m - 2; i >= 0; i--)
	{
	
	for (int j = 0; j <= i; j++)
		dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];

	for (int i = 0; i < m; i++)
		{
			cout << dp[i] << " ";
		}
		cout << endl;
}
	
	return dp[0];
}

/// <summary>
/// 下降路径的最小和
/// </summary>
/// 这个和上面一题基本上一模一样，看看能不能自己写出来
/// 写出来了！这道题必须得用O(n2)的空间复杂度，因为矩形和三角形不一样，三角形刚好j要用到的下一个数，没有被之前的动过，两个数处理为一个结果，这样的话，第二个数仍能保持下一行的数据
int minFallingPathSum(vector<vector<int>>& matrix) {
	int n = matrix.size();
	vector<vector<int>>dp = matrix;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + matrix[i][j];
			else if (j == n - 1)
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j - 1]) + matrix[i][j];
			else
				dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i + 1][j - 1])) + matrix[i][j];


		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << dp[i] << " ";
	//}
	//cout << endl;
	//}
	int ans = INT_MAX;
	for (int i = 0,j = 0; j < n; j++)
	{
		ans = min(ans, dp[0][j]);
	}
	return ans;
}


/// <summary>
/// 最大正方形
/// </summary>
/// 用 dp(i,j)\textit{dp}(i, j)dp(i,j) 表示以 (i,j)(i, j)(i,j) 为右下角，且只包含 111 的正方形的边长最大值。
int maximalSquare(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int maxSide = 0;
	vector<vector<int>> dp(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		if (matrix[i][0] == '0')
			dp[i][0] = 0;
		else
			dp[i][0] = 1;
		maxSide = max(maxSide, dp[i][0]);
	}
	for (int i = 0; i < n; i++)
	{
		if (matrix[0][i] == '0')
			dp[0][i] = 0;
		else
			dp[0][i] = 1;
		maxSide = max(maxSide, dp[0][i]);
	}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			if (matrix[i][j] == '0')
				dp[i][j] = 0;
			else
			{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
			maxSide = max(maxSide, dp[i][j]);
		}

	return maxSide * maxSide;
}


//int main() {
//	//vector<vector<int>> triangle = { {2,1,3} ,{6,5,4},{7,8,9}};
//	///*int ans = uniquePaths(3, 3);*/
//	////int ans = uniquePathsWithObstacles(grid);
//	//int ans = minFallingPathSum(triangle);
//	vector<vector<char>>matrix = { {'1', '0', '1', '0', '0'},{'1', '0', '1', '1', '1'},{'1', '1', '1', '1', '1'},{'1', '0', '0', '1', '0'} };
//	int ans = maximalSquare(matrix);
//	cout << ans;
//	return 0; 
//}


/// <summary>
/// 整数拆分
/// </summary>
int integerBreak(int n) {
	vector<int>dp(n+1, 0);
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
		}

	return dp[n];
}


/// <summary>
/// 不同的二叉搜索树
/// </summary>
int numTrees(int n) {
	vector<int>dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}


///****************************
/// 动态规划在字符串中的应用
///****************************

/// <summary>
/// 最长回文子串
/// </summary>
/// 动态规划解决
string longestPalindrome(string s) {
	int n = s.size();
	if (n <= 1) {
		return s;
	}

	vector<vector<bool>> dp(n,vector<bool>(n, false));

	// 初始化长度为1的回文子串
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}

	int start = 0;  // 记录最长回文子串的起始位置
	int maxLen = 1; // 记录最长回文子串的长度

	// 动态规划填表
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;

			if (s[i] == s[j]) {
				if (len == 2 || dp[i + 1][j - 1]) {
					dp[i][j] = true;
					if (len > maxLen) {
						maxLen = len;
						start = i;
					}
				}
			}
		}
	}

	return s.substr(start, maxLen);

}


//int main() {
//
//	string s = "abcba";
//	string ans = longestPalindrome(s);
//	for (auto an : ans)
//		cout << an;
//
//}


/// <summary>
/// 单词拆分
/// </summary>
bool wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

	vector<bool> dp(n + 1, false);
	dp[0] = true;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[j] && wordSet.count(s.substr(j, i - j))) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[n];

}

/// <summary>
/// 0-1背包问题！！
/// </summary>
/// dp[i][j]的含义：从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
int  bag01(vector<int>weight, vector<int>value, int bagweight) {
	vector<vector<int>>dp(weight.size(), vector<int>(bagweight+1, 0));
	
	//初始化第一行，从大于等于bagweight开始
	for (int i = weight[0]; i <= bagweight; i++)
	{	
			dp[0][i] = value[0];
	}

	for (int i = 1; i < weight.size(); i++)
		for (int j = 1; j <= bagweight; j++)
		{
			if (weight[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
			    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}

	//打印dp数组
	for (int i = 0; i < weight.size(); i++) {
		for (int j = 0; j <= bagweight; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[weight.size()-1][bagweight];
}

/// <summary>
/// 使用滚动数组优化，将二位转化为一维
/// </summary>
int  bag01_1(vector<int>weight, vector<int>value, int bagweight) {
	 vector<int>dp(bagweight + 1, 0);

	//初始化第一行，从大于等于bagweight开始
	for (int i = weight[0]; i <= bagweight; i++)
	{
		dp[i] = value[0];
	}
	//先遍历物品，再遍历背包，顺序不可以换，如果遍历背包容量放在上一层，那么每个dp[j]就只会放入一个物品，即：背包里只放入了一个物品。
	//倒序遍历的原因是，本质上还是一个对二维数组的遍历，并且右下角的值依赖上一层左上角的值，因此需要保证左边的值仍然是上一层的，从右向左覆盖。
	for (int i = 0; i < weight.size(); i++)
		for (int j = bagweight; j >= weight[i]; j--)
		{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}

	//打印dp数组
	for (int i = 0; i <= bagweight; i++) 
	{
		
			cout << dp[i] << " ";	
	}
	cout << endl;
	return dp[bagweight];
}


//int main() {
//	vector<int>weight = {1,3,4};
//	vector<int>value = {15,20,30};
//	int ans = bag01_1(weight, value,4);
//	cout << ans;
//}



/// <summary>
/// 完全平方数
/// </summary>
/// 这道题和上面的整数拆分基本上一模一样
/// 这个代码是我自己写的，使用二维数组模拟01背包问题，虽然有点复杂，但是我想下面我会进行优化的！
int numSquares(int n) {
	int squareRoot = static_cast<int>(sqrt(n));
	vector<vector<int>>dp(squareRoot + 1, vector<int>(n + 1, 0));

	dp[0][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		dp[0][i] = i;
	}

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i * i <= n; i++)
		{		
			if(j-i*i>=0)
				dp[i][j] = min(dp[i - 1][j], dp[i][j - i * i] + 1);
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	//打印dp数组
	for (int i = 1;  i*i <= n; i++) {
		for (int j = 0; j <= n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[squareRoot][n];
}

/// <summary>
/// 开始进行优化
/// </summary>

int numSquares1(int n) {
	vector<int>dp(n + 1, INT_MAX);

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	//打印dp数组
	for (int j = 0; j <= n; j++)
	{
			cout << dp[j] << " ";
	}
	cout << endl;

	return dp[n];
}


//int main() {
//	int ans = numSquares1(10);
//	cout << ans;
//}



/// <summary>
/// 分割等和子集
/// </summary>
/// dp[j]表示 背包总容量（所能装的总重量）是j，放进物品后，背的最大重量为dp[j]。
bool canPartition(vector<int>& nums) {
	int sum = 0;
	int n = nums.size();
	vector<int>dp(10001, 0);
	for (auto num : nums)
		sum += num;

	if (sum % 2 == 1) return false;
	int target = sum / 2;

	for (int i = 0; i < n; i++)
		for (int j = target; j >= nums[i]; j--)// 每一个元素一定是不可重复放入，所以从大到小遍历
		{
			dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
		}
	// 集合中的元素正好可以凑成总和target
	if (dp[target] == target) return true;
	return false;
}

//int main() {
//	vector<int>nums = { 1,5,11,5 };
//	bool ans = canPartition(nums);
//	cout << ans;
//}



/// <summary>
/// 最后一块石头的重量2
/// </summary>
/// 本题的关键就是转化为一个重要的概念，把石头尽可能分为相同重量的两堆，这样的话，这个题目简直就跟上面的题目一模一样了
int lastStoneWeightII(vector<int>& stones) {
	int sum = 0;
	int n = stones.size();
	vector<int>dp(1501, 0);
	for (auto num : stones)
		sum += num;

	int target = sum / 2;

	for (int i = 0; i < n; i++)
		for (int j = target; j >= stones[i]; j--)// 每一个元素一定是不可重复放入，所以从大到小遍历
		{
			dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		}
	// 集合中的元素正好可以凑成总和target
	return sum - dp[target] - dp[target];
}
