//一个企业员工信息管理系统，能够对企业员工的根据工号、部门或职位进行统计、处理和更新，并且可以方便企业领导对员工进行整体分析。
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//员工结构体
typedef struct Worker {
    int id; // 工号
    char name[20];   // 姓名
    int age; // 年龄
    char bra[20];  // 部门
    char post[20];    // 职位
    int pay;  // 工资
} Worker;

//创建空链表
typedef struct Node {
    Worker wor;    // 员工信息
    struct Node *next; // 下一个节点指针,(定义结构体指针变量)
} Node;

//头结点
Node *Head = NULL;

//打开文件操作
void openfile();

// 登录验证函数
void Authentication();

// 欢迎界面
void menu();

//创建头结点
void CreatHead();

//录入员工信息
void InputWorkerInfo();

//查看员工信息
void ViewWorkerInfo();

//工资排序
void Salary_ranking();

//搜索员工信息(id)
void SearchWorkerInfo_id();

//搜索员工信息(name)
void SearchWorkerInfo_name();

//修改员工信息
void ModifyWorkerInfo();

//删除员工信息(id)
void DeleteWorkerInfo_id();

//删除员工信息(name)
void DeleteWorkerInfo_name();

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
    printf("    *          欢迎使用企业管理系统               *\n");
    printf("    *******************************************\n");
    printf("    *             请选择功能列表                 *\n");
    printf("    *******************************************\n");
    printf("    *          [1] 录入员工信息                 *\n");
    printf("    *          [2] 查看员工信息                 *\n");
    printf("    *          [3] 按工资排序                   *\n");
    printf("    *          [4] 搜索员工信息                 *\n");
    printf("    *          [5] 修改员工信息                 *\n");
    printf("    *          [6] 删除员工信息                 *\n");
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

//创建头结点
void CreatHead() {
    Node *Head = (Node *) malloc(sizeof(Node));
    Head->next = NULL;
}

// 录入员工信息函数
void InputWorkerInfo() {
    int val;
    printf("请输入要录入的员工个数:");
    scanf("%d", &val);
    for (int i = 0; i < val; ++i) {
        //申请内存，开辟节点
        Node *p = (Node *) malloc(sizeof(Node));
        p->next = NULL;
        printf("->请输入第 %d 位员工信息:\n", i + 1);
        printf("-->工号:");
        scanf("%d", &p->wor.id);
        printf("-->姓名:");
        scanf("%s", p->wor.name);
        printf("-->年龄:");
        scanf("%d", &p->wor.age);
        printf("-->部门:");
        scanf("%s", p->wor.bra);
        printf("-->职位:");
        scanf("%s", p->wor.post);
        printf("-->工资:");
        scanf("%d", &p->wor.pay);

        //将节点添加到链表中
        if (Head == NULL) {
            Head = p;
        } else {
            //头插法
            p->next = Head;
            Head = p;
        }
    }
    save_date();
}

// 查看员工信息函数
void ViewWorkerInfo() {
    char ch;
    FILE *fp = NULL;
    fp = fopen("../data.txt", "r");
    ch = fgetc(fp);
    if (ch == EOF) {
        printf("没有存储任何员工信息!\n");
        system("pause");
        return;
    }
    printf("工号\t姓名\t年龄\t部门\t职位\t工资\n");
    putchar(ch);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    system("pause");
    return;
}

// 按工资从高到低排名函数
void Salary_ranking() {
    Worker temp;
    Node *p = Head;
    Node *q = NULL;
    Node *r = NULL;
    while (p->next != NULL) {
        p = p->next;
    }
    q = p;
    p = Head;
    r = p->next;
    while (p != q) {
        while (r != q->next) {
            if (p->wor.pay < r->wor.pay) {
                temp = p->wor;
                p->wor = r->wor;
                r->wor = temp;
            }
            if (r == q) {
                q = p;
                p = Head;
                r = p->next;
                break;
            }
            p = p->next;
            r = r->next;
        }
    }
    printf("*****【工资排名】*****\n");
    while (p != NULL) {
        printf("工号\t姓名\t年龄\t部门\t职位\t工资\n");
        printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.bra, p->wor.post,
               p->wor.pay);
        p = p->next;
    }
    system("pause");
}

