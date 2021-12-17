#include <iostream>
using namespace std;
int staircase(int n){
	if(n==0|| n==1){ //when n=0 or n=1 there is only one way
		return 1;
	}
	if(n==2){ // when n=2 there are two ways either-take 1 step two times, or take two steps at a time
		return 2;
	}
	int x=staircase(n-1);
	int y=staircase(n-2);
	int z=staircase(n-3);
	return x+y+z;
}
int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}

