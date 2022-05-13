//
// Created by zhangqiangqiang on 2022/3/25.
//

#include <stdio.h>
#include <string.h>

// 定义数据
struct Student {
    int id;
    char name[16];
    int scores[3];
};
Student data[100];  // 数据源 ：存储所有数据
int count = 0;      //总个数

// 定义一个用入信息输入的函数：
// 将输入的信息保存到输出参数s
// 返回0，表示成功录入。返回-1，表示录入失败。
int input(Student *s) {
    printf("ID:");
    scanf("%d", &s->id);

    printf("Name:");
    //gets(s->name); // char*
    scanf("%s", s->name);

    printf("Score:");
    int a, b, c;
    scanf("%d,%d,%d", &a, &b, &c);
    s->scores[0] = a;
    s->scores[1] = b;
    s->scores[2] = c;
    //scanf("%d,%d,%d",&s->scores[0], &s->scores[1], &s->scores[2]);
    return 0;
}

//函数: 将新录入的学生信息保存到数据源
// 返回值：0，成功；-1，失败
int add(const Student *student){
    data[count] = *student;
    count++;
    return 0;   // 总是成功
}

//函数: 将数据源里所有记录全部打印显示。
void list_all(){
    printf("ID \tName \tScore \n");
    printf("------------------------\n");

    for (int i = 0; i < count; ++i) {
        Student *s = &data[i];
        printf("%d \t%s \t%d,%d,%d \n",
               s->id,
               s->name,
               s->scores[0],
               s->scores[1],
               s->scores[2]);
    }
    printf("------------------------\n");
}

//  按照名称查找
Student *find(const char *name){
    for (int i = 0; i < count; ++i) {
        Student *s = &data[i];
        if (strcmp(name, s->name) == 0) {
            return s;
        }
    }
    return NULL;
}

#define main03 main03

int main03(){
    char cmdline[128];
    while (1) {
        printf("> ");
        scanf("%s", cmdline);

        // 退出
        if (strcmp(cmdline, "exit") == 0) {
            break;
        }

        // 菜单处理
        if (strcmp(cmdline, "add") == 0) {
            Student s;
            input(&s);
            add(&s);
            continue;
        }

        if (strcmp(cmdline, "list") == 0) {
            list_all();
            continue;
        }

        if (strcmp(cmdline, "count" )== 0) {
            printf("total: %d \n", count);
            continue;
        }

        if (strcmp(cmdline, "find") == 0) {
            printf("enter Name: ");
            char name[16];
            scanf("%s", name);

            Student *s = find(name);
            if (s) {
                printf("Found: ID:%d, Name:%s,Score:%d,%d,%d\n",
                       s->id, s->name,
                       s->scores[0], s->scores[1],
                       s->scores[2]);
            } else {
                printf("Not Found\n");
            }
            continue;
        }

        printf("Bad Input\n");
    }
    return 0;
}

int test ()
{
    Student s;

    //input(&s);
    s.id = 1024;
    strcpy(s.name, "shaofa");
    s.scores[0] = 70;
    s.scores[1] = 80;
    s.scores[2] = 90;

    add(&s);

    list_all();
    return 0;
}

