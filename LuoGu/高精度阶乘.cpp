#include <iostream>
#include <iterator>


int fact(int num);
int muti(int num1, int num2);

int main()
{
    int input;

    std::cin >> input;

    int a = 0;

    for(int i = 1; i <= input; i++)
    {
        a += fact(i);
    }

    std::cout << a << std::endl;
}

int fact(int num)
{
    int temp = 1;

    for(int i = 1; i <= num; i++)
    {
        temp = i * temp;
    }

    return temp;
}

int muti(int num1, int num2)
{
    int arr1[3];

    for(int i = 0; i < std::size(); i++)
    {
        
    }
}
