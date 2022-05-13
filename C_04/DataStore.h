//
// Created by zxx on 2022/5/13.
//

#ifndef WORKSPACEC_DATASTORE_H
#define WORKSPACEC_DATASTORE_H


struct Student{
    int id;
    char name[16];
    Student* next;
};

struct DataStore{
    Student head;
};

DataStore* ds_create();

void ds_destroy(DataStore *store);

void ds_add(DataStore *store, const Student *data);

// (2) 可以按ID来查找一个记录
Student *ds_find(DataStore *store, int id);

//(3) 可以按ID删除一个记录
void ds_remove(DataStore *store, int id);

// (4) 可以打印显示所有的记录
void ds_print(DataStore *store);


#endif //WORKSPACEC_DATASTORE_H
