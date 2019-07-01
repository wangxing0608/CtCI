//
// Created by wangxing on 19-7-1.
//

// 1.5 判断两个字符串是否小于等于一个编辑距离
// 插入一个字符,移除一个字符,替代一个字符两个字符串相等.即为一个编辑距离


#include <string.h>
#include <iostream>

using namespace std;


bool isOneAway(string s1, string s2){
    string a, b;
    a = s1.length() >= s2.length() ? s1 : s2;
    b = s1.length() < s2.length() ? s1 : s2;
    int len1, len2;
    len1 = a.length();
    len2 = b.length();
    if(abs(len1-len2) > 1)
        return false;

    bool flag = false;
    for(int i = 0,j=0; i<len1 && j<len2;){
        if (a[i] != b[i]) {
            if(flag)
                return false;
            flag = true;
            if(len1=len2){
                i++;
                j++;
            }
            else
                i++;
        }
        else
            i++,j++;
    }
    return true;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if(isOneAway(s1, s2))
        cout<<"One edit away."<<endl;
    else
        cout<<"Not one edit away."<<endl;
    return 0;
}
