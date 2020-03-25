#include "Student.h"

ostream& operator << (ostream& out, const Student& s1)
{
    out<<"Age:"<<s1.getAge()<<" Avg:"<<s1.getAvg();
    return out;
}