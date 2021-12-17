//Move last element to front of a given Linked List
#include<iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node* next;

	Node(T data) {
		next = NULL;
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
Node<int>* moveToFront(Node<int> *head_ref) {
    Node<int>* temp=head_ref;
    Node<int>* secondlast =NULL;
	while(temp->next != NULL){
		secondlast=temp;
		temp=temp->next;
	}
	secondlast->next=NULL;
	temp->next=head_ref;
	head_ref=temp;
	return head_ref;
}
void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node<int>* head = takeLLInput();
	head = moveToFront(head);
	printLL(head);
	delete head;
}

