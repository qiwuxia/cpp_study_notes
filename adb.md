* `adb /-e/-s/-s/ serialNumber command`
  *  -d：指定当前唯一通过USB连接的安卓设备作为命令目标
    -e：指定当前唯一运行的模拟器为命令坐标
    -s：指定相应的设备作为命令目标（重点）
  * 例 `adb -s 127.0.0.1:5555 disconnect` 将127.0.9.1设备断开连接
* `adb devices` 查看连接的所有adb设备
* `adb connect 127.0.0.1:5555`连接设备
* `adb get-state`查询adb状态：
  * device：正常
    Offline：连接退出
    Unauthorized：未授权
* `adb kill-server`杀死adb服务
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
  * `adb logcat ActivityManager:I|findstr "cmp"`(使用adb打印命令，打印对应标签的信息，可找到对应活动页的标签名称)
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