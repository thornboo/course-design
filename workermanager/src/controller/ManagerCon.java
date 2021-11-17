package controller;

import java.util.ArrayList;
import java.util.Scanner;

import Implement.ManagerImp;
import modle.Manager;

public class ManagerCon implements ManagerImp {
    Scanner scan = new Scanner(System.in);      // 通过 Scanner类来获取用户的输入
    ArrayList<Manager> managers; // 创建动态数组

    public ManagerCon(ArrayList<Manager> managers) {
        this.managers = managers;
    }

    @Override
    // 注册管理员的方法
    public void addManager() {
        System.out.println("请输入管理员用户名：");
        String name = scan.next();
        System.out.println("请输入管理员密码：");
        String password = scan.next();
        Manager manager = new Manager();
        int id = managers.size();
        // 调用Manager中的方法
        manager.setManager_id(id);
        manager.setManager_name(name);
        manager.setManager_password(password);
        // 增加新的管理员
        managers.add(manager);
        System.out.println("新建的管理员账号信息为：工号：" + id + "用户名：" + name + "密码：" + password);
    }

    // 管理员登录系统
    public boolean isLogin() {
        boolean flag = false;
        System.out.println("请输入用户名：");
        String name = scan.next();
        System.out.println("请输入密码");
        String password = scan.next();
        Manager manager = new Manager();
        // 为manager设置name和password
        manager.setManager_name(name);
        manager.setManager_password(password);
        for (Manager value : managers) {    // 循环已有的每一个对象
            if (value.equals(manager)) {    // 比较value和manager两个对象是否相同
                flag = true;
                System.out.println("欢迎登陆员工管理系统！");
                break;
            }
        }
        if (!flag) {
            System.out.println("用户名或密码输入错误！");
        }
        return flag;
    }
}
