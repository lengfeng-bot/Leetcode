#include<iostream>
#include<vector>
using namespace std;





/// <summary>
/// ���ó˷�ʵ���������
/// </summary>
int multiply(int A, int B) {
	if (B == 0) return 0;

	return A+multiply(A, B-1);
}


/// <summary>
/// �绰�������ĸ���
/// </summary>
vector<string> letterCombinations(string digits) {
	vector<string>ans;
	return ans;
}