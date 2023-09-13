#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>



using namespace std;


//STL�й�ϣ���Ļ����÷�
void basic()
{
	std::unordered_map<std::string, int> myMap;

	// ���Ӽ�ֵ��
	myMap["Alice"] = 25;
	myMap["Bob"] = 30;
	myMap["Charlie"] = 35;


	//ɾ����ֵ��
	myMap.erase("Bob");

	// �����Ƿ����
	if (myMap.find("David") != myMap.end()) {
		std::cout << "David's age is: " << myMap["David"] << std::endl;
	}
	else {
		std::cout << "David is not in the map." << std::endl;
	}
	// ������ϣ��
	for (const auto& pair : myMap) {
		std::cout << pair.first << "'s age is: " << pair.second << std::endl;
	}


}

//int main()
//{
//
//	basic();
//	return 0;
//}



/// <summary>
/// 1.����֮��--��ϣʵ��
/// </summary>
vector<int> twoSum(std::vector<int>& nums, int target) {
	unordered_map<int, int>map;
	vector<int>result;
	for (int i = 0; i < nums.size(); i++)
	{
		int other = target - nums[i];
		if (map.find(other) != map.end())
		{
			result.push_back(map[other]);
			result.push_back(i);
			return result;
		}
		map[nums[i]] = i;

	}
	return result;
}


//int main() {
//	std::vector<int> nums = { 2, 7, 11, 15 };
//	int target = 14;
//	std::vector<int> result = twoSum(nums, target);
//
//	if (result.size() == 2) {
//		std::cout << "Indices: " << result[0] << " and " << result[1] << std::endl;
//	}
//	else {
//		std::cout << "No solution found." << std::endl;
//	}
//
//	return 0;
//}


/// <summary>
/// ���ظ�����Ӵ��ĳ���
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
int lengthOfLongestSubstring(string s) {
	unordered_map<char, int>map;
	

	return 0;

}

/// <summary>
/// ��������ת����
/// </summary>
int romanToInt(string s) {

	unordered_map<char, int>map;
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;

	int result = 0;
	int prevValue = 0;

	for (int i = s.length() - 1; i >= 0; i--) {
		int currentValue = map[s[i]];

		// �����ǰ�ַ�����������С��ǰһ���ַ�����Ҫ��ȥ
		if (currentValue < prevValue) {
			result -= currentValue;
		}
		// ���򣬼��ϵ�ǰ�ַ�����������
		else {
			result += currentValue;
		}

		prevValue = currentValue;
	}

	return result;
	

}


//int main()
//{
//	string  s1 = { "IV" };
//	int a = romanToInt(s1);
//	cout << a << endl;
//	return 0;
//}



//Ψһ��֮��
int sumOfUnique(vector<int>& nums) {

	unordered_map<int, int> hashMap;
	int sum = 0;

	for (int i = 0; i < 100; ++i) {
		hashMap[i] = 0;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		hashMap[nums[i]]++;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (hashMap[nums[i]] == 1)
			sum += nums[i];
	}
	return sum;
}


/// <summary>
/// �����黮�ֳ��������
/// </summary>
bool divideArray(vector<int>& nums) {
	unordered_map<int, int> hashMap;

	for (int i = 0; i < 501; ++i) {
		hashMap[i] = 0;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		hashMap[nums[i]]++;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (hashMap[nums[i]] / 2 != 0)
			return false;
		

	}
	return true;

}


/// <summary>
/// �жϾ����Ƿ�Ϊȫ��ĸ��
/// </summary>
bool checkIfPangram(string sentence) {
	unordered_map<char, int> hashMap;
	for (int i = 0; i < 26; i++)
	{
		hashMap['a'+i] = 0;
	}
	for (int i = 0; i < sentence.size(); i++)
	{
		hashMap[sentence[i]]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (hashMap['a' + i] == 0)
			return false;
	}

	return true;

}



