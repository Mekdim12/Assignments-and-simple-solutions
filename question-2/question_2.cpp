#include <iostream>
#include <limits>

using namespace std;

// int double float char bool
void check_int_type_limit(long long input_value)
{
    int max_int = numeric_limits<int>::max();
    cout << "Max int" << ": " << max_int << endl;
    cout << "Max int + 1" << ": " << max_int + 1 << " (Overflow)" << endl;
    int min_int = numeric_limits<int>::min();
    cout << "Min int" << ": " << min_int << endl;
    cout << "Min int - 1" << ": " << min_int - 1 << " (Underflow)" << endl;
    if (input_value > max_int)
    {
        cout << "Input value " << input_value << " is out of int range!" << endl;
    }
    else if (input_value < min_int)
    {
        cout << "Input value " << input_value << " is out of int range!" << endl;
    }
    else
    {
        int valid_int = static_cast<int>(input_value);
        cout << "Input value " << input_value << " is within int range: " << valid_int << endl;
    }
}

void check_double_type_limit(long double input_value)
{
    double max_double = numeric_limits<double>::max();
    cout << "Max double" << ": " << max_double << endl;
    cout << "Max double * 2" << ": " << max_double * 2 << " (Overflow to Inf)" << endl;
    double min_double = numeric_limits<double>::lowest();
    cout << "Min double" << ": " << min_double << endl;
    cout << "Min double * 2" << ": " << min_double * 2 << " (Underflow to -Inf)" << endl;
    if (input_value > max_double)
    {
        cout << "Input value " << input_value << " is out of double range!" << endl;
    }
    else if (input_value < min_double)
    {
        cout << "Input value " << input_value << " is out of double range!" << endl;
    }
    else
    {
        double valid_double = static_cast<double>(input_value);
        cout << "Input value " << input_value << " is within double range: " << valid_double << endl;
    }
}

void check_float_type_limit(long double input_value)
{
    float max_float = numeric_limits<float>::max();
    cout << "Max float" << ": " << max_float << endl;
    cout << "Max float * 2" << ": " << max_float * 2 << " (Overflow to Inf)" << endl;
    float min_float = numeric_limits<float>::lowest();
    cout << "Min float" << ": " << min_float << endl;
    cout << "Min float * 2" << ": " << min_float * 2 << " (Underflow to -Inf)" << endl;
    if (input_value > max_float)
    {
        cout << "Input value " << input_value << " is out of float range!" << endl;
    }
    else if (input_value < min_float)
    {
        cout << "Input value " << input_value << " is out of float range!" << endl;
    }
    else
    {
        float valid_float = static_cast<float>(input_value);
        cout << "Input value " << input_value << " is within float range: " << valid_float << endl;
    }
}

void check_char_type_limit(long long input_value)
{
    char max_char = numeric_limits<char>::max();
    cout << "Max char" << ": " << static_cast<int>(max_char) << endl;
    cout << "Max char + 1" << ": " << static_cast<int>(max_char + 1) << " (Overflow)" << endl;
    char min_char = numeric_limits<char>::min();
    cout << "Min char" << ": " << static_cast<int>(min_char) << endl;
    cout << "Min char - 1" << ": " << static_cast<int>(min_char - 1) << " (Underflow)" << endl;
    if (input_value > max_char)
    {
        cout << "Input value " << input_value << " is out of char range!" << endl;
    }
    else if (input_value < min_char)
    {
        cout << "Input value " << input_value << " is out of char range!" << endl;
    }
    else
    {
        char valid_char = static_cast<char>(input_value);
        cout << "Input value " << input_value << " is within char range: " << static_cast<int>(valid_char) << endl;
    }
}

int main()
{

    long double input = 10'000'000'000;
    cout << "Max input value: " << input << endl;

    check_int_type_limit((long long)input);
    check_double_type_limit(input);
    check_float_type_limit(input);
    check_char_type_limit((long long)input);

    return 0;
}