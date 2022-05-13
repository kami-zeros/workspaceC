//
// Created by zxx on 2022/5/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DataStore.h"

DataStore *ds_create() {
    //动态创建对象
    DataStore *store = (DataStore *) malloc(sizeof(DataStore));
    //初始化
    store->head.next = NULL;

    return store;
}

void ds_destroy(DataStore *store) {
    //释放所有相关资源
    Student *p = store->head.next;
    while (p) {
        Student *next = p->next;
        free(p);
        p = next;
    }
    //销毁对象
    free(store);
}

void ds_add(DataStore *store, const Student *data) {
    // 创建对象、复制数据
    Student *copy = (Student *) malloc(sizeof(Student));
    *copy = *data;

    //插入一个对象到链表中
    Student *cur = store->head.next;    // 当前节点current
    Student *pre = &store->head;        // 上一个节点previous

    while (cur) {
        if (copy->id < cur->id) {       // 找到这个位置
            break;
        }
        pre = cur;
        cur = cur->next;                // 找到最后一个对象
    }

    //插入到pre节点的后面
    copy->next = pre->next;
    pre->next = copy;
}

// (2) 可以按ID来查找一个记录
Student *ds_find(DataStore *store, int id){
    Student *p = store->head.next;
    while (p) {
        if (p->id == id) {
            return p;
        }
        p = p->next;    //下一个对象
    }
    return NULL;
}

//(3) 可以按ID删除一个记录
void ds_remove(DataStore *store, int id){

}

// (4) 可以打印显示所有的记录
void ds_print(DataStore *store){
    Student *p = store->head.next;
    while (p) {
        printf("ID:%d, name:%s \n", p->id, p->name);
        p = p->next;    //下一个对象
    }
}


