#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include<unordered_set>
#include<stack>



using namespace std;


//STL中哈希表的基本用法
void basic()
{
	std::unordered_map<std::string, int> myMap;

	// 添加键值对
	myMap["Alice"] = 25;
	myMap["Bob"] = 30;
	myMap["Charlie"] = 35;


	//删除键值对
	myMap.erase("Bob");

	// 检查键是否存在
	if (myMap.find("David") != myMap.end()) {
		std::cout << "David's age is: " << myMap["David"] << std::endl;
	}
	else {
		std::cout << "David is not in the map." << std::endl;
	}
	// 遍历哈希表
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
/// 1.两数之和--哈希实现
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
/// 无重复的最长子串的长度
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
int lengthOfLongestSubstring(string s) {
	unordered_map<char, int>map;
	

	return 0;

}

/// <summary>
/// 罗马数字转整数
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

		// 如果当前字符代表的数字小于前一个字符，需要减去
		if (currentValue < prevValue) {
			result -= currentValue;
		}
		// 否则，加上当前字符代表的数字
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



//唯一数之和
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
/// 将数组划分成相等数对
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
/// 判断句子是否为全字母句
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
/// 好数对的个数
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
/// 差的绝对值为 K 的数对数目
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
/// 和相同的二元子数组
/// </summary>
/// 方法一---哈希表前缀和
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
		//如果前缀和中已经有 prefixSum - goal，说明当前位置到前一个位置的子数组和为 goal
		if (map.find(presum - goal) != map.end()) 
		{
		count += map[presum - goal];
		}
		// 更新前缀和计数
		map[presum]++;
	}
	return count;
}

//滑动窗口解法
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
//	cout << "具有和为 " << goal << " 的非空子数组数量为：" << result << endl;
//
//	return 0;
//}



/// <summary>
/// 三数之和
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



/// <summary>
/// 字母异位数
/// </summary>
/// 只使用一个简单的<char,int>哈希表的话，不能判断一个字符串组中的异位数
/// 让每个键对应由该键组成的所有字母异位数，此时，key为string,而value为vector<value>
/// 只需把每个将要遍历的字符串赋值给key，之后排序，即可找到对应关系
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>>ans;
	unordered_map<string, vector<string>>map;
	for (auto str:strs){
		string key = str;
		sort(key.begin(), key.end());
		map[key].emplace_back(str);
	
	}		
	for (auto it = map.begin(); it != map.end(); ++it)
	{
			ans.emplace_back(it->second);
	}
	return ans;

}



//int main() {
//	vector<string> input = { "eat", "tea", "tan", "ate", "nat", "bat" };
//	vector<vector<string>> groupedAnagrams = groupAnagrams(input);
//
//	// Print the grouped anagrams
//	for (const vector<string>& group : groupedAnagrams) {
//		for (const string& word : group) {
//			cout << word << " ";
//		}
//		cout << endl;
//	}
//
//	return 0;
//}


///先介绍一下和哈希表相似的set的基本用法
///set是是C++标准库中的一种无序集合，用于存储唯一的元素
void unorder_set_basic() {

	unordered_set<int> myHashSet;

	// 插入元素
	myHashSet.insert(10);
	myHashSet.insert(5);
	myHashSet.insert(8);
	myHashSet.insert(12);

	// 查找元素并输出
	int searchValue = 8;
	std::unordered_set<int>::iterator it = myHashSet.find(searchValue);
	if (it != myHashSet.end()) {
		std::cout << "元素 " << searchValue << " 存在于集合中。" << std::endl;
	}
	else {
		std::cout << "元素 " << searchValue << " 不存在于集合中。" << std::endl;
	}

	// 删除元素
	myHashSet.erase(5);

	// 遍历集合并输出
	std::cout << "集合中的元素：";
	for (const int& value : myHashSet) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

	// 检查集合是否为空
	if (myHashSet.empty()) {
		std::cout << "集合为空。" << std::endl;
	}
	else {
		std::cout << "集合不为空，大小为：" << myHashSet.size() << std::endl;
	}

	// 使用 count 检查元素是否存在
	int elementToCheck = 3;
	if (myHashSet.count(elementToCheck) == 1) {
		std::cout << elementToCheck << " 存在于集合中。" << std::endl;
	}
	else {
		std::cout << elementToCheck << " 不存在于集合中。" << std::endl;
	}


}

/// <summary>
/// 最长连续序列
/// </summary>
int longestConsecutive(vector<int>& nums) {
	unordered_set<int>set;
	for (auto& num : nums)
		set.insert(num);

	int longestStreak = 0;

	for (auto& num : nums) {

		if (!set.count(num - 1))
		{
			int currentNum = num;
			int currentStreak = 1;

			while (set.count(currentNum + 1))
			{
				currentNum += 1;
				currentStreak += 1;
			}
		}
		longestStreak = max(longestStreak, currentStreak);
		
	}
	return longestStreak;

}



bool isValid(string s) {
	std::stack<char> stack;
	std::unordered_map<char, char> mapping = { {')', '('}, {']', '['}, {'}', '{'} };
	for (auto c : s) {
		if (mapping.count(c))
		{
			char topElement = stack.empty() ? '#' : stack.top();
			if (topElement != mapping[c]) {
				return false;
			}
			stack.pop();
		}
		else
			stack.push(c);
	
	}
	return stack.empty();
		

}