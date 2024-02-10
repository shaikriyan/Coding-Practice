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

// In Selection sort, we will select the least element one by one 
// place it in the begining...sort it.

void selectionSort(vector<int>&v){
	int n = v.size();

	for(int i=0;i<n;i++){
		int ind = -1, mini = INT_MAX;
		for(int j=i;j<n;j++){
			if(v[j]<mini){
				mini = v[j];
				ind = j;
			}
		}
		swap(v[i], v[ind]);
	}

	return;
}


int main()
{
	// vector<int>v = {5,4,1,3,2};
	vector<int>v = {0, 23,234, -123, 534,34,245,34,664,74,56,4};
	
	int n = v.size();

	selectionSort(v);

	for(auto it : v){
		cout<<it<<" ";
	}cout<<endl;

	return 0;
}