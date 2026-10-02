#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct Cell{
    string word;
    int counts;
};

int main(){
    vector<string> word;
    string x;

    for(;cin >> x;){
        string temp;
        for(unsigned char y:x){
            temp.push_back(tolower(y));
        }
        x = temp;
        x.erase(remove(x.begin(), x.end(), '.'), x.end());
        word.push_back(x);
    }

    int num;
    vector<Cell> stat = {};
    vector<string> repeat = {};

    for(auto i:word){
        if(repeat.end() == find(repeat.begin(), repeat.end(), i)){
            repeat.push_back(i);
            num = count(word.begin(), word.end(), i);
            stat.push_back(Cell(i, num));
            // cout << i;
        }
    }

    sort(stat.begin(), stat.end(),
        [](const Cell& a, const Cell& b){return a.word < b.word;});

    for(Cell x:stat){
        cout << x.word << ':' << x.counts << '\n';
    }
}
