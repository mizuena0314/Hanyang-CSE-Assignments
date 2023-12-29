#include <iostream>

using namespace std;

class A
{
};
class B : public A
{
};
class C : public B
{
};

int main(){
    int n;
    cout << "input num(0~2):";
    cin >> n;

    try{
        if(n == 0)
            throw A();
        else if(n == 1)
            throw B();
        else if(n == 2)
            throw C();
        else throw string("invalid input");
    }
    catch(string& e){
        cout << e << endl;
    }
    catch(C& c){
        cout << "throw C has been called" << endl;
    }
    catch(B& b){
        cout << "throw B has been called" << endl;
    }
    catch(A& a){
        cout << "throw A has been called" << endl;
    }

    return 0;
}
