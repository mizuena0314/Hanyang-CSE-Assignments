#include "minimal_fighter.h"

MinimalFighter::MinimalFighter(){
    this->mHp = 0;
    this->mPower = 0;
    this->mStatus = Invalid;
}

MinimalFighter::MinimalFighter(int _hp, int _power){
    this->mHp = _hp;
    this->mPower = _power;
    if(_hp>0) this->mStatus = Alive;
    else this->mStatus = Dead;
}

int MinimalFighter::hp(){
    return (this->mHp);
}

int MinimalFighter::power(){
    return (this->mPower);
}

FighterStatus MinimalFighter::status(){
    return (this->mStatus);
}

void MinimalFighter::setHp(int _hp){
    this->mHp = _hp;
}

void MinimalFighter::setStatus(){
    if(this->mHp > 0) this->mStatus = Alive;
    else this->mStatus = Dead;
}

void MinimalFighter::hit(MinimalFighter *_enemy){
    _enemy->mHp -= this->mPower;
    this->mHp -= _enemy->mPower;
    this->setStatus();
    _enemy->setStatus();
}

void MinimalFighter::attack(MinimalFighter *_enemy){
    _enemy->mHp -= this->mPower;
    this->mPower = 0;
    this->setStatus();
    _enemy->setStatus();
}

void MinimalFighter::fight(MinimalFighter *_enemy){
    while(this->mHp > 0 && _enemy->mHp > 0){
        this->hit(_enemy);
    }
    this->setStatus();
    _enemy->setStatus();
}
