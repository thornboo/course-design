//一个学生信息管理系统，能够对学生的学号、姓名和各科成绩进行统计、处理和更新
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stu_count = 0;

//学生结构体
typedef struct Student {
    int id; // 学号
    char name[20];   // 姓名
    int math; // 数学成绩
    int eng;  // 英语成绩
    int C;    // C语言成绩
    int sum;  // 总成绩
} Student;

//创建空链表
typedef struct Node {
    Student stu;    // 学生信息
    struct Node *next; // 下一个节点指针,(定义结构体指针变量)
} Node;

//头结点
Node *firstHead = NULL;

//文件
void openfile();

// 欢迎界面
void menu();

//创建头结点
void CreatHead();

//录入学生信息
void InputStudentInfo();

//查看学生信息
void ViewStudentInfo();

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

//永久循环体
int Loop();

int main() {
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
    printf("    *          [3] 按总成绩排序                 *\n");
    printf("    *          [4] 搜索学生信息                 *\n");
    printf("    *          [5] 修改学生信息                 *\n");
    printf("    *          [6] 删除学生信息                 *\n");
    printf("    *          [0] 退出系统                    *\n");
    printf("    *******************************************\n");
}

// 打开文件保存信息函数
void save_date() {
    char value[5];
    printf("是否将信息到文件中:\n");
    printf("【Y】 / 【N】\n");
    printf("-->");
    scanf("%s", value);
    if (strcmp(value, "Y") == 0) {
        Node *p = firstHead;
        FILE *fp = NULL;
        fp = fopen("../data.txt", "a+");
        while (p != NULL) {
            fprintf(fp, "%d %s %d %d %d %d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
                    p->stu.sum);
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

//创建头结点
void CreatHead() {
    Node *firstHead = (Node *) malloc(sizeof(Node));
    firstHead->next = NULL;
}

// 录入学生信息函数
void InputStudentInfo() {
    int val;
    char value;
    printf("请输入要录入的学生个数:");
    scanf("%d", &val);
    for (int i = 0; i < val; ++i) {
        //申请内存，开辟节点
        Node *p = (Node *) malloc(sizeof(Node));
        p->next = NULL;
        printf("请输入第%d学生信息:\n", i + 1);
        printf("-->学号:");
        scanf("%d", &p->stu.id);
        printf("-->姓名:");
        scanf("%s", p->stu.name);
        printf("-->数学成绩:");
        scanf("%d", &p->stu.math);
        printf("-->英语成绩:");
        scanf("%d", &p->stu.eng);
        printf("-->C语言成绩:");
        scanf("%d", &p->stu.C);
        p->stu.sum = p->stu.math + p->stu.eng + p->stu.C;

        //将节点添加到链表中
        if (firstHead == NULL) {
            firstHead = p;
        } else {
            //头插法
            p->next = firstHead;
            firstHead = p;
        }
    }
    save_date();
}

// 查看学生信息函数
void ViewStudentInfo() {
    //遍历链表
    printf("学号\t姓名\t数学\t英语\tC语言\t总成绩\n");
    Node *p = firstHead;
    while (p != NULL) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
               p->stu.sum);
        p = p->next;
    }
    if (firstHead == NULL) {
        printf("没有存储任何学生信息!\n");
    }
    system("pause");
}

// 按总成绩从高到低排名函数
void GradesRanking() {
    Student temp;
    Node *p = firstHead;
    Node *q = NULL;
    Node *r = NULL;
    while (p->next != NULL) {
        p = p->next;
    }
    q = p;
    p = firstHead;
    r = p->next;
    while (p != q) {
        while (r != q->next) {
            if (p->stu.sum < r->stu.sum) {
                temp = p->stu;
                p->stu = r->stu;
                r->stu = temp;
            }
            if (r == q) {
                q = p;
                p = firstHead;
                r = p->next;
                break;
            }
            p = p->next;
            r = r->next;
        }
    }
    printf("*****【总成绩排名】*****\n");
    while (p != NULL) {
        printf("学号\t姓名\t数学\t英语\tC语言\t总成绩\n");
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
               p->stu.sum);
        p = p->next;
    }
    system("pause");
}

// 按学号搜索学生信息函数
void SearchStudentInfo_id() {
    Node *p = firstHead;
    int id, val = 1;
    printf("请输入要搜索的学生学号:");
    scanf("%d", &id);
    while (p->next != NULL) {
        if (p->stu.id == id) {
            printf("学号\t姓名\t数学\t英语\tC语言\t总成绩\n");
            printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
                   p->stu.sum);
            --val;
            system("pause");
        }
        p = p->next;
        if (val == 1) {
            printf("未查询到该生有关信息!\n");
            system("pause");
            return;
        }
    }
}

// 按姓名搜索学生信息函数
void SearchStudentInfo_name() {
    Node *p = firstHead;
    char name[20];
    printf("请输入要搜索的学生姓名:");
    scanf("%s", name);
    while (p && (strcmp(p->stu.name, name) != 0)) {
        p = p->next;
    }
    if (p) {
        printf("学号\t姓名\t数学\t英语\tC语言\t总成绩\n");
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", p->stu.id, p->stu.name, p->stu.math, p->stu.eng, p->stu.C,
               p->stu.sum);
        system("pause");
    } else {
        printf("未查询到该生有关信息!\n");
        system("pause");
        return;
    }
}

// 修改学生信息函数
void ModifyStudentInfo() {
    int id;
    printf("请输入要修改的学生学号:");
    scanf("%d", &id);
    Node *p = firstHead;
    while (p && (p->stu.id != id)) {
        p = p->next;
    }
    if (p) {
        printf("请输入新的信息:\n");
        printf("-->请输入修改后的学号:");
        scanf("%d", &p->stu.id);
        printf("-->请输入修改后的姓名:");
        scanf("%s", p->stu.name);
        printf("-->请输入修改后的数学成绩:");
        scanf("%d", &p->stu.math);
        printf("-->请输入修改后的成绩:");
        scanf("%d", &p->stu.eng);
        printf("-->请输入修改后的C语言成绩:");
        scanf("%d", &p->stu.C);
        p->stu.sum = p->stu.math + p->stu.eng + p->stu.C;
        save_date();
        system("pause");
        return;
    } else {
        printf("未查询到该生有关信息!\n");
        system("pause");
        return;
    }
}

// 按学号删除学生信息函数
void DeleteStudentInfo_id() {
    int id;
    printf("请输入要删除的学生学号:");
    scanf("%d", &id);
    Node *p = firstHead;
    while (1) {
        if (p->next && (p->next->stu.id == id)) {
            Node *useless = p->next;
            p->next = useless->next;
            printf("该生有关信息已删除!");
            system("pause");
            free(useless);
            save_date();
            return;
        } else {
            if (p->next != NULL) {
                p = p->next;
            } else {
                printf("信息删除失败!");
                system("pause");
                return;
            }
        }
    }
}

// 按姓名删除学生信息函数
void DeleteStudentInfo_name() {
    char name[20];
    printf("请输入要删除的学生姓名:");
    scanf("%s", name);
    Node *p = firstHead;
    while (1) {
        if (p->next && (strcmp(p->stu.name, name) == 0)) {
            Node *useless = p->next;
            p->next = p->next->next;
            printf("该生有关信息已删除!\n");
            system("pause");
            free(useless);
            save_date();
            return;
        } else {
            if (p->next != NULL) {
                p = p->next;
            } else {
                printf("信息删除失败!");
                system("pause");
                return;
            }
        }
    }
}

// 永久循环体函数
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
                GradesRanking();
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