//
// Created by zxx on 2022/3/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 作者注：
   语法篇的重点是学习语法，至于scanf/gets这些函数并不重要；将来再学完语法之后，
   你不太可能再需要这些函数了，因为真正的项目一般都不是控制台这样的黑窗口程序。
   所以在这里提供了一些函数，大家直接调用就行了，只是为了方便练习。

   注：VS2013,2015下面把gets换成gets_s就行了，详情看《常见问题汇总》

   注：这6个函数采用"先声明后定义"的方式，函数体在main()的后面呢，相关语法请参考
   视频8.6讲的内容。
*/

// 输入一个字符串, 存到output里(左右的空白字符会被自动去掉)
char *AfGetString(char *output);

// 获取一个整数, 如果输入为空则返回默认值defValue
int AfGetInt(int defValue);

// 获取一个小数, 如果输入为空则返回默认值defValue
double AfGetDouble(double defValue);

// 获取单字符输入, 如果输入为空则返回默认值defValue
char AfGetChar(char defValue);

// 获取bool型输入, 如果输入为空则返回默认值defValue
// 支持"yes", "no" | "1", "0" | "true", "false"
bool AfGetBool(bool defValue);

struct User {
    int id;
    char name[128];
    char phone[32];
    bool vip;
};


struct Object{
    int id;
    char name[16];
};

#define main03_1 main03_1

int main03_1() {
//    User u;
//    u.id = AfGetInt(0);
//    AfGetString(u.name);
//    AfGetString(u.phone);
//    u.vip = AfGetBool(true);

    Object a = {1, "shaofa"};
    Object &r = a;
    int size = sizeof(r);
    printf("大小：%d \n", size);

    int a1 = 123;
    int b1 = 345;
    int &r1 = a1;
    r1 = b1;
    printf("a:%d, b:%d, r:%d", a1, b1, r1);

    // 加上这么一行, 则需要按回车后才能退出
    system("pause");
    return 0;
};

/* 从控制台输入各种类型的数据示例
   语法篇18章后可以完全不用scanf，直接使用这一套API
*/

// 去除头尾的空白字符, 返回一个C风格字符串指针
// 注： 不创建新的buffer，不作内存拷贝和移动
// 如果长空为零，则返回NULL
char *AfTrim(char *src) {
    char *pStart = NULL;
    char *pEnd = NULL;
    char *p;

    // 从第1个字符开始扫描
    for (p = src; *p != '\0'; p++) {
        if (*p == ' ' || *p == '\t' || *p == '\n') {

        } else {
            pStart = p; // 开头(拿到开头即跳出循环)
            break;
        }
    }

    // 全部为空白字符
    if (pStart == NULL) {
        *src = '\0';
        return NULL;
    }

    // 继续扫描
    bool nonBlank = true;
    for (;; p++) {
        if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\0') {
            if (nonBlank) {
                pEnd = p;
                nonBlank = false;
            }
            if (*p == '\0') break;
        } else {
            nonBlank = true;
        }
    }

    // 截断末尾的空白
    *pEnd = '\0';

    // 有效长度为0，返回空指针
    if (pEnd == pStart) return NULL;

    return pStart;
}

// 输入一个字符串, 返回接收到的长度
char *AfGetString(char *output) {
    char buf[512];
    gets(buf);
    char *str = AfTrim(buf);
    if (str == NULL) {
        output[0] = '\0';
        return NULL;
    } else {
        int n = strlen(str);
        memcpy(output, str, n + 1);
        return output;
    }
};

// 获取一个整数
int AfGetInt(int defValue) {
    char buf[512];
    char *str = AfGetString(buf);
    if (str == NULL) {
        return defValue;
    } else {
        return atoi(str);
    }
};

// 获取一个小数
double AfGetDouble(double defValue) {
    char buf[512];
    char *str = AfGetString(buf);
    if (str == NULL)
        return defValue;
    else
        return atof(str);
}

// 获取单字符输入
char AfGetChar(char defValue) {
    char buf[512];
    char *str = AfGetString(buf);
    if (str == NULL)
        return defValue;
    else
        return str[0];
}

// 获取bool型输入
// 获取单字符输入
bool AfGetBool(bool defValue) {
    char buf[512];
    char *str = AfGetString(buf);
    if (str == NULL)
        return defValue;
    else {
        if (strcmp(str, "YES") == 0 ||
            strcmp(str, "yes") == 0 ||
            strcmp(str, "1") == 0 ||
            strcmp(str, "true") == 0 ||
            strcmp(str, "TRUE") == 0) {
            return true;
        }
        return false;
    }
}
