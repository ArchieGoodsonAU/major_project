#include <iostream>
#include "schedule.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class employee{
    //Abstract employee class from which all other employees will inherit
    public:
    schedule mySchedule; //Work Schedule
    schedule availability; //Availability (So employee can call off certain shifts)
    int id; //Unique numerical ID for employee
    int max_hours; //Max weekly hours
    std::string firstName; //For that personal touch :)
    virtual void call_off(int day, int shift) = 0; //Calling off is different for different types of employees so this function is purely virtual
    void checkSchedule(); //Check schedule against availability
    employee(); //Initiator
};
#endif
