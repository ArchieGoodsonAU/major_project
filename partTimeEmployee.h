#include "employee.h"
#include <iostream>
#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H
class partTimeEmployee : public employee{
    public:
        int maxHours;
        void schedule_unavailabity();
        int hourly_wage;
        partTimeEmployee(std::string name, int max_hours, int ID);

        void call_off();
    /*
    void countAvailability(int availability[]);
    int* setAvailability(int n, int availability[]);
    */
};
#endif