#include<bits/stdc++.h>

using namespace std;

bool markSquare[3][3][9]={false};
bool markRow[9][10]={false};
bool markCol[9][10]={false};
int sudoku[9][9];
int sudokuCheck[9][9]={0};
int solution=0;

bool check(int r,int c,int v){
    if(markRow[r][v]==false&&markCol[c][v]==false&&markSquare[r/3][c/3][v]==false)
        return true;
    return false;
}

void Try(int r, int c){
    if(sudokuCheck[r][c]==1){
        if(r==8&&c==8){
            solution++;
            return;
        }
        if(c<8) Try(r,c+1);
        else Try(r+1,0);
    }
    for(int v=1;v<10;v++){
        if(check(r,c,v)==true){
            if(r==8&&c==8){
                solution++;
                return;
            }
            if(sudokuCheck[r][c]!=1) sudoku[r][c]=v;
            markSquare[r/3][c/3][v]=true;
            markRow[r][v]=true;
            markCol[c][v]=true;
            if(c<8){
                // cout << "(r,c) = " << r+1 << "," << c+1 << endl; 
                // cout << "v = " << v << endl;
                // for(int i=0;i<9;i++){
                //     for(int j=0;j<9;j++){
                //         cout << sudoku[i][j] << " ";
                //     }cout << endl;
                // }
                Try(r,c+1);
            }else Try(r+1,0);
            if(sudokuCheck[r][c]!=1) sudoku[r][c]=0;
            markSquare[r/3][c/3][v]=false;
            markRow[r][v]=false;
            markCol[c][v]=false;
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j]!=0){
                sudokuCheck[i][j]=1;
            }
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]!=0){
                markSquare[i/3][j/3][sudoku[i][j]]=true;
                markRow[i][sudoku[i][j]]=true;
                markCol[j][sudoku[i][j]]=true;
            }
        }
    }
    Try(0,0);
    cout << solution;
}
