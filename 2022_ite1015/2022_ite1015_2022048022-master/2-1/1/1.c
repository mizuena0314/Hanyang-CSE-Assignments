#include <stdio.h>
#include <string.h>

struct Book{
    char title[21];
    int year;
};

Book arr[4];

int main(){
    for(int i=0; i<4; i++){
        scanf("%s %d", arr[i].title, &arr[i].year);
    }

    for(int i=0; i<4; i++){
        printf("Name: %s, Published Year: %d\n", arr[i].title, arr[i].year);
    }
    return 0;
}
        
