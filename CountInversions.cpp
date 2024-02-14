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

int countInversion(int s, int mid, int e, vector<int>&arr){

	int i = s;
	int n1 = mid+1;

	int j = mid+1;
	int n2 = e+1;

	int count = 0;

	while(i<n1 && j<n2){
		if(arr[i]<=arr[j]){
			i++;
		}
		else if(arr[i]> arr[j]){
			j++;
			count++;
		}
	}

	return count;

}


int MergeSort(int s, int e, vector<int>&arr){

	if(s==e) return 0;

	int mid = s + (e-s)/2;
	int left = MergeSort(s, mid, arr);
	int right = MergeSort(mid+1, e, arr);


	return countInversion(s, mid, e, arr) + left + right;




}


int main()
{
	
	vector<int>arr = {2, 4, 1, 3, 5};

	cout<<MergeSort(0, arr.size()-1, arr)<<endl;
	return 0;
}