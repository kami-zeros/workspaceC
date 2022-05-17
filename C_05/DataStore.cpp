//
// Created by zxx on 2022/5/17.
// 构造函数 与 析构函数 且头源分离
//
#include <stdlib.h>
#include <stdio.h>

#include "DataStore.h"

DataStore::DataStore() {
    m_head.next = NULL;
}

DataStore::~DataStore() {
    Student *p = m_head.next;
    while (p) {
        Student *next = p->next;
        free(p);
        p = next;
    }
}

void DataStore::Add(const Student *data) {
    //创建对象、复制数据
    Student *copy = (Student *) malloc(sizeof(Student));
    *copy = *data;

    //插入一个对象到链表中
    Student *cur = m_head.next;     //当前节点的next
    Student *pre = &m_head;         //上一个节点

    while (cur) {
        if (copy->id < cur->id) {   //找到这个位置
            break;
        }
        //比cur的id大
        pre = cur;          //往后挪一个节点，为了在接下来的语句中，插入到pre后面
        cur = cur->next;
    }

    //插入到pre节点后面，cur前面（因为id小）
    copy->next = pre->next;
    pre->next = copy;
}

Student *DataStore::Find(int id) {
    Student *p = m_head.next;
    while (p) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void DataStore::Print() {
    Student *p = this->m_head.next;
    while (p) {
        printf("ID: %d, name: %s\n", p->id, p->name);
        p = p->next; // 下一个对象
    }
}