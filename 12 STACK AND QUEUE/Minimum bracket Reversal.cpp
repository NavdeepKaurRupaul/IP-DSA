#include <iostream>
using namespace std;
#include<stack>
#include<cstring>
int countBracketReversals(char input[]){
    stack<char> s;
    // can you see this
    int len=strlen(input);
    if(len==0)
        return 0;
    if(len%2 !=0) {
        return -1;
    }
    for(int i=0;i<len;i++){
        if(input[i]=='{'){
            s.push(input[i]);
        }
        if(input[i]=='}')
        {
            if( !s.empty() && s.top()=='{'){
                s.pop();
            }
            else
            {
                s.push('}');
            }
        }
    }
    int count=0;
    while(!s.empty())
    {
        char a= s.top();
        s.pop();
        char b=s.top();
        s.pop();
        if(a==b){
            count+=1;
        }
        else{
            count+=2;
        }
    }
    return count;
}


int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
