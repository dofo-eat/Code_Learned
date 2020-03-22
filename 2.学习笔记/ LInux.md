#  LInux

##  1.发展历程

###  1.操作系统的产生

* 概念产生->微程序->IBM(system/360)

###  2.UNIX的出现

* Multics->Unics->Unix    //c语言在1973年发明的

###  3.LINUX的兴起

* AT & T回收版本->谭邦宁教授开发minux->Linus开发LInux

###  4.LInux的主要代表

- LInux指的是内核

###  5.LINUX的主要应用

- 大型机
- 小型机
- 中低端服务器
- 手机
- 电视盒子
- 其他几乎所有的嵌入式设备

###  6.全局设置与个人设置

* 全局设置

~~~c
System-wide
	COnfig ans Setup
											/etc/bash.bashrc
											/etc/bash.profile
											/etc/bash.bash.logout

~~~

* 个人设置

~~~c
Individual
Config and Setup
											~/.basshrc
											~/bash_profile
											~/.input
~~~





##  二.shell编程

### 1.第一个shell脚本 

~~~ c
#!/bin/bash//由bin bash解释
echo 'hello haozei' //echo 解释
~~~

###  2.变量与局部变量

* 变量的定义

* a=12

*  a=helloworld 

* a='pwd' //命令替换符

* ~~~
  a=a:a 或者a=${a}:a
  ~~~

局部变量

* local a=12
* //都没有空格

###  3.特殊变量

位置变量

* $0:获取当前执行的shell脚本的文件名， 包括路径
* $n:获取当前执行脚本的第n个参数， n = 1-9， 如果n>9需要将n用大括号阔起来
* (  $$) *：获取当前shell的所有参数， 将所有命令行参数视为单个字符串， 相当于“$1$3$3”
* $#得到当前脚本的参数个数
* (  $)@获取这个程序的所有参数，并保留参数之间的任何空白，相当于"$1" "$2" "$3",这是将参数传给其他程序的最好办法
* $* 和$@其实是差不多的， 主要是用$*

