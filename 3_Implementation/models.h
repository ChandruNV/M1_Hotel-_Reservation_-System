#ifndef MODELS_DOT_H    
#define MODELS_DOT_H   

typedef struct person{
    char name[100];
    int id,age;
}Person;

typedef struct room{
   int id,
   roomNo,
   price;
   Person* occupiedBy;
}Room;

typedef struct hotel{
    char name[100];
    int capacity,
    id;
    Room* rooms;
}Hotel;

#endif