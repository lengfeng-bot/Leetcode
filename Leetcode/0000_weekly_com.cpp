#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#include<unordered_map>
#include<unordered_set>
#include <stack>
#include <queue>

using namespace std;



/// <summary>
/// 3.17
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool isSubstringPresent(string s) {

	if (s.size() <= 1) return false;
	string s2 = s;
	reverse(s2.begin(), s2.end());
	for (int i = 0; i < s.size()-1; i++)
	{
		string str2 = s.substr(i, 2);
		for (int j = 0; j < s.size()-1; j++)
		{
			string str3 = s2.substr(j, 2);
			if (str2 == str3) return true;
		}
	}
	return false;
}




long long countSubstrings(string s, char c) {
	int count = 0;
	for (auto m : s) if (m == c) count++;


	return (count * (count + 1)) / 2;;

}

/// <summary>
/// 成为K特殊字符串需要删除的最少字符数
/// </summary>
/// 真难，自己写不出来，，，哎
int minimumDeletions(string word, int k) {
	unordered_map<char, int>map;
	for (auto w : word) map[w]++;
	vector<int>nums;
	for (auto it = map.begin(); it != map.end(); it++) {
		nums.push_back(it->second);
	}
	sort(nums.begin(), nums.end(), greater<int>());
	for (auto num : nums)cout << num << " ";
	cout << endl;
	int ans = 0;

	while (nums.front() - nums.back() > k)
	{
		if (nums.size() == 1)  break;
		if(nums.at(1) == nums.back())
			if(nums.front() - nums.back() >= nums.back())
			{ans += nums.back();
				nums.pop_back();}
			else
			{
				nums.front()--;
				ans++;
			}
				


			
		else if (nums.at(1) - nums.back() > k) {
			ans += nums.back();
			nums.pop_back();
		}
		else {
				nums.front()--;
				ans++;
		}

		
	}

	return ans;
}




//int main() {
//	//string s = "cowlsc";
//	//bool ans = isSubstringPresent(s);
//	//long long ans = countSubstrings("zzz", 'z');
//	//cout << ans;
//	int ans = minimumDeletions("aaaaaabbbbc", 1);
//	cout << ans;
//	return 0;
//
//}

