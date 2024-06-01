#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}

template<typename T>
void print(vector<T> v){
	cout<<"[ ";
	for(int i=0;i<v.size();i++){
		print(v[i]);
		cout<<" ";
	}
	cout<<"]";
}


int binarySearch(vector<int> &nums, int target){

	//if targeted number is found return it's index
	// else return -1;

	int ans = -1;

	int low = 0;
	int high = nums.size()-1;

	while(low<=high){
	int mid = low + (high-low)/2;
	if(nums[mid]==target) return mid;
	else if(nums[mid]>target) high = mid-1;
	else if (nums[mid]<target) low = mid+1;
	}

	return ans;

}


int myLowerBound(vector<int>&nums, int target){

	int low = 0;
	int high = nums.size()-1;

	while(low<=high){
		int mid = low + (high-low)/2;

		if(nums[mid]==target) high = mid-1;
		else if(nums[mid]>target) high = mid-1;
		else if(nums[mid]<target) low = mid+1;
	}

	return low;


}


int main()
{
	

	// for Binary search the data must be in sorted order.

	// vector<int>nums = {1,2,3,4,5,6,7,8};





	// cout<<binarySearch(nums, 4)<<endl;
	// cout<<binarySearch(nums, 14)<<endl;


	vector<int>nums = {1,2,2,3,3,3,4,6,8};
	cout<<"size : "<<nums.size()<<endl;

	// ans = 3
	cout<<myLowerBound(nums, 3)<<endl;

	//ans = 7
	cout<<myLowerBound(nums, 5)<<endl;

	//ans = 0
	cout<<myLowerBound(nums, 1)<<endl;

	//ans = -1 (there is not element which is equal to or greater than)
	// in this case lowerbound is gonna point to end.
	cout<<myLowerBound(nums, 14)<<endl;



	return 0;
}