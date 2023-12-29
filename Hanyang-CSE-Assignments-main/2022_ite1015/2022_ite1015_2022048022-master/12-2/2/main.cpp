#include <iostream>
#include <string>
#include <cstdlib>
#include "list.h"

using namespace std;

template<typename T>
void merge(List<T>& li1, List<T>& li2){
        int idx1 = 0;
        int idx2 = 0;
        int cursor = 0;

        int en1 = li1.size();
        int en2 = li2.size();

        T tmp[en1+en2];
        while(idx1 != en1 || idx2 != en2){
            if(idx1 == en1){
                tmp[cursor++] = li2.getdata(idx2++);
            }
            else if(idx2 == en2){
                tmp[cursor++] = li1.getdata(idx1++);
            }
            else if(li1.getdata(idx1) <= li2.getdata(idx2)){
               tmp[cursor++] = li1.getdata(idx1++);
            }
            else{
                tmp[cursor++] = li2.getdata(idx2++); 
            }
        }

        while(li1.size()){
            li1.pop_front();
        }
        /*
        for(int i=0; i<en1+en2; i++) cout << tmp[i] << ' ';
        cout << endl;
        */
        for(int i=en1+en2-1; i>=0; i--) li1.push_front(tmp[i]);
}

int main(){
    int array[5] = {1,2,4,5,6 };
    int array2[4] = {1,3,5,7 };

    List<int> li(array, 5);
    List<int> li2(array2, 4);

    //implement here
    merge(li, li2);

    li.remove_at(0);
    cout << li << endl; // 1,1,2,3,4,5,5,6,7

    return 0;
}
