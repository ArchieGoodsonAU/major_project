#include "employee.h"
#include "schedule.h"
#include <iostream>
#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H
class fullTimeEmployee : public employee{
    int maxHours;
    int salary;
    void schedule_unavailabity();
    fullTimeEmployee(int availability[]);
    void call_off();
    /*
    void countAvailability(int availability[]);
    int* setAvailability(int n, int availability[]);
    */
};
#endif