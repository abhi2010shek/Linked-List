#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int val){
			data=val;
			next=NULL;
		}
};
void insert_at_tail(node* &head, int val){
	node* n= new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
void display(node* head){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	/*node* head= new node(10);
	cout<<head->data<<endl;
	cout<<head->next<<endl;*/
	node* head=NULL;
	insert_at_tail(head,1);
	insert_at_tail(head,2);
	insert_at_tail(head,3);
	display(head);
	return 0;
}
