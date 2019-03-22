#include<iostream>
#include<time.h>
using namespace std;

int main(){
    srand((unsigned)(time(0)));
    cout<<rand()%2;
}
