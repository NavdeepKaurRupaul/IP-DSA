#include <iostream>
#include <algorithm>
using namespace std;
#include<unordered_map>
void intersection(int input1[], int input2[], int size1, int size2) {
unordered_map<int,bool> status1,status2;
    for(int i=0;i<size1;i++){
        status1[input1[i]]=true;
    }
    for(int i=0;i<size2;i++){
        status2[input2[i]]=true;
    }
    if(size1<size2){
        for(int i=0;i<size1;i++){
            if(status2.count(input1[i])>0){
                cout<<input1[i]<<endl;              
            }          
        }
    }
   else{
        for(int i=0;i<size2;i++){
            if(status1.count(input2[i])>0){
                cout<<input2[i]<<endl;              
            }         
        }
    }
}
int main() {
	int size1,size2;
	cin>>size1;
	int *input1=new int[1+size1];		
	for(int i=0;i<size1;i++)
		cin>>input1[i];
	cin>>size2;
	int *input2=new int[1+size2];	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	intersection(input1,input2,size1,size2);	
	return 0;
}

