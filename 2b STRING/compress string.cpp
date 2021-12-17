#include <iostream>
using namespace std;
void stringCompression(char input[])
{
    int i=1,j=1;
    char c='1',output[1000000], f=input[0];
    output[0]=f;
    while(input[i]!='\0')
    {
        if(f!=input[i])
        {
            if(c>'1')
            {
                output[j]=c;
                j++;
            }
            f=input[i];
            output[j]=input[i];
            j++;
            c='1';
        }
        else if(f==input[i])
        {
            c++;
        }
        i++;
    }
    if(c>'1'){
        output[j] = c;
    }
    j=0;
    while(output[j]!='\0')
    {
        input[j]=output[j];
        j++;
    }
    input[j]='\0'; 
} 

int main() {
    char input[1000];
    cin.getline(input, 1000);
    stringCompression(input);
    cout << input << endl;
}

