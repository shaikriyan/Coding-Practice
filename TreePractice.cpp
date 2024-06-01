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

class TreeNode{
	
	public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d, TreeNode* _left=nullptr, TreeNode* _right=nullptr){
		data = d;
		left = _left;
		right = _right;
	}

};

TreeNode* constructTree(int preStart, int preEnd, vector<int>&preorder,
						int inStart,  int inEnd,  vector<int>&inorder){

	if(preStart>preEnd || inStart>inEnd) return nullptr;

	int r = preorder[preStart];
	int rootIndex = -1;
	for(int i=inStart; i<=inEnd; i++){
		if(r==inorder[i]){
			rootIndex = i;
			break; 
		}
	}

	TreeNode* root = new TreeNode(r);

	int x = rootIndex - inStart; // no of left side elements

	root->left = constructTree(preStart+1, preStart+x, preorder, inStart, rootIndex-1, inorder);
	root->right = constructTree(preStart+x+1, preEnd, preorder, rootIndex+1, inEnd, inorder);	

	return root;

}

void preOrder(TreeNode* root , vector<int>&preorder){
	if(root==NULL) return;
	preorder.push_back(root->data);
	preOrder(root->left, preorder);
	preOrder(root->right, preorder);
}

void inOrder(TreeNode* root , vector<int>&inorder){
	if(root==NULL) return;
	inOrder(root->left, inorder);
	inorder.push_back(root->data);
	inOrder(root->right, inorder);
}

void postOrder(TreeNode* root , vector<int>&postorder){
	if(root==NULL) return;
	postOrder(root->left, postorder);
	postOrder(root->right, postorder);
	postorder.push_back(root->data);
}

int main()
{
	
	vector<int> inorder = {9,2,6,5,7,8,3};
	vector<int> preorder = {5,9,6,2,8,7,3};

	TreeNode* root = constructTree(0, preorder.size()-1, preorder,
									0,inorder.size()-1,inorder);

	vector<int>preorderAns;
	preOrder(root, preorderAns);
	deb(preorderAns);

	vector<int>inorderAns;
	inOrder(root, inorderAns);
	deb(inorderAns);


	vector<int>postorderAns;
	postOrder(root, postorderAns);
	deb(postorderAns);
	// 2 6 9 7 3 8 5

	return 0;
}