#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

void makeSudoku (int a[][9]);
bool solveSudoku (int a[][9], int , int);
bool checkSudoku (int a[][9], int , int ,int);

int main (){
    int a[9][9];
    makeSudoku(a);
    cout <<endl<<"Solved Sudoku:\n";
    if (!solveSudoku(a, 0 ,0)){
        cout << "Invalid Sudoku";
    }
    return 0;
}

void makeSudoku(int a[][9]){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cin >> a[i][j];
        }
    }
}

void printSudoku (int a[][9]){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cout << a[i][j]<<" ";
        }
        cout <<endl;
    }
}

bool solveSudoku (int a[][9], int x, int y){
    if(y==9){
        if(x==8){
            printSudoku(a);
            return true;
        } else {
            return solveSudoku(a, x+1, 0);
        }
    } else if (a[x][y]==0){
        for (int i=1; i<=9;i++){
            if (checkSudoku(a, x, y, i)){
                a[x][y]=i;
                if (solveSudoku(a, x, y+1)){
                    return true;
                }
                a[x][y]=0;
            }
        }
        return false;
    } else {
        return solveSudoku(a, x, y+1);
    }
}

bool checkSudoku (int a[][9], int x, int y, int number){
    for (int i=0;i<9;i++){
        if (a[i][y]==number){
            return false;
        }
        if (a[x][i]==number){
            return false;
        }
    }
    for (int i=(x/3)*3;i<(x/3)*3+3;i++){
        for (int j=(y/3)*3;j<(y/3)*3+3;j++){
            if (a[i][j]==number){
                return false;
            }
        }
    }
    return true;
}
