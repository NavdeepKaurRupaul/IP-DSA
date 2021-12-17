#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void breakWords(char* S){
	vector<char> v;
    int i=0;
	while(S[i]!='\0'){
		int count =0;
        int j=i;
		while(S[j]!=' ' || S[j]!='\0'){
			count++;
			j++;
		}
		if(count>=4 && count%2==0){
			int b=count/2;
			for(int k=i;k<b+i;k++){
				v.push_back(S[k]);
			}
			v.push_back(' ');
			for(int k=b+1;k<=count+i;k++){
				v.push_back(S[k]);
			}
			v.push_back(' ');
		}
		else {
			for(int k=i;k<count+i;k++){
				v.push_back(S[k]);
			}
			v.push_back(' ');
		}
        i=i+count+1;
	}
	for(int i=0;i<v.size();i++){
		S[i]=v[i];
	}
    v.clear();
}

int main()
{
	char str[100000];
	cin.getline(str,100000);
	breakWords(str);
	cout<<str;
}

