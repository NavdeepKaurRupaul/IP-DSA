#include <iostream>
using namespace std;
void Test(int N, int k){
if (k > N) {
    return;
}
for(int i = 0; i<10; i++){
if (k <= N){
cout<<k<<endl;
k *= 10;
Test(N, k);
k /= 10;
k++;
if (k%10 == 0) return;
}
}
}
void lexicographicalOrder(int n){
    Test(n,1);
	/*for(int i = 1; i <= 9; i ++){
        int j = 1;
        while( j <= n){
            for(int m = 0; m < j ; ++ m){
                if(m + j * i <= n){
                    cout << m + j * i << endl;
                }
            }
            j *= 10;
        }*/
    }
int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}

