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

void solve(vector<int> &nums){

	int n = nums.size();

	int i= n-1;

	int ind = -1;

	while(i>=0){
		if(nums[i-1] < nums[i]){
			ind = i;
			break;
		}
		i--;
	}

	i = ind;

	while(i>=0){
		if(nums[i] < nums[ind]){
			swap(nums[i], nums[ind]);
			break;
		}
		i--;
	}

	if(ind>0)
		sort(nums.begin()+ind, nums.end());
	else{
		reverse(nums.begin(), nums.end());
	}


	return;

}







int main()
{

	// vector<int> nums = {1,2,3};
	vector<int> nums = {1,3,2};
	// vector<int> nums = {1,1,5};

	solve(nums);
	deb(nums);

	return 0;
}