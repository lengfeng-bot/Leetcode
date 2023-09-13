

#include <iostream>
#include<vector>
#include<string>


using namespace std;


/// <summary>
/// 反转每个单词
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
string reverseWords(string s) {
    int l = 0, r;
    char temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i + 1] == ' ' || i + 1 == s.size()) {//判断当前位置的下一位是否为空格，或者是不是最后一位
            r = i;
            while (r > l) {         //s[r]和s[l]交换,r代表这个单词的最后一位，l代表第一位
                temp = s[r];   
                s[r] = s[l];
                s[l] = temp;
                r--;
                l++;
            }
            l = i + 2;
        }
    }
    return s;

}

/// <summary>
/// 二分法
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int findMin(vector<int>& nums) {
    int len = nums.size();
    int right = len - 1;
    int left = 0;
    
    while (left<right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
            right = mid ;

    }

    return nums[left];

}



void moveZeroes(vector<int>& nums) {
    int len = nums.size();

    int slow = 0;
    int fast = 0;
    int temp;
    for (int fast = 0; fast < len; fast++)
    {
        if (nums[fast] != 0)
        {
            nums[slow++] = nums[fast];
        }
    }

    while (slow < len) 
    {
        nums[slow++] = 0;
    }


}







//int main()
//{
//    vector<int>nums = { 4, 5, 6, 7, 0, 1, 2 };
//    moveZeroes(nums);
//    for (int i = 0; i < nums.size(); i++)
//    {
//        cout << nums[i] << endl;
//    }
//    cout << "Hello World!\n";
//}