~~~
Max=sssss1234
echo${#Max}  #获取字符串的长度
echo${Max}   #获取字符串
~~~

###  4.状态变量

* $?:判断上一个指令是否成功执行， 0为成功
* $$:取当前进程的PID//PID进程编号
* &!:上一个指令的PID

###  5.变量， 参数展开

* ${parameter:-word}如果变量为定义， 则表达式的值为word.
* ${parameter:=word}如果变量为定义， 则设置变量的值为word.返回表达式的值也是word.
* ${parameter:?word}用于捕捉变量未定义而导致的错误并退出程序
* ${parameter:+word}如果变量已经定义， 返回为word.也就是true
* ${!prefix*}
* ${!prefix@} prefix开头的变量

###  6.字符串的展开

* ${#parameter}//求字符串的长度
* ${#parameter:offset}  #从第offest字符开始截取
* ${#parameter:offset}  #从第offest字符开始截取，取length长度
* ${#parameter##pattern}  #最长
* ${#parameter#pattern} #从头删除最短匹配
* ${#parameter%pattern}  #从尾删除最短
* ${#parameter%%pattern}  #从尾删除最长
* ${parameter/pattren/string}第一个匹配被替换
* ${parameter//pattren/string}全部匹配被替换
* ${parameter/#pattren/string} #字符串开头的被替换
* ${parament/%pattern/string}# 字符串结尾被替换
* ${parameter,,} ​${parameter^^} #全部转换为小写.大写
* ${parameter,} ${parameter^} #首字母转换为小写.大写

###  7.输入数处——READ

* read [-options][variable...]
* -a array #把输入赋值到数组array中， 从索引号零开始
* -d delimiter # 用字付串delimiter中的第一个字符指示输入结束， 而不是一个换行符
* -e  #使用Readline来处理输入．这是的与命令相同额方式是编辑输入
* -n num #读取num个输入字符，而不是整行
* -p prompt #为输入显示提示信息，使用字符串prompt
* -r #Raw mode, 不把反斜杠字符解释为转义字符
* -s　#Silent mode
* -t seconds #超时
* -u fd　#使用文件描述符fd中的插入,而不是标准输入

输出

* echo string
* echo -e "Hello HaiZei\n"  #开始转义
* echo "Hello $name, Thils is HaiZei"
* echo "\"Hello HaiZei\""
* printf format-string [arguments...]
* printf"Hello %s , This is HaiZei\n""Small A"   #输出结果 Hello Small A, This is HaiZei

###  8.函数

~~~visual basic
#!/bin/bash
function _printf_{
	echo $1
	return
}

  _printf_() {
    echo $1
    return 
    }
  
  function_printf_() {
    echo $1
    return
    }
  //三种表达方式
~~~

###  9.流程控制 —IF

~~~sh
#!/bin/bash
if[[ condition ]] ;then
	#statements
	//两个中括号叫做TEST表达式有两个空格 then 相当于大括号   fi表示结束当前判断
if[[ condition ]] ;then
#statement
		else 
				#statement
fi

if [[ condition ]]; then
	#statement
elif [[ condition ]]; then
	#statement
elif [[ condition ]]; then
	#statement
elif [[ condition ]]; then
	#statement
fi


~~~

###  10.流程控制FOR

~~~sh
for i in words; do
	#statements
done
for (( i = 0; i < 10； i++)) ; do
	#statements
done
~~~

e.g.

~~~sh
for i in `seq 1 10`; do 
done

输出就是1 2 3 4 5 6 7 8 9 10 　　
#seq是序列
~~~

### 11. 流程控制－WHILE

~~~sh
while [[ condition ]];  do
	#statements
done
~~~

e.g.

~~~sh
while [[ $i -lt 100]]; do
		echo $i
		i=$[ ${i} + 1 ]  #let i=i+1
done
~~~

###  12.流程控制 -UNIT

~~~sh
UNTIL [[  condtion ]]; do
		#statements
done
~~~

###  13.流程控制-CASE

~~~sh
case word in 
	pattern )
				;;
esac
~~~

e.g.

~~~sh
read -p "Input Num" Num
case $Num in
		1)
			echo "1"
			;;
		2)
			echo"2"
			;;
esac
~~~

###  14.数组

~~~sh
declare -a a
		name[subscript ]=value
		name=(value1 value2 ...)
~~~

e.g.

~~~sh
files=(`ls`)
echo ${files} #输出ls结果的第一个
echo ${files[*]} #输出全部
echo ${!files[*]} #取所有下标
upset #用来清空某个变量
~~~

###  15.数组操作

~~~c
- 输入数组内容
  ${arry[*]}
  ${arry[@]}
- 确定数组元素个数
  ${#arry[@]}
- 找到数组的下标
  ${!arry[@]}
- 数组追加
  arry+=(a b c)
- 数组排序
  sort
- 删除数组与元素
  upset
~~~

###  16.任务管理

* &    在命令后面加上&表示后台执行的意思
* ；    在命令之间以；相连 表示顺序执行的意思
* &&   命令以&&相连时只有第一个命令执行成功， 第二个命令才会执行
* fg  前台  bg 后台 把后台命令调前台
* || 命令之间以||相连时， 如果前一个命令执行失败， 则执行第二个命令
* ``  命令中如果包含另一个命令， 则用符号``  将它包括起来， 在执行的时候系统将优先执行``中的子命令， 然后将其结果带入父命令继续执行。
* ctrl + z 在shell中执行命令时， 同时按下ctrl + z可以暂时挂起
* 什么时挂起？  相当于阻塞状态， 把内存释放出来， 系统中有一个swap， 他就是暂时存放挂起的数据， 利用fg将挂起的进程拉会前台， 可以加上序号， 来标记挂起的进程。



##  三、Linux帮助系统

* 例如查看ls的帮助手册， 可以直接使用 man ls即可查看ls的命令帮助。
* ​



##  四、linux信息系统

###  1.系统信息

* uptime:打印系统运行时长和平均负载
* who:显示当前登录系统的用户信息
* last:显示用户最近登陆信息
* date:显示或设置系统时间与日期
* w:当前登陆用户列表及正在执行的任务
* whoami:打印当前有效的用户名称
* uname:打印当前系统信息
* cal：显示日历

###  2.目录结构

* cd 切换当前工作目录 
* mkdir 创建目录
* pwd 创建目录
* 入
* 1.按开机键
* 2.加在BIOS（BIOS CMOS是什么）硬件信息， 自检， 并根据配置信息取的第一个可启动的设备
* 3.读取并执行第一个启动设备MBR（什么是MBR）的boo loader.(grub)等
* 4.根据boot loader的设置加在kernel(匹配的驱动)， 开始检测硬件， 并加载驱动。
* boot loader加载虚拟文件系统， 并加载启动过程中需要的内核模块（usb, RAID, LVM, SCSI）
* 启动第一个进程init
* init启动终端getty
* 运行Xwindows系统/

###  3.cd切换工作目录

* cd /etc 直接切换到etc目录
* cd ..      切换到上层目录
* cd .        切换到当前目录
* cd   / cd ~回到自己的家目录
* cd -         回到上次工作目录

###  4.pwd打印当前工作目录

* L显示逻辑工作目录
* p显示物理工作目录

~~~
cd /var
ls -al run
cd run
pwd -L
/var/run
pwd -P
/run
~~~



###  5.mkdir创建目录

* -p自动创建父母路
* -m设置权限

###  6.rmdir删除目录

* p删除祖先

###  7.cp拷贝

* -i:若文件存在， 询问用户
* -r;递归复制
* -a:pdr的集合
* -P：连同文件属性一起拷贝
* -d:  若源文件为连接文件的属性， 则复制连接文件的属性
* -s:拷贝为软连接
* -l: 拷贝为硬连接
* -u :源文件比目的文件新才拷贝

###  8.rm删除

* -i互动模式
* -r递归删除
* -f:强制删除

###  9.mv移动

* -i互动模式
* -f:强制删除
* -u:源文件更新才会移动

###  10.文件内容的查阅

1.cat 正向连续读

* -A：相当于-vEF
* -v:列出看不出的字符
* -E :显示断行符为$
* -T:显示TAB为^T
* -b:列出行号
* -n:列出行号， 连同空行也编号

2.TAC反向连续读

* 与cat相反， 从最后一行开始打印

3.NL输出行号显示文件

* -b :行号的指定方式(-b a  相当于cat -a)(-b t相当于cat -b)


* -n:(-n ln:行号在屏幕最左边显示）(-n rn 行号在自己的字段最右边显示）（-n rz 行号在自己的字段最右边显示， 前面自动补全0）
* -w:行号所占位数

### 11.MORE按页查看

1.more file

* /string  向下查找string 关键字
* ：f 显示文件名称和当前显示的行数
* q 离开

###  12.LESS 按页查看

- /string  向下查找
- N 继续反向查询
- n继续向下查找
- /？string 反向查找

###  13.head查看头几行

* -n num 显示前num行
* -n -num：除了后num行外， 其他都显示

###  14.查看末尾几行

* -n num :显示文件后num 行
* -n +num除了前num行， 其他都显示

###  练习

* 如何查看一个文件的第101行到120行
* man ls | nl -b a -n rz -3 |head -101|tail 20









##  五、管道重定向

###  1.管道定义

* 用来把前一个命令的标准输出作为标准输入来输入下一个命令

###  2.重定向

* ‘>’重定向符号
* '>>'  作用与‘>’基本相同， 不同的是‘>>’将内容最佳到文件末尾， 而‘>’内容覆盖原文件
* ‘<’ 是文件到命令的重定向， 他将文件的内容输出到命令作为输入。
* ‘<<’  名令到文件的重定向   crtl+d文件输入结束标志 EOF也会结束


##  六、修改文件时间与新建文件

###  1.文件的三个时间

* mtime :内容数据改动时才更新这个时间
* ctime :文件的权限， 属性改动时更新这个时间
* atime :文件内容被取用access时， 更新这个时间

~~~
ls -l --time=ctime /etc/hostname//-l显示更多的时间
~~~

###  2.touch（没有特殊需求就记住可以创建空白文件）

* -a:仅修改访问时间
* -c:仅修改文件的时间， 若文件不错在， 不新建
* -d:修改文件日期
* -m:仅修改mtime
* -t:修改文件事件

##   七、文件隐藏属性

###  1.chattr  【+-=】

* A:不修改atime（为了提高效率， 减少时间）
* S:同步写入(直接写入数据库， 不再内核中缓存例如银行)
* a:只能增加数据（对于以前的内容无法进入修改， 一般用在关键日志， 和记账系统上）
* c:自动压缩， 解压
* d:不会被dump程序备份
* i:不能删除， 修改， 建立连接(如果进行了i 无法进行删除改动等行为-i权限， 就可以正常操作)（chmod修改的时对不同用户有什么属性）（chatter对于用户没有关系， 只与文件有关系）
* s:文件删除时， 直接从磁盘删除（在磁盘上删除和写入一样费时）
* u:文件删除时， 数据内容存在磁盘中
* (显示的rwx的权限的组根汉语权限差不多， 选择用户)

###  lsattr查看文件属性

* -a
* ​

## 八、文件的特殊权限

* set_uid 放在usr的权限位置
* set_gid
* sticky Bit



| 权限      |      |              |                                          |
| ------- | ---- | ------------ | ---------------------------------------- |
| set_uid | s    | 二进制程序文件， 非脚本 | 用户在执行改程序时获取程序所有者权限                       |
| set_gid | s    | 目录和二进制程序文件   | 用户在该目录l里， 有效组变为目录所数组（就是在不同的环境有不同的身份， 应该做的事） |
| stick   |      |              |                                          |

e.g.(sudo i切换管理员)

(cd ~suxinxin)快速回到某一个用户的家目录

set_gid举例（即使你不是该左成员但是在本权限下一九要遵从规则， 进入他人管理权限暂时奇名在组长名下）

##  八、命令与文件的查询

###  1.which 寻找可执行文件

* 查找path路径下的可执行文件

###  2.whereis 寻找特定文件

* -b:只查找二进制文件
* -m:只查找manual路径下的文件
* -s:只查找source源文件
* -u:查找其他文件

###  3.locate [ir]  模糊定位

* 基于索引技术的（全局的，最近一段时间的）
* -i 忽略大小写
* -r 后面可接正则表达式 

###  4.find高级查找

~~~
find ~ -name "*.log" -o -name "*.sh" -o -name "*.c" -type f 2>/dev/null | xargs cat 2>/dev/null | wc -l 2>/dev/null输出.log 等文件个数
~~~

1.与时间相关的参数 ：-atime -ctime -mtime

* -mtime n : n天前的“一天之内”修改的文件
* -mtime +n: n天之前， 不包含N，修改过的文件


* -mtime -n : n天之内， 包含N， 修改过的文件
* -newer file ：比file还要新的文件

2.与用户或用户组相关的参数

* -uid n:用户UID为n
* -gid n:群组Gid为n
* -user name ：用户名为name
* -group name ：群组名为name
* nouser ：文件所有者不存在
* nogroup: 文件所在组不存在

3.与文件权限及名称有关的参

* -name filename   文件名为filename
* -size [+-] SIZE     查找比size大或者小的
* -type TYPE : f b c d l s p
* -perm mode :mode 刚好等于的文件
* -perm -mode :全部包含mode的文件
* find -exec ls -l {} \;s


##  SIze of是一个操作符号







































