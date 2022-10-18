//Included header files and libraries
#include "employee.h"
#include "schedule.h"
#include <iostream>
//Defensive programming
#ifndef FULLTIMEEMPLOYEE_H
#define FULLTIMEEMPLOYEE_H

//Define the class
class fullTimeEmployee : public employee{
    public:
    int salary; //Salary rather than hourly_rate
    fullTimeEmployee(std::string name, int ID, int mySalary); //Full initialiser
    fullTimeEmployee(std::string name, int ID); //Partial initialiser
    void call_off(int day, int shift); //Schedule unavailability
    fullTimeEmployee(); //Empty initialiser
    void setData(std::string name, int ID, int mySalary); //update all data
    void setData(std::string name, int ID); //update key Data
    /*
    void countAvailability(int availability[]);
    int* setAvailability(int n, int availability[]);
    */
};
#endif
