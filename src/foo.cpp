#include "../inc/foo.hpp"
#include "foo_one.cpp"
#include "foo_two.cpp"

internal void myFunction()
{
    u8 val1 = myFunctionOne(1);
    u8 val2 = myFunctionTwo(2);
}
