//
// Created by zxx on 2022/5/17.
//

#ifndef WORKSPACEC_CMDINPUT_H
#define WORKSPACEC_CMDINPUT_H


#include "CmdHandler.h"

class CmdInput {
public:
    CmdInput();

    void SetHandler(CmdHandler *h);

    // 开始运行
    int Run();

private:
    CmdHandler *m_handler;
};


#endif //WORKSPACEC_CMDINPUT_H
