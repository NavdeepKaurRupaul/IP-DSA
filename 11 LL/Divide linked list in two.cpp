//Write a function AlternatingSplit() that takes one list and divides up its nodes to make two smaller lists ?a? and ?b?. 
//The sublists should be made from alternating elements in the original list.
//nodes should be in the reverse order of which they occurred in the source list
#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
		//(*this).data = data;
		this->data = data;
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
	}
};
Node<int>* takeLLInput() {
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newnode=new Node<int>(data);
        if(head==NULL) {
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

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
void AlternatingSplit(Node<int>* head) {
	Node<int>* start1 =head;
	while(start1 != NULL)
    {
        Node<int>* temp1 = head;
        temp1 ->data = start1 ->data;
        temp1->next = start2;
        start2 = temp1;
        start1 = start1 -> next;

        if(start1 != NULL)
        {
            Node<int> *temp2 = head;
            temp2 ->data = start1 ->data;
            temp2->next = start3;
            start3 = temp2;
            start1 = start1 -> next;
        }
    }
    
}


int main()
{ 
	Node<int>* head=takeLLInput();

	AlternatingSplit(head);
	
}

