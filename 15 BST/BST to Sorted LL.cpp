#include <iostream>
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
// Following is the Binary Tree node structure
/**************
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
 class BinaryTreeNode {
 public :
 T data;
 BinaryTreeNode<T> *left;
 BinaryTreeNode<T> *right;
 
 BinaryTreeNode(T data) {
 this -> data = data;
 left = NULL;
 right = NULL;
 }
 };
 ***************/
template<typename T>
class Pair{
    public:
    Node<T>* head;
    Node<T>* tail;
};
Pair<int>* helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        Pair<int> *ans;
        ans->head=NULL;
        ans->tail=NULL;
        return ans;
    }
    Node<int>* headd=new Node<int>(root->data);
    Pair<int>* l=helper(root->left);
    Pair<int>* r=helper(root->right);
    Node<int>* lhead=l->head;
    Node<int>* ltail=l->tail;
    Node<int>* rhead=r->head;
    Node<int>* rtail=r->tail;
    Pair<int> *finals= new Pair<int>;
    if(rhead==NULL && lhead==NULL){
        finals->head=headd;
        finals->tail=headd;
        return finals;
    }
    else if(rhead==NULL && lhead!=NULL)
    {
        finals->head=lhead;
        ltail->next=headd;
        finals->tail=headd;
        return finals;
    }
    else if(lhead==NULL && rhead!=NULL)
    {
        finals->head=headd;
        headd->next=rhead;
        finals->tail=rtail;
        return finals;
    }
    else
    {
        finals->head=lhead;
        ltail->next=headd;
        headd->next=rhead;
        finals->tail=rtail;
        return finals;
        
    }
}
Node<int>* constructBST(BinaryTreeNode<int>* root) {
	
	return helper(root)->head;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}

