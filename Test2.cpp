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

void solve(vector<int>&nums1, vector<int>&nums2){


	int n1 = nums1.size();
	int n2 = nums2.size();


	int j = n2-1;

	while(j>=0){

		if(nums1[n1-1] > nums2[j]){
			swap(nums1[n1-1], nums2[j]);
			int i = n1-1;
			while(i>0 && nums1[i-1]>nums1[i]){
				swap(nums1[i-1], nums1[i]);
				i--;
			}
		}else{
			j--;
		}
	}

	return;
}



int main()
{

	vector<int> nums1 = {1, 9, 9, 10, 15, 15};

	vector<int> nums2 = {2, 3, 3, 13};

	solve(nums1, nums2);

	deb(nums1);
	cout<<endl;
	deb(nums2);




	return 0;
}