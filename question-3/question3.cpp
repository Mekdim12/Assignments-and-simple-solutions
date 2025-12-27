#include <iostream>
#include <limits>

using namespace std;

// 1. Safe Addition Check
void safe_add(int a, int b)
{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();

    // Logic: If a + b > max, then a > max - b
    if (b > 0 && a > max - b)
    {
        cout << "[ADD] Overflow detected: " << a << " + " << b << " would exceed " << max << endl;
    }
    else if (b < 0 && a < min - b)
    {
        cout << "[ADD] Underflow detected: " << a << " + " << b << " would be less than " << min << endl;
    }
    else
    {
        cout << "[ADD] Result: " << a + b << " (Safe)" << endl;
    }
}

// 2. Safe Subtraction Check
void safe_subtract(int a, int b)
{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();

    if (b > 0 && a < min + b)
    {
        cout << "[SUB] Underflow detected: " << a << " - " << b << " is below " << min << endl;
    }
    else if (b < 0 && a > max + b)
    {
        cout << "[SUB] Overflow detected: " << a << " - " << b << " exceeds " << max << endl;
    }
    else
    {
        cout << "[SUB] Result: " << a - b << " (Safe)" << endl;
    }
}

// 3. Safe Multiplication Check
void safe_multiply(int a, int b)
{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();

    if (a > 0 && b > 0 && a > max / b)
    {
        cout << "[MUL] Overflow detected!" << endl;
    }
    else if (a > 0 && b < 0 && b < min / a)
    {
        cout << "[MUL] Underflow detected!" << endl;
    }
    else if (a < 0 && b > 0 && a < min / b)
    {
        cout << "[MUL] Underflow detected!" << endl;
    }
    else if (a < 0 && b < 0 && a < max / b)
    {
        cout << "[MUL] Overflow detected!" << endl;
    }
    else
    {
        cout << "[MUL] Result: " << a * b << " (Safe)" << endl;
    }
}

int main()
{
    int large_val = 2147483640;  // Near INT_MAX
    int small_neg = -2147483640; // Near INT_MIN

    cout << "--- Testing Arithmetic Safety ---" << endl;

    safe_add(large_val, 10);      // Should Overflow
    safe_subtract(small_neg, 10); // Should Underflow
    safe_multiply(1000000, 3000); // Should Overflow

    return 0;
}