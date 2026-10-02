#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Cell{char letter;int count;};

int main(){
    int stat[26] = {0};
    vector<char> letter;
    string word;

    for(; cin >> word;){
        for(unsigned char a: word){
            letter.push_back(a);
        }
    }

    for(char x: letter){stat[x - 'A']++;}

    int max = 0;
    for(int x : stat){
        if(max < x){
            max = x;
        }
    }

    int head = 0;
    int times = 0;
    int outputs[max][26] = {0};

    for(int i = 0; i < 26; ++i){
        for(int out:stat){
            if(out - max >= 0){
                fill(outputs[i], outputs[i], '*');
            }else{
                fill(outputs[i], outputs[i], ' ');
            }
            fill(outputs[i], outputs[i], ' ');
        }
    }

    for(int a[max]:outputs){
        for(int b:a){
            cout << a << ' ';
        }
        cout << '\n';
    }
}
