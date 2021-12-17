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
int decimal(Node<int> *head) {
    int res = 0;  
  
    // Traverse linked list  
    while (head != NULL)  
    {  
        // Multiply result by 2 and add  
        // head's data  
        res = (res << 1) + head->data;  
  
        // Move next  
        head = head->next;  
    }  
    return res;  
    
}
int main() {

	Node<int>* head1 = takeLLInput();
	
	
	cout<<decimal(head1)<<endl;
	
	delete head1;
	
}

