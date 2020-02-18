/*************************************************************************
	> File Name: 括号匹配-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月09日 星期日 20时11分43秒
 ************************************************************************/

 #include <iostream>
 #include <cstdio>
 #include <stack>
 using namespace std;
     int ans[50000][2];
         stack<int>q;
         int main()
         {
                 int c1=0;
                 char i;
                 int cnt=0;
                 while(scanf("%c",&i)==1&&i!=10)
                 {   cnt++;
                         if(i=='(')q.push(cnt);
                                    if(i==')')
                  {
                                  if(q.empty() ){cout<<"No";return 0;}
                                  ans[c1][0]=q.top() ;
                                  ans[c1][1]=cnt;
                                  c1++;
                                  q.pop() ;
                               
                  } 
                      }
                 if(q.empty())
             {
                         cout<<"Yes"<<"\n";
                         for(int i=0;i<c1;i++)
                 {
                                 cout<<ans[i][0]<<" "<<ans[i][1];
                                 if(i+1!=c1)cout<<endl;
                              
                 } 
                     
             }
                 else cout<<"No";
                 return 0;
         } 
    
