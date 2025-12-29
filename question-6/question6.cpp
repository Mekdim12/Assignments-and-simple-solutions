#include <iostream>
#include <cstdio>

using namespace std;
void vulnerableFunctionFixed(int input_size = 100)
{
    cout << "\n\ninside fixed function\n";
    char input[input_size];
    cout << "Enter some text: " << endl;
    cin >> input;

    printf("%s", input); // Fixed: Use %s to treat input as data, not format
    cout << endl;
}

void vulnerableFunction()
{
    cout << "\nInsinde vulnerable function \n";
    char input[10];
    cout << "Enter some text: " << endl;
    cin >> input;

    printf(input);
}

int main()
{
    cout << "Type of low level security vulnerability is FORMAT STRING VULNERABILITY" << endl;
    vulnerableFunction();
    vulnerableFunctionFixed();
    return 0;
}