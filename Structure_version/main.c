#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id; //学号
    char name[20]; //姓名
    int literature;  //语文成绩
    int math;  // 数学成绩
    int eng;    //英语成绩
    int sum;  //总成绩
} stu[200], n;  //保存n个人的信息

// 录入学生信息
void InputStudentInfo();

// 查看学生信息
void ViewStudentInfo();

//总成绩排序
void Grade_ranking();

//搜索学生信息(id)
void SearchStudentInfo_id();

//搜索学生信息(name)
void SearchStudentInfo_name();

//修改学生信息
void ModifyStudentInfo();

//删除学生信息(id)
void DeleteStudentInfo_id();

//删除学生信息(name)
void DeleteStudentInfo_name();

//程序循环体
int Loop();

//打开文件并存储信息
void save_data(int num);

//读取文件信息
int get_Info();

int main() {
    Loop();

    return 0;
}

// menu表示菜单
void menu() {
    printf("\n\n\n");
    printf("    **********************************************\n");
    printf("    *          欢迎使用学生管理管理系统               *\n");
    printf("    **********************************************\n");
    printf("    *             请选择功能列表                    *\n");
    printf("    **********************************************\n");
    printf("    *          [1] 录入学生信息                    *\n");
    printf("    *          [2] 查看学生信息                    *\n");
    printf("    *          [3] 按总成绩排序                    *\n");
    printf("    *          [4] 搜索学生信息                    *\n");
    printf("    *          [5] 修改学生信息                    *\n");
    printf("    *          [6] 删除学生信息                    *\n");
    printf("    *          [0] 退出系统                       *\n");
    printf("    **********************************************\n");
}

int Loop() {
    while (1) {
        int ch, sea, mo;
        menu();
        printf("->请选择：");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                InputStudentInfo();
                break;
            case 2:
                ViewStudentInfo();
                break;
            case 3:
                Grade_ranking();
                break;
            case 4:
                printf("\n");
                printf("[1] 【按学号搜索】\n");
                printf("[2] 【按姓名搜索】\n");
                printf("[3] 【返回】\n");
                printf("-->请选择:");
                scanf("%d", &sea);
                switch (sea) {
                    case 1:
                        SearchStudentInfo_id();
                        break;
                    case 2:
                        SearchStudentInfo_name();
                        break;
                    case 3:
                        break;
                }
                break;
            case 5:
                ModifyStudentInfo();
                break;
            case 6:
                printf("\n");
                printf("[1] 【按学号删除】\n");
                printf("[2] 【按姓名删除】\n");
                printf("[3] 【返回】\n");
                printf("-->请选择:");
                scanf("%d", &mo);
                switch (mo) {
                    case 1:
                        DeleteStudentInfo_id();
                        break;
                    case 2:
                        DeleteStudentInfo_name();
                        break;
                    case 3:
                        break;
                }
                break;
            case 9:
                get_Info();
                break;
            case 0:
                //退出系统
                exit(0);
            default:
                printf("输入错误，请重新输入！\n\n");
                system("pause");
                break;
        }
    }
}

// 打开文件保存信息函数,num为保存个数
void save_data(int num) {
    char value[5];
    printf("是否保存信息:\n");
    printf("【Y】 / 【N】\n");
    printf("-->");
    scanf("%s", value);
    if (strcmp(value, "Y") == 0) {
        FILE *fp = NULL;
        fp = fopen("../data.txt", "w+");
        for (int i = 0; i < num; ++i) {
            fprintf(fp, "%d\t%s\t%d\t%d\t%d\t%d\n", stu[i].id, stu[i].name, stu[i].literature, stu[i].math, stu[i].eng,
                    stu[i].sum);
        }
        printf("数据保存成功!\n");
        fclose(fp);
        system("pause");
        return;
    }
    if (strcmp(value, "N") == 0) {
        printf("请注意,数据未保存,请先保存后操作,避免丢失数据!\n");
        system("pause");
        return;
    }
}

// 录入学生信息
void InputStudentInfo() {
    int val, num = get_Info();
    printf("请输入要录入的学生个数:");
    scanf("%d", &val);
    for (int i = num; i < num + val; ++i) {
        printf("->请输入第 %d 位学生信息:\n", i + 1);
        printf("-->学号:");
        scanf("%d", &stu[i].id);
        printf("-->姓名:");
        scanf("%s", stu[i].name);
        printf("-->语文成绩:");
        scanf("%d", &stu[i].literature);
        printf("-->数学成绩:");
        scanf("%d", &stu[i].math);
        printf("-->英语成绩:");
        scanf("%d", &stu[i].eng);
        stu[i].sum = stu[i].literature + stu[i].math + stu[i].eng;
    }
    save_data(num + val);
}

// 查看学生信息
void ViewStudentInfo() {
    char ch;
    FILE *fp;
    fp = fopen("../data.txt", "a+");
    ch = fgetc(fp);
    if (ch == EOF) {
        printf("未存储任何学生信息！请先储存信息后操作！\n");
        system("pause");
        return;
    }
    printf("****所有学生信息****\n");
    printf("学号\t姓名\t语文\t数学\t英语\t总分\n");
    putchar(ch);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    system("pause");
}

