#include<iostream>
using namespace std;
#include<vector>
template<typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode*> children;
		TreeNode(T data){
			this->data=data;
		}
};
#include<queue>
TreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cout<<"Entre root data"<<endl;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		TreeNode<int>* front= pendingnodes.front();
		pendingnodes.pop();
		cout<<"Enter no of children of "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++){
			int childdata;
			cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
			cin>>childdata;
			TreeNode<int> *child= new TreeNode<int>(childdata);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
void print(TreeNode<int>* root){
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		print(root->children[i]);
	}
}
int main(){
	TreeNode<int>* root=takeinputlevelwise();
	print(root);	
}
