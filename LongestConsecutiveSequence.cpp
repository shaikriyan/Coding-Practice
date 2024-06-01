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

int solve(vector<int>&nums){

	int n = nums.size();
	if(n==0) return n;
	int len = 0;
	int ans = INT_MIN;

	sort(nums.begin(), nums.end());
	deb(nums);

	for(int i=0;i<n-1;i++){

		if(nums[i] == nums[i+1]) continue;

		if(abs(nums[i]-nums[i+1])==1){
			len++;
			ans = max(ans, len);
		}else{
			len = 0;
		} 
	}

	return ans + 1;

}



int main()
{

	// vector<int> nums = {100,4,200,1,3,2};
	// vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
	vector<int> nums = {1,2,0,1};
	int ans = solve(nums);
	deb(ans);

	return 0;
}