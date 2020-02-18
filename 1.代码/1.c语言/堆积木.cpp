/*************************************************************************
	> File Name: 堆积木.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月04日 星期二 16时18分33秒
 ************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> arr[n + 50];
    for(int i = 1; i <= n; i++) {
        arr[i].push_back(i);
    }
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        if(a == b) continue;
        for(int j = 0; j < arr[b].size(); j++) {
            arr[a].push_back(arr[b][j]);        
        }
        vector<int> c;{
            c.swap(arr[b]);
        }  
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < arr[i].size();j++) {
            cout << arr[i][j];
            j < arr[i].size() && cout << " ";           
        }
        cout << endl;            
    }
        return 0;

}