//总成绩排序
void Grade_ranking() {
    int num = get_Info();
    if (num == 0) {
        return;
    }
    int i, j;
    for (i = 0; i < num; i++) { // 使用冒泡排序
        for (j = i + 1; j < num; j++) {
            if (stu[i].sum < stu[j].sum) {
                n = stu[i];
                stu[i] = stu[j];
                stu[j] = n;
            }
        }
    }
    printf("****总成绩排序****\n");
    printf("学号\t姓名\t语文\t数学\t英语\t总分\n");
    for (int k = 0; k < num; ++k) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", stu[k].id, stu[k].name, stu[k].literature, stu[k].math, stu[k].eng,
               stu[k].sum);
    }
    system("pause");
}

//搜索学生信息(id)
void SearchStudentInfo_id() {
    int num = get_Info();
    if (num == 0) {
        return;
    }
    int value, count = 0;
    printf("--->请输入学号:");
    scanf("%d", &value);
    for (int i = 0; i < num; ++i) {
        if (value == stu[i].id) {
            printf("学号\t姓名\t语文\t数学\t英语\t总分\n");
            printf("%d\t%s\t%d\t%d\t%d\t%d\n", stu[i].id, stu[i].name, stu[i].literature, stu[i].math, stu[i].eng,
                   stu[i].sum);
            ++count;
            break;
        }
    }
    if (count == 0) {
        printf("搜索学生信息失败!\n");
    }
    system("pause");
}

//搜索学生信息(name)
void SearchStudentInfo_name() {
    int num = get_Info(), count = 0;
    if (num == 0) {
        return;
    }
    char find_name[20];
    printf("--->请输入姓名:");
    scanf("%s", find_name);
    for (int i = 0; i < num; ++i) {
        if (strcmp(stu[i].name, find_name) == 0) {
            printf("学号\t姓名\t语文\t数学\t英语\t总分\n");
            printf("%d\t%s\t%d\t%d\t%d\t%d\n", stu[i].id, stu[i].name, stu[i].literature, stu[i].math, stu[i].eng,
                   stu[i].sum);
            ++count;
            break;
        }
    }
    if (count == 0) {
        printf("搜索学生信息失败!\n");
    }
    system("pause");
}

//修改学生信息
void ModifyStudentInfo() {
    int num = get_Info(), count = 0;  // 先获取的学生个数
    if (num == 0) {
        return;
    }
    int val;
    printf("请输入学号:");
    scanf("%d", &val);
    for (int i = 0; i < num; ++i) {
        if (stu[i].id == val) {
            printf("请输入修改后的学号:");
            scanf("%d", &stu[i].id);
            printf("请输入修改后的姓名:");
            scanf("%s", stu[i].name);
            printf("请输入修改后的语文成绩:");
            scanf("%d", &stu[i].literature);
            printf("请输入修改后的数学成绩:");
            scanf("%d", &stu[i].math);
            printf("请输入修改后的英语成绩:");
            scanf("%d", &stu[i].eng);
            stu[i].sum = stu[i].literature + stu[i].math + stu[i].eng;
            ++count;
            break;
        }
    }
    if (count == 0) {
        printf("未查找到该学生!\n");
    }
    system("pause");
    save_data(num); // 保存数据函数
}

//删除学生信息(id)
void DeleteStudentInfo_id() {
    int num = get_Info(), count = 0, val;
    if (num == 0) {
        return;
    }
    printf("--->请输入学号:");
    scanf("%d", &val);
    for (int i = 0; i < num; ++i) {
        if (stu[i].id == val) {
            for (int j = i; j < num; ++j) {
                stu[j] = stu[j + 1];
            }
            ++count;
            printf("删除信息成功!\n");
            save_data(num - 1);
            break;
        }
    }
    if (count == 0) {
        printf("删除信息失败!\n");
    }
    system("pause");
}

//删除学生信息(name)
void DeleteStudentInfo_name() {
    int num = get_Info(), count = 0;
    if (num == 0) {
        return;
    }
    char del_name[20];
    printf("--->请输入姓名:");
    scanf("%s", del_name);
    for (int i = 0; i < num; ++i) {
        if (strcmp(stu[i].name, del_name) == 0) {
            for (int k = i; k < num; ++k) {
                stu[k] = stu[k + 1];
            }
            ++count;
            printf("删除信息成功!\n");
            save_data(num - 1);
            break;
        }
    }
    if (count == 0) {
        printf("删除信息失败!\n");
    }
    system("pause");
}

// 读取文件信息
int get_Info() {
    int num = 0, i = 0;
    char ch, val;
    FILE *fp;
    fp = fopen("../data.txt", "a+");
    ch = fgetc(fp);
    if (ch == EOF) {
        printf("未存储任何学生信息！请先储存信息后操作！\n");
        system("pause");
        return 0;
    } else {
        fp = fopen("../data.txt", "a+");
        while ((feof(fp) == 0)) {
            fscanf(fp, "%d", &stu[i].id);
            fgetc(fp);
            fscanf(fp, "%s", stu[i].name);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].literature);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].math);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].eng);
            fgetc(fp);
            fscanf(fp, "%d", &stu[i].sum);
            fgetc(fp);
            ++i;
            ++num;
        }
        --num;
    }
    return num;
}