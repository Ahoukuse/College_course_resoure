# 我的全部家当

### 感兴趣的话随便用，也欢迎指点。

## 如何使用

> Linux 系统下

这个项目我使用[CMake](https://cmake.org/)来管理。所以你也需要有这个工具才行。


安装`CMake`后运行以下命令

    git clone git@github.com:Ahoukuse/College_course_resoure.git
    cd College_course_resoure
    chmod 775 haw.sh
    ./haw.sh test.c on

你还要在`C_course_code`创建用于测试的`in.data`和`out.data`文件

    touch in.data out.data
 
好现在你就可以开始开发了。

在`C_course_code`中新建一个文件叫`test.c`

放入以下内容

    #include "TestModule/AhoTestModule.h"

    int main(int argc, char const *argv[])
    {
        INIT                              //  一定要在开头引入 'INIT'
        
        TEST_SECTION_BEGIN(10)            //在这之中包围的代码会被执行10次

        /*>>>这里是将被测试的代码<<<*/

        TEST_SECTION_END                  //标示结束

        DROP                              //在return前要引入 'DROP'
        return 0;
    }


要在函数初始化栈时声明`INIT`,同时要在`main`函数结束前`DROP`

    TEST_SECTION_BEGIN(x)
        ...
    TEST_SECTION_END

用于执行x次某部语句

`Static_analyze`用于分析结果

函数为代码如下

    void Static_analyze(checkfile,times,show_mod);

