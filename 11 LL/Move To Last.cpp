#include <iostream>
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

void printLL(Node<int>*  head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
Node<int>* func(Node<int> *head,int n) {
    Node<int>* pKey = head; 
  
    // Traverse list 
    Node<int>* pCrawl = head; 
    while (pCrawl != NULL) { 
        // If current pointer is not same as pointer 
        // to a key location, then we must have found 
        // a key in linked list. We swap data of pCrawl 
        // and pKey and move pKey to next position. 
        if (pCrawl != pKey && pCrawl->data != n) { 
            pKey->data = pCrawl->data; 
            pCrawl->data = n; 
            pKey = pKey->next; 
        } 
  
        // Find next position where key is present 
        if (pKey->data != n) 
            pKey = pKey->next; 
  
        // Moving to next Node 
        pCrawl = pCrawl->next; 
    
	} 
	return head;
}
int main() {

	Node<int>* head1 = takeLLInput();
	int n;
	cin>>n;
	printLL(func(head1,n));	
	delete head1;
	
}

