#include "employee.h"
#include "schedule.h"
#include <iostream>
employee::employee(){
    
}

void employee::checkSchedule(){
    int hourCount = 0; //Total hours worked
    schedule given_schedule = mySchedule;
    std::cout << "Hi " << firstName << " checking " << this->firstName  << "'s schedule!";
    for(int day = 0; day < 5; day++){ //Loop through every 
        for(int shift = 0; shift < 3; shift++){
            
            if(given_schedule.mySchedule[day][shift] == 0){ //If you are scheduled to work
                hourCount += 3; //Add 3 hours for 3 hour shift
                if(availability.mySchedule[day][shift] == 1){ //If you have called off this shift
                    //If both conditions are true, you have been scheduled for a shift you have called off
                    std::cout << this->firstName <<" has been scheduled for a shift on day " << day + 1 << "shift " << shift + 1 << " which they have previously booked off \n";
                    std::cout << "Please contact employee or change schedule \n \n";
                }
            }
        }
    }
    if(hourCount > max_hours){
        std::cout << this-> firstName <<" has been scheduled for " << hourCount << " hours this week, this excedes their indicated maximum hours of: " << max_hours << std::endl;
        std::cout << "Please contact employee or change schedule \n";
    }
    std::cout << "Schedule check complete!";
    return;
}