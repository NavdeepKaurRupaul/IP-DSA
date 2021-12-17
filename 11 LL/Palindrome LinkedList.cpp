#include <iostream>
#include<vector>
using namespace std;
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool check_palindrome(node* head)
{
    vector<int> a;
    node* temp=head;
    while(temp!= NULL){
    	a.push_back(temp->data);
    	temp=temp->next;
	}
	int i=0;
	int j= a.size()-1;
	while(i<j){
		if(a[i]!=a[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}

