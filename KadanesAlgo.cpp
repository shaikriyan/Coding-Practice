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

	 // TODO : get the index range of the subarray...


	int n = nums.size();

	long long curr_sum = 0;
	long long final_sum = 0;
	bool allNeg = true;
	int maxi = INT_MIN;
	int maxi_ind = -1;

	int start_ind = 0;
	int end_ind = 0;

	for(int i=0;i<n;i++){
		
		if(maxi < nums[i]){
			maxi = nums[i];
			maxi_ind = i;
		}

		if(nums[i] > 0) allNeg = false;

		curr_sum += nums[i];
		if(curr_sum<0){
			curr_sum = 0;
			start_ind = i + 1;	
		} 
		if(curr_sum >= final_sum){
			end_ind = i;
			final_sum = curr_sum;
		} 
	} 



	if(allNeg){
		start_ind = maxi_ind;
		end_ind = maxi_ind;
	}

	deb(start_ind);
	deb(end_ind);

	for(int i=start_ind; i<end_ind+1; i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;



	return (allNeg) ? maxi : final_sum;
}



int main()
{

	vector<int>nums = {-2,-3,4,-1,-2,1,5,-3};
	// vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
	// vector<int>nums = {-2, 0, -1};
	int ans = solve(nums);
	deb(ans);
	return 0;
}