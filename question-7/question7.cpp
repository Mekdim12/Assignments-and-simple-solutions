#include <iostream>
#include <string>

using namespace std;

void secretFunction()
{
    // fixing thsi s just remove the function
    cout << "Access granted: You exploited the program!" << endl;
}

void vulnerableFunctionFixed()
{
    string buffer;
    cout << "Enter some input: ";
    getline(cin, buffer);
}

void vulnerableFunction()
{
    char buffer[20];
    cout << "Enter some input ";
    cin >> buffer;
}
int main()
{
    cout << "Type of low level security vulnerability is " << endl;
    cout << "1. STACK SMASHING" << endl;
    cout << "2. Code Injection Attack" << endl;
    // vulnerableFunction();
    vulnerableFunctionFixed();
    return 0;
}