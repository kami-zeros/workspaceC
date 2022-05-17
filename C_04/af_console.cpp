//
// Created by zxx on 2022/5/16.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 把字母转成小写
void af_string_lowercase(char *str) {
    for (int i = 0;; i++) {
        char ch = str[i];
        if (ch == 0) // 判断字符串结束
        {
            break;
        }
        if (ch >= 'A' && ch <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
}

// 把字母转成大写
void af_string_uppercase(char *str) {
    for (int i = 0;; i++) {
        char ch = str[i];
        if (ch == 0) // 判断字符串结束
        {
            break;
        }
        if (ch >= 'a' && ch <= 'z') {
            str[i] += ('A' - 'a');
        }
    }
}

// 去掉字符串两边的空白，返回处理后的结果
char *af_string_trim(char *str) {
    char *start = str;
    char *p = 0;

    // 找到头部
    for (p = str; *p != 0; p++) {
        char ch = *p;
        if (ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n') {
            start = p;
            break;
        }
    }

    // 达到尾部
    char *end = p;
    while (*end != 0) end++;

    // 从尾部往前找，找到第一个非空白字符
    for (p = end - 1; p >= start; p--) {
        char ch = *p;
        if (ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n') {
            break;
        }
    }
    *(p + 1) = 0; // 结尾置0

    return start;
}

// 定义一个全局的变量
char af_console_buffer[1000];

// 用户输入一个 string
char *af_get_string(char *defValue) {
    gets(af_console_buffer);

    char *str = af_string_trim(af_console_buffer);
    if (strlen(str) > 0) {
        return str;
    }
    return defValue; // 用户输入为空
}

// 用户输入一个int
int af_get_int(int defValue) {
    char *str = af_get_string(NULL);
    if (str != NULL) {
        return atoi(str);
    }
    return defValue;
}

// 用户输入一个double
double af_get_double(double defValue) {
    char *str = af_get_string(NULL);
    if (str != NULL) {
        return atof(str);
    }
    return defValue;
}

// 输入一个bool类型的值
// 其中 y/yes/true/1 为是， n/no/false/0 为否，大小写均支持
bool af_get_bool(bool defValue) {
    char *str = af_get_string(NULL);
    if (str != NULL) {
        af_string_lowercase(str);
        if (strcmp(str, "y") == 0
            || strcmp(str, "yes") == 0
            || strcmp(str, "true") == 0
            || strcmp(str, "1") == 0
                ) {
            return true;
        } else if (strcmp(str, "n") == 0
                   || strcmp(str, "no") == 0
                   || strcmp(str, "false") == 0
                   || strcmp(str, "0") == 0
                ) {
            return false;
        }

    }
    return defValue;
}

