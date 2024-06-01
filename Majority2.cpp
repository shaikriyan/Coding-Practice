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

vector<int> solve(vector<int>&nums){

	int n = nums.size();

	int x = n/3;

	set<int> ans;

	// num, count
	unordered_map<int,int>umap;


	for(int i=0;i<n;i++){
		umap[nums[i]]++;
		if(umap[nums[i]]>x) ans.insert(nums[i]);
	}

	return vector<int>(st.begin(), st.end());


}



int main()
{	

	vector<int> nums = {1,2};

	vector<int> ans = solve(nums);

	deb(ans);


	return 0;
}