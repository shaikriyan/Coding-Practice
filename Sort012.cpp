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

void solve(vector<int>&nums){

	// Make sure to check , all edge cases... 
	// like 
	// 1. if only {0, 0, 0, 0} are given
	// 2. if only {1,1,1,1} are given
	// 3. if only {2,2,2} are given
	// 4. if Only {1,1,1,0,0,} are given


	int n = nums.size();

	int i=0, j=0, k= n-1;

	while(j<=k){
		if(nums[j]==0){
			swap(nums[i++], nums[j]);
			if(i>j) j=i;	
		} 
		else if(nums[j]==2) swap(nums[k--], nums[j]);
		else j++;
	}

	return;
}



int main()
{
	vector<int>nums = {2,0,2,1,1,0};
	solve(nums);

	deb(nums);

	return 0;
}