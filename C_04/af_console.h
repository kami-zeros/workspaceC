//
// Created by zxx on 2022/5/16.
// 字符串的输入（转换）
//

#ifndef WORKSPACEC_AF_CONSOLE_H
#define WORKSPACEC_AF_CONSOLE_H

#include <stdbool.h>

//把字符串转成小写
void af_string_lowercase(char *str);

//把字符串转成大写
void af_string_uppercase(char *str);

//去掉字符串两边的空白，返回处理后的结果
char *af_get_string(char *str);

//用户输入一个 string
char *af_get_string(char *defValue);

//用户输入一个int
int af_get_int(int defValue);

//用户输入一个double
double af_get_double(double defValue);

//// 输入一个bool类型的值
//// 其中 y/yes/true/1 为是， n/no/false/0 为否，大小写均支持
bool af_get_bool(bool defValue);

#endif //WORKSPACEC_AF_CONSOLE_H