// 按工号搜索员工信息函数
void SearchWorkerInfo_id() {
    Node *p = Head;
    int id, val = 1;
    printf("请输入要搜索的员工工号:");
    scanf("%d", &id);
    while (p->next != NULL) {
        if (p->wor.id == id) {
            printf("工号\t姓名\t年龄\t部门\t职位\t工资\n");
            printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.bra, p->wor.post,
                   p->wor.pay);
            --val;
            system("pause");
        }
        p = p->next;
        if (val == 1) {
            printf("未查询到该员工有关信息!\n");
            system("pause");
            return;
        }
    }
}

// 按姓名搜索员工信息函数
void SearchWorkerInfo_name() {
    Node *p = Head;
    char name[20];
    printf("请输入要搜索的员工姓名:");
    scanf("%s", name);
    while (p && (strcmp(p->wor.name, name) != 0)) {
        p = p->next;
    }
    if (p) {
        printf("工号\t姓名\t年龄\t部门\t职位\t工资\n");
        printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->wor.id, p->wor.name, p->wor.age, p->wor.bra, p->wor.post,
               p->wor.pay);
        system("pause");
    } else {
        printf("未查询到该员工有关信息!\n");
        system("pause");
        return;
    }
}

// 修改员工信息函数
void ModifyWorkerInfo() {
    int id;
    printf("请输入要修改的员工工号:");
    scanf("%d", &id);
    Node *p = Head;
    while (p && (p->wor.id != id)) {
        p = p->next;
    }
    if (p) {
        printf("请输入新的信息:\n");
        printf("-->请输入修改后的工号:");
        scanf("%d", &p->wor.id);
        printf("-->请输入修改后的姓名:");
        scanf("%s", p->wor.name);
        printf("-->请输入修改后的年龄:");
        scanf("%d", &p->wor.age);
        printf("-->请输入修改后的部门:");
        scanf("%s", p->wor.bra);
        printf("-->请输入修改后的职位:");
        scanf("%s", p->wor.post);
        printf("请输入修改后的工资:");
        scanf("%d", &p->wor.pay);
        save_date();
        system("pause");
        return;
    } else {
        printf("未查询到该员工有关信息!\n");
        system("pause");
        return;
    }
}

// 按工号删除员工信息函数
void DeleteWorkerInfo_id() {
    int id;
    printf("请输入要删除的员工工号:");
    scanf("%d", &id);
    Node *p = Head;
    while (1) {
        if (p->next && (p->next->wor.id == id)) {
            Node *useless = p->next;
            p->next = useless->next;
            printf("该员工有关信息已删除!");
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

// 按姓名删除员工信息函数
void DeleteWorkerInfo_name() {
    char name[20];
    printf("请输入要删除的员工姓名:");
    scanf("%s", name);
    Node *p = Head;
    while (1) {
        if (p->next && (strcmp(p->wor.name, name) == 0)) {
            Node *useless = p->next;
            p->next = p->next->next;
            printf("该员工有关信息已删除!\n");
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
                InputWorkerInfo();
                break;
            case 2:
                ViewWorkerInfo();
                break;
            case 3:
                Salary_ranking();
                break;
            case 4:
                printf("\n");
                printf("[1] 【按工号搜索】\n");
                printf("[2] 【按姓名搜索】\n");
                printf("[3] 【返回】\n");
                printf("-->请选择:");
                scanf("%d", &sea);
                switch (sea) {
                    case 1:
                        SearchWorkerInfo_id();
                        break;
                    case 2:
                        SearchWorkerInfo_name();
                        break;
                    case 3:
                        break;
                }
                break;
            case 5:
                ModifyWorkerInfo();
                break;
            case 6:
                printf("\n");
                printf("[1] 【按工号删除】\n");
                printf("[2] 【按姓名删除】\n");
                printf("[3] 【返回】\n");
                printf("-->请选择:");
                scanf("%d", &mo);
                switch (mo) {
                    case 1:
                        DeleteWorkerInfo_id();
                        break;
                    case 2:
                        DeleteWorkerInfo_name();
                        break;
                    case 3:
                        break;
                }
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

// 登录验证函数
void Authentication() {
    char account[20];
    char password[20];
    printf("账号:");
    scanf("%s", account);
    printf("密码:");
    scanf("%s", password);
}