# 海贼hython语言设计与开发

## 项目描述

![图片](https://static.dingtalk.com/media/lADPD4d8qNAtVoXND4DNC6A_2976_3968.jpg_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22366609415%3A366609415%22%2C%22msgId%22%3A%224925793921903%22%7D&bizType=im&open_id=366609415)

### 1. Antlr 的基础使用

1. 增加除法表达式的支持

2. 增加取余表达式的支持

   ~~~ c++
   multExpr
       : atom ((TIMES^ | DIVIDE^ | MOD^) atom)*
       ;
    
   TIMES: '*';
   DIVIDE: '/';
   MOD: '%';
   ~~~

3. 修改解释器，对于每一行内容，都输出其表达式的值

   *  ​

        else {
           int k = tree->getChildCount(tree);
            int r = 0;
            for(int i = 0; i < k; i++) {
                r = run(getChild(tree, i));
                cout << "Evaluator result :" << r << "\n";
            }
            return r;
        }


1. 增加作用域的功能
   * 以分号进行结尾， 增加def关键字
   * 增加作用域， 通过链表来实现，优先查找子作用域的的看是否有这个变量， 通过变量的依次进行遍历， 如果子类没有在取父类作用去寻找

   ~~~ c++
    ExprTreeEvaluator() : next(nullptr) {}
       ExprTreeEvaluator(ExprTreeEvaluator *next) : next(next) {}
    ExprTreeEvaluator *next;
   ~~~

   * 作用域的范围单度定义一个

   ~~~ c++
   void ExprTreeEvaluator::def_param(string name, int val) {
       if (memory.find(name) != memory.end()) {
           #ifdef DEBUG
           for (auto x : memory) {
               cout << "debug log(memory) : " << x.first << " " << x.second << endl;
           }
           #endif
           throw std::runtime_error("param redefined : " + name);
       }
       memory[name] = val;
       return ;
   }

   ~~~

   * case BLOCK

   ~~~ c++
   case BLOCK: {
               ExprTreeEvaluator new_this(this);
               int k = tree->getChildCount(tree);
               for (int i = 0; i < k; i++) {
                   int val = new_this.run(getChild(tree, i));
                   cout << "Block Value : " << val << endl;
               }
               return 0;
           } break;

   ~~~

   ​

### 2.简单的流程控制

* if结构的增加
* for结构的增加
* while结构的增加
* do_while语句的增加
* printf语句

1，封装抽象语法树

* 封装到命名空间
* 第一个构造函数传入文件名， 通过文件名构建与发树

2.拿到ASTNode 

* 在当前节点信息获得子孩子
* 获得当前节点的字符串信息