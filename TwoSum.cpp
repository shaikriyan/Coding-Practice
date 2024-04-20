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


vector<int> solve(vector<int>&nums, int target){

	// nums[i], i
	unordered_map<int , int>mp;

	for(int i=0;i<nums.size();i++){

		if(mp.find(target-nums[i])!=mp.end()){
			return {mp[target-nums[i]], i};
		}
		mp[nums[i]] = i;
	}

	return {-1,-1};



}



int main()
{
	vector<int>nums = {2,7,11,15};
	int target = 9;


	vector<int> ans  = solve(nums, target);

	cout<<ans[0]<<" "<<ans[1]<<endl;

	return 0;
}