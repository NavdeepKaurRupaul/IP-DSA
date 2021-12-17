#include<iostream>
#include<queue>
using namespace std;


template<typename T>
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

BinaryTreeNode<int> * takeinputlevelwise()
     {

    queue<BinaryTreeNode<int>*> pendingnodes;
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1)
        return NULL;

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootdata);

    pendingnodes.push(root);


    while(!pendingnodes.empty())
    {

        BinaryTreeNode<int> * frontnode = pendingnodes.front();
        BinaryTreeNode<int> * currentnode = frontnode;
        pendingnodes.pop();

        int lchild;
        cin>>lchild;

        if(lchild!=-1)
        {
            BinaryTreeNode<int> * leftchild = new BinaryTreeNode<int>(lchild);
            pendingnodes.push(leftchild);
            currentnode->left = leftchild;

        }

        int rchild;
        cin>>rchild;

        if(rchild!=-1)
        {
            BinaryTreeNode<int> * rightchild = new BinaryTreeNode<int>(rchild);
            pendingnodes.push(rightchild);
            currentnode->right = rightchild;
        }


    }
    return root;
}
#include<stack>
void printSpecificLevelOrderUtil(BinaryTreeNode<int> * root, stack<BinaryTreeNode<int> *> s) 
{ 
    if (root == NULL) 
        return; 
  
    // Create a queue and enqueue left and right 
    // children of root 
    queue<BinaryTreeNode<int> *> q; 
  
    q.push(root->left); 
    q.push(root->right); 
  
    // We process two nodes at a time, so we 
    // need two variables to store two front 
    // items of queue 
    BinaryTreeNode<int> *first = NULL;
	BinaryTreeNode<int> *second = NULL; 
  
    // traversal loop 
    while (!q.empty()) 
    { 
        // Pop two items from queue 
        first = q.front(); 
        q.pop(); 
        second = q.front(); 
        q.pop(); 
  
        // Push first and second node's chilren 
        // in reverse order 
        s.push(second->left); 
        s.push(first->right); 
        s.push(second->right); 
        s.push(first->left); 
  
        // If first and second have grandchildren, 
        // enqueue them in specific order 
        if (first->left->left != NULL) 
        { 
            q.push(first->right); 
            q.push(second->left); 
            q.push(first->left); 
            q.push(second->right); 
        } 
    } 
} 
#include<stack>
void printSpecificPattern(BinaryTreeNode<int> * root){
    stack<BinaryTreeNode<int> * > s; 
    s.push(root);
    if (root->left != NULL) { 
        s.push(root->right); 
        s.push(root->left); 
    } 
    if (root->left->left != NULL) 
        printSpecificLevelOrderUtil(root, s);
    while (!s.empty()) { 
        cout << s.top()->data << " "; 
        s.pop(); 
    } 
}

int main()
{
    BinaryTreeNode<int> * root = NULL;
    root = takeinputlevelwise();
    printSpecificPattern(root);
}

