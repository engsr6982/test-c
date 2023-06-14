#include <string>
#include <iostream>

#include <llapi/mc/CommandOrigin.hpp>
#include <llapi/mc/CommandOutput.hpp>
#include <llapi/mc/ItemStack.hpp>
#include <llapi/mc/Level.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/Types.hpp>

#include <llapi/EventAPI.h>
#include <llapi/GlobalServiceAPI.h>
// 命令头文件
#include <llapi/RegCommandAPI.h>
#include <llapi/DynamicCommandAPI.h>

extern Logger logger;

void RegCommand();

void PluginInit()
{
    std::cout << "12345667";
    if (!std::filesystem::exists("./plugins/EULA"))
    {
        std::string str;                     // 声明一个str的字符串变量
        std::cout << "请同意MoJang　EULA\n"; // 显示初始内容
        std::getline(std::cin, str);         // 从控制台输入一行字符串
        if (str != "y" && str != "yes")
        {
            exit(0);
        }
        WriteAllFile("./plugins/EULA", "true");
    }
    RegCommand();
}

using namespace RegisterCommandHelper;
void RegCommand()
{
    // 减短参数
    using Param_Type = DynamicCommand::ParameterType;
    auto cmd = DynamicCommand::createCommand("cpp", "CPP Test", CommandPermissionLevel::Any, {(CommandFlagValue)0x80}, {(CommandFlagValue)0});
    cmd->addOverload();
    cmd->setCallback([](DynamicCommand const &command, CommandOrigin const &origin, CommandOutput &output, std::unordered_map<std::string, DynamicCommand::Result> &results)
        {
            // 使用lambda表达式设置回调函数
            // 回调函数将在执行cmd命令时被调用
            // 回调函数的参数为command、origin、output和results
            // command表示执行的命令，origin表示命令的来源，output表示命令输出，results表示结果集
            output.success("hello"); // 回调函数的执行体，表示输出"hello"
        });
    // 安装命令 并转移所有权
    DynamicCommand::setup(std::move(cmd));
}