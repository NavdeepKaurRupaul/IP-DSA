#include<iostream>
#include<set>
using namespace std;
bool notInRow(int arr[][9], int row){ 
    // Set to store characters seen so far. 
    set<int> st; 
    for (int i = 0; i < 9; i++) { 
        // If already encountered before, return false 
        if (st.find(arr[row][i]) != st.end()) {
        	return false;
		}      
        // If it is not an empty cell, insert value at the current cell in the set 
        if (arr[row][i] != 0){
        	 st.insert(arr[row][i]);
		}      
    } 
    return true; 
} 
// Checks whether there is any duplicate in current column or not. 
bool notInCol(int arr[][9], int col) { 
    set<int> st; 
    for (int i = 0; i < 9; i++) { 
        // If already encountered before, return false 
        if (st.find(arr[i][col]) != st.end()) {
        	return false;
		}  
        // If it is not an empty cell, insert value at the current cell in the set 
        if (arr[i][col] != 0){
        	st.insert(arr[i][col]);
		}         
    } 
    return true; 
} 
// Checks whether there is any duplicate in current 3x3 box or not. 
bool notInBox(int arr[][9], int startRow, int startCol) { 
    set<char> st; 
    for (int row = 0; row < 3; row++) { 
        for (int col = 0; col < 3; col++) { 
            char curr = arr[row + startRow][col + startCol]; 
            // If already encountered before, return false 
            if (st.find(curr) != st.end()) 
                return false; 
            // If it is not an empty cell,insert value at current cell in set 
            if (curr != 0){
            	st.insert(curr);
			}         
        }
    } 
    return true; 
}   
// Checks whether current row and current column and current 3x3 box is valid or not 
bool isValid(int arr[][9], int row, int col) { 
    return notInRow(arr, row) && notInCol(arr, col) && notInBox(arr, row - row % 3, col - col % 3); 
} 
bool isValidConfig(int arr[][9], int n) { 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            // If current row or current column or current 3x3 box is not valid, return false 
            if (!isValid(arr, i, j)) {
            	return false;
			}    
        } 
    } 
    return true; 
}
bool sudokuSolver(int board[][9]){
	return isValidConfig(board,9);
}
int main(){
  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}



