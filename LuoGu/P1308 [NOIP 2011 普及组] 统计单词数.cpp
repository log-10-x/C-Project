#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;


int main(){
    string target;
    vector<string> sentence;
    vector<char> letter;
    string x;

    for(int i = 0; cin >> x; i++){
        string temp;
        for(unsigned char y:x){
            temp.push_back(tolower(y));
        }
        x = temp;
        if(i == 0){target=x;}
        else{sentence.push_back(x);
            sentence.push_back(" ");}
    }


    auto it = find(sentence.begin(), sentence.end(), target);
    // cout << target << '\n';
    // for(auto i : sentence){cout << i << ' ';}
    // cout << count(sentence.begin(), sentence.end(), target) << '\n';

    if(it != sentence.end()){
        vector<string> sub(sentence.begin(), it);
        for(string x:sub){
            for(char y:x){
                letter.push_back(y);
            }
        }
        cout << distance(letter.begin(), letter.end());
        cout << count(sentence.begin(), sentence.end(), target);
    }else{cout << "-1";}
}
