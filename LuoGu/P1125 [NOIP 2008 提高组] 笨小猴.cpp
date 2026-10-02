#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string in;
    cin >> in;

    int maxn = 0;
    int minn = 100;
    int total;

    for(char a:in){
        total = count(in.begin(), in.end(), a);
        maxn = (maxn > total)?maxn:total;
        minn = (minn < total)?minn:total;
    }

    int num = maxn - minn;
    bool flag = true;

    if(num == 1){goto out1;}
    if(num == 2){goto out2;}
    for(int i = 2; i < num; ++i){
        if(num%i == 0){flag = false;}
    }

    if(flag){
        out2:
        cout << "Lucky Word\n" << num;
    }else{
        out1:
        cout << "No Answer\n" << 0;
    }
}
