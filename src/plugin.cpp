#include <string>
#include <iostream>

#include <llapi/mc/Level.hpp>
#include <llapi/mc/Player.hpp>

// 命令头文件
#include <llapi/RegCommandAPI.h>
#include <llapi/DynamicCommandAPI.h>

#include <llapi/FormUI.h>

extern Logger logger;

void RegCommand();
void test_form(Player* pl);

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
            auto player = origin.getPlayer();
            test_form(player);
        });
    // 安装命令 并转移所有权
    DynamicCommand::setup(std::move(cmd));
}

using namespace Form;
void test_form(Player* pl) {
    CustomForm form2("Information Collection Form");                               // Initialize the form with title
        form2.addLabel("label1", "Personal Information")                               // Add a label shows "Personal Information"
        .addInput("username", "Your Name")                                         // Add an input line to gather player's name
        .addDropdown("sex", "Your Sex", { "Male","Female","Secret" })              // Add a dropdown to gather player's sex
        .addSlider("age", "Your Age", 3, 100)                                      // Add a slider to gather player's age

        .addLabel("label2", "MC Information")                                      // Add a label shows "MC Information"
        .addToggle("licensed", "Purchased a licensed Minecraft?", true)            // Add a toggle about whether he buys a licensed mc or not
        .addStepSlider("skill", "Skill Lvl", { "Beginner", "Amateur", "Pro" })     // Add a step slider shows his game skill level

        .sendTo(pl,                                     // Send the form to a player called "yqs112358"
            [](Player* player, auto result)                                        // Callback function to process the result
            {
                if (result.empty())                                                // Player cancelled the form
                    return;
                player->sendText("You have commited the form.");
                player->sendFormattedText("Your name: {}", result["username"]->getString());
            });
}