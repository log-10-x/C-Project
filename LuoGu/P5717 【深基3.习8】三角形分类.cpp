#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());

    int min_num1 = v[0];
    int min_num2 = v[1];
    int max_num = v[2];

    if(max_num >= min_num1 + min_num2){
        cout << "Not triangle" << '\n';
    }
    else{
        if(max_num*max_num == min_num1*min_num1 + min_num2*min_num2){
            cout << "Right triangle" << '\n';
        }else if(max_num*max_num < min_num1*min_num1 + min_num2*min_num2){
            cout << "Acute triangle" << '\n';
        }else{
            cout << "Obtuse triangle" << '\n';
        }if(a == b || a == c || b == c){
            cout << "Isosceles triangle" << '\n';
        }if(a == b && a == c){
            cout << "Equilateral triangle" << '\n';
        }
    }
    return 0;
}
