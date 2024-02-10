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

// we will need to segregate the elements on the basic of pivotElement
int getPivotIndexInOurRange(int s, int e, int intialPivotIndex, vector<int>&v){

	int i = s;
	int j = e;
	int pivotElement = v[intialPivotIndex];

	while(i<=j){
		if(v[i]<=pivotElement){
			i++;
		}else if(v[j]>pivotElement){
			j--;
		}else{
			swap(v[i++], v[j--]);
		}
	}

	// at one point of time j = i+1;
	swap(v[j], v[intialPivotIndex]);

	return j;
}


// choose a pivot element, It can be anything i.e. 1st element, last element, mid element
// find the pivotIndex
// perform the quicksort for {s,  pivotIndex-1} && {pivotIndex+1, e};
void QuickSort(int s, int e, vector<int>&v){

	if(s>=e) return;

	// int pivotElement = v[s];
	int intialPivotIndex = s;
	int pivotIndex = getPivotIndexInOurRange(s,e,intialPivotIndex, v);

	QuickSort(s, pivotIndex-1, v);
	QuickSort(pivotIndex+1, e, v);
	return;

}



int main()
{
	
	// vector<int>v = {5, 4, 1, 3, 2};
	vector<int>v = {0, 23,234, -123, 534,34,245,34,664,74,56,4};
	int n = v.size();

	QuickSort(0, n-1, v);

	for(auto it : v){
		cout<<it<<" ";
	}cout<<endl;

	return 0;
}