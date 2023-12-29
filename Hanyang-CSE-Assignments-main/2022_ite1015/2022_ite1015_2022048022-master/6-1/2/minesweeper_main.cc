#include "minesweeper.h"

int main(){
    Minesweeper mine;
    while(1){
        string inst;
        cin >> inst;
        if(inst==":set"){
            int width, height;
            cin >> width >> height;
            vector<string> map;
            if(height>0){
                for(int i=0; i<height; i++){
                    string row;
                    cin >> row;
                    map.push_back(row);
                }
            }
            mine.setMap(width, height, map);
        }
        if(inst==":toggle"){
            int x, y;
            cin >> x >> y;
            mine.toggleMine(x, y);
        }
        if(inst==":quit") return 0;
    }
}

            

