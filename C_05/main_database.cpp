//
// Created by zxx on 2022/5/16.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "student.h"
#include "../C_04/af_console.h"

// 数据存储在数组里
int DB_SIZE = 40;
struct Student database[40];   // 越小越容易观察测试, 正式的可以改成400
//初始化
void db_init() {
    for (int i = 0; i < DB_SIZE; ++i) {
        database[i].id = 0; // 学号置为0，表示空的记录
    }
}

//添加一条记录
void db_add(struct Student stu) {
    for (int i = 0; i < DB_SIZE; ++i) {
        if (database[i].id == 0) {
            database[i] = stu;
            break;
        }
    }
}

//录入一条学生的信息
struct Student get_input_student() {
    struct Student stu;
    printf("学号:");
    stu.id = af_get_int(0);

    printf("姓名:");
    char *name = af_get_string("No name");
    strcpy(stu.name, name);

    printf("性别(Y/N): ");
    stu.sex = af_get_bool(true);

    printf("手机");
    char *phone = af_get_string("13223443344");
    strcpy(stu.cellphone, phone);

    return stu;
}

//查看所有记录
void db_list() {
    int count = 0;
    for (int i = 0; i < DB_SIZE; ++i) {
        if (database[i].id > 0) {
            count++;
            struct Student *ps = &database[i];
            printf("[%04d]  %08d, %12s ,  %s , %14s \n",
                   i, ps->id, ps->name, ps->sex ? "男" : "女", ps->cellphone);
        }
    }
    printf("共 %d 记录 \\n \n", count);
}

void db_find_by_name(char *nameFilter) {
    int count = 0;
    for (int i = 0; i < DB_SIZE; ++i) {
        Student *ps = &database[i];
        if (ps->id <= 0) {
            continue;
        }

        // 查找子串是否存在 strstr (str, sub)
        if (strstr(ps->name, nameFilter) != NULL) {
            count++;
            printf("[%04d]  %08d , %12s , %s , %14s \n",
                   i,
                   ps->id,
                   ps->name,
                   ps->sex ? "男" : "女",
                   ps->cellphone);
        }
    }
    printf("共找到 %d 记录 \n", count);
}

#define main05_1 main05

int main05_1() {
    db_init();

    printf("----- 学 生 管 理 系 统 -----\n\n");
    printf("( 切换到英文输入 )\n\n");

    while (true) {
        // 命令提示符
        printf("\n> ");
        char *cmd = af_get_string("");

        if (strcmp(cmd, "quit") == 0) {
            break;
        } else if (strcmp(cmd, "help") == 0) {
            printf("help - 显示帮助\n");
            printf("quit - 退出系统\n\n");
            printf("list - 查看所有记录\n");
            printf("add  - 添加记录\n");
            printf("del  - 删除记录\n");
            printf("find - 查找记录\n");

        } else if (strcmp(cmd, "add") == 0) {
            struct Student stu = get_input_student();
            if (stu.id > 0) {
                db_add(stu);
                printf("OK，已添加\n");
            } else {
                printf("** 错误的学号!\n");
            }

        } else if (strcmp(cmd, "list") == 0) {
            db_list();

        } else if (strcmp(cmd, "find") == 0) {
            printf("输入要查找的名字: ");
            char *name = af_get_string("");

            if (strlen(name) > 0) {
                db_find_by_name(name);
            }

        } else {
            printf("不能识别的命令: %s \n", cmd);
        }
    }

    printf("\n退出系统,再见!\n");
    getchar();
    return 0;
}