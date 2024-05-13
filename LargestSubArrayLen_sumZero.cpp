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

int solve(vector<int>&nums, int n){

	// prefixsum, ind
	unordered_map<int, int>umap;

	int sum = 0;
	int ans = INT_MIN;

	for(int i=0;i<n;i++){
		sum += nums[i];
		if(umap.find(sum)!=umap.end()){
			int prevInd = umap[sum];
			ans = max(ans, i-prevInd);
		}else{
			umap[sum] = i;
		}
	}

	return ans;

}


int main()
{

	vector<int> nums = {15,-2,2,-8,1,7,10,23};
	int n = nums.size();

	int ans = solve(nums, n);
	deb(ans);

	return 0;
}