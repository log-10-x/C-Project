#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a;
    int total;
    int count = 0;
    vector<string> names = {};
    vector<string> repeats = {};


    while(cin >> a){
        if(count == 0){
            total = stoi(a);
        }else if(count <= total){
            names.push_back(a);
        }else if(count > total+1){
            auto p1 = find(names.begin(), names.end(), a);
            auto p2 = find(repeats.begin(), repeats.end(), a);
            if(p1 != names.end()){
                if(p2 == repeats.end()){
                    cout << "OK\n";
                    repeats.push_back(a);
                }else{
                    cout << "REPEAT\n";
                }
            }else{
                cout << "WRONG\n";
            }
        }
        ++count;
    }
}
