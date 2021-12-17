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
TreeNode<int>* takeinput(){
	int rootdata;
	cout<<"Entre root data"<<endl;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	int n;
	cout<<"entre number of children of "<<rootdata;
	cin>>n;
	for(int i=0;i<n;i++){
		TreeNode<int>* child= takeinput();
		root->children.push_back(child);
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
	TreeNode<int>* root=takeinput();
	print(root);	
}
