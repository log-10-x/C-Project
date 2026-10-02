#include <iostream>

int main()
{
    int k;
    std::cin >> k;
    float sum = 0;
    int i = 1;
    while(sum <= k)
    {
        sum += (float)1/i;
        i += 1;
        std::cout << sum << ' ';
    }

    int new_sum = sum + 1;

    std::cout << new_sum;
}
