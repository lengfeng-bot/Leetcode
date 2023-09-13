#include <iostream>
#include<vector>
#include<string>


using namespace std;


//模板1
/// <summary>
/// 1.最简单的二分查找[left, right]
/// </summary>
int binarySearch1(vector<int>& nums, int target) {

	int len = nums.size();    
	int left = 0;
	int right = len - 1;             // [left, right]
	int mid = left + (right - left) / 2;
	while (left<=right)
	{
		if (nums[mid] == target)
			return mid;
		if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1 ;
		mid = left + (right - left) / 2;
	}

	return -1;
		
}





/// <summary>
/// 2.x的平方根
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
int mySqrt(int x) {
	if (x == 0) return 0;
	int left = 1;
	int right = x;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (mid <= x / mid && (mid + 1) > x / (mid + 1)) 
			{ return mid; }
		else if ((mid + 1) <= x / (mid + 1))
		 { left = mid + 1; }
		else if 
			(mid > x / mid) { right = mid - 1; }
	}
	return -1;



}


//int main() {
//
//	//vector<int>nums = { 1,2,3,4,5,6,7 };
//	//int tar = 0;
//	//int result = search(nums, tar);
//	//cout << result << endl;
//
//	int x = 8;
//	int result = mySqrt(x);
//	cout << result << endl;
//
//}




/// <summary>
/// 3. 搜索旋转排序数组(这个确实值得仔细，先使用二分法区分出哪边是递增区间，之后再继续使用二分法进行查找目标值)
/// </summary>

int searchplus(vector<int>& nums, int target) {

	int l = 0;
	int r = nums.size()-1;

	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] ==target)
			return mid;
		else if (nums[mid] >= nums[l]) {
			if (target == nums[mid])
				return mid;
			else if (target>= nums[l] && target< nums[mid])
				r = mid ;
			else 
				l = mid + 1;}

		else
		{
			if (target == nums[mid])
				return mid;
			else if (target > nums[mid] && target <= nums[r])
				l = mid + 1;
			else
				r = mid ;

		}

	}
	return -1;

}


//int main(){
//	vector<int>nums = {1};
//	int tar = 2;
//	int result = searchplus(nums, tar);
//	cout << result << endl;
//	return 0;
//	}







//模板二 用于查找需要访问数组中当前索引及其直接右邻居索引的元素或条件。
int binarySearch2(vector<int>& nums, int target) {
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size();  //注意！   // [left, right)
	while (left < right) {						//注意！
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) { return mid; }  //注意！
		else if (nums[mid] < target) { left = mid + 1; }
		else { right = mid; }
	}

	// Post-processing:
	// End Condition: left == right
	if (left != nums.size() && nums[left] == target) return left;
	return -1;
}




/// <summary>
/// 1.寻找峰值
/// </summary>
int findPeakElement(vector<int>& nums) {
	if (nums.size() == 1)return 0;

	int left = 0, right = nums.size()-1;  
	while (left < right) {						
		int mid = left + (right - left) / 2;
		if (nums[mid] >nums[mid+1]) { right = mid; }
		else if (nums[mid] < nums[mid+1]) { left = mid + 1; }
	}

	return left;

}


//int main(){
//	vector<int>nums = { 2,1 };
//	
//	int result = findPeakElement(nums);
//	cout << result << endl;
//	return 0;
//	}


/// <summary>
/// 2.寻找旋转排序数组中的最小值
/// </summary>
int findMin(vector<int>& nums) {
	if (nums.size() == 1)return 0;

	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[left] < nums[right]) { return nums[left]; }
		else  if (nums[mid] >= nums[left])left = mid + 1;
		else right = mid;
	}

	return nums[left];

}


//int main() {
//	vector<int>nums = { 2,1 };
//
//	int result = findMin(nums);
//	cout << result << endl;
//	return 0;
//}





/// <summary>
/// 模板三-用于搜索需要访问当前索引及其在数组中的直接左右邻居索引的元素或条件。
/// </summary>
int binarySearch3(vector<int>& nums, int target) {  
	if (nums.size() == 0)
		return -1;

	int left = 0, right = nums.size() - 1;     //// (left, right)
	while (left + 1 < right) {
		// Prevent (left + right) overflow
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	// Post-processing:
	// End Condition: left + 1 == right
	if (nums[left] == target) return left;
	if (nums[right] == target) return right;
	return -1;
}





/// <summary>
/// 1.在排序数组中查找元素的第一个和最后一个位置
/// </summary>
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> arr = { -1, -1 };

	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		int mid1 = mid;

		if (nums[mid] == target) {
			while (mid > 0 && nums[mid - 1] == nums[mid]) {
				mid--;
			}
			while (mid1 < nums.size() - 1 && nums[mid1 + 1] == nums[mid1]) {
				mid1++;
			}
			arr[0] = mid;
			arr[1] = mid1;
			return arr;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return arr;
}



//int main() {
//
//	vector<int>nums = { 2,2};
//	int tar = 2;
//	vector<int> result = searchRange(nums, tar);
//
//	cout << result[0]<<" "<<result[1] << endl;
//
//}




/// <summary>
/// 2.找到 K 个最接近的元素
/// </summary>
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
	vector<int>  a;
	int left = 0, right = arr.size() - k;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (x-arr[mid] > arr[mid + k] - x)left = mid + 1;    //选择区间[4,5,6]还是[3,4,5]的关键在在[3,4,5,6]中判断删掉3还是6，相当于这个区间为一个整体之后二分
		else right = mid;
	}
	for (int i = left; i < k+left; i++)
	{
		a.push_back(arr[i]);
	}
	return a;
}

//int main() {
//
//	vector<int>nums = { 1,1,1,10,10,10};
//	int k = 1;
//	int x = 9;
//	vector<int> result = findClosestElements(nums,k,x);
//
//	for (int i = 0; i < result.size(); i++)
//	{
//		cout <<result[i] << endl;
//	}
//	
//
//}



/// <summary>
/// 综合例题
/// </summary>
/// 1.x的n次方
/// 
double traval(double x, int n) {
	if (n == 0) {
		return 1;
	}
	double val = traval(x, n / 2);
	return n % 2 == 0 ? val * val : val * val * x;
}


double myPow(double x, int n) {
	if (n == 0) {
		return 1;
	}
	int N = n > 0 ? n : 0 - n;
	double val = traval(x, N);
	return n > 0 ? val : 1 / val;
}


/// <summary>
/// 2.寻找比目标字母大的最小字母
/// </summary>
char nextGreatestLetter(vector<char>& letters, char target) {

	int left = 0, right = letters.size()-1;  //注意！   // [left, right)

	while (left < right) {						//注意！
		int mid = left + (right - left) / 2;
		 if (letters[mid] > target)
				right = mid;

		else if (letters[mid] <= target) { left = mid + 1; }
		
	}
	if (target >= letters[letters.size() - 1]) return letters[0];
	return letters[left];

	//return letters[left] <= target ? letters[0] : letters[left];
}


//int main() {
//	vector<char> s = { 'c','f','j'};
//	char target = 'c';
//	char c = nextGreatestLetter(s,target);
//	cout << c << endl;
//
//
//}

/// <summary>
/// 寻找旋转排序数组中的最小值
/// </summary>