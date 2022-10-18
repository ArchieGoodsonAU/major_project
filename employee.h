#include <iostream>
#include "schedule.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class employee{
    public:
    schedule mySchedule;
    int id;
    std::string firstName;
    int* unavailability;
    int unavailability_count;
    virtual void call_off() = 0;
    //virtual void setData(std::string new_name, int max_hours, int ID) = 0;
    employee();
};
#endif