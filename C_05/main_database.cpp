//
// Created by zxx on 2022/5/16.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "student.h"
#include "../C_04/af_console.h"

// ���ݴ洢��������
int DB_SIZE = 40;
struct Student database[40];   // ԽСԽ���׹۲����, ��ʽ�Ŀ��Ըĳ�400
//��ʼ��
void db_init() {
    for (int i = 0; i < DB_SIZE; ++i) {
        database[i].id = 0; // ѧ����Ϊ0����ʾ�յļ�¼
    }
}

//���һ����¼
void db_add(struct Student stu) {
    for (int i = 0; i < DB_SIZE; ++i) {
        if (database[i].id == 0) {
            database[i] = stu;
            break;
        }
    }
}

//¼��һ��ѧ������Ϣ
struct Student get_input_student() {
    struct Student stu;
    printf("ѧ��:");
    stu.id = af_get_int(0);

    printf("����:");
    char *name = af_get_string("No name");
    strcpy(stu.name, name);

    printf("�Ա�(Y/N): ");
    stu.sex = af_get_bool(true);

    printf("�ֻ�");
    char *phone = af_get_string("13223443344");
    strcpy(stu.cellphone, phone);

    return stu;
}

//�鿴���м�¼
void db_list() {
    int count = 0;
    for (int i = 0; i < DB_SIZE; ++i) {
        if (database[i].id > 0) {
            count++;
            struct Student *ps = &database[i];
            printf("[%04d]  %08d, %12s ,  %s , %14s \n",
                   i, ps->id, ps->name, ps->sex ? "��" : "Ů", ps->cellphone);
        }
    }
    printf("�� %d ��¼ \\n \n", count);
}

void db_find_by_name(char *nameFilter) {
    int count = 0;
    for (int i = 0; i < DB_SIZE; ++i) {
        Student *ps = &database[i];
        if (ps->id <= 0) {
            continue;
        }

        // �����Ӵ��Ƿ���� strstr (str, sub)
        if (strstr(ps->name, nameFilter) != NULL) {
            count++;
            printf("[%04d]  %08d , %12s , %s , %14s \n",
                   i,
                   ps->id,
                   ps->name,
                   ps->sex ? "��" : "Ů",
                   ps->cellphone);
        }
    }
    printf("���ҵ� %d ��¼ \n", count);
}

#define main05_1 main05

int main05_1() {
    db_init();

    printf("----- ѧ �� �� �� ϵ ͳ -----\n\n");
    printf("( �л���Ӣ������ )\n\n");

    while (true) {
        // ������ʾ��
        printf("\n> ");
        char *cmd = af_get_string("");

        if (strcmp(cmd, "quit") == 0) {
            break;
        } else if (strcmp(cmd, "help") == 0) {
            printf("help - ��ʾ����\n");
            printf("quit - �˳�ϵͳ\n\n");
            printf("list - �鿴���м�¼\n");
            printf("add  - ��Ӽ�¼\n");
            printf("del  - ɾ����¼\n");
            printf("find - ���Ҽ�¼\n");

        } else if (strcmp(cmd, "add") == 0) {
            struct Student stu = get_input_student();
            if (stu.id > 0) {
                db_add(stu);
                printf("OK�������\n");
            } else {
                printf("** �����ѧ��!\n");
            }

        } else if (strcmp(cmd, "list") == 0) {
            db_list();

        } else if (strcmp(cmd, "find") == 0) {
            printf("����Ҫ���ҵ�����: ");
            char *name = af_get_string("");

            if (strlen(name) > 0) {
                db_find_by_name(name);
            }

        } else {
            printf("����ʶ�������: %s \n", cmd);
        }
    }

    printf("\n�˳�ϵͳ,�ټ�!\n");
    getchar();
    return 0;
}