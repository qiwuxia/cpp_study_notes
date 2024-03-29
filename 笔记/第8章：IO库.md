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

### 8.1.3 管理输出缓冲

每个输出流都管理一个缓冲去，用来保存程序读写的数据。例如，执行下面的代码：

```cpp
os << "please enter a value:";
```

文本串可能立即打印出来，但也有可能被操作系统保存在缓冲区中，随后再打印。有了缓冲机制，操作系统就可以将程序的多个输出操作组合成单一的系统级写操作。由于设备的写操作可能很耗时，允许操作系统将多个输出操作组合为单一的设备写操作可以带来很大的性能提升。

导致缓冲刷新（即，数据真正写到输出设备或文件）的原因有很多：

* 程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行。
* 缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区。
* 我们可以使用操纵符如 `endl` 来显式刷新缓冲区
* 在每个输出操作之后，我们可以用操纵符 `unitbuf` 设置流的内部状态，来清空缓冲区。默认情况下，对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新的。
* 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新。例如，默认情况下，cin和cerr都关联到cout。因此，都cin或写cerr都会导致cout的缓冲区被刷新

#### 刷新输出缓冲区

* `endl`向缓冲区中插入一个空字符，然后刷新缓冲区
* `flush`刷新缓冲区，不附加任何字符
* `ends`向缓冲区插入一个空字符，然后刷新缓冲区

#### `unitbuf`操纵符

如果向每次输出操作后都刷新缓冲区，我们可以使用`unitbuf`操纵符。它告诉流在接下来的每次写操纵之后都进行一次`flush`操作。而`nounitbuf`操纵符则重置流，使其恢复正常的系统管理的缓冲区刷新机制：

```cpp
cout << unitbuf;		//所有输出操作后都会立即刷新缓冲区
// 任何输出都直接刷新，无缓冲
cout << nounitbuf; // 回到正常的缓冲方式
```



* 如果程序崩溃，输出缓存区不会被刷新，它所输出的数据很可能停留在输出缓冲区中等待打印

#### 关联输入流和输出流

当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新关联的输出流。标准库将`cout`和`cin`关联在一起，因此下面语句

```cpp
cin >> ival;
```

会导致cout的缓冲区刷新

---

* 交互式系统通常应该关联输入流和输出流。这意味着所有输出，包括用户提示信息，都会在都操作之前被打印出来。

---

`tie`函数有两个重在的版本：一个版本不带参数，返回指向输出流的指针。如果本对象当前关联到一个输出流，则返回的就是这个流的指针，如果对象未关联到流，则返回空指针。`tie`函数的第二个版本接受一个指向`ostream`的指针，将自己关联到此ostream。即，`x.tie(&o)`将流`x`关联到输出流`o`。

我们既可以将一个`istream`对象关联到另一个ostream，也可以将一个ostream关联到另一个ostream：

```cpp
cin.tie(&cout); //仅仅是用来展示：标准库将cin和cout关联在了一起
//old_tie指向当前关联到cin的流（如果有的话）
ostream *old_tie = cin.tie(nullptr); // cin.tie(nullptr)操纵将解除cin与其他流关联的操作，并返回之前cin关联的流；
cin.tie(&cerr);   // 读取cin会刷新cerr而不是cout
cin.tie(old_tie);   // 重建cin和cout间的正常关联
```

* 每个流同时最多关联到一个输出流，但多个流可以同时关联到同一个ostream。比如`cin`和`cerr`能同时关联`cout`

## 8.2 文件输入输出

头文件fstream定义了三个类型支持文件IO:ifstream从一个给定文件读取数据，ostream向一个给定文件写入数据，以及fstream可以读写给定文件。

* 这些类型提供的操纵和`cin`和`cout`的操作一样。也可以用IO运算符（`<<`和`>>`）来读写文件，可以用getline从一个ifstream读取数据等

* 除了继承自iostream类型的行为之外，`fstream`中定义的类型还增加了一些新的成员来管理与流相关 的文件。下表列出了我们可以对`fstream`、`ifstream`和`ostream`对象调用这些操纵，但不能对其他IO类型调用这些操作。

