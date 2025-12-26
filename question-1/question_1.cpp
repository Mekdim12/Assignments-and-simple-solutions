#include <iostream>
#include <limits>

using namespace std;
// https://en.cppreference.com/w/cpp/types/numeric_limits.html

int main()
{
    cout << "Limits for int:\n";
    cout << "Min: " << numeric_limits<int>::min() << "\n";
    cout << "Max: " << numeric_limits<int>::max() << "\n\n";

    cout << "Limits for unsigned int:\n";
    cout << "Min: " << numeric_limits<unsigned int>::min() << "\n";
    cout << "Max: " << numeric_limits<unsigned int>::max() << "\n\n";

    cout << "Limits for long:\n";
    cout << "Min: " << numeric_limits<long>::min() << "\n";
    cout << "Max: " << numeric_limits<long>::max() << "\n\n";

    cout << "Limits for unsigned long:\n";
    cout << "Min: " << numeric_limits<unsigned long>::min() << "\n";
    cout << "Max: " << numeric_limits<unsigned long>::max() << "\n\n";

    cout << "Limits for char:\n";
    cout << "Min: " << static_cast<int>(numeric_limits<char>::min()) << "\n";
    cout << "Max: " << static_cast<int>(numeric_limits<char>::max()) << "\n\n";

    cout << "Limits for unsigned char:\n";
    cout << "Min: " << static_cast<int>(numeric_limits<unsigned char>::min()) << "\n";
    cout << "Max: " << static_cast<int>(numeric_limits<unsigned char>::max()) << "\n\n";

    cout << "Limits for signed char:\n";
    cout << "Min: " << static_cast<int>(numeric_limits<signed char>::min()) << "\n";
    cout << "Max: " << static_cast<int>(numeric_limits<signed char>::max()) << "\n\n";

    cout << "Limits for short:\n";
    cout << "Min: " << numeric_limits<short>::min() << "\n";
    cout << "Max: " << numeric_limits<short>::max() << "\n\n";

    cout << "Limits for unsigned short:\n";
    cout << "Min: " << numeric_limits<unsigned short>::min() << "\n";
    cout << "Max: " << numeric_limits<unsigned short>::max() << "\n";

    return 0;
}