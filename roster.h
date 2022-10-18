#include "employee.h"
#include "partTimeEmployee.h"
#include "fullTimeEmployee.h"
#include "manager.h"
#ifndef ROSTER_H
#define ROSTER_H
class roster{
    public:
    bool accessible;
    roster();
    void input_employees();
    void roster_employees();
    partTimeEmployee* part_time_employees;
    fullTimeEmployee* full_time_employees;
    int employeeCount;
    int ft_employeeCount;
    manager Manager;
};
#endif