* | fstream fstrm;           | 创建一个未绑定的文件流。`fstream`是头文件 `fstream`中定义的一个类型 |
  | ------------------------ | ------------------------------------------------------------ |
  | `fstream fstrm(s);`      | 创建一个`fstream`，并打开名为`s`的文件。s可以是`string`类型，或者是一个指向C风格字符串的指针。这些构造函数都是`explicit`（即不能隐式转换）的。默认的文件模式mode依赖与`fstream`的类型 |
  | `fstream fstrm (s,mode)` | 与前一个构造函数类似，但按指定mode打开文件                   |
  | fstrm.open(s)            | 打开名为s的文件，并将文件与fstrm绑定。s可以是一个string或一个指向C风格字符串的指针。默认的文件mode依赖于fstream的类型。返回void |
  | fstrm.close()            | 关闭与fstrm绑定的文件。返回void                              |
  | fstrm.is_open()          | 返回一个bool值，指出与fstrm关联的文件是否成功打开且尚未关闭  |

    
### 8.2.1 使用文件流对象

需要对一个文件进行读写时，可以先定义一个文件流对象，并将对象与文件关联起来。每个文件流类都定义了一个名为open的成员函数，他完成一些系统相关的操作，来定位给定的文件，并视情况打开为读或写模式。

创建文件流对象时，我们可以提供文件名（可选的）。如果提供了一个文件名，则open会自动被调用：

```cpp
ifstream in(ifile);  // 构造一个ifstream并打开给定文件
ofstream out;		// 输出文件流未关联到任何文件
```



这段代码定义了一个输入流`in`，他被初始化为从文件读取数据，文件名有`string`类型的参数`ifile`指定。第二条语句定义了一个输出流cout，位于任何文件关联。在新C++标准中，文件名既可以是库类型string对象，也可以是C风格字符数组。旧版本的标准库只允许C风格字符数组。

#### 用`fstream`代替`iostream&`

在使用基类型对象的地方，我们可以用继承类型的对象来替代。例如：

* 接收一个`iosream`类型引用（或指针）参数的函数，可以用一个对应的fstream（或sstream)类型来调用。也就是说，如果有一个函数接受一个`ostream&`参数，我们在调用这个函数时，可以传递给它一个`ofstream`对象，对`istream&`和`ifstream`也是类似的。

#### 成员函数`open`和`close`

* 如果我们第一了以恶搞空文件流对象，可以随后调用open来将它与文件关联起来

* 如果调用`open`失败，`failbit`会被置位。因为调用`open`可能失败，进行open是否成功的检测通常是一个好习惯：

  * ```cpp
    ifstream in(ifile);		//构筑一个ifstream并打开给定文件
    ofstream out;			// 输出文件流未与任何文件相关联
    out.open(ifile + ".copy");	// 打开指定文件
    if (out) // 检查open是否成功
        //open 成功，我们就可以使用文件了
        
    ```

  * 这个条件判断和将`cin`用作条件相似。如果`open`失败，条件会为假，我们就不会去使用`out`了

  


一旦一个文件流已经打开，他就保持对应文件的关联。实际上，对一个已经打开的文件流调用`open`会失败，并会导致`failbit`被置位。随后试图使用文件流的操作都会失败。为了将文件流关联到另外一个文件，必须首先关闭已经关联的文件。一旦文件成功关闭，我们可以打开新的文件：

```cpp
in.close();   //关闭文件
in.open(file + "2"); 		//打开另一个文件

```



如果`open`成功，则`open`会设置流的状态，使得`good()`为`true`.

#### 自动构造和析构

* 当一个`fstream`对象离开其作用域时，与之关联的文件会自动关闭。

### 8.2.2 文件模式

每个流都有一个关联的 **文件模式（file mode)**，用来指出如何使用文件。下表列出了文件模式和他们的含义：

| in     | 以读模式打开                 |
| ------ | ---------------------------- |
| out    | 以写模式打开                 |
| app    | 每次写操作前均定位到文件末尾 |
| ate    | 打开文件后立即定位到文件末尾 |
| trunc  | 截断文件                     |
| binary | 以二进制方式进行IO           |

无论用哪种方式打开文件，我们都可以指定文件模式，调用open打开文件时可以，用一个文件名初始化流来隐式打开文件时也可以。指定文件模式有如下限制：

