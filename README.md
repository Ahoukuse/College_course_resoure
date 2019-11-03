# 我的全部家当

### 感兴趣的话随便用，也欢迎指点。

## 如何使用

> Linux 系统下

这个项目我使用[CMake](https://cmake.org/)来管理。所以你也需要有这个工具才行。


安装`CMake`后运行以下命令

    git clone git@github.com:Ahoukuse/College_course_resoure.git
    cd College_course_resoure
    chmod 775 haw.sh
    ./haw.sh test2.c on
 
好现在你就可以开始开发了。

在`C_course_code`中新建一个文件叫`test.c`

放入以下内容

    #include <stdio.h>

    #ifdef Localhost
    #include "TestModule/AhoTestModule.h"
    #endif // Localhost

    int main(int argc, char const *argv[])
    {
        INIT
        char str[20] = {0x0};
        //Gen_char(10,30);
        TEST_SECTION_BEGIN(7)

        scanf("%s",str);
        printf("%s\n",str);
        loggl("%s\n",str);

        TEST_SECTION_END

        

        DROP
        Static_analyze("check.data",7,SHOWERR | SHOWCURR);
        return 0;
    }

`TestModule`头文件的引入要在`Localhost`中进行

要在函数初始化栈时声明`INIT`,同时要在`main`函数结束前`DROP`回收内存

    TEST_SECTION_BEGIN(x)
        ...
    TEST_SECTION_END

用于执行x次某部语句

`Static_analyze`用于分析结果

函数为代码如下

    void Static_analyze(checkfile,times,show_mod);

