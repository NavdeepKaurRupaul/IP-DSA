#include <iostream>
#include <stack>
using namespace std;
void calculateSpan(int price[], int n, int S[])  {   
    S[0] = 1;  
    for (int i = 1; i < n; i++)  
    {  
        S[i] = 1; 
        for (int j = i - 1; (j >= 0) &&  (price[i] > price[j]); j--)  
            S[i]++;  
    }  
} 
int* stockSpan(int *price, int size) {
	int *array=new int[size];
	calculateSpan(price,size,array);
	return array;
}
int main() {
    stack<int> input;
    int size, value;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> value;
        input.push(value);
    }
    sortStack(input);
    while(!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
}

