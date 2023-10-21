#include<iostream>
#include<vector>
using namespace std;





/// <summary>
/// 不用乘法实现两数相乘
/// </summary>
int multiply(int A, int B) {
	if (B == 0) return 0;

	return A+multiply(A, B-1);
}


/// <summary>
/// 电话号码的字母组合
/// </summary>
vector<string> letterCombinations(string digits) {
	vector<string>ans;
	return ans;
}