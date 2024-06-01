#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}
template<typename T, typename V> void print(pair<T,V> pr){ cout<<"{ "; print(pr.first); cout<<" : "; print(pr.second); cout<<" },"; }
template<typename T> void print(vector<T> v){ cout<<"[ "; for(auto it : v){ print(it); cout<<" "; } cout<<"]"; }
template<typename T> void print(set<T> v){ cout<<"[ "; for(auto it :v){ print(it);cout<<" "; } cout<<"]"; }
template<typename K, typename V> void print(unordered_map<K, V> umap){ cout<<"{ "; for(auto it : umap){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename K, typename V> void print(map<K, V> mp){ cout<<"{ "; for(auto it : mp){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename T> void print(stack<T> st){ cout<<"[ "; while(!st.empty()){ print(st.top());cout<<" "; st.pop(); } cout<<"]"; }

// int search(vector<int>&nums, int target){

// 	int n = nums.size();
// 	int low = 0;
// 	int high = n-1;
// 	while(low<=high){
// 		int mid = low + (high-low)/2;
// 		if(nums[mid]==target) return mid;
// 		else if(nums[mid]>target) high = mid-1;
// 		else if(nums[mid]<target) low = mid+1;
// 	}
// 	return -1;
// } 


int firstOccurance(vector<int>&nums, int target){

	int n = nums.size();
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]>=target){
			ans = mid;
			high = mid-1;
		}
		else if(nums[mid]<target) low = mid+1;
	}
	return (ans==-1) ? n : ans;
} 

int lastOccurance(vector<int>&nums, int target){

	int n = nums.size();
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]==target){
			ans = mid;
			low = mid+1;
		}
		else if(nums[mid]>target) high = mid-1;
		else if(nums[mid]<target) low = mid+1;
	}
	return ans;
} 


int getFloor(vector<int>&nums, int n, int x){
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]<=x){
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}
	return (ans!=-1) ? nums[ans] : ans;
}

int getCeil(vector<int>&nums, int n, int x){
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]>=x){
			ans = mid;
			high = mid-1;
		}
		else low = mid+1;
	}
	return (ans!=-1) ? nums[ans] : ans;
}


pair<int,int> getFloorAndCeil(vector<int>&nums, int n, int x){
	sort(nums.begin(), nums.end());
	int floor = getFloor(nums, n, x);
	int ceil = getCeil(nums, n, x);
	return {floor, ceil};

}


int binarySearch(vector<int>&nums, int s, int e, int target){
	int low = s;
	int high = e;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]==target) return mid;
		else if(nums[mid]>target) high = mid-1;
		else if(nums[mid]<target) low = mid+1;
	}
	return -1;
}

int binarySearchII(vector<int>&nums, int s, int e, int target){
	int low = s;
	int high = e;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]==target) return mid;
		else if(nums[mid]==nums[high] && mid!=high) high--;
		else if(nums[mid]>target) high = mid-1;
		else if(nums[mid]<target) low = mid+1;
	}
	return -1;
}


int findMin(vector<int>& nums){
	int n = nums.size();
	int low = 0;
	int high = n-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid] < nums[high]) high = mid;
		else low = mid+1;
	}
	return high;
}


int findMinII(vector<int>& nums){
	int n = nums.size();
	int low = 0;
	int high = n-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid] == nums[high] && mid!=high) high--;
		else if(nums[mid] < nums[high]) high = mid;
		else low = mid+1;
	}
	return high;
}

int search(vector<int>&nums, int target){
	int ind = findMin(nums);
	int n = nums.size();

	int ans = binarySearch(nums, 0, ind-1, target);
	if(ans!=-1) return ans;
	return binarySearch(nums, ind, n-1, target);
}

int searchII(vector<int>&nums, int target){
	int ind = findMinII(nums);
	int n = nums.size();

	int ans = binarySearch(nums, 0, ind-1, target);
	if(ans!=-1) return true;
	return (binarySearch(nums, ind, n-1, target)!=-1);
}

int singleNonDuplicate(vector<int>&nums){

	int n = nums.size();
	if(n==1) return nums[0];
	if(nums[0]!=nums[1]) return nums[0];
	if(nums[n-1]!=nums[n-2]) return nums[n-1];

	int low = 1;
	int high = n-2;


	while(low<=high){
		int mid = low + (high-low)/2;

		if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];
		else{
			if(mid&1){
				cout<<"odd"<<endl;
				if(nums[mid-1] == nums[mid]) low = mid+1;
				else high = mid-1;
			}
			else{
				// mid is even
				if(nums[mid] == nums[mid+1]) low = mid+1;
				else high = mid-1;
			}
		}

	}
	return -1;

}


int findPeakElement(vector<int>& nums){

	int n = nums.size();
	if(n==1) return 0;

	if(nums[0] > nums[1]) return 0;
	if(nums[n-1] > nums[n-2]) return n-1;


	int low = 1;
	int high = n-2;

	while(low<=high){

		int mid = low + (high-low)/2;

		if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;
		else if(nums[mid-1] > nums[mid]) high = mid-1;
		else low = mid+1; // nums[mid] < nums[mid+1]

		// there might be the edge case 
		// nums[mid-1] > nums[mid] < nums[mid+1]  .. reverse peak scenario.
		// then also it will be covered via else scenario...

	}

	return -1;


}




int main()
{


	// vector<int> nums = {5, 6, 8, 9, 6, 5, 5, 6};
	// int target = 20;

	// pair<int,int> ans = getFloorAndCeil(nums, nums.size(), target);

	// deb(ans);

	// vector<int> nums = {3,4,5,1,2};
	// int ans = findMin(nums);
	// deb(ans);

	// vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
	// deb(nums.size());
	// int ans = findMinII(nums);
	// deb(ans);

	vector<int> nums = {3,3,7,7,10,11,11};
	int ans = singleNonDuplicate(nums);
	deb(ans);

	return 0;
}