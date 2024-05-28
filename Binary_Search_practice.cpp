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

int search(vector<int>&nums, int target){

	int n = nums.size();
	int low = 0;
	int high = n-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(nums[mid]==target) return mid;
		else if(nums[mid]>target) high = mid-1;
		else if(nums[mid]<target) low = mid+1;
	}
	return -1;
} 


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





int main()
{


	vector<int> nums = {5, 6, 8, 9, 6, 5, 5, 6};
	int target = 20;

	pair<int,int> ans = getFloorAndCeil(nums, nums.size(), target);

	deb(ans);





	return 0;
}