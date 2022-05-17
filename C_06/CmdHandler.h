//
// Created by zxx on 2022/5/17.
//

#ifndef WORKSPACEC_CMDHANDLER_H
#define WORKSPACEC_CMDHANDLER_H

/**
 * 接口类
 */

class CmdHandler {
public:
    virtual ~CmdHandler(){}     // 析构函数声明为 virtual
    virtual void OnCommand(char *cmdline) = 0;  // 纯虚函数
};


#endif //WORKSPACEC_CMDHANDLER_H
