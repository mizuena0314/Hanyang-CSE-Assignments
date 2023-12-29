#include <iostream>
using namespace std;

int n;

void fillAscend(int** a){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = n*i+(j+1);
        }
    }
}

void fillDescend(int** a){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j] = n*(n-i)-j;
        }
    }
}

void magicSquare(int**a, int** asc, int** dsc){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i<n/4||i>=n*3/4) && (j<n/4 || j>=n*3/4)){
                a[i][j] = asc[i][j];
            }
            else if((i>=n/4 && i<n*3/4) && (j>=n/4 && j<n*3/4)){
                a[i][j] = asc[i][j];
            }
            else a[i][j] = dsc[i][j];
        }
    }
}

int main(){
    cin >> n;
    if(n%4!=0) return 0;

    int** table = new int*[n]();
    int** asc = new int*[n]();
    int** dsc = new int*[n]();
    for(int i=0; i<n; i++){
        table[i] = new int[n]();
        asc[i] = new int[n]();
        dsc[i] = new int [n]();
    }

    fillAscend(asc);
    fillDescend(dsc);
    magicSquare(table, asc, dsc);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0; i<n; i++){
        delete[] table[i];
        delete[] asc[i];
        delete[] dsc[i];
    }
    delete[] table;
    delete[] asc;
    delete[] dsc;
    return 0;
}
