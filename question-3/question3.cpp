#include <iostream>
#include <limits>

using namespace std;

void safe_add(int val_1, int val_2)
{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();

    //  If a + b > max, then a > max - b

    if (val_2 > 0 && val_1 > max - val_2)
    {
        cout << "Overflow detected: " << val_1 << " + " << val_2 << " would exceed " << max << endl;
    }
    else if (val_2 < 0 && val_1 < min - val_2)
    {
        cout << "Underflow detected: " << val_1 << " + " << val_2 << " would be less than " << min << endl;
    }
    else
    {
        cout << "Result: " << val_1 + val_2 << " (Safe)" << endl;
    }
}

void safe_subtract(int a, int b)
{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();

    if (b > 0 && a < min + b)
    {
        cout << "Underflow detected: " << a << " - " << b << " is below " << min << endl;
    }
    else if (b < 0 && a > max + b)
    {
        cout << "Overflow detected: " << a << " - " << b << " exceeds " << max << endl;
    }
    else
    {
        cout << "Result: " << a - b << " (Safe)" << endl;
    }
}

void safe_multiply(int a, int b)
{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();

    if (a > 0 && b > 0 && a > max / b)
    {
        cout << "Overflow detected!" << endl;
    }
    else if (a > 0 && b < 0 && b < min / a)
    {
        cout << "Underflow detected!" << endl;
    }
    else if (a < 0 && b > 0 && a < min / b)
    {
        cout << "Underflow detected!" << endl;
    }
    else if (a < 0 && b < 0 && a < max / b)
    {
        cout << "Overflow detected!" << endl;
    }
    else
    {
        cout << "Result: " << a * b << " (Safe)" << endl;
    }
}

int main()
{
    int large_val = 2147483640;  // 2^31-1
    int small_neg = -2147483640; // -2^31

    cout << "--- Testing Arithmetic Safety ---" << endl;

    safe_add(large_val, 1000);
    safe_subtract(small_neg, 0);
    safe_multiply(1000000, 3000);

    return 0;
}