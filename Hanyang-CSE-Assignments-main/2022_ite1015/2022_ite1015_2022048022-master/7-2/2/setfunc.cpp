#include <iostream>
#include "setfunc.h"

#define iter std::set<int>::iterator

std::set<int> parseSet(const std::string& str){
    std::set<int>tmp;
    int sum=0;
    bool neg=false;
    for(int i=0; i<str.size(); i++){
        if(str[i]==' '){
            if(str[i-1]=='{') continue;
            else if(str[i+1]=='}'){
                if(neg) sum*=-1; 
                tmp.insert(sum);
            }
            else{
                if(neg) sum*=-1;
                tmp.insert(sum);
                sum = 0;
                neg = false;
            }
        }
        else{
            if(str[i]=='-') neg = true;
            else if(str[i]=='{' || str[i]=='}') continue;
            else sum = sum*10+(str[i]-'0');
        }
    }
    return tmp;
}


void printSet(const std::set<int>&res){
    std::cout << "{ ";
    for(iter it=res.begin(); it!=res.end(); it++) std::cout << *it << ' ';
    std::cout << "}" << std::endl;
}

std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1){
    std::set<int>tmp;
    for(iter it=set0.begin(); it!=set0.end(); it++){
        if(set1.find(*it)!=set1.end()) tmp.insert(*it);
    }
    return tmp;
}

std::set<int> getUnion(const std::set<int>& set0, const std::set<int>& set1){
    std::set<int>tmp;
    for(iter it=set0.begin(); it!=set0.end(); it++) tmp.insert(*it);
    for(iter it=set1.begin(); it!=set1.end(); it++) tmp.insert(*it);
    return tmp;
}

std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1){ 
    std::set<int>tmp;
    for(iter it=set0.begin(); it!=set0.end(); it++){
        if(set1.find(*it)==set1.end()) tmp.insert(*it);
    }
    return tmp;
}
