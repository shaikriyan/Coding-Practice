#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" = "; print(x); cout<<endl;

template<class T> void print(T a){ cout<<a;}
template<typename T, typename V> void print(pair<T,V> pr){ cout<<"{ "; print(pr.first); cout<<" : "; print(pr.second); cout<<" },"; }
template<typename T> void print(vector<T> v){ cout<<"[ "; for(auto it : v){ print(it); cout<<" "; } cout<<"]"; }
template<typename T> void print(set<T> v){ cout<<"[ "; for(auto it :v){ print(it);cout<<" "; } cout<<"]"; }
template<typename K, typename V> void print(unordered_map<K, V> umap){ cout<<"{ "; for(auto it : umap){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename K, typename V> void print(map<K, V> mp){ cout<<"{ "; for(auto it : mp){ cout<<"{ "; print(it); cout<<" }, "; } cout<<"}"; }
template<typename T> void print(stack<T> st){ cout<<"[ "; while(!st.empty()){ print(st.top());cout<<" "; st.pop(); } cout<<"]"; }



void selectionSort(vector<int>&nums){
	int n = nums.size();
	for(int i=0;i<n;i++){

		int tmp = nums[i];
		int ind = i;

		for(int j=i+1;j<n;j++){
			if(nums[j] < tmp){
				tmp = nums[j];
				ind = j;
			}
		}	

		swap(nums[ind], nums[i]);
	}
}

void bubbleSort(vector<int>&nums){
	int n = nums.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
		}
	}
	return;
}

void insertionSort(vector<int>&nums){

	int n = nums.size();
	for(int i=0;i<n-1;i++){

		int j = i+1;
		int tmp = nums[j];
		while(j>0 && nums[j-1] > tmp){
			nums[j] = nums[j-1];
			j--;
		}
		nums[j] = tmp;
	}
}




int qsort(vector<int>&nums, int low, int high){

	int mid = low + (high-low)/2;
	int pivot = nums[mid];

	int i=low, j = high;
	int pp = mid; // pivot position
	while(i<=j){
		if(nums[i]<=pivot){
			if(nums[i]==pivot) pp = i;
			i++;	
		}
		else if(nums[j] > pivot) j--;
		else swap(nums[i], nums[j]); 
	}

	swap(nums[j], nums[pp]);
	return j;

}



void QuickSort(vector<int>&nums, int start, int end){

	if(start >= end) return;

	int pInd = qsort(nums, start, end);
	QuickSort(nums, start, pInd-1);
	QuickSort(nums, pInd+1, end);

	return ;
}

void merge(vector<int>&nums, int s, int mid, int e){

	int i = s, n = mid+1;
	int j = mid+1, m = e+1;

	int temp[e-s+1];
	int c=0;
    
	while(i<n && j<m){
		if(nums[i] < nums[j]) temp[c++] = nums[i++];
		else temp[c++] = nums[j++];
	}

	while(i<n) temp[c++] = nums[i++];
	while(j<m) temp[c++] = nums[j++];
    
	for(int k=0;k<(e-s+1);k++){
		nums[s + k] = temp[k];
	}

	return;

}



void MergeSort(vector<int>&nums, int s, int e){

	if(s>=e) return; // if there is only one element or no element 
	int mid = s + (e-s)/2;

	MergeSort(nums, s, mid);
	MergeSort(nums, mid+1, e);
	merge(nums, s, mid, e);

	return;
}




int main()
{

	// vector<int> nums = {4, 1, 3, 9, 7};
	vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	// vector<int> nums = {14, 5, 8, 3, 17, 11, 6};
	// selectionSort(nums);
	// bubbleSort(nums);
	// insertionSort(nums);
	// QuickSort(nums, 0, nums.size()-1);
	MergeSort(nums, 0, nums.size()-1);


	deb(nums);

	return 0;
}