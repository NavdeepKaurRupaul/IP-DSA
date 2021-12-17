#include<iostream>
using namespace std;
template<typename T>
class BinaryTreeNode{
	public:
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		BinaryTreeNode(T data){
			this->data=data;
			left=NULL;
			right=NULL;
		}		
};
#include<queue>
BinaryTreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"Entre root data"<<endl;
	cin>>rootdata;
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
	queue<BinaryTreeNode<int>*> pending;
	pending.push(root);
	while(!pending.empty()){
		BinaryTreeNode<int>* front=pending.front();
		pending.pop();
		cout<<"Enter left child of "<<front->data<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild!= -1){
			BinaryTreeNode<int>* child= new BinaryTreeNode<int>(leftchild);
			front->left=child;
			pending.push(child);
		}
		cout<<"Enter right child of "<<front->data<<endl;
		int rightchild;
		cin>>rightchild;
		if(rightchild!= -1){
			BinaryTreeNode<int>* child= new BinaryTreeNode<int>(rightchild);
			front->right=child;
			pending.push(child);
		}
	}
	return root;
} 
void print(BinaryTreeNode <int>*root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" : ";
	if(root->left!=NULL){
		cout<<"L-"<<root->left->data<<" "; 
	}
	if(root->right!=NULL){
		cout<<"R-"<<root->right->data<<" "; 
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}
int main(){
	BinaryTreeNode <int>* root= takeinputlevelwise();
	print(root);
}
