#include "employee.h"
#include "schedule.h"
#include <iostream>
employee::employee(){
    //No initialiser as different types of employees initialise differently
}

void employee::checkSchedule(){
    
    //Check if MySchedule matches MyAvailability and total hours does not exceed max_hours
    int hourCount = 0; //Total hours worked
    std::cout << "Hi " << firstName << " checking " << this->firstName  << "'s schedule!"; //UI
    for(int day = 0; day < 5; day++){ //Loop through every day
        for(int shift = 0; shift < 3; shift++){ //Loop through every shift
            
            if(mySchedule.mySchedule[day][shift] == 0){ //If you are scheduled to work
                hourCount += 3; //Add 3 hours for 3 hour long shift
                if(availability.mySchedule[day][shift] == 1){ //If you have called off this shift
                    //If both conditions are true, you have been scheduled for a shift you have called off
                    //UI
                    std::cout << this->firstName <<" has been scheduled for a shift on day " << day + 1 << " shift " << shift + 1 << " which they have previously booked off \n";
                    std::cout << "Please contact employee or change schedule \n \n";
                }
            }
        }
    }
    if(hourCount > max_hours){ //Too many hours have been scheduled
        //UI
        std::cout << this-> firstName <<" has been scheduled for " << hourCount << " hours this week, this excedes their indicated maximum hours of: " << max_hours << std::endl;
        std::cout << "Please contact employee or change schedule \n";
    }//UI
    std::cout << "Schedule check complete!";
    return; //Void function as no output is needed other than cout
}
