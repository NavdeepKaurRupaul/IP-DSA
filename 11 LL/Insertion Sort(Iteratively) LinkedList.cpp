//insertion sort iterative
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

node*  sortedInsert(node*  sorted_head, node*  new_node, node * head)
{
    // Insertion at first position
    if(sorted_head == NULL or head->data >= new_node->data)
    {
        new_node->next = sorted_head;
        return new_node ;
    }
    else
    {
        node*  curr = sorted_head;
        while(curr->next != NULL and
                        curr->next->data < new_node->data)
            curr = curr->next;
        new_node->next = curr->next;
        curr->next = new_node;
    }
    return sorted_head;
}
node* insertion_sort_LinkedList_itr(node* head)
{
    node* curr = head;
  node*  sorted_head = NULL;
    while (curr != NULL)
    {
        node*  currNext = curr->next;
        sorted_head = sortedInsert(sorted_head,curr,head);
        curr = currNext;
    }
    return sorted_head;
}
int main()
{
    node* head=takeinput();
    head=insertion_sort_LinkedList_itr(head);
    print(head);
}

