//include header files and libraries
#include "employee.h"
#include "schedule.h"
#include <iostream>

//defensive programming
#ifndef PARTTIMEEMPLOYEE_H
#define PARTTIMEEMPLOYEE_H


class partTimeEmployee : public employee{
    //Employee with changeable max hours
    public:
        schedule mySchedule; //Work schedule
        int hourly_wage; //Hourly pay
        partTimeEmployee(); //Default initialiser
        partTimeEmployee(std::string name, int max_hours, int ID); //Key variables initialiser
        partTimeEmployee(std::string name, int max_hours, int ID, int hourly_rate); //All data initialiser
        void setData(std::string name, int max_hours, int ID); //Update key information
        void setData(std::string name, int max_hours, int ID, int hourly_rate); //Update all information
        void call_off(int day, int shift); //Schedule unavailability
        void call_of(int day, int shift);

};
#endif
