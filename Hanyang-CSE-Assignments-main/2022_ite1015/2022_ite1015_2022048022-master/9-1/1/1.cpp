#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class A{
    public:
        A(){}
        virtual ~A(){ /*cout << "del A" << endl;*/ }
        virtual string test(){
            string ret = "";
            ret += _type;
            ret += "::test()";
            return ret;
        }
        virtual void setType(char c){
            _type = c;
        }
    private:
        char _type;
};
 
class B: public A{
    public:
        B(){}
        virtual ~B(){ /*cout << "del B" << endl;*/ }
       
        virtual string test(){
            string ret = "";
            ret += _type;
            ret += "::test()";
            return ret;
        }

        virtual void setType(char c){
            _type = c;
        }
    private:
        char _type;
};

class C: public B{
    public:
        C(){}
        virtual ~C(){ /*cout << "del C" << endl;*/ }
        
        virtual string test(){
            string ret = "";
            ret += _type;
            ret += "::test()";
            return ret;
        }
        virtual void setType(char c){
            _type = c;
        }
    private:
        char _type;
};



int main(){
    vector<A*>arr;

    while(1){
        string type;
        cin >> type;
        if(type=="A"){
            A* a = new A;
            a->setType('A');
            arr.push_back(a);
        }

        if(type=="B"){
            A* a = new B;
            a->setType('B');
            arr.push_back(a);
        }

        if(type=="C"){
            A* a = new C;
            a->setType('C');
            arr.push_back(a);
        }

        if(type=="quit") break;
    }

    for(auto i:arr){
        cout << i->test() << endl;
        delete i;
    }
}
