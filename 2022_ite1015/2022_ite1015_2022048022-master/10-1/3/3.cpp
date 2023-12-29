#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class B
{
    public:
        virtual ~B(){}
};

class C : public B
{
    public:
        void test() { cout << "C::test()" << endl; }
};

class D : public B
{
    public:
        void test() { cout << "D::test()" << endl; }
};

int main(){
    vector<B*>arr;
    while(1){
        string s;
        cin >> s;
        if(s == "B") arr.push_back(new B);
        if(s == "C") arr.push_back(new C);
        if(s == "D") arr.push_back(new D);
        if(s == "0") break;
    }

    for(auto i:arr){
        C* c = dynamic_cast<C*>(i);
        D* d = dynamic_cast<D*>(i);
        if(c){
            c->test();
            delete i;
        }
        else if(d){
            d->test();
            delete i;
        }
        else delete i;
    }
    return 0;
}

