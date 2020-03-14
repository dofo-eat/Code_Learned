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









