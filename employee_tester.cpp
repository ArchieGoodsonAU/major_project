#include <iostream>
#include "employee.h"
#include "fullTimeEmployee.h"
#include "partTimeEmployee.h"
#include <time.h>
#include <iomanip>
using std::string;

int main(void) {
    time_t start, end;
    std::cout << "Start testing for full time employees" << std::endl;
    time(&start);
    int num_of_full;
    std::cin >> num_of_full;
    fullTimeEmployee* fulltimers = new fullTimeEmployee[num_of_full];
    for (int i = 0; i < num_of_full; i++) {
        string name;
        int ID;
        int salary;
        std::cin >> name;
        std::cin >> ID;
        std::cin >> salary;
        fulltimers[i].setData(name, ID, salary);
        if (fulltimers[i].firstName != name) {
            std::cout << "Test " << i + 1 << " Failed at setting name" << std::endl;
            std::cout << "Expected: " << name << "   Outputted: " << fulltimers[i].firstName << std::endl;
        }
        if (fulltimers[i].id != ID) {
            std::cout << "Test " << i + 1 << " Failed at setting id" << std::endl;
            std::cout << "Expected: " << ID << "    Outputted: " << fulltimers[i].id << std::endl;
        }
        if (fulltimers[i].salary != salary) {
            std::cout << "Test " << i + 1 << " Failed at setting salary" << std::endl;
            std::cout << "Expected: " << salary << "    Outputted: " << fulltimers[i].salary << std::endl;
        }
    }
    std::cout << "Finished testing in full time employees" << std::endl;
    time(&end);
    double time_taken = double(end - start);
    std::cout << "Time taken for full timers is : " << std::fixed << std::setprecision(3) << time_taken << std::endl;
/*
    std::cout << "Start testing for part time employees" << std::endl;
    int num_of_part;
    std::cin >> num_of_part;
    partTimeEmployee* parttimers = new partTimeEmployee[num_of_part];
    for (int i = 0; i < num_of_part; i++) {
        string name;
        int max_hours;
        int ID;
        int hourly_wage;
        std::cin >> name;
        std::cin >> max_hours;
        std::cin >> ID;
        std::cin >> hourly_wage;
        parttimers[i].setData(name, max_hours, ID, hourly_wage);
        if (parttimers[i].firstName != name) {
            std::cout << "Test " << i + 1 << " Failed at setting name" << std::endl;
        }
        if (parttimers[i].maxHours != max_hours) {
            std::cout << "Test " << i + 1 << " Failed at setting max hours" << std::endl;
        }
        if (parttimers[i].id != ID) {
            std::cout << "Test " << i + 1 << " Failed at setting id" << std::endl;
        }
        if (parttimers[i].hourly_wage != hourly_wage) {
            std::cout << "Test " << i + 1 << " Failed at setting hourly wage" << std::endl;
        }
    }
    std::cout << "Finished testing in part time employees" << std::endl;
*/
    return 0;
}
