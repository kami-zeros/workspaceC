//
// Created by zxx on 2022/5/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Tutorial {
public:
    Tutorial() {
        printf("P �Ĺ��캯��");
    }

//    virtual
    ~Tutorial() {
        printf("P ����������");
    }

public:
    char name[32];
    char author[16];
public:
    virtual void ShowInfo() {
        printf("Tutorial: %s, %s \n", name, author);
    }

protected:
    int abc;
};

//�̳�
class VideoTutorial : public Tutorial {
public:
    VideoTutorial() {
        printf("C �Ĺ��캯��");
    }

    ~VideoTutorial() {
        printf("C ����������");
    }

public:
    void Play() {
        printf("Playing...abc=%d\n", abc);
    }

    void ShowInfo() {
        printf("VideoTutorial: %s, %s \n", name, author);
    }

public:
    char url[128];
    int visits;
};


//--------------------------------------
#include "CmdInput.h"
#include "CmdParser.h"

//-------------------------------------


#define main06_1 main

int main06_1() {
    VideoTutorial cpp_guide;
    strcpy(cpp_guide.name, "Cѧϰ");
    strcpy(cpp_guide.author, "�ȸ�");
    //cpp_guide.ShowInfo();

    strcpy(cpp_guide.url, "http://1111");
    cpp_guide.visits = 1000;

    Tutorial *p = &cpp_guide;
    //printf("Parent::a = %s \n", p->name);
    //p->ShowInfo();

    //delete p;
    //cpp_guide.abc = 123;

    //-----------------------------------
    CmdInput input;
    CmdParser parser;
    input.SetHandler(&parser);
    input.Run();

    return 0;
}