/// <summary>
/// �����Եĸ���
/// </summary>
int numIdenticalPairs(vector<int>& nums) {
	unordered_map<int, int> hashMap;
	int ans = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		ans += hashMap[nums[i]];
		hashMap[nums[i]]++;
	}
	return ans;

}

//int main() {
//	vector<int>nums = { 1,2,1,5,1 };
//	int r = numIdenticalPairs(nums);
//	cout << r << endl;
//}



/// <summary>
/// ��ľ���ֵΪ K ��������Ŀ
/// </summary>

int countKDifference(vector<int>& nums, int k) {
	int result = 0;
	unordered_map<int, int>map;
	for (int i = 0; i < 100; ++i) {
		map[i] = 0;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		int x = nums[i] - k;
		if(x>=1&&x<=100)
			result+=map[x];
		x = nums[i] + k;
		if (x >= 1 && x <= 100)
			result += map[x];
		map[nums[i]]++;
	}
	return result;

}


//int main() {
//	vector<int>nums = {3,2,1,5,4};
//	int k = 2;
//	int r = countKDifference(nums,k);
//	cout <<r<< endl;
//}



/// <summary>
/// ����ͬ�Ķ�Ԫ������
/// </summary>
/// ����һ---��ϣ��ǰ׺��
int numSubarraysWithSum1(vector<int>& nums, int goal) {	
	
	int n = nums.size();
	unordered_map<int, int>map;
	int count = 0;
	int presum = 0;
	for (int i = 0; i < n; i++)
	{
		presum += nums[i];
		if (presum == goal)
		{
			count++;
		}
		//���ǰ׺�����Ѿ��� prefixSum - goal��˵����ǰλ�õ�ǰһ��λ�õ��������Ϊ goal
		if (map.find(presum - goal) != map.end()) 
		{
		count += map[presum - goal];
		}
		// ����ǰ׺�ͼ���
		map[presum]++;
	}
	return count;
}

//�������ڽⷨ
int numSubarraysWithSum(vector<int>& nums, int k) 
{	
	//int left1 = 0;
	//int left2 = 0
	//int sum1 = 0;
	//int sum2 = 0;
	//int count = 0;
	//for (int right = 0; right < nums.size(); right++)
	//{
	//	sum1 += nums[right];
	//	while(left1<=right&&sum1 > goal)
	//	{
	//		sum1 -= nums[left1];
	//		left1++;
	//	}

	//	sum2 += nums[right];
	//	while(left2 <= right && sum2 >= goal)
	//	{
	//		sum2 -= nums[left2];
	//		left2++;
	//	}
	//	if (sum1 == goal) {
	//		count += (left2 - left1);
	//	}

	//}
	//	return count;
	int n = nums.size();
	int left = 0;
	int sum = 0;
	int count = 0;

	for (int right = 0; right < n; right++) {
		sum += nums[right];

		while (left <= right && sum > k) {
			sum -= nums[left];
			left++;
		}

		if (sum == k) {
			count++;
		}
	}

	return count;
}


//int main() {
//	vector<int> nums = { -1,-1,1 };
//	int goal = 0;
//	int result = numSubarraysWithSum(nums, goal);
//	cout << "���к�Ϊ " << goal << " �ķǿ�����������Ϊ��" << result << endl;
//
//	return 0;
//}



/// <summary>
/// ����֮��
/// </summary>
vector<vector<int>> threeSum(vector<int>& nums) {

	vector<vector<int>> ans;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int l = i+1;
		int r = n - 1;
		while (l < r)
		{
			int sum = nums[l] + nums[r] + nums[i];

			if (sum == 0)
			{
				ans.push_back({ nums[l], nums[r], nums[i] });
				while (l < r && nums[l] == nums[l + 1])
					l++;
				while (l < r && nums[r] == nums[r - 1])
					r--;


				l++;
				r--;
			}
			else if (sum > 0)
				r--;
			else
				l++;


		}
		
	}
	return ans;

}


//int main() {
//	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
//	vector<vector<int>> result = threeSum(nums);
//
//	for (const vector<int>& triplet : result) {
//		for (int num : triplet) {
//			cout << num << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

