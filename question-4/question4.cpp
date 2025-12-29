#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <cctype>
// #include <windows.h>

using namespace std;

struct USER_dETAIL
{
    char username[20];
};

char *legacy_gets(char *buffer)
{
    // ref for later properties from cstdio library

    // Reads sequential characters from stdin, stops when it sees a newline or EOF; never stores the newline, does append a null terminator.
    // Never checks how much space the destination buffer has—every character keeps writing past the end if input is longer than expected, so the moment you exceed the buffer you hit undefined behavior.
    // Shorter input than the buffer: copies all characters, writes '\0', works as long as there’s no overflow.
    // Input exactly filling the buffer capacity: still overflows because there’s no room left for the terminator.
    // Input longer than the buffer: keeps writing through adjacent memory (stack variables, return addresses, etc.); the program may seem fine, crash, or be exploitable.
    // Hitting EOF before any character: returns nullptr and leaves the buffer unchanged; after copying some characters, EOF acts like newline—string is null-terminated.
    // mimic gets behavior without its risks
    int ch;
    char *cursor = buffer;

    while (true)
    {
        ch = getchar();
        if (ch == EOF)
        {
            if (cursor == buffer)
                return nullptr;
            break;
        }
        if (ch == '\n')
            break;
        *cursor++ = static_cast<char>(ch);
    }

    *cursor = '\0';
    return buffer;
}

char *custom_llccopy(const char *str, int buffer_size = 100)
{
    char buf[buffer_size];
    char *p;

    bool is_overflowed = strlen(str) >= buffer_size;
    if (is_overflowed)
    {
        cout << "Warning: Buffer overflow detected!" << endl;
    }

    strcpy(buf, str); // Vulnerable: No bounds checking
    for (p = buf; *p; p++)
    {
        if (isupper(*p))
        {
            *p = tolower(*p);
        }
    }
    return strdup(buf);
}
// string _custom_get()
// {
//     string input;
//     cin >> noskipws; // Disable skipping whitespace
//     char ch;
//     while (true)
//     {
//         ch = getchar();
//         if (ch == '\n' || ch == EOF)
//             break;
//         input += ch;
//     }
//     return input;
// }

void example_1a(int buffer_size = 4)
{
    cout << "\n Example 1.a buffer overflow using gets" << endl;
    char buffer[buffer_size];
    // https://www.programiz.com/cpp-programming/library-function/cstdio/gets
    // its deprecated due to safety issues maybe fake it get the code from cstdio
    // gets(buffer);
    cout << "Please enter a string ";
    legacy_gets(buffer);
    cout << "You entered: " << buffer << endl;
    cout << "Buffer size: " << buffer_size << " Your inputy string length: " << strlen(buffer) << endl;
    bool overflowed = strlen(buffer) >= buffer_size;
    if (overflowed)
    {
        cout << "Warning: Buffer overflow detected!" << endl;
    }
}

void example_1b(int buffer_size = 6)
{
    cout << "\n Example 1.b buffer overflow using cin" << endl;
    char buf[buffer_size];
    cout << "please enter a string: ";
    cin >> buf;

    cout << "You entered: " << buf << endl;
    bool overflowed = strlen(buf) >= buffer_size;
    if (overflowed)
    {
        cout << "Warning: Buffer overflow detected!" << endl;
    }
}

void example_2(int max_input_size = 200)
{
    cout << "\n Example 2 buffer overflow using memcpy" << endl;
    char buf[64];
    char user_input[max_input_size];
    int bytes;

    cout << "Enter buffer contents:" << endl;
    read(0, user_input, max_input_size - 1);

    cout << "how much bytes to copy: ";
    cin >> bytes;

    memcpy(buf, user_input, bytes);

    bool is_overflowed = bytes >= sizeof(buf);
    if (is_overflowed)
    {
        cout << "Warning: Buffer overflow detected!" << endl;
    }
    cout << "Copied to buf\n";
    cout << "Finnal Buffer contents: " << buf << endl;
}

void example_3()
{
    cout << "\n Example 3 buffer overflow using strcpy" << endl;
    const char *original = "HelloWorldFromCPlusPlus";
    char *modified = custom_llccopy(original, 3);
    cout << "Original: " << original << endl;
    cout << "Modified: " << modified << endl;
}

void example_4()
{
    // MY ToDo: come back to this later
}

void example_5(int username_length = 2)
{
    cout << "\n Example 5 buffer overflow using with mock MultiByteToWideChar " << endl;
    // WCHAR unicodeUser[username_length + 1];
    const char *WCHAR;

    const char *username = "softwaresecurity";
    int max_of_accepted_length = (username_length + 1) * sizeof(WCHAR); // tottal byte

    bool is_overflowed = strlen(username) > max_of_accepted_length;
    if (is_overflowed)
    {
        cout << "Warning: Buffer overflow detected!" << endl;
    }
    else
    {
        cout << "Username accepted: " << username << endl;
    }

    //     MultiByteToWideChar(CP_ACP, 0, username, -1,
    //                         unicodeUser, sizeof(unicodeUser));
    // review this part later
}
int main()
{
    example_1a();
    example_1b();
    example_2();
    example_3();
    example_4();
    example_5();
    return 0;
}