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

   *  

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