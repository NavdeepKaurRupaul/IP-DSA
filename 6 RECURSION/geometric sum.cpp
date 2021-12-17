#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double geometricSum(int k) {
    if (k==0){
	    return 1;
    }
    double d= 1/(pow(2,k));
    double small=geometricSum(k-1);
    return d+small;
}
int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}

