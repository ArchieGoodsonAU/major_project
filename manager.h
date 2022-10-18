#include "fullTimeEmployee.h"
#include "employee.h"
#include <iostream>
#ifndef MANAGER_H
#define MANAGER_H
class manager : public fullTimeEmployee{
    bool canOpen;
    bool canClose;
};
#endif