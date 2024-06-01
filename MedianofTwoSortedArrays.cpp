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

	int tempAns = 1;
	int finalAns = 1;

	int i=0;

	while(i<n){

		tempAns = tempAns * nums[i];

		if(tempAns ==0 || tempAns<0) tempAns = 1;

		if(finalAns < tempAns) finalAns = tempAns;

	}

	return finalAns;
}




int main()
{
	vector<int>nums = {2,3,-2,4};
	int ans = solve(nums);
	deb(ans);

	return 0;
}