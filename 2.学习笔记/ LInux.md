#  LInux

##  一.shell编程

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
* $*：获取当前shell的所有参数， 将所有命令行参数视为单个字符串， 相当于“$1$3$3”

###  4.状态变量

* $?:判断上一个指令是否成功执行， 0为成功
* $$:取当前进程的PID//PID进程编号
* &!:山一个指令的PID

###  5.变量， 参数展开

* ${parameter:-word}如果变量为定义， 则表达式的值为word.
* ${parameter:=word}如果变量为定义， 则设置变量的值为word.返回表达式的值也是word.
* ${parameter:?word}用于捕捉变量未定义而导致的错误并退出程序
* ${parameter:+word}如果变量已经定义， 返回为word.也就是true

###  6.字符串的展开

* ${#parameter}//求字符串的长度
* ${parameter/pattren/string}第一个匹配被替换
* ${parameter//pattren/string}全部匹配被替换
* ${parameter/#pattren/string}

###  7.输入数处——READ

* read [-options][variable...]
* -a array #把输入赋值到数组array中， 从索引号零开始
* -d delimiter # 用字付串delimiter中的第一个字符指示输入结束， 而不是一个换行符

echo 

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

~~~
#!/bin/bash
if[[ condition ]] ;then
	#statements
	//两个中括号叫做TEST表达式有两个空格 then 相当于大括号   fi表示结束当前判断
if[[ condition ]] ;then
~~~

###  10.流程控制FOR

~~~
for i in words; do
	#statements
done
for (( i = 0; i < 10； i++)) ; do
	#statements
done
~~~







