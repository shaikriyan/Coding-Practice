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

void Merge(int s, int mid, int e, vector<int>&v){
	int n1 = mid+1;
	int n2 = e+1;

	int i = s;
	int j = mid+1;


	vector<int> temp;

	while(i<n1 && j<n2){
		if(v[i]<=v[j]) temp.push_back(v[i++]);
		else temp.push_back(v[j++]);
	}

	while(i<n1){
		temp.push_back(v[i++]);
	}
	while(j<n2){
		temp.push_back(v[j++]);
	}

	for(int i=s;i<e+1;i++){
		v[i] = temp[i-s];
	}
	return;
}

void MergeSort(int l, int r, vector<int>&v){

	if(l==r) return;

	int mid = l + (r-l)/2;
	MergeSort(l, mid, v);
	MergeSort(mid+1, r, v);

	Merge(l, mid, r, v);
	return;
}


int main()
{
	vector<int>v = {23,234,534,34,245,34,664,74,56,4};
	int n = v.size();


	MergeSort(0, n-1, v);

	for(auto it : v){
		cout<<it<<" ";
	}cout<<endl;

	return 0;
}