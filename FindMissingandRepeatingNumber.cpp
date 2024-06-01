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

vector<int> solve(vector<int>&nums, int n){


	vector<int>hash(n+1, 0);


	int repeatingNumber = -1;
	int missingNumber = -1;


	for(int i=0;i<n;i++){
		hash[nums[i]]++;

		if(hash[nums[i]]>1){
			repeatingNumber = nums[i];
		} 
	}

	deb(hash);

	for(int i=1;i<n+1;i++){
		if(hash[i]==0){
			missingNumber = i;
			break;
		}
	}

	return {repeatingNumber, missingNumber};


}




int main()
{

	vector<int> nums = {21 ,12 ,20 ,17 ,15 ,36 ,22 ,6 ,29 ,3 ,4 ,34 ,5 ,1 ,23 ,32 ,14 ,31 ,25 ,18 ,19 ,39 ,19 ,13 ,8 ,9 ,7 ,37 ,11 ,27 ,33 ,24 ,2 ,26 ,35 ,38 ,10 ,16 ,28};
	int n = nums.size();
	deb(n);

	vector<int> ans = solve(nums, n);
	deb(ans);

	return 0;
}