#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a;
    for(int i = 2; i * i < a; i++){
        if(a%i == 0){
            b = a/i;
        }
    }
    cout << b;
}
