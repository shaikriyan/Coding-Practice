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

	int ans = nums[0];
	int cnt = 0;

	for(int i=0;i<n;i++){

		if(cnt==0) ans = nums[i];

		if(ans==nums[i]) cnt++;
		else cnt--;
	}

	return ans;

}



int main()
{

	vector<int> nums = {2,2,1,1,1,2,2};
	int ans = solve(nums);
	deb(ans);

	return 0;
}