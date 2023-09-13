
#include<iostream>
#include<vector>

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


int main() {
	vector<int>nums = { 1,2,3,4,5,6,1 };
	int ans = maxScore(nums, 3);
	cout << ans << endl;


}