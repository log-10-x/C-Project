#include <iostream>
#include <vector>
using namespace std;

int conbine(vector<int> v, int num, int sum, int i = 0);

// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<int> v = {1, 2, 3, 4};
//     int n = v.size();

//     for (int i = 0; i < n; ++i)
//         for (int j = i + 1; j < n; ++j)
//             for (int k = j + 1; k < n; ++k)
//                 std::cout << v[i] << " " << v[j] << " " << v[k] << "\n";

//     return 0;
// }

int main(){
    int num, sum;
    vector<int> v;
    int x;

    for(int times = 1;cin >> x;times++){
        switch (times){
        case 1:num = x;break;
        case 2:sum = x;break;
        default:
            v.push_back(x);
            break;
        }
    }
    // cout << num << ' ' << sum <<'\n';
    // for(int i : v){cout << i;}
    return 0;
}

//     for (int i = 0; i < n; ++i)
//         for (int j = i + 1; j < n; ++j)
//             for (int k = j + 1; k < n; ++k)
//                 std::cout << v[i] << " " << v[j] << " " << v[k] << "\n";

int conbine(vector<int> v, int num, int sum, int i=0){
    if(size(v)==1){
        return v[0];
    }
    else{
        for(; i < num; i++){
            conbine(v, num, sum-1, i+1);
        }
    }
}
