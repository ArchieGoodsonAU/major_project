#include "employee.h"
#include "schedule.h"
#include <iostream>
#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H
class fullTimeEmployee : public employee{
    public:
    int salary;
    void schedule_unavailabity();
    fullTimeEmployee(std::string name, int ID, int mySalary);
    fullTimeEmployee(std::string name, int ID);
    void call_off(int day, int shift);
    fullTimeEmployee();
    void setData(std::string name, int ID, int mySalary);
    void setData(std::string name, int ID);
    /*
    void countAvailability(int availability[]);
    int* setAvailability(int n, int availability[]);
    */
};
#endif