//Multi Stack Implementation in a Single Array
#include <iostream>
#define max 5
using namespace std;
struct M_Strack{
    int data [max];
    int topA, topB;
};
M_Strack S, *p;
void init(){
    p=&S;
    p->topA=-1;
    p->topB=max;
}
int EmptyA(){
    if(p->topA==-1)
        return 1;
    else
        return 0;
}int EmptyB(){
    if(p->topB==max)
        return 1;
    else
        return 0;
}
int Full(){
    if(p->topA+1 == p->topB)
        return 1;
    else
        return 0;
}
void pushA(int x){
    if(Full())
    return;
    p->topA++;
    p->data[p->topA]=x;
}
void pushB(int x){
    if(Full())
    return;
    p->topB--;
    p->data[p->topB]=x;
}
int popA(){
    if(EmptyA())
        return -1;
    int x=p->data[p->topA];
    p->topA--;
    return x;
}
int popB(){
    if(EmptyB())
        return -1;
    int x=p->data[p->topB];
    p->topB++;
    return x;
}
int main(){
    init();
    pushA(1);
    pushA(2);
    pushB(10);
    pushB(9);
    cout<<popA()<<endl;
    cout<<popB()<<endl;
    return 0;
}