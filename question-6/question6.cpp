#include <iostream>
#include <cstdio>

using namespace std;
void vulnerableFunctionFixed(int input_size = 100)
{
    char input[input_size];
    cout << "Enter some text: ";
    cin >> input;

    printf("%s\n", input); // Fixed: Use %s to treat input as data, not format
}

void vulnerableFunction()
{
    char input[100];
    cout << "Enter some text: ";
    cin >> input;

    printf(input);
}

int main()
{
    cout << "Type of low level security vulnerability is FORMAT STRING VULNERABILITY" << endl;
    vulnerableFunctionFixed();
    return 0;
}