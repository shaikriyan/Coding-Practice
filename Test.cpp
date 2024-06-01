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

bool solve(vector<int>&nums){

	int n = nums.size();

	int start_ind = -1;
	int mini = INT_MAX;
	for(int k=0;k<n;k++){
		if(mini > nums[k]){
			mini = nums[k];
			start_ind = k;
		}
	}

	deb(start_ind);

	int i = start_ind + 1;
	while(true){

		if(i==start_ind){
			break;
		}

		if(i>= n) i = i%n;

		if(i==0){
			return (nums[0] > nums[n-1]);
		}
		else if(nums[i-1]>nums[i]) return false;

		i++;
	}

	return true;

}

int main()
{
	vector<int>nums = {1,2,3};

	bool ans = solve(nums);
	

	deb(ans);


	return 0;
}