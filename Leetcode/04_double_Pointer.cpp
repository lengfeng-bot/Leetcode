
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;






/// <summary>
/// һ��ѭ��������
/// </summary>


/// <summary>
/// 1.ɾ�����������е��ظ���---��򵥵Ŀ���ָ�룡
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
/// �������������
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
/// ɾ�����������е��ظ��� II
/// </summary>

int removeDuplicates2(vector<int>& nums) {
    int slow = 2;
    if (nums.size() <= 2)  return nums.size();
    for (int fast = 2; fast < nums.size(); fast++)
    {
        if (nums[fast] != nums[slow - 2])  //��slow����fast
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
/// ��ɫ����
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
/// �����еĵ� K �����Ԫ��--��������
/// </summary>
int findKthLargest(vector<int>& nums, int k) {
    return 0;
}



/// <summary>
/// ˫ָ��----�������ƶ�����������
/// </summary>
/// 
/// 
/// <summary>
/// ʢˮ��������
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


///˫ָ���ѧϰ֮�þ͵���ɣ���������һЩ�й�˫ָ�����ϰ�⣬Ҳ���ſ������Ժ����һ�°ɡ�����
/// 
/// ϰ��ѵ��
/// 
/// ��ӽ�������֮��
/// ����֮��
/// ��С������֮��
/// ����ת������
/// �ȽϺ��˸���ַ���
/// �����е��ɽ��
/// ����ͧ
/// ��������
/// ���������ƽ��
/// С�� K ������֮��
/// ���Ż����ճ�
/// 


/// <summary>
/// ����֮��
/// </summary>
/// ����������֮�ͣ�
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

