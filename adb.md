* `adb /-e/-s/-s/ serialNumber command`
  *  -d：指定当前唯一通过USB连接的安卓设备作为命令目标
    -e：指定当前唯一运行的模拟器为命令坐标
    -s：指定相应的设备作为命令目标（重点）
  * 例 `adb -s 127.0.0.1:5555 disconnect` 将`127.0.9.1`设备断开连接
  
* `adb devices` 查看连接的所有`adb`设备

* `adb connect 127.0.0.1:5555`连接设备

* `adb get-state`查询`adb`状态：
  
  * device：正常
    Offline：连接退出
    Unauthorized：未授权
  
* `adb kill-server`杀死`adb`服务

* 安装指令：
  * `adb install <apk路径>` 普通安装
  * `adb install -r <apk路径>` 覆盖安装
  * `adb -s <设备名字> install -r <apk路径>` 指定设备覆盖安装
  
* 卸载指令
  * 卸载所有，包括存储数据：`adb uninstall`包名（有唯一包名）
  * 卸载应用（不删除配置文件，保存数据缓存信息）：`adb unintall -k 包名`
  * `adb shell`进入手机的内环境#马，可查看缓存数据 cd /data/data (所有应用的数据文件夹) -> ls
  
* 启动指令
  * 每个安卓应用都有对应的包名，进入app的每个页面也对应着各个活动页，每个活动页都有特定的标签，打开应该页面需要这个标签
  * 获取当前活动页的标签：`adb shell "dumpsys window | grep CurrentFocus"`
  * 获取系统安装的APK的报名标签：`adb shell pm list packages -3`
  * `adb logcat ActivityManager:I|findstr "cmp"`(使用`adb`打印命令，打印对应标签的信息，可找到对应活动页的标签名称)
  * `adb shell am start -n <apk包名/活动页>`（启动对应的应用或页面，输入后便可打开对应APK的活动页面）
  
* 停止指令
  * `adb shell am force-stop <包名>` ，停止该应用的一切活动
  
* 查看指令
  * `adb shell ls` 查看当前路径文件
  * `adb shell data` 查看日期
  * `adb shell cat /proc/cpuinfo` 打开CPU信息文件
  * `adb shell cat /proc/meminfo` 存储信息
  
* 包管理命器（pm）指令
  * `adb shell pm list packages` 列举所有的应用包
  * `adb shell pm list packages -s`列出系统应用包
  * `adb shell pm list packages -3` 列出用户自行安装的包
  * `adb shell pm clear <应用包名>` 清楚对应应用的数据，让其处于刚安装状态
  * `adb shell` 进入内环境，进入文件夹`data/data`可查看对应应用的数据文件
  
* 文件传输指令
  * `adb push <电脑路径> <设备路径>` ：把文件从电脑推到安卓设备
  * `adb pull <设备路径><电脑路径>`： 把文件从安卓设备推到电脑
  * `cd data/data（系统路径，不能随意操作）cd sdcard(内存卡路径，可操作)`
  
