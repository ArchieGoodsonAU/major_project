#include "manager.h"
#include "employee.h"
#include "roster.h"
#include "fullTimeEmployee.h"
#include <iostream>
manager::manager(std::string name){
    //countAvailability(availability);
    //unavailability = setAvailability(unavailability_count, availability);
    salary = 70000;
    this->firstName = name;
    this->maxHours = 45;
    this->id = 1;
    this->password = "ArchieRocks";
}
std::string manager::get_password(){
    return password;
}