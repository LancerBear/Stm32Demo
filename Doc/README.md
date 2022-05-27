# 项目说明

- 芯片STM32F103ZET6，普中开发板，stlink v2下载器
- 该项目作为linux环境下使用arm-none-eabi-gcc工具链编译stm32工程的模板，使用openocd工具烧写到目标机
- 当前项目实现在目标板上点亮LED0的功能

# 使用方式

- make 构建工程，根目录生成demo.elf demo.bin demo.hex文件

- make clean 清除构建结果

- make printf 打印Makefile中的一些变量，便于修改Makefile后debug

- make download 使用openocd通过stlink将demo.hex下载到目标机中

# 目录说明

```shell
Lancer@Lancer-PC:~/Documents/Codes/stm32/demo$ tree  -L 2
.
├── Libraries # 标准外设库文件，从STM32F10x_StdPeriph_Lib_V3.6.0/Libraries/STM32F10x_StdPeriph_Driver下拷贝
│   ├── inc
│   └── src
├── Makefile
├── Start # 启动相关文件
│   ├── core_cm3.c # 内核文件，从STM32F10x_StdPeriph_Lib_V3.6.0/Libraries/CMSIS/CM3/CoreSupport拷贝
│   ├── core_cm3.h
│   ├── startup_stm32f10x_hd.s # 启动汇编文件，STM32F10x_StdPeriph_Lib_V3.6.0/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/TrueSTUDIO中拷贝，当前芯片适用于hd
│   ├── stm32f10x.h
│   ├── system_stm32f10x.c #STM32F10x_StdPeriph_Lib_V3.6.0/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x
│   └── system_stm32f10x.h
├── stm32_flash.ld # 链接脚本，从STM32F10x_StdPeriph_Lib_V3.6.0/Project/STM32F10x_StdPeriph_Template/TrueSTUDIO/STM3210E-EVAL拷贝，注意对应文件夹是STM3210E-EVAL，文件注释描述Linker script for STM32F103ZE Device with512KByte FLASH, 64KByte RAM
└── User # 用户App层文件
    ├── main.c # 定义用户App层函数入口main
    ├── stm32f10x_conf.h # 使用外设标准库的总头文件，main中不需要直接include，只需要include stm32f10x_it.h
    ├── stm32f10x_it.c
    └── stm32f10x_it.h # 在该文件中根据宏USE_STDPERIPH_DRIVER来include stm32f10x_conf.h，因此需要使用标准外设库时，在Makefile中加入编译选项-D USE_STDPERIPH_DRIVER

5 directories, 12 files
```

