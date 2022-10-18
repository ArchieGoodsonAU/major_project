#include "employee.h"
#include "partTimeEmployee.h"
#include "fullTimeEmployee.h"
#ifndef ROSTER_H
#define ROSTER_H
class roster{
    public:
    bool accessible;
    roster();
    void input_employees();
};
#endif