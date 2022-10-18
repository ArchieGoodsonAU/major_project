#include <iostream>
#include "employee.h"
#include "fullTimeEmployee.h"

fullTimeEmployee::fullTimeEmployee(std::string name, int ID, int mySalary){
    //Initiator with all information
    salary = mySalary; //Yearly earnings
    this->firstName = name; //For that personal touch :)
    this->max_hours = 38; //Full time maximum hours
    this->id = ID; //Numerical ID
}

fullTimeEmployee::fullTimeEmployee(std::string name, int ID){
    //Initiator with critical information
    salary = 42255; //Full time minimum wage (default salary)
    this->firstName = name; //For that personal touch
    this->max_hours = 38; //Max full time hours
    this->id = ID; //Numerical ID
}

fullTimeEmployee::fullTimeEmployee(){
    //Empty initiator
    this->firstName = "N/A"; //No name
    this->max_hours = -1; //To be distinguishable from employees with no availability
    this->id = 0; // Empty numerical ID

}
void fullTimeEmployee::setData(std::string name, int ID, int mySalary){
    //std::cout << "attempt made";
    this->firstName = name;
    this->max_hours = 38;
    this->id = ID;
    salary = mySalary;
    //this->mySchedule = schedule();
}
void fullTimeEmployee::setData(std::string name, int ID){
    //Update personal data
    this->firstName = name; //For that personal touch
    this->max_hours = 38; //Full time max hours (default)
    this->id = ID; //Numerical ID

}

void fullTimeEmployee::call_off(int day, int shift){
    //To ensure valid inheritance
}