* `out`模式只可以对`ofstream`或`fstream`对象设定
* `in`模式只可以对`ofstream`或`fstream`对象设定
* 只有当`out`也被设定是才可设定`trunc`模式
* 只要`trunc`没被设定，就可以设定`app`模式。在`app`模式下，即使没有显式指定`out`模式，文件也总是以输出方式被打开。
* 默认情况下，即使我们没有指定`trunc`，以`out`模式打开的文件也会被截断。为了保留以`out`模式打开的文件的内容，我们必须同时指定`app`模式，这样只会将数据追加写到文件末尾；或者同时指定`in`模式，即打开文件同时进行读写操作（第17.5.3节，将介绍对同一个文件既进行输入，又进行输出的方法）。
* `ate`和`binary`模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用。

每个文件流类型都定义了一个默认的文件模式，当我们未指定文件模式时，就使用此默认模式。与`ifstream`关联的文件默认以`in`模式打开；与`ofstream`关联的文件默认以`out`模式打开；与`fstream`关联的文件默认以`in`和`out`模式打开。

***

* **以`out`模式打开文件会丢弃已有数据**

  默认情况下，当我们打开一个`ofstream`时，文件的内容会被丢弃。阻止一个``ofstream`清空给定文件内容的方法时同时指定`app`模式:

  ```cpp
  // 在这几条语句中，file1都被截断
  ofstream out("file1"); // 隐含以输出模式打开文件并截断文件
  ofstream out2("file1", ofstream::out); // 隐含地截断文件，显式以输出模式打开文件
  ofstream out3("file1", ofstream::out | ofstream::trunc); //显式以输出模式打开文件，并截断文件
  // 为了保留文件内容，我们必须显式指定app模式
  ofstream app("file2", ofstream::app); // 隐含为输出模式
  ofstream app2("file2", ofstream::out | ofstream::app);
  ```
  
  * 保留被`ofstream`打开的文件中已有数据的唯一方法式显式指定`app`或`in`模式

***

* 每次调用`open`时都会确定文件模式

  对于一个给定流，每当打开文件时，都可以改变其文件模式。

  ```cpp
  ofstream out; // 未指定文件打开模式
  out.open("scratchpad"); // 模式隐含设置为输出和截断
  out.close(); // 关闭out，以便我们将其用于其他文件
  out.open("precious", ofstream::app); // 模式为输出和追加
  out.close();
  ```

  第一个`open`调用为显式指定输出模式，文件隐式地以`out`模式打开。通常情况下，`out`模式意味着同时使用`trunc`模式。因此，当前目录下名为`scratchpad`的文件的内容将被清空。当打开名为`precious`的文件时，我们指定了`append`模式，因此文件中的原有数据得到保留，我们每次写操作将在文件末尾进行

  * 在每次打开文件时，都要设置文件模式，可能是显式地设置，也可能是隐式地设置。当程序未指定模式时，就使用默认值。

***

## 8.7 string流

`sstream`头文件定义了三个类型支持内存IO：`istringstream`从`string`读取数据，`ostringstream`向`string`写入数据，而`stringstream`从`string`读写数据。

* 头文件`sstream`也是`iostream`的继承头文件

  * 下表列出了`sstream`中新增的一些操作（`iostream`没有的）

  | sstream strm;    | `strm`是一个未绑定的`stringstream`对象。`sstream`是头文件`sstream`中定义的一个类型 |
  | ---------------- | ------------------------------------------------------------ |
  | sstream strm(s); | `strm`是一个`sstream`对象，保存`string s`的一个拷贝。此构造函数是`explicit`的 |
  | strm.str()       | 返回`strm`所保存的`string`的拷贝                             |
  | strm.str(s)      | 将`string s`拷贝到`strm`中。返回`void`                       |



### 8.3.1 使用`istringstream`

### 8.3.2 使用`ostringstream`

* 当我们逐步构造输出，希望最后一起打印时，`ostringstream`是很有用的。这样可以最后分情况输出不同的内容，以及更改输出格式等等



***

# 小结

***

C++使用标准库类来处理面向流的输入和输出：

* `iostream`处理控制台 **IO**
* `fstream`处理命名文件 **IO**
* `stringstream` 完成内存 `string`的 **IO**

类 `fstream`和`stringstream`都是继承自类 `iostream`的。输入类都继承自 `istream`,输出类都继承自`ostream`。

每个 **IO** 对象都维护一组条件状态，用来指出此对象上是否可以进行 **IO** 操作。如果遇到了错误-——例如在输入流上遇到了文件末尾，则对象的状态变为失效，所有后续输入操作都不能执行，直至错误被纠正。标准库提供了一组函数，用来设置和检测这些状态。

***



# 术语表

***

