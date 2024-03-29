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


    string tmp;
    vector<string> board = { "", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> ans;

    void dfs(int pos, string digits) {
        if (pos == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        int num = digits[pos] - '0'; //表示按到了键盘上的第几个键
        for (int i = 0; i < board[num].size(); i++) {
            tmp.push_back(board[num][i]);
            dfs(pos + 1, digits);  //递归下一层
            tmp.pop_back();      //回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        dfs(0, digits);
        return ans;
    }

//int main() {
//	string d = "23";
//	vector<string> ans = letterCombinations(d);
//    for (auto a : ans) cout << a << " ";
//	return 0;
//}