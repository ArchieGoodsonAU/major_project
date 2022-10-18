#include "employee.h"
#include "schedule.h"
#include <iostream>
#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H
class partTimeEmployee : public employee{
    public:
        schedule mySchedule;
        int maxHours;
        void schedule_unavailabity();
        int hourly_wage;
        partTimeEmployee();
        partTimeEmployee(std::string name, int max_hours, int ID);
        partTimeEmployee(std::string name, int max_hours, int ID, int hourly_rate);
        void setData(std::string name, int max_hours, int ID);
        void setData(std::string name, int max_hours, int ID, int hourly_rate);
        void call_off(int day, int shift);
        void call_of(int day, int shift);
    /*
    void countAvailability(int availability[]);
    int* setAvailability(int n, int availability[]);
    */
};
#endif