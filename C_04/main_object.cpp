//
// Created by zxx on 2022/5/13.
// 面向对象：头文分离
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "DataStore.h"
#include "af_console.h"
#include "student.h"

#define main04_1 main04

class Object{
public:
    void Test(){
        printf("this: %p \n", this);
    }
};

void funDataStore();

void funAfConsole();

int main04_1() {
    //funDataStore();

    //测试对象是否相同
    Object obj;
    printf("Obj: %p \n", &obj);
    obj.Test();

    funAfConsole();

    return 0;
}

//字符串的输入
void funAfConsole() {
    char *p = af_get_string("nothing");
    printf("input: %s \n", p);

    /////数字的输入
    printf("输入年龄: ");
    int a = af_get_int(0);

    printf("输入身高: ");
    double b = af_get_double(0.0);

    printf("性别(Y/N): ");
    bool c = af_get_bool(true);

    printf("----------------\n");
    printf("age: %d, tall: %.1lf ，sex: %d \n", a, b, c);

    ////结构体的输入
    struct Student2 stu;

    printf("输入学号: ");
    stu.id = af_get_int(0);

    printf("输入姓名: ");
    char* name = af_get_string("No Name");
    strcpy(stu.name, name); // 将用户输入的字符串拷贝下来

    printf("性别(Y/N): ");
    stu.sex = af_get_bool(true);

    printf("联系方式: ");
    char* phone = af_get_string("13800000000");
    strcpy(stu.cellphone, phone); // 将用户输入的字符串拷贝下来

    printf("\n----- 学生信息 --------\n");
    printf("学号: %d \n", stu.id);
    printf("姓名: %s \n", stu.name);
    printf("性别: %d \n", stu.sex);
    printf("手机: %s \n", stu.cellphone);
}

//结构体的 头源分离
void funDataStore() {
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

    printf("FFF:%d, NNN:%s \n", f->id, f->name);
}


