package main;

import java.util.ArrayList;
import java.util.Scanner;

import controller.ManagerCon;
import controller.WorkerCon;
import modle.Manager;
import modle.Worker;

public class Main {

    //创建管理类
    static WorkerCon workercon;
    static ManagerCon managercon;

    //创建动态集合
    static ArrayList<Worker> workers = new ArrayList<>();
    static ArrayList<Manager> managers = new ArrayList<>();

    public static void main(String[] args) {

        //初始化
        workercon = new WorkerCon(workers);
        managercon = new ManagerCon(managers);
        //记录操作数
        String manipulation;
        //flag标识符，判断退出条件
        boolean flag = true;
        //输入类调入
        Scanner scan = new Scanner(System.in);

        while (flag) {
            System.out.println("|-----欢迎来到员工管理系统-----|");
            System.out.println("您可以进行如下操作:");
            System.out.print("1.登录\t2.注册\t0.退出\n");
            System.out.println("请选择您的操作:");
            manipulation = scan.next();
            switch (manipulation) {
                case "1":
                    //登录界面
                    if (managercon.isLogin()) {
                        // 登陆成功
                        boolean flag1 = true;
                        while (flag1) {
                            System.out.println("|-----员工信息管理系统-----|");
                            System.out.println("您可以进行如下操作:");
                            System.out.print("1.增加员工信息\t2.删除员工信息\t3.查找员工信息\t4.修改员工信息\t5.显示所有员工信息\t0.退出系统\n");
                            System.out.println("请选择您的操作:");
                            String manipulation1 = scan.next();
                            switch (manipulation1) {
                                case "1":
                                    workercon.addWorker();
                                    break;
                                case "2":
                                    System.out.println("1、输入工号\t2、输入姓名\t0、返回上级");
                                    System.out.println("请选择您的操作:");
                                    String manipulation2 = scan.next();
                                    switch (manipulation2) {
                                        case "1":
                                            workercon.removeWorkerById();
                                            break;
                                        case "2":
                                            workercon.removeWorkerByName();
                                            break;
                                        case "0":
                                            break;
                                    }
                                    break;
                                case "3":
                                    System.out.println("1、输入工号\t2、输入姓名\t0、返回上级");
                                    System.out.println("请选择您的操作:");
                                    String manipulation3 = scan.next();
                                    switch (manipulation3) {
                                        case "1":
                                            workercon.searchWorkerById();
                                            break;
                                        case "2":
                                            workercon.searchWorkerByName();
                                            break;
                                        case "0":
                                            break;
                                    }
                                    break;
                                case "4":
                                    System.out.println("1、输入工号\t2、输入姓名\t0、返回上级");
                                    System.out.println("请选择您的操作:");
                                    String manipulation4 = scan.next();
                                    switch (manipulation4) {
                                        case "1":
                                            workercon.modifyWorkerById();
                                            break;
                                        case "2":
                                            workercon.modifyWorkerByName();
                                            break;
                                        case "0":
                                            break;
                                    }
                                    break;
                                case "5":
                                    workercon.printAllWorker();
                                    break;
                                case "0":
                                    flag1 = false;
                                    System.out.println("退出成功！");
                                    break;
                                default:
                                    System.out.println("输入操作有误！");
                            }
                        }
                    }
                    break;
                case "2":
                    managercon.addManager();
                    break;
                case "0":
                    flag = false;
                    System.out.println("退出成功！");
                    break;
                default:
                    System.out.println("输入操作有误！");
            }
        }
    }
}
