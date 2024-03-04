


#include<iostream>
#include<vector>
#include <unordered_map>
#include<unordered_set>
#include<deque>
using namespace std;



//��̬�滮�ĵ��ĸ����ⲽ���ǣ�
//
//1.����������
//2.д��������ĵ��ƹ�ϵ
//3.ȷ�� DP ����ļ���˳��
//4.�ռ��Ż�(��ѡ)

//1.ȷ��dp���飨dp table���Լ��±�ĺ���
//2.ȷ�����ƹ�ʽ
//3.dp������γ�ʼ��
//4.ȷ������˳��
//5.�����Ƶ�dp����

/// <summary>
/// �ȴ�������¥�ݿ�ʼ
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
/// 쳲���������
/// </summary>
/// �ڴ����еȼ���¥��
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
/// ��N��쳲�������
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
/// ʹ����С������¥��
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
/// ��ҽ���1
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
/// ɾ������õ���
/// </summary>
/// ���� dp �е�ÿ��Ԫ�� dp[i] ��ʾ��ѡ������ i ʱ���Ի�õ���������
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
/// �ⷨ����������Ǵ�ҽ��᣿��
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
/// ��ͬ·��
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
/// ��С·����
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
/// ��ͬ·��2----���ϰ�������
/// </summary>
/// �������ͨ�����������һ���������ϰ���ĵط���Ϊ0����
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
/// ��������С·����
/// </summary>
/// ���ϵ��²��У������ҵ��Ǿֲ���Сֵ������̰���㷨�����ǿ��Ǵ��µ���
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
/// dp[0]�ǲ��ϸ��µģ�dp��������i�㵽�����һ������·��
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
/// �½�·������С��
/// </summary>
/// ���������һ�������һģһ���������ܲ����Լ�д����
/// д�����ˣ������������O(n2)�Ŀռ临�Ӷȣ���Ϊ���κ������β�һ���������θպ�jҪ�õ�����һ������û�б�֮ǰ�Ķ���������������Ϊһ������������Ļ����ڶ��������ܱ�����һ�е�����
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
/// ���������
/// </summary>
/// �� dp(i,j)\textit{dp}(i, j)dp(i,j) ��ʾ�� (i,j)(i, j)(i,j) Ϊ���½ǣ���ֻ���� 111 �������εı߳����ֵ��
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
/// �������
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
/// ��ͬ�Ķ���������
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
/// ��̬�滮���ַ����е�Ӧ��
///****************************