* 日志指令
  * `adb logcat`级别
    * `V-明细verbose`（最低优先级）
    * `D-调试debug`
    * `I - info`
    * `W-警告warn`
    * `E-错误error`
    * `F-严重错误fatal`
    * `S-无记载silent`最高优先级，绝不会输出任何内容
    *  以上优先级从低到高，设定这个打印优先级主要是味蕾能更好的抓到对应的打印信息，屏蔽不必要的信息，便于排查问题
    
  * `adb logcat`参数
    * `adb logcat --help` 可查看关于`logcat`使用的帮助信息
    * `adb logcat -v time` 显示事件
    * `adb logcat -v color` 显示打印的颜色
    * `adb logcat -f<sdcard/log.lo>` 保存日志到当前安卓设备
    * `adb logcat > <电脑路径>` : 保存日志到电脑
      * 例：`C:\Users\24637>adb logcat -v color > C:\Users\24637\Desktop\test.logcat`
    * `adb logcat -c`清理日志缓存，清理后，logcat会重新从头开始打印，而不会打印之前的缓存打印信息
    * `adb logcat "*:w"`：打印`warn`及以上级别的日志，可设定打印特定优先级的打印信息
    * `adb logcat ActivityManger:D "*:S"`: 过滤`tag`为`Activitymanager`,`level`为`debug`及以上级别的日志）
    
  * 输入指令：
  
    * 打开开发者模式的USB调试模式后->找到输入栏目，打开指针位置设置的开关，打开后，我们使用鼠标或触控点击设备大屏，设备上方都会显示每次点击对应的坐标，根据显示的`dx，dy`坐标，我们便可定位到当前点击的位置信息，进而可使用以下指令进行各种输入事件模拟。
  
    * 截图相关指令：
  
      * ```cpp
        （1）adb shell screencap -p /sdcard/screen.png
        
        （2）adb pull /sdcard/screen.png
        
        （1）是截图保存到sd卡；
        
        （2）是将screen.png保存到计算机上；保存的路径为你使用adb命令时的当前目录，当然你也可以在最后加入你想存放的路径名。
        
        2. 直接保存到电脑上的指令：adb exec-out screencap -p > screen.png
            或：adb shell screencap -p > /sdcard/screen.png
        
        ```
  
      * 
  
    * `adb shell input --help`:
  
      * ```cpp
        C:\Users\24018>adb -s emulator-5554 shell input --help
        Error: Unknown command: --help
        Usage: input [<source>] <command> [<arg>...]
        
        The sources are:
              dpad
              keyboard
              mouse
              touchpad
              gamepad
              touchnavigation
              joystick
              touchscreen
              stylus
              trackball
        
        The commands and default sources are:
              text <string> (Default: touchscreen)
              keyevent [--longpress] <key code number or name> ... (Default: keyboard)
              tap <x> <y> (Default: touchscreen)
              swipe <x1> <y1> <x2> <y2> [duration(ms)] (Default: touchscreen)
              draganddrop <x1> <y1> <x2> <y2> [duration(ms)] (Default: touchscreen)
              press (Default: trackball)
              roll <dx> <dy> (Default: trackball)
        ```
  
      * `adb shell input tap x y` : 点击对应坐标
  
      * `adb shell input test 文本`：光标放入输入框里面
  
        * 例：`C:\Users\24637>adb shell input text 1234567890`
  
      * `adb input shell swipe 起点x 起点y 终点x 重点y 滑动时常（毫秒）`
  
        * 例：`C:\Users\24637>adb shell input swipe 587 1601 520 323 1000`
  
      * `adb shell input keyevent <编号>`：模拟手机按键
  
        * ```cpp
          此处的编号是固定的键值
          不同的键值可对应安卓设备的一个功能按键
          
          ```
  
      * `adb shell input keyevent 4`:（点击手机的返回）
  
      * `adb shell input keyevent 3`:(回home,置于后台运行)
  
      * `adb shell input keyevent 24`:(volume +)
  
      * `adb shell input keyevent 25（volume -）`
  
      * 对应键值查找网址
  
        [查看对应的按键数值]: https://developer.android.google.cn/reference/kotlin/android/view/KeyEvent
  
      * `adb shell input press`:暂时不懂
  
      * `adb shell input roll`:暂时不懂
  
      * `adb shell input tmode`:暂时不懂
  
  * 性能指令：
  
    * `adb shell dumpsys cpuinfo`:查看当前系统CPU使用情况
  
    * `adb shell dumpsys meminfo`:查看当前系统内存的使用情况
  
    * `adb shell dumpsys meminfo + 包名`：查看当前应用的使用情况
  
    * `adb shell dumpsys battry`: 查看电池状态
  
      * ```
        AC powered: true
        USB powered: false
        Wireless powered: false
        Max charging current: 2000000（最大充电电流）
        status: 2（充电状态，其他数字为非充电状态）
        health: 2（只有数字2表示good）
        present: true（电池是否安装在机身）
        level: 89（电池百分比）
        scale: 100
        voltage: 4172（电池电压）
        temperature: 377（温度37.7）
        technology: Li-poly（电池种类）
        ```
  
    * `adb shell top`:当前系统的进程使用情况类似任务管理器
  
    * `aab shell top|findstr 包名`：对应应用的占用
  
    * `adb shell top -d 1|grep 包名`： 打印时间和对应应用的占用
  
    * 除以上性能指令外，还有很多对应的性能指令可以参照下面网址找到https://developer.android.google.cn/studio/command-line/dumpsys?hl=en
  
  * `adb monkey`
  
  * 学习大纲
  
    * ![`adb`学习大纲](C:\Users\24018\Documents\GitHub\cpp_study_notes\adb学习大纲.png)

