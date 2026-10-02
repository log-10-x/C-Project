#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <variant>
using namespace std;

#define LETTERS ABCDEFGHIJKLMNOPQRSTUVWXYZ

int main(){
    using VarType= variant<int, char>;
    vector<vector<VarType>> stat;
    vector<char> letter;
    string word;
    int num;
    
    for (;cin >> word;) {
        for(unsigned char a:word){
            letter.push_back(a);
        }
    }
    
    for(char x:letter){
        num = count(letter.begin(), letter.end(), x);
        stat.push_back(vector<VarType>{x, num});
        letter.erase(std::remove(letter.begin(), letter.end(), x), letter.end());
    }

    sort(stat.begin(), stat.end(),
        [](const vector<VarType>& a,
           const vector<VarType>& b){
        return a[0] < b[0];
        });

    for(vector<VarType> x:stat){
        for(VarType y:x){
            visit([](const auto& val){
                cout << val << ' ';
            }, y);
        }
        cout << '\n';
    }
    
    //count(letter.begin(), letter.end(), )
    
    return 0;
}