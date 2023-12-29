#ifndef minesweeper_h
#define minesweeper_h

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Minesweeper
{
public:
    Minesweeper();
    ~Minesweeper();
    
    // return false when input is incorrect
    bool setMap(size_t _width, size_t _height, vector<string>& _map);
    bool toggleMine(int _x, int _y);
    
    // return map width, height, and char
    size_t width() const;
    size_t height() const;
    char get(int _x, int _y) const; // return ' ' if input is illegal
    
    bool setPlay(); // return false when map is not set
    bool touchMap(int _x, int _y); // return true when dead
    
    int touchCount() const;
    
private:
    // add private member variables and functions if it is needed.
    unsigned int mTouchCount;
    size_t mWidth;
    size_t mHeight;
    bool onPlay;
    vector<string> mMap;
    vector<string> countMap;
    vector<string> playMap;

    void fillCountMap(size_t width, size_t height);
    void printCountMap() const;
    void printPlayMap() const;
};

#endif /* minesweeper_h */

