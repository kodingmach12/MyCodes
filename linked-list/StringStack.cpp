#include <string>
#include <iostream>
using namespace std;

class StringStack{
    static const int size = 100;
    const string* stack[size];
    int index;
   public:
    StringStack();
    void push(const string* s);
    const string* pop();
}

StringStack :: StringStack() : index(0) {
    memset(stack,0,size * sizeof(string*) );
}

StringStack :: push(const string* s){
    if(index<size)
        stack[index++]=s;
}

const string* StringStack :: pop(){
    if(index>0)

}
