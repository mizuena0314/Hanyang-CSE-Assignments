#include "message.h"

MessageBook::MessageBook(){}
MessageBook::~MessageBook(){}

void MessageBook::AddMessage(int number, const std::string& message){
    messages_[number]=message;
}

void MessageBook::DeleteMessage(int number){
    messages_.erase(number);
}

std::vector<int> MessageBook::GetNumbers(){
    std::vector<int>tmp;
    for(std::map<int, std::string>::iterator it = messages_.begin(); it!=messages_.end(); it++){
        tmp.push_back(it->first);
    }
    return tmp;
}

const std::string& MessageBook::GetMessage(int number){
    return messages_[number];
}
