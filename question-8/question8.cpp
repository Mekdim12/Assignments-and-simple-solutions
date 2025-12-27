
#include <iostream>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

// // Demonstrate Control Flow Hijacking via overwriting a function pointer (illustrative)
// struct Victim
// {
//     char buf[8];
//     void (*callback)();
// };
// void demonstrate_control_flow_hijack()
// {
//     Victim v;
//     v.callback = safe_target;
//     std::cout << "[CFH] before hijack calling callback:\n";
//     v.callback();

//     // Simulate a buffer overflow that overwrites the function pointer
//     // We copy the bytes of hijack_target into memory immediately after buf,
//     // which will overwrite the callback pointer on typical layouts.
//     void (*attack)() = hijack_target;
//     std::memcpy(v.buf + sizeof(v.buf), &attack, sizeof(attack)); // overflow write

//     std::cout << "[CFH] after overflow calling callback:\n";
//     v.callback(); // now likely calls hijack_target (undefined behavior but demonstrates concept)
// }

const string *leak_stack_pointer()
{
    const string course_name = "Computer Security";
    return &course_name; // return the address
}

void dangling_pointer_demo()
{
    const string *dangling = leak_stack_pointer();
    cout << "Dangling pointer address: " << static_cast<const void *>(dangling) << endl;
    cout << "Dereferencing dangling pointer (undefined behavior): " << *dangling << endl;
}

void use_after_free_demo()
{
    cout << "USE AFTER FREE" << endl;
    int *int_pointer = new int(42);
    cout << "Allocated int_pointer @" << int_pointer << " = " << *int_pointer << "\n";
    delete int_pointer;

    //  solution for this de referncing
    // int_pointer = nullptr; //

    cout << "value int_pointer after deleting value " << int_pointer << " = " << *int_pointer << "\n";
}

int add_pi(int x)
{
    return x + 3.14;
}
int multiply_pi(int x)
{
    return x * 3.14;
}

int print_value(int x)
{
    cout << "value is: " << x << endl;
    return x;
}

void returned_oriented_programming_demo()
{
    // creatre a pinter to function
    int (*chain_of_matmathaal_operations[])(int) = {print_value, add_pi, multiply_pi};

    int value = 7;
    int arraylength = sizeof(chain_of_matmathaal_operations) / sizeof(chain_of_matmathaal_operations[0]);
    for (int i = 0; i < arraylength; i++)
    {
        value = chain_of_matmathaal_operations[i](value);
    }
    cout << "Final value after ROP-like chain: " << value << endl;
}

void normal_flow_the_program()
{
    cout << "NORMAL PROGRAM FLOW DEMO" << endl;
    cout << "This function executes normally without hijacking." << endl;
}

void hijacked_flow_the_program()
{
    cout << "HIJACKED PROGRAM FLOW DEMO" << endl;
    cout << "This function simulates hijacked control flow!" << endl;
}

void control_flow_hijacking_demo(bool is_controlled_by_Attacker = true)
{
    void (*function_pointer)() = normal_flow_the_program;
    //  spf first it will go to normal flow the program

    function_pointer();
    if (is_controlled_by_Attacker)
    {
        // Attacker overwrites function pointer to hijack control flow
        function_pointer = hijacked_flow_the_program;
    }
    // Now calls intercepted by attacker
    function_pointer();
}

int main()
{
    cout << "=== Vulnerability demonstrations  ===";
    use_after_free_demo();
    returned_oriented_programming_demo();
    dangling_pointer_demo();
    control_flow_hijacking_demo();
    return 0;
}