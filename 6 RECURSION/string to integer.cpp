#include <iostream>
using namespace std;
#include<cmath>
#include<cstring>
using namespace std;
int stringToNumber(char input[]) {
    if(input[0]=='\0'){
        return 0;
    }
    int ans=stringToNumber(input+1);
    int a=input[0]-48;
    int tens=pow(10,strlen(input)-1);
    a=a*tens;
    return a+ans;
}
int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

