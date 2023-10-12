


#include<iostream>
#include<vector>
using namespace std;



//��̬�滮�ĵ��ĸ����ⲽ���ǣ�
//
//1.����������
//2.д��������ĵ��ƹ�ϵ
//3.ȷ�� DP ����ļ���˳��
//4.�ռ��Ż�(��ѡ)


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


int main() {

	vector<int>nums = { 1,2,3,1 };
	int ans = rob(nums);
	cout << ans;
	return 0;
}
