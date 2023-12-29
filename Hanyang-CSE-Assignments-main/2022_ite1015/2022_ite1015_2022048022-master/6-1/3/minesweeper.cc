#include "minesweeper.h"

Minesweeper::Minesweeper(){}
Minesweeper::~Minesweeper(){}

bool Minesweeper::setMap(size_t _width, size_t _height, vector<string>& _map){
    if(_width<=0 || _height<=0) return false;
    if(_map.size()!=_height) return false;
    for(int i=0; i<_height; i++){
        if(_map[i].size()!=_width) return false;
    }
    for(int i=0; i<_height; i++){
        for(int j=0; j<_width; j++){
            if(_map[i][j]!='*' &&  _map[i][j]!='.'){
                return false;
            }
        }
    }
    this->mWidth = _width;
    this->mHeight = _height;
    this->mMap = _map;
    //
    //cout << "reach point 1" << endl;
    //
    this->fillCountMap(_width, _height);
    //
    //cout << "reach point 2" << endl;
    //
    this->printCountMap();
    //
    //cout << "reach point 3" << endl;
    //
    return true;
}

bool Minesweeper::toggleMine(int _x, int _y){
    if(_x<0 || _x>=mWidth) return false;
    if(_y<0 || _y>=mHeight) return false;
    if(mMap.empty()) return false;
    if(onPlay) return false;
    if(mMap[_y][_x]=='.') mMap[_y][_x]='*';
    else mMap[_y][_x]='.';
    this->fillCountMap(this->mWidth, this->mHeight);
    this->printCountMap();
    return true;
}

size_t Minesweeper::width() const{
    return mWidth;
}

size_t Minesweeper::height() const{
    return mHeight;
}

char Minesweeper::get(int _x, int _y) const{
    if(_x<0 || _x>=mWidth) return ' ';
    if(_y<0 || _y>=mHeight) return ' ';
    return mMap[_y][_x];
}

void Minesweeper::fillCountMap(size_t _width, size_t _height){
    int dx[8] = {1,-1,0,0,1,1,-1,-1};
    int dy[8] = {0,0,1,-1,1,-1,1,-1};
    while(!countMap.empty()) countMap.pop_back();
    for(int i= 0; i< _height; i++){
        string row = "";
        for(int j=0; j< _width; j++){
            int count = 0;
            if(mMap[i][j]=='*'){
                row += '*';
                continue;
            }
            for(int dir=0; dir<8; dir++){
                int ny = i + dx[dir];
                int nx = j + dy[dir];
                if(nx<0 || nx>=_width || ny<0 || ny>=_height){
                    continue;
                }
                if(mMap[ny][nx]=='*') count++;
            }
            row += (count+'0');
        }
        countMap.push_back(row);
    }
}


void Minesweeper::printCountMap() const{
    for(int i=0; i<countMap.size(); i++){
        cout << countMap[i] << endl;
    }
}

bool Minesweeper::setPlay(){
    if(countMap.empty()) return false;
    this->onPlay = true;
    while(!playMap.empty()) playMap.pop_back();
    for(int i=0; i<mHeight; i++){
        string row = "";
        for(int j=0; j<mWidth; j++) row += '_';
        playMap.push_back(row);
    }
    printPlayMap();
    mTouchCount = 0;
    return true;
}

void Minesweeper::printPlayMap() const{
    for(int i=0; i<mHeight; i++){
        cout << playMap[i] << endl;
    }
}

bool Minesweeper::touchMap(int _x, int _y){
    if(!onPlay) return false;
    if(_x<0 || _x>=mWidth || _y<0 || _y>=mHeight) return false;
    mTouchCount++;
    if(countMap[_y][_x]=='*'){
        onPlay = false;
        while(!countMap.empty()) countMap.pop_back();
        while(!mMap.empty()) mMap.pop_back();
        return true;
    }
    else{
        playMap[_y][_x]=countMap[_y][_x];
        this->printPlayMap();
        return false;
    }
}

int Minesweeper::touchCount() const{
    return mTouchCount;
}

