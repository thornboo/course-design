#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

struct student {
    int id; //学号
    char name[20]; //姓名
    int math;  //数学成绩
    int eng;  // 英语成绩
    int C;    //C语言成绩
    int sum;  //总成绩
    double av;  //平均成绩
} stu, n;  //保存n个人的信息

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

//永久循环体
int Loop();

//打开文件保存信息函数
void save_date();

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
                    case 2:
                        DeleteStudentInfo_name();
                    case 3:
                        break;
                }
                break;
            case 0:
                //退出系统
                exit(0);
            default:
                break;
        }
    }
}

// 打开文件保存信息函数
void save_date() {
    char value[5];
    printf("是否将信息到文件中:\n");
    printf("【Y】 / 【N】\n");
    printf("-->");
    scanf("%s", value);
    if (strcmp(value, "Y") == 0) {
        Node *p = Head;
        FILE *fp = NULL;
        fp = fopen("../data.txt", "a+");
        while (p != NULL) {
            fprintf(fp, "%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.post, p->wor.bra,
                    p->wor.pay);
            p = p->next;
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

}

// 查看学生信息
void ViewStudentInfo() {

}

//总成绩排序
void Grade_ranking() {

}

//搜索学生信息(id)
void SearchStudentInfo_id() {

}

//搜索学生信息(name)
void SearchStudentInfo_name() {

}

//修改学生信息
void ModifyStudentInfo() {

}

//删除学生信息(id)
void DeleteStudentInfo_id() {

}

//删除学生信息(name)
void DeleteStudentInfo_name() {

}