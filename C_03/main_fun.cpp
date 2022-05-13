//
// Created by zxx on 2022/3/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** ����ע��
   �﷨ƪ���ص���ѧϰ�﷨������scanf/gets��Щ����������Ҫ��������ѧ���﷨֮��
   �㲻̫��������Ҫ��Щ�����ˣ���Ϊ��������Ŀһ�㶼���ǿ���̨�����ĺڴ��ڳ���
   �����������ṩ��һЩ���������ֱ�ӵ��þ����ˣ�ֻ��Ϊ�˷�����ϰ��

   ע��VS2013,2015�����gets����gets_s�����ˣ����鿴������������ܡ�

   ע����6����������"����������"�ķ�ʽ����������main()�ĺ����أ�����﷨��ο�
   ��Ƶ8.6�������ݡ�
*/

// ����һ���ַ���, �浽output��(���ҵĿհ��ַ��ᱻ�Զ�ȥ��)
char *AfGetString(char *output);

// ��ȡһ������, �������Ϊ���򷵻�Ĭ��ֵdefValue
int AfGetInt(int defValue);

// ��ȡһ��С��, �������Ϊ���򷵻�Ĭ��ֵdefValue
double AfGetDouble(double defValue);

// ��ȡ���ַ�����, �������Ϊ���򷵻�Ĭ��ֵdefValue
char AfGetChar(char defValue);

// ��ȡbool������, �������Ϊ���򷵻�Ĭ��ֵdefValue
// ֧��"yes", "no" | "1", "0" | "true", "false"
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
    printf("��С��%d \n", size);

    int a1 = 123;
    int b1 = 345;
    int &r1 = a1;
    r1 = b1;
    printf("a:%d, b:%d, r:%d", a1, b1, r1);

    // ������ôһ��, ����Ҫ���س�������˳�
    system("pause");
    return 0;
};

/* �ӿ���̨����������͵�����ʾ��
   �﷨ƪ18�º������ȫ����scanf��ֱ��ʹ����һ��API
*/

// ȥ��ͷβ�Ŀհ��ַ�, ����һ��C����ַ���ָ��
// ע�� �������µ�buffer�������ڴ濽�����ƶ�
// �������Ϊ�㣬�򷵻�NULL
char *AfTrim(char *src) {
    char *pStart = NULL;
    char *pEnd = NULL;
    char *p;

    // �ӵ�1���ַ���ʼɨ��
    for (p = src; *p != '\0'; p++) {
        if (*p == ' ' || *p == '\t' || *p == '\n') {

        } else {
            pStart = p; // ��ͷ(�õ���ͷ������ѭ��)
            break;
        }
    }

    // ȫ��Ϊ�հ��ַ�
    if (pStart == NULL) {
        *src = '\0';
        return NULL;
    }

    // ����ɨ��
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

    // �ض�ĩβ�Ŀհ�
    *pEnd = '\0';

    // ��Ч����Ϊ0�����ؿ�ָ��
    if (pEnd == pStart) return NULL;

    return pStart;
}

// ����һ���ַ���, ���ؽ��յ��ĳ���
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

// ��ȡһ������
int AfGetInt(int defValue) {
    char buf[512];
    char *str = AfGetString(buf);
    if (str == NULL) {
        return defValue;
    } else {
        return atoi(str);
    }
};

// ��ȡһ��С��
double AfGetDouble(double defValue) {
    char buf[512];
    char *str = AfGetString(buf);
    if (str == NULL)
        return defValue;
    else
        return atof(str);
}

// ��ȡ���ַ�����
char AfGetChar(char defValue) {
    char buf[512];
    char *str = AfGetString(buf);
    if (str == NULL)
        return defValue;
    else
        return str[0];
}

// ��ȡbool������
// ��ȡ���ַ�����
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
