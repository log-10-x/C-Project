#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total;//得到总行数
    cin >> total;

    int num;//得到每单行总词数量
    string temp;//零时存单词
    vector< unordered_set <string> > lines(total);//得到每单行总词
    for(int i = 0;i < total;++i){
        cin >> num;
        for(int j = 0;j < num;++j){
            cin >> temp;
            lines[i].insert(temp);
        }
    }

    int ask;//询问次数
    cin >> ask;

    vector<string> asks(ask);//询问单词
    for(int i = 0;i < ask;++i){
        cin >> temp;
        asks.push_back(temp);
    }

    //查找
    bool contain = false;
    for(string word:asks){
        for(int i = 0;i < total;++i){
            if(lines[i].count(word)){
                cout << i + 1 << ' ';
                contain = true;}
            }
        if(!contain){
            cout << ' ';
        }
        cout << '\n';
        contain = false;
    }
}
