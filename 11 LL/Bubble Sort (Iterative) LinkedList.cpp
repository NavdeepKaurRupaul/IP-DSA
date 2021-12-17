//bubble sort iterative
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
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
void swap(node *a, node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    int swapped, i; 
    node *ptr1; 
    node *lptr = NULL; 
  
    /* Checking for empty list */
    if (head == NULL) 
        return head; 
  
    do
    { 
        swapped = 0; 
        ptr1 = head; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
    return head;
}
int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

