# VSCode + MSVC + Cmake 配置

也不知道怎么想的， 搁这套娃
有一说一，真nm难配置

软件
vscode
cmake
git
vs 2022编译器

扩展
C/C++
C/C++ Extension Pack
C/C++ Themes
CMake
CMake Language Support
CMake Tools

拉取仓库什么的就省略了, 直接重点吧

1. 确保编译器正常运行
如果不确定，用vs试试就知道了

2. 确保cmake环境变量正常

3. 参考本仓库的launch和tasks配置

4. ctrl shift p 输入CMake:Configure，选择vs编译器

5. 打开你的plugin.cpp，按f5

就会生成dll到build/release/目录下

至于启动bds调试我也还没弄明白，只是编译没问题了