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

	int curr = 1;
	int ans = INT_MIN;
	
	for(int i=0;i<n;i++){

		curr *= nums[i];
		ans = max(ans, curr);
		if(curr==0) curr=1;



	}

	curr =1;

	for(int i=n-1;i>=0;i--){
		curr*=nums[i];
		ans = max(ans, curr);
		if(curr==0) curr=1;

	}

	return ans;


}





int main()
{

	// vector<int> nums = {4,2, 0, -6, -2, 8, 5, -8, 0, 2};
	vector<int> nums = {-2,0,-1};

	int ans = solve(nums);
	deb(ans);



	return 0;
}