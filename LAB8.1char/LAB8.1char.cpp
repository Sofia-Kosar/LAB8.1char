#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(char* s) {
    int k = 0,
        pos = 0;
    char* t;
    while (t = strchr(s + pos, 'a')) {
        pos = t - s + 1;
        if (s[pos] == 'a') {
            k++;
        }
    }
    while (t = strchr(s + pos, 'b')) {
        pos = t - s + 1;
        if (s[pos] == 'b') {
            k++;
        }
        while (t = strchr(s + pos, 'c')) {
            pos = t - s + 1;
            if (s[pos] == 'c') {
                k++;
            }
        }
    }
    return k;
}

char* Change(char* s) {
    char* t = new char[strlen(s) * 3 + 1];
    char* p;
    int pos1 = 0,
        pos2 = 0;
    *t = 0;

    while (p = strchr(s + pos1, 'a')) {
        if (s[p - s + 1] == 'a') {
            pos2 = p - s + 2;
            strncat(t, s + pos1, pos2 - pos1 - 2);
            strcat(t, "***");
            pos1 = pos2;
        }
        else {
            pos2 = p - s + 1;
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    while (p = strchr(s + pos1, 'b')) {
        if (s[p - s + 1] == 'b') {
            pos2 = p - s + 2;
            strncat(t, s + pos1, pos2 - pos1 - 2);
            strcat(t, "***");
            pos1 = pos2;
        }
        else {
            pos2 = p - s + 1;
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    while (p = strchr(s + pos1, 'c')) {
        if (s[p - s + 1] == 'c') {
            pos2 = p - s + 2;
            strncat(t, s + pos1, pos2 - pos1 - 2);
            strcat(t, "***");
            pos1 = pos2;
        }
        else {
            pos2 = p - s + 1;
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main() {
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contains " << Count(str) << " pairs of 'aa' , 'bb' , 'cc' " << endl;

    char* dest = new char[strlen(str) * 3 + 1];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    return 0;
}
