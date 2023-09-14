
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;




/// <summary>
/// �������ڵ��������
/// </summary>
/// 1.ͬ�����ƶ�����������



/// <summary>
/// ���������ƽ���� I
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
	// ��������
	for (b = k; b < n; b++) {
		sum += nums[b] - nums[a];  // ����Ԫ�ؼ��봰�ڣ�ͬʱ����Ԫ���Ƴ�����
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
/// ������������ϰ�
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
//	cout << "�������˿�Ϊ:" << ans << endl;
//}


/// <summary>
/// �ɻ�õ�������
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
/// �����Ӵ���Ԫ���������Ŀ
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
/// �� x ���� 0 ����С������
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
	int target = sum - x; // ���target��ֵ
	sum = 0;
	int ans = -1;
	int left = 0, right = 0;
	// ʹ�û�������Ѱ����������
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
	// ���û�ҵ����򷵻�-1
	if (ans == -1) return -1;
	else return nums.size() - ans;

}





//int main() {
//	vector<int> nums = { 1,1,4,2,3 };
//	int ans = minOperations(nums, 5);
//	cout << ans << endl;
//	return 0;
//}



///�������� 2----�������ȵĻ�������
//��˼�������ⷨ�����������ⷨ��ȱ�㣨һ����Ա����ⷨ��ȱ�����ظ����㣩��Ȼ�� ���������ص㣬ʹ�á�˫ָ�롹���ɶԱ����ⷨ���м�֦��



/// <summary>
/// ��С�����ִ�
/// �������ڼӹ�ϣ��
/// </summary>
string minWindow(string s, string t) {

	int left = 0; // �������ڵ���߽�
	int minLen = INT_MAX; // ��С����������ĳ���
	int minLeft = 0; // ��С�������������߽�
	int count = t.length(); // ��ǰ��������Ҫƥ����ַ���
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
			// ������С�������������Ϣ
			if (right - left + 1 < minLen) {
				minLen = right - left + 1;
				minLeft = left;
			}
			// ��С���ڵ���߽磬�����ҵ���С�ĸ���������
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
		return ""; // δ�ҵ����������ĸ��������飬���ؿ��ַ���
	}

	return s.substr(minLeft, minLen); // ������С������������ַ���
}




//int main() {
//	string s = "ADOBECODEBANC";
//	string t = "ABC";
//
//	string result = minWindow(s, t);
//
//	if (result.empty()) {
//		cout << "δ�ҵ����������ĸ���������" << endl;
//	}
//	else {
//		cout << "��С���������飺" << result << endl;
//	}
//
//	return 0;
//}


/// <summary>
/// �滻�����ظ��ַ�
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
//	cout << "���ͬ��ĸ�Ӵ��ĳ�����: " << result << endl;
//
//	return 0;
//}




/// <summary>
/// ���ظ��ַ�����С�Ӵ�
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
/// ������С��������
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


///�������Ƶ�ϰ��̫���ˣ��ȼ�¼һ��
/// һ.����
/// ɾ������������÷�
/// �ҵ��ַ�����������ĸ��λ��
/// �ַ���������
/// �������1�ĸ��� II
/// ������� 1 �ĸ��� III
/// ������ʹ�ַ������
/// ɾ��һ��Ԫ���Ժ�ȫΪ 1 ���������
/// �����������
/// 
/// 
/// ��.������
/// K ����λ����С��ת����
/// ��С����������
/// ����Ϊ K �����ظ��ַ��Ӵ�
/// ���ٽ���������������е� 1
/// ����ƻ�����
/// 
/// 
/// ��ʱ��Ļ���һ����