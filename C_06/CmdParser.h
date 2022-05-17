//
// Created by zxx on 2022/5/17.
//

#ifndef WORKSPACEC_CMDPARSER_H
#define WORKSPACEC_CMDPARSER_H
/**
 * 实现接口的类
 */

#include "CmdHandler.h"

class CmdParser: public CmdHandler {
public:
    CmdParser();

public:
    // 函数接口集
    virtual void OnCommand(char *cmdline);

private:
    // 解析命令
    int Split(char text[], char *parts[]);

};


#endif //WORKSPACEC_CMDPARSER_H
