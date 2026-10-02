#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string title;
    int total;

    while(cin >> title){
        total += title.length();
    }

    cout << total;
}
