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


int myUpperBound(vector<int>&nums, int target){

	int low = 0;
	int high = nums.size()-1;

	while(low<=high){

		int mid = low + (high-low)/2;
		if(nums[mid]<=target) low = mid+1;
		else if(nums[mid]>target) high = mid-1;

	}

	if(low==nums.size()) low = -1;
	return low;

}


int main()
{
	vector<int>nums = {1,2,2,3,3,3,4,6,8};
	cout<<"size : "<<nums.size()<<endl;


	cout<<myUpperBound(nums, 3)<<endl; // 6
	cout<<myUpperBound(nums, 5)<<endl; // 7
	cout<<myUpperBound(nums, 0)<<endl; // 0
	cout<<myUpperBound(nums, 11)<<endl; // -1




	return 0;
}