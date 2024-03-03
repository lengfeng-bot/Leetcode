
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;






/// <summary>
/// 一、循环不变量
/// </summary>


/// <summary>
/// 1.删除有序数组中的重复项---最简单的快慢指针！
/// </summary>
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];

        }
    }
    return j + 1;
}

/// <summary>
/// 最长连续递增数列
/// </summary>
int findLengthOfLCIS(vector<int>& nums) {
    int l = 0;
    int len = 0;
    for (int r = 1; r < nums.size(); r++)
    {   
        if (nums[r] <= nums[r-1]) 
        {   
        l = r ;
       
        }
        int prelen = r - l+1;
        len = max(len, prelen);
    }

    return len;
}



//int main()
//{
//    vector<int>nums = {1,3,5,7 };
//    int a = findLengthOfLCIS(nums);
//    cout << a << endl;
//    return 0;
//}


/// <summary>
/// 删除排序数组中的重复项 II
/// </summary>

int removeDuplicates2(vector<int>& nums) {
    int slow = 2;
    if (nums.size() <= 2)  return nums.size();
    for (int fast = 2; fast < nums.size(); fast++)
    {
        if (nums[fast] != nums[slow - 2])  //是slow不是fast
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}


//int main()
//{
//    vector<int>nums = { 1,1,1,2,2,3 };
//    int a = removeDuplicates2(nums);
//    cout << a << endl;
//    return 0;
//}


/// <summary>
/// 颜色分类
/// </summary>
/// <param name="nums"></param>
void sortColors(vector<int>& nums) {
    int l = 0;
    int r = nums.size();
    int i = 0;
    while (i<=r)
    {
        if (nums[i] == 2)
        {
            int tmp = nums[i];
            nums[i] = nums[r];
            nums[r] = tmp;
            r--;
        }
        else if (nums[i] == 0)
        {
            int tmp = nums[i];
            nums[i] = nums[l];
            nums[l] = tmp;
            l++;
        }
        else
            i++;
    }
}


/// <summary>
/// 数组中的第 K 个最大元素--快速排序
/// </summary>
int findKthLargest(vector<int>& nums, int k) {
    return 0;
}



/// <summary>
/// 双指针----相向交替移动的两个变量
/// </summary>
/// 
/// 
/// <summary>
/// 盛水最多的容器
/// </summary>

int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0;
    int j = n - 1;
    int maxarea = 0;
    while (i<j)
    {   
        int area = min(height[j], height[i]) * (j - i);
        if (height[i] > height[j])
            j--;
        else
            i++;
        maxarea = max(maxarea, area);
        
    }
    return maxarea;
}


///双指针的学习之旅就到这吧！接下来是一些有关双指针的练习题，也许大概可能我以后会做一下吧。。。
/// 
/// 习题训练
/// 
/// 最接近的三数之和
/// 四数之和
/// 较小的三数之和
/// 有序转化数组
/// 比较含退格的字符串
/// 数组中的最长山脉
/// 救生艇
/// 长按键入
/// 有序数组的平方
/// 小于 K 的两数之和
/// 安排会议日程
/// 


/// <summary>
/// 四数之和
/// </summary>
/// 先来个四数之和！
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int> > res;
    if (n < 4)
        return res;

    int l = 0;
    int r = n - 1;
    int sum = 0;
    
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        continue;
        if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)break;
        {

        }
        for (int j = i+1; j < n-2; j++)
        {

        }
    }
    return res;
}

