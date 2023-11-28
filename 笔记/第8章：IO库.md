# 第8章：IO库

复习之前学到的一些IO设施：

* istream（输入流）类型，提供输入操作。
* ostream（输出流）类型，提供输出操作。
* cin，一个istream对象，从标准输入读取数据
* cout,一个ostream对象，向标准输出写入数据
* cerr，一个ostream对象，通常用于输出程序的错误消息，写入标准错误。
* `>>` 运算符，用来从一个istream对象读取输入数据
* `<<`运算符， 用来向一个ostream对象写入输出数据
* getline函数，从一个给定的istream读取一行数据，存入一个给定的string对象中。

## 8.1 IO类

| IO库类型和头文件 |      |
| :--- | ---- |
| 头文件 |类型|
| iostream | istream, wistream从流读取数据 |
|      | ostream, wostream向流写入数据 |
|      | iostream, wiostream读写流 |
| fstream | ifstream, wifstream从文件读取数据 |
|      | ofstream， wofstream向文件写入数据 |
|      | fstream， wfstream读写文件 |
| sstream | istringstream， wistringstream从string读取数据 |
|      | ostringstream, wofstringstream向文件写入数据 |
|      | stringstream,wstringstream读写string |

为了支持使用宽字符的语言，标准库定义了一组类型和对象来操纵wchar_t类型的数据。关子夫版本的类型和函数的名字以一个w开始。如：wcin、wcout和wcerr分别对应的cin、cout和cerr的宽字符版对象。宽字符版本的类型和对象与其对应的普通char版本的类型定义在同一个头文件中。例如，头文件fstream定义了ifstream和wiftream类型。

### IO对象无拷贝或赋值操作

### 8.1.2  条件状态

IO操作一个与身俱来的问题是可能发生错误。一些错误是可恢复的，而其他错误则发生在系统深处，已经超出了应用程序可以修正的范围。下表列出了IO类所定义的一些函数和标志，可以帮助我们访问和操纵流的条件状态（condition state）：

| strm::iostate     | strm是一种IO类型，在上表中已经列出。iostate是一机器相关的类型，提供了表达条件状态的完整功能 |
| ----------------- | ------------------------------------------------------------ |
| strm::badbit      | strm::badbit用来指出流已崩溃                                 |
| strm::failbit     | 用来指出一个IO操作失败了                                     |
| strm::eofbit      | 用来指出流到达了文件结束                                     |
| strm::goodbit     | 用来指出流未处于错误状态。此值保证为0                        |
| s.eof()           | 若流s的eofbit置位，则返回true                                |
| s.fail()          | 若流s的failbit或badbit置位，则返回true                       |
| s.bad()           | 若s的badbit置位，则返回true                                  |
| s.good()          | 若流处于有效状态，则返回true                                 |
| s.clear()         | 将流s中所有条件状态复位，将流的状态设置为有效。返回void      |
| s.clear(flags)    | 根据给定的flags标志位，将流s中对应条件状态位复位。flags的类型为strm::iostate。返回void |
| s.setstate(flags) | 根据给定的flags标志位，将流s中对应条件状态位置位。flags的类型为strm::iostrate。返回void |
| s.rdstate()       | 返回流s的当前条件状态，返回值类型是strm::iostrate            |

#### 查询流的状态

IO库定义了一个与机器无关的iostate类型，它提供了表达流状态的完整功能。这个类型应作为一个位集合来使用。

IO库定义了4个iostate类型的constexpr值表示特定的位模式。这些值用来表示特定类型的IO条件，可以与位运算符一起使用来一次性检测或设置多个标志位。

* badbit 表示系统级错误，如不可恢复的读写错误。通常情况下，一旦badbit被置位，流就无法再使用了。
* 在发生可恢复错误时，failbit被置位，如期望读取数值却读出一个字符等错误。这种问题通常是可以修正的，流还可以继续使用。
* 如果到达文件结束位置，eofbit和failbit都会被置位。
* goodbit的值为0，表示流未发生错误。
* 如果badbit、failbit和eofbit人一个被置位，则检测流状态的条件会失败

