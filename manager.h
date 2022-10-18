#include "fullTimeEmployee.h"
#include "employee.h"
#include <iostream>
#ifndef MANAGER_H
#define MANAGER_H
class manager : public fullTimeEmployee{
    public:
    int ID;
    manager(std::string name);
    manager();
    std::string get_password();
    private:
    std::string password;

};
#endif