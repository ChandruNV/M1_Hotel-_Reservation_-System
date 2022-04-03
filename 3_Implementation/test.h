#ifndef TEST_DOT_H    
#define TEST_DOT_H 
#include "models.h"

int testPerson(){
    Person tempPerson = {"Sample Name",1,20};
    if(tempPerson.age == 20 && tempPerson.id == 1) return 1;
    return 0;
}

int testRoom(){
	Room tempRoom = {1,101,2500,0};
	if(tempRoom.id ==1 && tempRoom.price == 2500 && tempRoom.roomNo == 101 && tempRoom.occupiedBy == 0) return 1;
	return 0;
}

int testHotel(){
	Hotel tempHotel = {"Random",1,12,0};
	if(tempHotel.id == 12,tempHotel.capacity =1)return 1;
	else return 0;
}

#endif
