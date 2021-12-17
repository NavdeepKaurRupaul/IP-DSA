#include <iostream>
#include <string>
using namespace std;
int keypad(int num, string output[]){
    if(num==0){
        output[0]="";
        return 1;
    }
    int small=keypad(num/10,output);
    int LastDigit = num%10;
    if(LastDigit==2){
        for(int i=0;i<small;i++){
            output[i+2*small]=output[i]+'a';
            output[i+small]=output[i]+'b';
            output[i]=output[i]+'c';
        }
        return small*3;
    }
    else if(LastDigit==3){
        for(int i=0;i<small;i++){
            output[i+2*small]=output[i]+'d';
            output[i+small]=output[i]+'e';
            output[i]=output[i]+'f';
    }
        return 3*small;
    }
    else if(LastDigit==4){
        for(int i=0;i<small;i++){
            output[i+2*small]=output[i]+'g';
            output[i+small]=output[i]+'h';
            output[i]=output[i]+'i';
    }
        return 3*small;
    }
    else if(LastDigit==5){
        for(int i=0;i<small;i++){
            output[i+2*small]=output[i]+'j';
            output[i+small]=output[i]+'k';
            output[i]=output[i]+'l';
    }
        return 3*small;
    }
    else if(LastDigit==6){
        for(int i=0;i<small;i++){
            output[i+2*small]=output[i]+'m';
            output[i+small]=output[i]+'n';
            output[i]=output[i]+'o';
    }
        return 3*small;
    }
    else if(LastDigit==7){
        for(int i=0;i<small;i++){
            output[i+3*small]=output[i]+'p';
            output[i+2*small]=output[i]+'q';
            output[i+small]=output[i]+'r';
            output[i]=output[i]+'s';
    }
        return 4*small;
    }
    else if(LastDigit==8){
        for(int i=0;i<small;i++){
            output[i+2*small]=output[i]+'t';
            output[i+small]=output[i]+'u';
            output[i]=output[i]+'v';
    }
        return 3*small;
    }
        else if(LastDigit==9){
        for(int i=0;i<small;i++){
            output[i+3*small]=output[i]+'w';
            output[i+2*small]=output[i]+'x';
            output[i+small]=output[i]+'y';
            output[i]=output[i]+'z';
    }
        return 4*small;
    }
}
int main(){
    int num;
    cin >> num;
    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

