#include <iostream>
#include "schedule.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class employee{
    public:
    schedule mySchedule;
    schedule availability;
    int id;
    int max_hours;
    std::string firstName;
    int* unavailability;
    int unavailability_count;
    virtual void call_off(int day, int shift) = 0;
    void checkSchedule();
    //virtual void setData(std::string new_name, int max_hours, int ID) = 0;
    employee();
};
#endif