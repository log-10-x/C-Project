#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //获取集合长度
    int length;
    cin >> length;

    //获取集合
    vector<int> set = {};//遍历
    unordered_set<int> dict = {};//查询
    int num;
    for(int i = 0;i < length;++i){
        cin >> num;
        set.push_back(num);
        dict.insert(num);
    }

    //组合对比
    int sum;
    int output = 0;
    for(int i = 0;i < length;++i){
        for(int j = i+1;j < length;++j){
            sum = set[i] + set[j];
            if(dict.count(sum)){
                output += 1;
                dict.erase(sum);
            }
        }
    }
    cout << output;
}
