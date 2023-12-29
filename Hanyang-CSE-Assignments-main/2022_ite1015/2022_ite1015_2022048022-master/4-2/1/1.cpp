#include <iostream>
using namespace std;

int n, magicConst;

void magicSquare(int** a, int row, int col, int num){
    if(num>n*n) return;

    a[row][col]=num;
    int newrow=row-1;
    int newcol=col+1;
    if(newrow<0) newrow = n-1;
    if(newcol>=n) newcol = 0;
    if(a[newrow][newcol]!=0){
        newcol = col;
        newrow = row+1;
    }
    magicSquare(a, newrow, newcol, num+1);
}

int main(){
    cin >> n;
    if(n%2==0 || n<3) return 0;

    int** table = new int*[n]();
    for(int i=0; i<n; i++) table[i] = new int[n]();
    
    magicConst = n*((n*n+1)/2);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            table[i][j]=0;
        }
    }
    magicSquare(table, 0, n/2, 1);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0; i<n; i++) delete[] table[i];
    delete[] table;
    return 0;
}
