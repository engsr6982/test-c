#include <string>
#include <iostream>

#include <llapi/mc/CommandOrigin.hpp>
#include <llapi/mc/CommandOutput.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Level.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/Types.hpp>

#include <llapi/DynamicCommandAPI.h>
#include <llapi/EventAPI.h>
#include <llapi/GlobalServiceAPI.h>

extern Logger logger;

void PluginInit()
{
    if (!std::filesystem::exists("./plugins/EULA"))
    {
        std::string str;//声明一个str的字符串变量
        std::cout << "请同意MoJang　EULA\n";//显示初始内容
        std::getline(std::cin, str);  // 从控制台输入一行字符串
        if (str != "y" && str != "yes")
        {
            exit(0);
        }
        WriteAllFile("./plugins/EULA", "true");
    }
}