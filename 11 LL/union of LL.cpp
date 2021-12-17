#include <iostream>
using namespace std;

template <typename T>
class ListNode {
    public:
    T data;
    ListNode<T> *next;
    ListNode<T>(T data)
    {
        this -> data=data;
        next = NULL;
    }
};

 ListNode<int>* createlist()
	{
	    ListNode<int> *head=NULL;
		ListNode<int> *rear=NULL;
		int data;
		cin>>data;
		while(data!=-1)
		{
			ListNode<int> *newnode=new ListNode<int>(data);
			if(head==NULL)
			{
				head=newnode;
				rear=head;
			}
			else
			{
				rear->next=newnode;
				rear=rear->next;
			}
			cin>>data;
		}
		return head;
	}

    void print(ListNode<int> * head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<endl;
			head=head->next;
		}
	}
	#include<vector>
ListNode<int> *unionOf2LL(ListNode<int> *head1,ListNode<int> *head2)
	{
	    ListNode<int>* a;
	    ListNode<int>* temp1=head1;
	    ListNode<int>* prev =NULL;
	    ListNode<int>* temp2=head2;
	    while(temp2 != NULL){
	    	while(temp1 != NULL){
	    		if(temp1->data !=temp2->data){
	    			prev = temp1;
	    			temp1=temp1->next;
			}
			if(temp1->data==temp2->data){
				//break;
			}
			}
				if(temp1==NULL){
					prev->next=temp2;
					a=temp2->next;
					prev->next->next=NULL;
				}
				temp2=a;
				//prev->next->next= NULL;
			}
			return head1;
	    }

int main()
{
   ListNode<int> *head1=createlist();
   ListNode<int> *head,*head2=createlist();
   head=unionOf2LL(head1,head2);
   print(head);
}