# python配合`adb`

1. 基本原理
   在window系统上实现python对`adb`命令的调用可以使用三种方法。其中分别用到了`os`库与`subprocess`库，借助这两个库实现对`adb`命令的编辑。下面用运行python脚本实现`adb`的连接的实验来进行介绍。在进行以下实验时先确保可以通过`cmd`进行`adb`命令的连接和使用。

   ```python
   import os
   import subprocess
   
   ```

   

## 方法一：使用`os.system()函数实现`

代码如下（实例）：

```python
#此函数可实现adb的连接和进行一次点击事件
import os

#连接adb
def adb_connect1(IP):
    os.system(f"adb connect {IP}")

# 点击事件
def touch1(x, y):
    os.system(f"adb shell input tap {x} {y}")

if __name__ == "__main__":
	os.system("adb connect 127.0.0.1:7555")
	os.system("adb shell input tap 216 310")
    #adb_connect1('127.0.0.1:7555')
    #touch1(216,310) 

```

## 方法2：使用`os.popen()`函数实现

```python
import os

#连接adb
def adb_connect2(IP):
    output_date = os.popen(f"adb connect {IP}")
    print(output_date.read())

# 点击事件
def touch2(x, y):
    output_date = os.popen(f"adb shell input tap {x} {y}")
    print(output_date.read())

if __name__ == "__main__":
    adb_connect2('127.0.0.1:7555')
    touch2(216,310)

```

## 方法三：使用`subprocess.Popen()`函数实现



```python
import os
import subprocess

#连接adb
def adb_connect3():
    p = subprocess.Popen("adb connect 127.0.0.1:7555", shell=True, close_fds=True, stdin=subprocess.PIPE,
                         stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    print(str(p.communicate()))
    
def touch3(x, y):
    p = subprocess.Popen(f"adb shell input tap {x} {y}", shell=True, close_fds=True, stdin=subprocess.PIPE,
                         stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    print(str(p.communicate()))
    
if __name__ == "__main__":
    adb_connect3()
    touch3(216,310)

```

```python
如何判断命令是否执行呢，我们就要使用到commands模块,此模块适用于python2.x。python3.x 要使用subprocess
subprocess模块是python的内置模块，他共有三个函数分别是：
(1) subprocess.getstatusoutput(cmd)返回一个元组（status，output）status代表的shell命令的返回状态，如果成功的话是0；output是shell的返回的结果
(2)subprocess.getstatus（file）返回ls -ld file执行的结果.
(3) subprocess.getoutput(cmd) 判断Shell命令的输出内容
import subprocess


def check_adb_status(device_id="xxxxx"):
    out, err = subprocess.getstatusoutput("adb -s " + device_id + " get-state")

    if err == 0:
        if 'device' in out:
            print("[INFO] ADB is on")
            return True
        elif 'offline' in out:
            print("[WARNING] ADB device is dumb")
            return False
        else:
            print("[WARNING] ADB is abnormal: " + out)
    else:
        print("[WARNING] ADB is bad: " + err)
    return False


if __name__ == '__main__':
    check_adb_status(device_id="xxxx")

```

