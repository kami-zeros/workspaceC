//
// Created by zxx on 2022/5/13.
// 面向对象：头文分离
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DataStore.h"

#define main04_1 main


int main04_1() {
    DataStore *store = ds_create();

    Student s;
    s.id = 1;
    strcpy(s.name, "111");
    ds_add(store, &s);

    s.id = 2;
    strcpy(s.name, "222");
    ds_add(store, &s);

    Student *f = ds_find(store, 2);

    ds_print(store);
    ds_destroy(store);

    printf("FFF:%d, NNN:%s", f->id, f->name);

    return 0;
}


