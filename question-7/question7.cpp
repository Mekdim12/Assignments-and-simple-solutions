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
    cout << "\n===> FIXED FUNCTION <===\n"
         << endl;
    string buffer;
    cout << "Enter some input: ";
    getline(cin, buffer);
}

void vulnerableFunction()
{
    cout << "\n===> VULNERABLE FUNCTION <===\n"
         << endl;
    char buffer[20];
    cout << "Enter some input ";
    cin >> buffer;
}
int main()
{
    cout << "Type of low level security vulnerability is " << endl;
    cout << "1. STACK SMASHING" << endl;
    cout << "2. Code Injection Attack" << endl;
    cout << endl;
    // vulnerableFunction();
    vulnerableFunctionFixed();
    return 0;
}