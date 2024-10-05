## 0.0.4.1

- 修复GLFW链接报错
  - 因为当前工程是直接引用了最新版本的GLFW，这里不能直接照搬原来GLFW的premake5.lua的配置(原来的配置有漏包含一些文件)
  - 参考GLFW的CMakeLists，把漏包含的文件加到files配置中，重新生成项目，即可链接成功

## 0.0.4

- 添加预编译头文件
- 添加GLFW库
  - 链接GLFW报错，后续处理...
- 添加Window类

## 0.0.3.1

0.0.3版本构建失败问题修复

- 最终定位到问题出现在Application.cpp执行`CORE_LOG_TRACE(e)`的地方，使用spdlog格式化输出WindowResizeEvent时编译失败
- spdlog是基于<b>{fmt}</b>库的，它具有内置std::ostream支持，包括对具有重载插入运算符(operator<<)的用户定义类型的格式化
- 但是从<b>{fmt}</b>库的版本9开始，需要为从ostream_formatter派生的用户类显式地专门化(*specialize*) fmt::formatter结构
- [参考链接](https://stackoverflow.com/questions/62320177/cannot-format-argument-from-within-spdlog)

## 0.0.3

- 编写了事件系统，用来处理各种事件,ApplicationEvent、KeyEvent、MouseEvent
- 出现编译错误，关于spdlog，留待解决

## 0.0.2

- 引入<b>spdlog</b>库，通过git子模块链接到项目中
  - 在项目里添加子分支时要 `git submodule add "src" path`
- 通过premake构建工程
  - ps: premake[这个release版本](https://github.com/premake/premake-core/releases/tag/v5.0.0-beta2)或更新版本才支持构建vs2022

## 0.0.1

- 创建工程，创建HEngine库和Sandbox应用程序
