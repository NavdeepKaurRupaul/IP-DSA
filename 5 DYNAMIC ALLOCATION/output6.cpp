#include <iostream>
using namespace std;

#define SQUARE(x) x*x
/*"SQUARE(x) x*x" will be replaced by "x*x" in code. So,36 / SQUARE(6) will be replaced by 36/x*x.
And according to operator precedence, division operator (/) has higher precedence than multiply operator (8). 
So, 36/6 will be evaluated first. Hence expression will become : 6*6=36*/
int main(){
    int x = 36 / SQUARE(6);
    cout << x;

    return 0;
}