/// <summary>
/// ������Ӵ�
/// </summary>
/// ��̬�滮���
string longestPalindrome(string s) {
	int n = s.size();
	if (n <= 1) {
		return s;
	}

	vector<vector<bool>> dp(n,vector<bool>(n, false));

	// ��ʼ������Ϊ1�Ļ����Ӵ�
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}

	int start = 0;  // ��¼������Ӵ�����ʼλ��
	int maxLen = 1; // ��¼������Ӵ��ĳ���

	// ��̬�滮���
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
/// 0-1�������⣡��
/// </summary>
/// dp[i][j]�ĺ��壺���±�Ϊ[0-i]����Ʒ������ȡ���Ž�����Ϊj�ı�������ֵ�ܺ�����Ƕ��١�
int  bag01(vector<int>weight, vector<int>value, int bagweight) {
	vector<vector<int>>dp(weight.size(), vector<int>(bagweight+1, 0));
	
	//��ʼ����һ�У��Ӵ��ڵ���bagweight��ʼ
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

	//��ӡdp����
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
/// ʹ�ù��������Ż�������λת��Ϊһά
/// </summary>
int  bag01_1(vector<int>weight, vector<int>value, int bagweight) {
	 vector<int>dp(bagweight + 1, 0);

	//��ʼ����һ�У��Ӵ��ڵ���bagweight��ʼ
	for (int i = weight[0]; i <= bagweight; i++)
	{
		dp[i] = value[0];
	}
	//�ȱ�����Ʒ���ٱ���������˳�򲻿��Ի������������������������һ�㣬��ôÿ��dp[j]��ֻ�����һ����Ʒ������������ֻ������һ����Ʒ��
	//���������ԭ���ǣ������ϻ���һ���Զ�ά����ı������������½ǵ�ֵ������һ�����Ͻǵ�ֵ�������Ҫ��֤��ߵ�ֵ��Ȼ����һ��ģ��������󸲸ǡ�
	for (int i = 0; i < weight.size(); i++)
		for (int j = bagweight; j >= weight[i]; j--)
		{
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}

	//��ӡdp����
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
/// ��ȫƽ����
/// </summary>
/// �����������������ֻ�����һģһ��
/// ������������Լ�д�ģ�ʹ�ö�ά����ģ��01�������⣬��Ȼ�е㸴�ӣ��������������һ�����Ż��ģ�
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

	//��ӡdp����
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
/// ��ʼ�����Ż�
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

	//��ӡdp����
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
/// �ָ�Ⱥ��Ӽ�
/// </summary>
/// dp[j]��ʾ ����������������װ������������j���Ž���Ʒ�󣬱����������Ϊdp[j]��
bool canPartition(vector<int>& nums) {
	int sum = 0;
	int n = nums.size();
	vector<int>dp(10001, 0);
	for (auto num : nums)
		sum += num;

	if (sum % 2 == 1) return false;
	int target = sum / 2;

	for (int i = 0; i < n; i++)
		for (int j = target; j >= nums[i]; j--)// ÿһ��Ԫ��һ���ǲ����ظ����룬���ԴӴ�С����
		{
			dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
		}
	// �����е�Ԫ�����ÿ��Դճ��ܺ�target
	if (dp[target] == target) return true;
	return false;
}

//int main() {
//	vector<int>nums = { 1,5,11,5 };
//	bool ans = canPartition(nums);
//	cout << ans;
//}



/// <summary>
/// ���һ��ʯͷ������2
/// </summary>
/// ����Ĺؼ�����ת��Ϊһ����Ҫ�ĸ����ʯͷ�����ܷ�Ϊ��ͬ���������ѣ������Ļ��������Ŀ��ֱ�͸��������Ŀһģһ����
int lastStoneWeightII(vector<int>& stones) {
	int sum = 0;
	int n = stones.size();
	vector<int>dp(1501, 0);
	for (auto num : stones)
		sum += num;

	int target = sum / 2;

	for (int i = 0; i < n; i++)
		for (int j = target; j >= stones[i]; j--)// ÿһ��Ԫ��һ���ǲ����ظ����룬���ԴӴ�С����
		{
			dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		}
	// �����е�Ԫ�����ÿ��Դճ��ܺ�target
	return sum - dp[target] - dp[target];
}

/// <summary>
/// Ŀ���
/// </summary>
int findTargetSumWays(vector<int>& nums, int target) {
	int sum = 0;
	int n = nums.size();

	for (auto num : nums)
		sum += num;
	if (abs(target) > sum) return 0;
	if ((sum + target) % 2 == 1) return 0;
	int left = (sum + target) / 2;
	vector<int>dp(left + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = left; j >= nums[i]; j--)
		{
			dp[j] += dp[j - nums[i]];
		}
	return dp[left];
}


/// <summary>
/// һ����
/// </summary>
/// �����տ�ʼ���ҿ����ˣ��൱�ڱ���������ά�ȵ�0-1��������õķ�������д��һά���������ά����������
int findMaxForm(vector<string>& strs, int m, int n) {
	vector<vector<int>>dp(m + 1 ,vector<int>(n + 1, 0));
	for(auto str:strs)
	{
		int count0 = 0;
		int count1 = 0;
		for (auto st : str){
			if (st == '0') count0++;
			if (st == '1') count1++;}

		for (int i = m; i >= count0; i--)
			for (int j = n; j >= count1; j--)
		    {
				dp[i][j] = max(dp[i][j], dp[i - count0][j - count1]+1);
			}
			
	}
	//for (auto arr : arr0) cout << arr << " ";
	//cout << endl;
	//for (auto arr : arr1) cout << arr << " ";


	return dp[m][n];
}

//int main() {
//	vector<string>nums = { "10", "0001", "111001", "1", "0" };
//	int ans = findMaxForm(nums,1,1);
//}



///�ܽ�
//�� 0 - 1 ����(opens new window)���� ������������ װ������ ������ֵ�Ƕ��١�
// 
//416. �ָ�Ⱥ��Ӽ�(opens new window)���� ���������������ܲ���װ�����������
// 
//1049. ���һ��ʯͷ������ II(opens new window)���� ��������������������װ�������װ����
// 
//494. Ŀ���(opens new window)���� ��������������װ�������ж����ַ�����
// 
//һ����  ���� ������������(��ά)��װ����������ж��ٸ���Ʒ��



/// <summary>
/// ��ȫ�������⣡
/// ��0-1������Ψһ��ͬ���ǣ�ÿ����Ʒ�����Զ�η��뱳����������֮��Ӧ�ľ��ǣ�����Ӧ�ô�С������б���
/// </summary>
int  bagCom(vector<int>weight, vector<int>value, int bagweight) {
	vector<int>dp(bagweight + 1, 0);

	//��ʼ����һ�У��Ӵ��ڵ���bagweight��ʼ
	for (int i = weight[0]; i <= bagweight; i++)
	{
		dp[i] = value[0];
	}
	for (int i = 0; i < weight.size(); i++)
		//��֮ͬ������
		for (int j = weight[i]; j <= bagweight; j++)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}

	//��ӡdp����
	for (int i = 0; i <= bagweight; i++)
	{

		cout << dp[i] << " ";
	}
	cout << endl;
	return dp[bagweight];
}


/// <summary>
/// ��Ǯ�һ�2
/// </summary>
int change(int amount, vector<int>& coins) {
	vector<int>dp(amount + 1, 0);
	//���������1����Ҫ���һ��
	dp[0] = 1;
	for (int i = 0; i < coins.size(); i++)
		for (int j = coins[i]; j <= amount; j++)
		{
			dp[j] += dp[j - coins[i]];
		}

	return dp[amount];
}


/// <summary>
/// ����ܺ�
/// </summary>
/// ���һ�£���Ϻ���������Щ����
/// ��ϲ�ǿ��˳�򣬶����в�ͬ��˳���ǲ�ͬ�����У����Ա�������������
/// 
int combinationSum4(vector<int>& nums, int target) {
	vector<int>dp(target + 1, 0);
	//���������1����Ҫ���һ��
	dp[0] = 1;
	for (int i = 0; i <= target; i++)
		for (int j =0; j <nums.size(); j++)
		{
			if(nums[j]<=i)
				dp[i] += dp[i - nums[j]];
		}

	for (auto d : dp)
		cout << d << " ";
	return dp[target];
}


//int main() {
//	vector<int>nums = {1,2,3};
//	int ans = combinationSum4(nums, 4);
//	return 0;
//}



//������������¥�ݡ���Ҫ n ������ܵ���¥����
//ÿ�������������m(1 <= m < n)��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
//	ע�⣺���� n ��һ����������

int climbStairsplus(int m,int n) {
	vector<int>dp(n + 1, 0);
	//���������1����Ҫ���һ��
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
		{
			if (j <= i)
				dp[i] += dp[i - j];
		}

	return dp[n];

}


/// <summary>
/// ��Ǯ�һ�
/// </summary>
/// ����൱�ڸ�����ֵ��������ü�ֵ�ı�������С��Ʒ����
/// dp[j]�����ǣ��ܽ��Ϊjʱ���ճ�������ֵ����С����
int coinChange(vector<int>& coins, int amount) {
	vector<int>dp(amount + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < coins.size(); i++)
		for (int j = coins[i]; j <= amount; j++)
		{
			if (dp[j - coins[i]] != INT_MAX)
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	for (auto d : dp)
		cout << d << " ";
	if (dp[amount] == INT_MAX) return -1;
	return dp[amount];
}
//int main() {
//	vector<int>nums = {2};
//	int ans = coinChange(nums, 3);
//	return 0;
//}



/// <summary>
/// ���ʲ��
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
/// �����������
/// </summary>
/// dp[j]������ǰj����Ŀ��õ���߷���
/// ���̫���ˣ�ǰ����Ŀ��ѡ������˺���Ľ��  ��Ҫ�õ��޺�Ч�ԣ�ɶ���Ⱑ
long long mostPoints(vector<vector<int>>& questions) {
	int n = questions.size();
	vector<long long>dp(n + 1, 0);
	long long ans = 0;
	for (int i = 0; i < questions.size(); i++) {
		dp[i] = questions[i][0];
		for (int j = 0; j < i; j++) {
			if (i - j > questions[j][1]) dp[i] = max(dp[i], dp[j] + questions[i][0]);
		}
		ans = max(ans, dp[i]);
	}

	return ans;
}


//int main() {
//	vector<vector<int>>nums = { {3,2},{4,3},{4,4},{2,5} };
//	long long ans = mostPoints(nums);
//	return 0;
//}

/// <summary>
/// ��ҽ����
/// </summary>
/// ����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�
/// ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��
/// ��������ת��Ϊ���������Ĵ�ҽ��ᣬ��Ϊ��β�����Ļ������൱���׺�βֻ��ȡһ�����������˼·��ȡ���ν������󣬾������յĽ��
int rob2(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return nums[0];
	}
	
	vector<int>dp1(n, 0);
	vector<int>dp2(n+1, 0);
	dp1[0] = 0;
	dp1[1] = nums[0];
	dp2[0] = 0;
	dp2[1] =0;
	//��0:n-1������dp
	for (int i = 2; i <= n-1; i++)
	{
		dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
	}
	//��1:n������dp
	for (int i = 2; i <= n; i++)
	{
		dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
	}

	return max(dp1[n - 1], dp2[n]);
}



/// <summary>
/// ���Ʊ�����ʱ��1
/// </summary>
/// <param name="prices"></param>
/// <returns></returns>
int maxProfit(vector<int>& prices) {
	return 0;
}


/// <summary>
/// ���Ʊ��
/// </summary>
/// ���Ƕ���dp���� f ������ f[i] ��ʾ�ﵽ day[i] ����Ҫ��������ѡ�
///�������⣬���������ַ������Ե��� day[i]�� ���������Ǵ� days[j] ���� day[i] ��
int mincostTickets(vector<int>& days, vector<int>& costs) {
	int n = days.size();
	vector<int>dp(days.size()+1, 0);
	dp[0] = 0;
	for (int i =0 ; i < n; i++)
	{
		
		dp[i+1] = dp[i] + costs[0];
		for (int j = i-1; j >=0; j--)
		{	int dif = days[i] - days[j];
		if (dif < 7) dp[i+1] = min(dp[i+1], dp[j] + costs[1]);
		if (dif < 30)dp[i+1] = min(dp[i+1], dp[j] + costs[2]);
		else break;
		}
	}
	return dp[n];
}


/// <summary>
/// ��Ծ��Ϸ4
/// </summary>
/// �ҵĵ�һ��˼·���ö�̬�滮���dp[i]��ʾ�ߵ���i��Ԫ��ʱ������÷֡������Ļ����ߵ���һ��Ԫ�ص����ķ�
/// Ҫôѡ��ǰԪ�أ�Ҫô�Ǵ�֮ǰ��dp[i]����ת���ġ�֮ǰ������£�ֱ��ѡ���Ƿ�ȡ��ǰԪ�ؾͿ����ˡ���������������Ծk�����ǲ��Ǹ�����һЩ��
/// ����취���ټ�һ��forѭ��ѭ��k���ͺ��ˣ��ɹ����У�����ֻͨ������ʾ��������
/// ԭ���ǳ���ʱ�������ˣ���������������Ż�
int maxResult(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int>dp(n,0);
	dp[0] = nums[0];
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= k; j++)
		{
			if (i- j >= 0)
				dp[i] = max(dp[i - 1], dp[i  - j]) + nums[i];
			else  break;
 		}

	for (auto d : dp) cout << d<<" ";
	cout << endl;
	return dp[n - 1];
}


/// <summary>
/// û�����������һ����⣬ת�����Զ������䣬����ʹ�õ��������Ż�dp������
/// ֮ǰû�нӴ����������У��������ж��ڻ������ں����ã�ֵ���˽�һ�¡��������������������е���Ŀ
/// ����һ�¹ٷ�����
int maxResult1(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> dp(n);
	dp[0] = nums[0];
	deque<int> queue;
	queue.push_back(0);
	for (int i = 1; i < n; i++) {
		while (!queue.empty() && queue.front() < i - k) {
			queue.pop_front();
		}
		dp[i] = dp[queue.front()] + nums[i];
		while (!queue.empty() && dp[queue.back()] <= dp[i]) {
			queue.pop_back();
		}
		queue.push_back(i);
	}
	return dp[n - 1];
}


//int main() {
//	vector<int>nums = { 1,-1,-2,4,-7,3 };
//	int ans = maxResult1(nums, 2);
//	cout << ans << endl;
//	return 0;
//}