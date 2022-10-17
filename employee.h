#include <iostream>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class employee{
    public:
    int id;
    std::string firstName;
    int* unavailability;
    int unavailability_count;
    virtual void call_off() = 0;
    employee();
};
#endif