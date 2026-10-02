#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Stack{
    private:
        vector<int> vec = {};
        int capacity = 0;

    public:
        Stack(const vector<int>& v, int cap)
            :vec(v), capacity(cap) {}
        void append(int num){
            if(vec.size() < capacity){
                vec.push_back(num);
            }else{
                vec.erase(vec.begin());
                vec.push_back(num);
            }
        }

        // int read(int num){
        //     return vec[num];
        // }

        bool if_find(const auto x){
            auto it = find(vec.begin(), vec.end(), x);
            if(it != vec.end()){
                return true;
            }else{
                return false;
            }
        }
};

int main(){
    int capacity, length;
    vector<int> v;
    int x;

    for(int i = 0; cin >> x; i++){
        if(i==0){capacity=x;}
        else if(i==1){length=x;}
        else{
            v.push_back(x);
        }
    }

    // cout << capacity << '\n' << length;
    // for(int x:v){
    //     cout << x << '\n';
    // }

    vector<int> contain = {};
    Stack container(contain, capacity);

    int check = 0;

    // for(int x:v){
    //     cout << x << '\n';
    // }
    
    for(int x:v){
        cout << x << '\n';//
        if(container.if_find(x)){
            // cout << "find";
            ;
        }else{
            // cout << "not found";
            container.append(x);
            check += 1;
        }
    }

    cout << check;

    return 0;
}
