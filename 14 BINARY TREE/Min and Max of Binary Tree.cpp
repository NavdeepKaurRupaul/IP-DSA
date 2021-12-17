#include <iostream>
#include <queue>

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

class PairAns {
    public :
    int min;
    int max;
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
#include<climits>
PairAns minMax(BinaryTreeNode<int> *root) {
	if(root == NULL){
		PairAns p;
        p.min= INT_MAX;
        p.max= INT_MIN;
        return p;
	}  
    int minimum=root->data;
    PairAns leftans= minMax(root->left);
    PairAns rightans= minMax(root->right);
    int lminimum=leftans.min;
    int rminimum=rightans.min;
     if(lminimum<minimum) {
       minimum=lminimum;
   }
   if(rminimum<minimum){
       minimum=rminimum;
   }
      int maximum=root->data;
      int lmaximum=leftans.max;
      int rmaximum=rightans.max;
    if(lmaximum>maximum){
        maximum=lmaximum;
    }
    if(rmaximum>maximum){
        maximum=rmaximum;
    }   
    PairAns p1;
    p1.min=minimum;
    p1.max=maximum;
    return p1;    
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    PairAns ans = minMax(root);
    cout << ans.max << " " << ans.min << endl;
}
