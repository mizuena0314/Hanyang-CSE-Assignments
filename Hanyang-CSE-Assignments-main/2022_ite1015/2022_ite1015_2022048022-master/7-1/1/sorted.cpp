#include "sorted.h"
#include <algorithm>

SortedArray::SortedArray(){};
SortedArray::~SortedArray(){};

void SortedArray::AddNumber(int num){
    numbers_.push_back(num);
}

std::vector<int> SortedArray::GetSortedAscending(){
    std::vector<int> tmp = numbers_;
    std::sort(tmp.begin(), tmp.end());
    return tmp;
}


std::vector<int> SortedArray::GetSortedDescending(){
    std::vector<int> tmp = numbers_;
    std::sort(tmp.begin(), tmp.end(), std::greater<int>() );
    return tmp;
}

int SortedArray::GetMax(){
    std::vector<int>tmp = this->GetSortedDescending();
    return tmp[0];
}


int SortedArray::GetMin(){
    std::vector<int>tmp = this->GetSortedAscending();
    return tmp[0];
}
