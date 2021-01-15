//一个学生信息管理系统，能够对学生的学号、姓名和各科成绩进行统计、处理和更新
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生结构体
typedef struct _Student {
    int id; // 学号
    char name[20];   // 姓名
    int math; // 数学成绩
    int eng;  // 英语成绩
    int C;    // C语言成绩
    int sum;  // 总成绩
} Student;

//创建链表
typedef struct _Node {
    Student stu;        // 学生信息
    struct _Node *next; // 下一个节点指针
} Node;

//头结点
Node *g_pHead = NULL;


//文件
FILE *fp;
char filename[120];

// 欢迎界面
void menu();

//创建头结点
void CreatListOfHead();

//录入学生信息
void InputStudentInfo();

//查看学生信息
void ViewStudentInfo();

//增加学生信息
void AddStudentInfo();

//总成绩排序
void GradesRanking();

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

//循环体
int Loop();

int main() {
    menu();
    Loop();

    return 0;
}


// menu表示菜单
void menu() {
    printf("\n\n\n");
    printf("    *******************************************\n");
    printf("    *          欢迎使用成绩管理系统               *\n");
    printf("    *******************************************\n");
    printf("    *             请选择功能列表                 *\n");
    printf("    *******************************************\n");
    printf("    *          [1] 录入学生信息                 *\n");
    printf("    *          [2] 查看学生信息                 *\n");
    printf("    *          [3] 增加学生信息                 *\n");
    printf("    *          [4] 按总成绩排序                 *\n");
    printf("    *          [5] 搜索学生信息                 *\n");
    printf("    *          [6] 修改学生信息                 *\n");
    printf("    *          [7] 删除学生信息                 *\n");
    printf("    *          [0] 退出系统                    *\n");
    printf("    *******************************************\n");
}

//创建头结点
void CreatListOfHead() {
    Node *g_pHead = (Node *) malloc(sizeof(Node));
    g_pHead->next = NULL;
}

void InputStudentInfo() {
    //申请内存，开辟节点
    Node *p = (Node *) malloc(sizeof(Node));
    p->next = NULL;
    printf("请输入学生信息:\n");
    printf("学号:");
    scanf("%d", &p->stu.id);
    printf("姓名:");
    scanf("%s", p->stu.name);
    printf("数学成绩:");
    scanf("%d", &p->stu.math);
    printf("英语成绩:");
    scanf("%d", &p->stu.eng);
    printf("C语言成绩:");
    scanf("%d", &p->stu.C);
    p->stu.sum = p->stu.math + p->stu.eng + p->stu.C;

    //将节点添加到链表中
    if (g_pHead == NULL) {
        g_pHead = p;
    } else {
        //头插法
        p->next = g_pHead;
        g_pHead = p;
    }
    printf("信息录入成功！\n");
}

void ViewStudentInfo() {

    //遍历链表
    Node *p = g_pHead;
    while (p != NULL) {
        printf("%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng,
               p->stu.C, p->stu.sum);
        p = p->next;
    }
    if (g_pHead == NULL) {
        printf("|没有存储学生信息!\n");
    }
}

void AddStudentInfo() {

}

void GradesRanking() {

}

void SearchStudentInfo_id() {

}

void SearchStudentInfo_name() {

}

void ModifyStudentInfo() {

}

void DeleteStudentInfo_id() {

}

void DeleteStudentInfo_name() {

}

int Loop() {
    while (1) {
        int ch, sea, mo;
        printf("请选择：");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                InputStudentInfo();
                break;
            case 2:
                ViewStudentInfo();
                break;
            case 3:
                AddStudentInfo();
                break;
            case 4:
                GradesRanking();
                break;
            case 5:
                printf("\n");
                printf("[1] 【按学号搜索】\n");
                printf("[2] 【按姓名搜索】\n");
                printf("[3] 【返回】\n");
                printf("->请选择:");
                scanf("%d", &sea);
                switch (sea) {
                    case 1:
                        SearchStudentInfo_id();
                    case 2:
                        SearchStudentInfo_name();
                    case 3:
                        break;
                }
                break;
            case 6:
                ModifyStudentInfo();
                break;
            case 7:
                printf("\n");
                printf("[1] 【按学号删除】\n");
                printf("[2] 【按姓名删除】\n");
                printf("[3] 【返回】\n");
                printf("->请选择:");
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