#include <stdio.h>
#include <stdlib.h>

#include "models.h"
#include "test.h"


void bookRoom(Hotel *hotel);
void printChart(Hotel hotel);
void runTests();

int main(void)
{
    // Initializing new Hotel
    Hotel hotel1;
    printf("Please Enter the Hotel name: ");
    fgets(hotel1.name, 100, stdin); // Getting Hotel name
    printf("Please Enter No of rooms: ");
    scanf("%d", &(hotel1.capacity));
    hotel1.id = 1;

    // Initializing memory for rooms
    hotel1.rooms = (Room *)malloc(hotel1.capacity * sizeof(Room *));
    int i;
    // Initializing Rooms
    for (i = 0; i < hotel1.capacity; i++)
    {
        (hotel1.rooms + i)->id = i + 1;
        printf("Enter room no of %d room: ", i + 1);
        scanf("%d", &((hotel1.rooms + i)->roomNo));
        printf("Enter price of %d room: ", i + 1);
        scanf("%d", &((hotel1.rooms + i)->price));
        (hotel1.rooms + i)->occupiedBy = (Person *)malloc(1 * sizeof(Person));
        (hotel1.rooms + i)->occupiedBy->id = 0;
    }

    printf("\n\n");

    int choice = 0;
    while (choice != 4)
    {
        printf("1) Book a room\n");
        printf("2) Print chart\n");
        printf("3) Exit\n");
        printf("4) Run tests\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bookRoom(&hotel1);
            break;
        case 2:
            printChart(hotel1);
            break;
        case 3:
            choice = 4;
            break;
        case 4:
            runTests();
            break;
        default:
            printf("WRONG CHOICE!!!\n");
            break;
        }
    }
    return 0;
}

void bookRoom(Hotel *hotel)
{
    printf("Available Rooms: \n");
    int noOfRoomsAvailable = 0,i;
    for (i = 0; i < hotel->capacity; i++)
    {
        if ((hotel->rooms + i)->occupiedBy->id == 0)
        {
            printf("Room no: %d price - rs.%d\n", (hotel->rooms + i)->roomNo, (hotel->rooms + i)->price);
            noOfRoomsAvailable++;
        }
    }

    if (noOfRoomsAvailable == 0){
        printf("No Rooms Available\n");
        return;
    }
        

    printf("please Enter the Room no to book: \n");
    int roomNo = 0;
    scanf("%d", &roomNo);
    for (i = 0; i < hotel->capacity; i++)
    {
        if ((hotel->rooms + i)->roomNo == roomNo)
        {
            printf("please Enter Your Name: \n");
            scanf("%s", (hotel->rooms + i)->occupiedBy->name);
            printf("Please Enter Your age: \n");
            scanf("%d", &((hotel->rooms + i)->occupiedBy->age));
            (hotel->rooms + i)->occupiedBy->id = 1;
        }
    }
}

void printChart(Hotel hotel)
{
	int i;
    for (i = 0; i < hotel.capacity; i++)
    {
        if ((hotel.rooms + i)->occupiedBy->id != 0)
            printf("RoomNo: %d Occupied by: %s\n", (hotel.rooms + i)->roomNo, (hotel.rooms + i)->occupiedBy->name);
    }
}

void runTests(){
	if(testPerson() == 1)printf("TEST #1 PASSED\n");
	else printf("TEST #2 FAILED\n");
	
	if(testRoom() == 1)printf("TEST #2 PASSED\n");
	else printf("TEST #2 FAILED\n");
	
	if(testHotel() == 1)printf("TEST #3 PASSED\n");
	else printf("TEST #3 FAILED\n");
}
