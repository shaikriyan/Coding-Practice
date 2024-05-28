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

class Node{
public :

	int data;
	Node* next;
	
	Node(int data1=0, Node* next1=nullptr){
		data = data1;
		next = next1;
	}

};


Node* array2LL(vector<int>&nums){

	int n = nums.size();
	Node* head = nullptr;
	Node* temp = NULL;
	for(int i=0;i<n;i++){
		if(i==0){
			head = new Node(nums[i]);
			temp = head;
		}
		else{
			temp->next = new Node(nums[i]);
			temp = temp->next;
		}
	}
	return head;

}

int getCount(Node *head){
	int len = 0;
	if(head==NULL) return len;
	Node* temp = head;
	while(temp){
		len++;
		temp = temp->next;
	}
	return len;
}

void printLL(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
 	cout<<endl;
}


Node* middleofLL(Node* head){
	Node *hare=head, *tortoise=head;
	while(hare!=NULL && hare->next!=nullptr){
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	return tortoise;
}


Node* reverseLL(Node* head){
	if(head==nullptr || head->next==nullptr) return head;
	Node *left = nullptr, *curr=head, *right = nullptr;
	while(curr){

		right = curr->next;
		curr->next = left;
		left = curr;
		curr = right;
	}
	return left;
}


/*
Node* reverseLL(Node* head){

	if(head==nullptr || head->next==nullptr) return head;
	Node* ans = reverseLL(head->next);
	head->next = nullptr;
	Node* temp = ans;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = head;
	return ans;
}
*/

bool hasCycle(Node* head){
	if(head==nullptr || head->next==nullptr) return false;
	Node *hare=head, *tortoise = head;
	while(hare!=nullptr && hare->next!=nullptr){
		hare = hare->next->next;
		tortoise = tortoise->next;
		if(hare==tortoise) return true;
	}
	return false;
}


Node* oddEvenList(Node* head){
	if(head==nullptr || head->next==nullptr) return head;

	Node* oddHead = new Node(-1);
	Node* evenHead = new Node(-1);

	Node* temp = head;
	Node* odd = oddHead;
	Node* even = evenHead;
	int cnt = 0;

	while(temp){
		cnt++;

		if(cnt&1){
			odd->next = temp;
			odd = odd->next;
		}
		else{
			even->next = temp;
			even = even->next;
		}

		Node* prev = temp;
		temp = temp->next;
		prev->next = nullptr;

	}

	odd->next = evenHead->next;
	evenHead->next = nullptr;
	head = oddHead->next;
	oddHead->next = nullptr;
	return head;

}


bool isPalindrome(Node* head){

	if(head==nullptr || head->next==nullptr) return true;

	Node* slow = head;
	Node* fast = head;

	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = reverseLL(slow);

	fast = slow;
	printLL(slow);
	Node* temp = head;

	while(slow && temp!=fast){
		if(temp->data!=slow->data) return false;
		temp = temp->next;
		slow = slow->next;
	}

	reverseLL(slow);
	return true;

}

Node* deleteMiddle(Node* head){

	if(head==nullptr || head->next==nullptr) return nullptr;

	Node* slow = head;
	Node* fast = head;
	Node* slowsPrev = head;

	while(fast!=NULL && fast->next!=NULL){
		slowsPrev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	slowsPrev->next = slow->next;
	slow->next = nullptr;
	return head;

}


Node* removeNthFromEnd(Node* head, int n){

	int len = getCount(head);
	deb(len);
	int x = len - n;
	deb(x)
	int cnt = 0;
	Node* temp = head;
	while(temp){
		cnt++;

		if(cnt==x){
			deb(cnt);
			temp->next = temp->next->next;
			break;
		}
		temp = temp->next;
	}

	return head;


}


Node* sort012(Node* head){

	if(head==nullptr || head->next==nullptr) return head;


	Node* zeroHead = new Node(-1);
	Node* oneHead = new Node(-1);
	Node* twoHead = new Node(-1);

	Node *one = oneHead, *two=twoHead, *zero=zeroHead;

	Node *temp = head;

	while(temp){

		if(temp->data==1){
			one->next = temp;
			one = one->next;
		}
		else if(temp->data==2){
			two->next = temp;
			two = two->next;
		}
		else{
			zero->next = temp;
			zero = zero->next;
		}

		temp = temp->next;

	}

	zero->next = nullptr;
	one->next = nullptr;
	two->next = nullptr;

	zeroHead = zeroHead->next;
	oneHead = oneHead->next;
	twoHead = twoHead->next;


	head = twoHead;

	if(oneHead!=nullptr){
		one->next = head;
		head = oneHead;	
	} 

	if(zeroHead!=nullptr){
		zero->next = head;
		head = zeroHead; 
	}

	return head;
}


Node* addTwoNumbers(Node* l1, Node* l2){

	Node* temp1 = l1;
	Node* temp2 = l2;
	int carry = 0;

	Node* ans = new Node(-1);
	Node* temp = ans;

	while(temp1 && temp2){

		int sum =  (temp1->data) + (temp2->data) + carry;
		temp->next = new Node(sum%10);
		temp = temp->next;
		carry = (sum/10);

		temp1 = temp1->next;
		temp2 = temp2->next;
	} 

	while(temp1){
		int sum =  (temp1->data) + carry;
		temp->next = new Node(sum%10);
		temp = temp->next;
		carry = (sum/10);
		temp1 = temp1->next;
	}

	while(temp2){
		int sum =  (temp2->data) + carry;
		temp->next = new Node(sum%10);
		temp = temp->next;
		carry = (sum/10);
		temp2 = temp2->next;
		
	}

	while(carry){
		int sum =  carry;
		temp->next = new Node(sum%10);
		temp = temp->next;
		carry = (sum/10);
	}

	return ans->next;

}


Node* addOne(Node* head){

	head = reverseLL(head);
	Node* temp1 = head;

	Node* ans =nullptr;
	Node* temp = ans;

	Node* newNode = nullptr;

	int carry = 1;

	while(temp1){
		int sum = (temp1->data) + carry;
		newNode =  new Node(sum%10);
		newNode->next = temp;
		temp = newNode;
		carry = sum/10;
		temp1 = temp1->next;
	}

	while(carry){
		int sum = carry;
		newNode =  new Node(sum%10);
		newNode->next = temp;
		temp = newNode;
		carry = sum/10;
	}

	reverseLL(head);
	return temp;

}

Node* mergeLL(Node* l1, Node* l2){



	Node* temp1 = l1;
	Node* temp2 = l2;
	Node* ans = new Node(-1);
	Node* temp = ans;

	while(temp1 && temp2){

		if(temp1->data < temp2->data){
			temp->next = temp1;
			temp = temp->next;
			temp1 = temp1->next;
		}
		else{
			temp->next = temp2;
			temp = temp->next;
			temp2 = temp2->next;
		}

	}


	while(temp1){
	temp->next = temp1;
	temp = temp->next;
	temp1 = temp1->next;
	}

	while(temp2){
	temp->next = temp2;
	temp = temp->next;
	temp2 = temp2->next;
	}


	return ans->next;

}



Node* sortList(Node* head){

	if(head==nullptr || head->next==nullptr) return head;

	Node* slow = head;
	Node* fast = head;
	Node* slowsPrev = nullptr;

	while(fast && fast->next){
		slowsPrev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	slowsPrev->next = nullptr;

	fast = head;
	fast = sortList(fast);
	slow = sortList(slow);

	return mergeLL(fast, slow);


}


Node* getIntersectionNode(Node* head1, Node* head2){

	head1 = reverseLL(head1);
	head2 = reverseLL(head2);

	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* ans = nullptr;

	while(temp1 && temp2){

		if(temp1==temp2){
			ans = temp1;
		}

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return ans;

}








int main()
{

	// vector<int> nums = {1,2,2,1,2,0,2,2};
	// vector<int> nums = {1,2,2,1,2,2,2,2};
	// vector<int> nums = {2,2,2,1,2,2,2,2};
	// vector<int> nums = {1,1,1,1};
	// vector<int> nums = {1,0,1,0};
	// vector<int> nums = {0,0,0,0,2,2,0 };
	// vector<int> nums = {4, 5, 6 };
	// Node* head = array2LL(nums);
	// printLL(head);

	// head = middleofLL(head);
	// printLL(head);


	// head = reverseLL(head);
	// printLL(head);

	// head = oddEvenList(head);
	// printLL(head);

	// bool ans = isPalindrome(head);
	// deb(ans);

	// head = removeNthFromEnd(head, 2);

	// head = sort012(head);
	// printLL(head);

	// cout<<"hee hee"<<endl;

	// head = addOne(head);
	// printLL(head);

	// vector<int> nums1 = {1,2,3,4};
	// Node* head1 = array2LL(nums1);
	// vector<int>nums2 =  {5,6,7,8,9};
	// Node* head2 = array2LL(nums2);

	// Node* head = mergeLL(head1, head2);
	// printLL(head);


	// vector<int> nums = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
	// Node* head = array2LL(nums);
	// printLL(head);

	// head = sortList(head);
	// printLL(head);


	vector<int> nums1 = {1,9,1,2,4};
	Node* head1 = array2LL(nums1);

	vector<int> nums2 = {3,2,4};
	Node* head2 = array2LL(nums2);

	Node* head = getIntersectionNode(head1, head2);
	printLL(head);




	return 0;
}