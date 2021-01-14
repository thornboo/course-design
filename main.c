//一个学生信息管理系统，能够对学生的学号、姓名和各科成绩进行统计、处理和更新
#include<stdio.h>
#include <string.h>

struct student {
    char name[20]; // 姓名
    int id; // 学号
    int math; // 数学成绩
    int eng;  // 英语成绩
    int C;    // C语言成绩
    int sum;  // 总成绩
    double av;  // 平均成绩
} student[200], n;  // 保存n个人的信息


void menu() // menu表示菜单
{
    printf("欢迎使用学生信息管理系统\n");
    printf("[1] 录入所有学生信息\n");
    printf("[2] 输出所有学生信息\n");
    printf("[3] 增加学生信息\n");
    printf("[4] 按学号查找某个学生信息\n");
    printf("[5] 按姓名查找某个学生信息\n");
    printf("[6] 按总成绩对学生排序\n");
    printf("[7] 按学号修改某个学生信息\n");
    printf("[8] 按姓名修改某个学生信息\n");
    printf("[9] 按学号删除某个学生信息\n");
    printf("[10] 按姓名删除某个学生信息\n");
    printf("[0] 退出系统\n");
}


int main() {

    int num = 0, ch = 11; // 学生人数
    int input1(); // 函数声明
    void output2(int num);
    int output3(int num);
    void output4(int num);
    void output5(int num);
    void output6(int num);
    void output7(int num);
    void output8(int num);
    void output9(int num);
    void output10(int num);
    void pause();   // 暂停函数
    while (1) {
        menu();
        printf("请输入你的选择(0~10)：");
        scanf("%d", &ch);
        if (ch == 1) {
            num = input1();
            pause();
        } else if (ch == 2) {
            output2(num);
            pause();
        } else if (ch == 3) {
            num = output3(num);
            pause();
        } else if (ch == 4) {
            output4(num);
            pause();
        } else if (ch == 5) {
            output5(num);
            pause();
        } else if (ch == 6) {
            output6(num);
            pause();
        } else if (ch == 7) {
            output7(num);
            pause();
        } else if (ch == 8) {
            output8(num);
            pause();
        } else if (ch == 9) {
            output9(num);
            pause();
        } else if (ch == 10) {
            output10(num);
            pause();
        } else if (ch == 0) {
            break;
        }
    }
    return 0;
}

int input1() {
    int val;
    printf("请输入要录入信息的学生个数:");
    scanf("%d", &val);
    for (int i = 0; i < val; i++) {   // 录入n个学生的信息
        printf("请输入第%d个学生的姓名 学号，数学成绩，英语成绩，C语言成绩(用空格隔开)\n", i + 1);
        scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
              &student[i].C);
        student[i].sum = student[i].math + student[i].eng + student[i].C;
        student[i].av = 1.0 * student[i].sum / 3;
    }
    return val;
}

void output2(int num) {
    printf("以下为所有学生信息:\n");
    for (int j = 0; j < num; j++) {
        printf("姓名:%s, 学号:%d, 数学:%d, 英语:%d, C语言:%d, 总成绩:%d\n", student[j].name, student[j].id,
               student[j].math, student[j].eng, student[j].C, student[j].sum);
    }
}

int output3(int num) {
    int q;
    printf("请输入要增加的学生个数:");
    scanf("%d", &q);
    for (int i = num; i < num + q; i++) {
        printf("请依次输入姓名，学号，数学成绩，英语成绩，C语言成绩(用空格隔开)\n");
        scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
              &student[i].C);
        student[i].sum = student[i].math + student[i].eng + student[i].C;
        student[i].av = 1.0 * student[i].sum / 3;
    }
    return num + q;
}

void output4(int num) {
    int s;
    printf("请输入学号:");
    scanf("%d", &s);
    for (int i = 0; i < num; i++) {
        if (student[i].id == s) {
            printf("姓名:%s, 学号:%d, 数学:%d, 英语:%d, C语言:%d, 总成绩:%d\n", student[i].name, student[i].id,
                   student[i].math, student[i].eng, student[i].C, student[i].sum);
            break;
        }
    }
}

void output5(int num) {
    char s[20];
    printf("请输入姓名:");
    scanf("%s", s);
    for (int i = 0; i < num; i++) {
        if (strcmp(student[i].name, s) == 0) {
            printf("姓名:%s, 学号:%d, 数学:%d, 英语:%d, C语言:%d, 总成绩:%d\n", student[i].name, student[i].id,
                   student[i].math, student[i].eng, student[i].C, student[i].sum);
            break;
        }
    }
}

void output6(int num) {
    int i, j;
    for (i = 0; i < num; i++) { // 按总分递减排序
        for (j = i + 1; j < num; j++) {
            if (student[j].sum > student[i].sum) {
                n = student[i];
                student[i] = student[j];
                student[j] = n;
            }
        }
    }
    for (int k = 0; k < num; k++) {
        printf("姓名:%s, 学号:%d, 数学:%d, 英语:%d, C语言:%d, 总成绩:%d\n", student[k].name, student[k].id,
               student[k].math, student[k].eng, student[k].C, student[k].sum);
    }
}

void output7(int num) {
    int ID1;
    printf("请输入学号:\n");
    scanf("%d", &ID1);
    for (int i = 0; i < num; i++) {
        if (student[i].id == ID1) {
            printf("请输入新的信息:\n");
            scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
                  &student[i].C);
            student[i].sum = student[i].math + student[i].eng + student[i].C;
            student[i].av = 1.0 * student[i].sum / 3;
            break;
        }
    }
}

void output8(int num) {
    char title[20];
    printf("请输入姓名:");
    scanf("%s", title);
    for (int i = 0; i < num; i++) {
        if (strcmp(student[i].name, title) == 0) {
            printf("请输入新的信息:\n");
            scanf("%s %d %d %d %d", student[i].name, &student[i].id, &student[i].math, &student[i].eng,
                  &student[i].C);
            student[i].sum = student[i].math + student[i].eng + student[i].C;
            student[i].av = 1.0 * student[i].sum / 3;
            break;
        }
    }
}

void output9(int num) {
    int ID2;
    printf("请输入学号:");
    scanf("%d", &ID2);
    for (int i = 0; i < num; i++) {
        if (student[i].id == ID2) {
            
        }
    }
}

void output10(int num) {
    char title;
    printf("请输入姓名:");
    scanf("%c", &title);
    for (int i = 0; i < num; i++) {
        if (strcmp(student[i].name, &title) == 0) {

        }
    }
}

void pause() {
    getchar();
    printf("请按回车继续...");
    getchar();
}