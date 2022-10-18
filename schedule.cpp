#include <iostream>
#include "schedule.h"
schedule::schedule(){
    for(int day = 0; day < 5; day++){
        for(int shift = 0; shift < 3; shift++){
            mySchedule[day][shift] = 0;
        }
    }
}
void schedule::update_schedule(int day, int shift, int updatedAvail){
    mySchedule[day][shift] = updatedAvail;
    std::cout << shift << std::endl;
}