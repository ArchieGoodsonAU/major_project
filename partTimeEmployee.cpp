//include headers and libraries
#include "employee.h"
#include "partTimeEmployee.h"
#include "schedule.h"
#include <iostream>


partTimeEmployee::partTimeEmployee(std::string name, int given_max_hours, int ID){
    //Initialiser with key information

    this->firstName = name; //For that personal touch
    this->max_hours = given_max_hours; //Maximum hours to work per week
    this->id = ID; //Numerical ID
}
partTimeEmployee::partTimeEmployee(){
    //Empty/default initialiser
    this->firstName = "N/A"; //No name given
    this->max_hours = -1; //To differentiate from employees with no max hours
    this->id = 0; //Empty numerical ID

}
partTimeEmployee::partTimeEmployee(std::string name, int given_max_hours, int ID, int hourly_rate){
    //Full initialiser
    mySchedule = schedule(); //initialise schedule
    hourly_wage = hourly_rate; //Hourly pay
    firstName = name; //For that personal touch
    max_hours = given_max_hours; //Maximum hours per week
    id = ID; //Numerical ID

}

void partTimeEmployee::setData(std::string name, int given_max_hours, int ID){
    //Update/set key data

    hourly_wage = 21; //Minimum wage (default pay)
    firstName = name; //For that personal touch
    max_hours = given_max_hours; //Max weekly hours
    id = ID; //Numerical ID 

}

void partTimeEmployee::call_off(int day, int shift){
    //for setting unavailability
        mySchedule.update_schedule(day, shift, 1); //Update schedule to unworkable
        for(int i = 0; i < 5; i++){ //loop through days
            for(int j = 0; j < 3; j++){ //loop through shifts
                std::cout << j <<  mySchedule.mySchedule[i][j] << " "; //display schedule
            }
            std::cout << std::endl; // new line
        }
}
void partTimeEmployee::call_of(int day, int shift){ //
        mySchedule.update_schedule(day, shift, 1);
        std::cout << shift << std::endl;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 3; j++){
                std::cout << mySchedule.mySchedule[i][j] << " ";
            }
            std::cout << std::endl;
        }
}

void partTimeEmployee::setData(std::string name, int given_max_hours, int ID, int hourly_rate){
    //Full data reassignment
    hourly_wage = hourly_rate; //Set hourly pay
    firstName = name; //For that personal touch
    max_hours = given_max_hours; //Max weekly workload
    id = ID; //Numerical ID
}



