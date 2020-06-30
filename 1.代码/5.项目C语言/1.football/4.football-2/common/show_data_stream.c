/*************************************************************************
	> File Name: show_data_stream.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月30日 星期二 19时21分37秒
 ************************************************************************/
 #include "head.h"

 extern char data_stream[20];
 extern WINDOW *Help;
 extern struct MAp court;

 void show_data_stream(int type) {
     for(int i = 18; i > 0; --i) {
         data_stream[i] - data_stream[i - 1];
     }
     data_stream[0] = type;
     for(int i = 0; i < 20; ++i) {
         switch(data_stream[i]) {
             case 'l': {
                 wattron(Help, COLOR_PAIR(7));
             } break;
             case 'c': {
                 wattron(Help, COLOR_PAIR(8));
             } break;
             case 'k' {
                 wattron(, COLOR_PAIR(9));
            } break;
             case 's' {
                wattron(Help, COLOR_PAIR(10));
             }break;
             case 'n' {
                 wattron(Help, COLOR_PAIR(11));
             }break;
             case 'e' {
                 wattron(Help, COLOR_PAIR(12));
             }break;
         }
         mvwprintw(Help, Court.height, i, " ");
     }
 }
