package controller;

import java.util.ArrayList;
import java.util.Scanner;

import Implement.WorkerImp;
import modle.Worker;

public class WorkerCon implements WorkerImp {

    //创建一个集合类
    static ArrayList<Worker> workers = new ArrayList<Worker>();

    //创建输入
    Scanner scan = new Scanner(System.in);

    public WorkerCon(ArrayList<Worker> workers) {
        WorkerCon.workers = workers;
    }

    //输出全部员工的信息
    public void printAllWorker() {
        System.out.println("-----输出全部员工信息-----");
        System.out.println("工号\t姓名\t性别\t职位\t部门\t电话\t邮箱\n");
        for (Worker worker : workers) {
            System.out.printf("%d\t%s\t%s\t%s\t%s\t%s\t%s",
                    worker.getWorker_id(), worker.getWorker_name(), worker.getWorker_sex(), worker.getWorker_duty(),
                    worker.getWorker_department(), worker.getWorker_telephone(), worker.getWorker_email() + "\n");
        }
    }

    @Override
    public void addWorker() {
        //输入员工基本信息并存储
        System.out.println("-----添加员工信息-----");
        System.out.println("请输入员工姓名：");
        String worker_name = scan.next();
        System.out.println("请输入员工性别：");
        String worker_sex = scan.next();
        System.out.println("请输入员工职位：");
        String worker_duty = scan.next();
        System.out.println("请输入员工部门：");
        String worker_department = scan.next();
        System.out.println("请输入员工电话：");
        String worker_telephone = scan.next();
        System.out.println("请输入员工邮箱：");
        String worker_email = scan.next();

        //创建员工对象将数据写入
        Worker worker = new Worker();
        int worker_id = workers.size() + 1; // 获取员工工号
        worker.setWorker_id(worker_id);
        worker.setWorker_name(worker_name);
        worker.setWorker_sex(worker_sex);
        worker.setWorker_duty(worker_duty);
        worker.setWorker_department(worker_department);
        worker.setWorker_telephone(worker_telephone);
        worker.setWorker_email(worker_email);

        workers.add(worker);
        System.out.println("填加成功！\n");
        System.out.printf("添加员工信息为：工号:%d, 姓名:%s, 性别:%s, 职位:%s, 部门:%s, 电话:%s, 邮箱:%s",
                worker_id, worker_name, worker_sex, worker_duty, worker_department, worker_telephone, worker_email + "\n");
    }

    @Override
    public void removeWorkerById() {
        System.out.println("-----删除员工信息-----");
        System.out.println("请输入员工工号:");
        int worker_id = scan.nextInt();
        int sum;
        for (sum = 0; sum < workers.size(); ++sum) {
            Worker worker = workers.get(sum);
            if (worker.getWorker_id() == worker_id) {
                sum = 0;
                workers.remove(worker);
                System.out.println("删除成功！");
                System.out.printf("删除员工信息为:工号:%d, 姓名:%s, 性别:%s, 职务:%s, 部门:%s, 电话:%s, 邮箱:%s",
                        worker.getWorker_id(), worker.getWorker_name(), worker.getWorker_sex(), worker.getWorker_duty(),
                        worker.getWorker_department(), worker.getWorker_telephone(), worker.getWorker_email() + "\n");
                break;
            }
        }
        //如果员工不存在
        if (sum == workers.size() && workers.size() != 0)
            System.out.println("查无此人,请输入正确信息！\n");
    }

    public void removeWorkerByName() {
        System.out.println("-----删除员工信息-----");
        System.out.println("请输入员工姓名:");
        String worker_name = scan.next();
        int num = 0;
        for (Worker worker : workers) {
            num++;
            if (worker.getWorker_name().equals(worker_name)) {
                num = 0;
                workers.remove(worker);
                System.out.println("删除成功！\n");
                System.out.printf("删除员工信息为:工号:%d, 姓名:%s, 性别:%s, 职务:%s, 部门:%s, 电话:%s, 邮箱:%s",
                        worker.getWorker_id(), worker.getWorker_name(), worker.getWorker_sex(), worker.getWorker_duty(),
                        worker.getWorker_department(), worker.getWorker_telephone(), worker.getWorker_email() + "\n");
                break;
            }
        }

        //如果员工不存在
        if (num == workers.size() && workers.size() != 0)
            System.out.println("查无此人,请输入正确信息！\n");
    }

    public void searchWorkerById() {
        System.out.println("-----查询员工信息-----");
        System.out.println("请输入员工工号:");
        int id = scan.nextInt();
        int sum;
        for (sum = 0; sum < workers.size(); ++sum) {
            Worker worker = workers.get(sum);
            if (worker.getWorker_id() == id) {
                sum = 0;
                System.out.printf("删除员工信息为:工号:%d, 姓名:%s, 性别:%s, 职务:%s, 部门:%s, 电话:%s, 邮箱:%s",
                        worker.getWorker_id(), worker.getWorker_name(), worker.getWorker_sex(), worker.getWorker_duty(),
                        worker.getWorker_department(), worker.getWorker_telephone(), worker.getWorker_email() + "\n");
                break;
            }
        }
        //如果员工不存在
        if (sum == workers.size() && workers.size() != 0)
            System.out.println("查无此人,请输入正确信息！\n");
    }


    public void searchWorkerByName() {
        System.out.println("-----查询员工信息-----");
        System.out.println("请输入员工姓名：");
        String name = scan.next();
        int sum = 0;
        for (Worker worker : workers) {
            sum++;
            if (worker.getWorker_name().equals(name)) {
                System.out.printf("查询员工信息为:工号:%d, 姓名:%s, 性别:%s, 职务:%s, 部门:%s, 电话:%s, 邮箱:%s",
                        worker.getWorker_id(), worker.getWorker_name(), worker.getWorker_sex(), worker.getWorker_duty(),
                        worker.getWorker_department(), worker.getWorker_telephone(), worker.getWorker_email() + "\n");
                sum = 0;
            }
        }
        //如果员工不存在
        if (sum == workers.size() && workers.size() != 0)
            System.out.println("查无此人,请输入正确信息！\n");
    }

    @Override
    public void modifyWorkerById() {
        System.out.println("-----修改员工信息-----");
        System.out.println("请输入员工工号:");
        int id = scan.nextInt();
        int sum = 0;
        //根据ID查询员工信息
        for (Worker worker : workers) {
            sum++;
            if (worker.getWorker_id() == id) {
                System.out.printf("员工当前的信息为→:工号:%d, 姓名:%s, 性别:%s, 职务:%s, 部门:%s, 电话:%s, 邮箱:%s",
                        worker.getWorker_id(), worker.getWorker_name(), worker.getWorker_sex(), worker.getWorker_duty(),
                        worker.getWorker_department(), worker.getWorker_telephone(), worker.getWorker_email() + "\n");
                sum = 0;
                break;
            }
        }

        //如果员工不存在
        if (sum == workers.size() && workers.size() != 0) {
            System.out.println("查无此人,请输入正确信息！\n");
        } else { // 工号不允许做修改
            System.out.println("请输入员工姓名：");
            String worker_name = scan.next();
            System.out.println("请输入员工性别：");
            String worker_sex = scan.next();
            System.out.println("请输入员工职位：");
            String worker_duty = scan.next();
            System.out.println("请输入员工部门：");
            String worker_department = scan.next();
            System.out.println("请输入员工电话：");
            String worker_telephone = scan.next();
            System.out.println("请输入员工邮箱：");
            String worker_email = scan.next();

            for (Worker w : workers) {
                if (w.getWorker_id() == id) {
                    w.setWorker_name(worker_name);
                    w.setWorker_sex(worker_sex);
                    w.setWorker_duty(worker_duty);
                    w.setWorker_department(worker_department);
                    w.setWorker_telephone(worker_telephone);
                    w.setWorker_email(worker_email);
                    System.out.println("修改成功！\n");
                    System.out.printf("修改后的员工信息：工号:%d, 姓名:%s, 性别:%s, 职位:%s, 部门:%s, 电话:%s, 邮箱:%s",
                            w.getWorker_id(), w.getWorker_name(), w.getWorker_sex(), w.getWorker_duty(),
                            w.getWorker_department(), w.getWorker_telephone(), w.getWorker_email() + "\n");
                }
            }
        }
    }


    @Override
    public void modifyWorkerByName() {
        System.out.println("-----修改员工信息-----");
        System.out.println("请输入员工姓名:");
        String name = scan.next();
        int sum = 0;
        //根据ID查询员工信息
        for (Worker worker : workers) {
            sum++;
            if (worker.getWorker_name().equals(name)) {
                System.out.printf("员工当前的信息为→:工号:%d, 姓名:%s, 性别:%s, 职务:%s, 部门:%s, 电话:%s, 邮箱:%s",
                        worker.getWorker_id(), worker.getWorker_name(), worker.getWorker_sex(), worker.getWorker_duty(),
                        worker.getWorker_department(), worker.getWorker_telephone(), worker.getWorker_email() + "\n");
                sum = 0;
                break;
            }
        }

        //如果员工不存在
        if (sum == workers.size() && workers.size() != 0) {
            System.out.println("查无此人,请输入正确信息！\n");
        } else { // 工号不允许做修改
            System.out.println("请输入员工姓名：");
            String worker_name = scan.next();
            System.out.println("请输入员工性别：");
            String worker_sex = scan.next();
            System.out.println("请输入员工职位：");
            String worker_duty = scan.next();
            System.out.println("请输入员工部门：");
            String worker_department = scan.next();
            System.out.println("请输入员工电话：");
            String worker_telephone = scan.next();
            System.out.println("请输入员工邮箱：");
            String worker_email = scan.next();

            for (Worker w : workers) {
                if (w.getWorker_name().equals(name)) {
                    w.setWorker_name(worker_name);
                    w.setWorker_sex(worker_sex);
                    w.setWorker_duty(worker_duty);
                    w.setWorker_department(worker_department);
                    w.setWorker_telephone(worker_telephone);
                    w.setWorker_email(worker_email);
                    System.out.println("修改成功！\n");
                    System.out.printf("修改后的员工信息：工号:%d, 姓名:%s, 性别:%s, 职位:%s, 部门:%s, 电话:%s, 邮箱:%s",
                            w.getWorker_id(), w.getWorker_name(), w.getWorker_sex(), w.getWorker_duty(),
                            w.getWorker_department(), w.getWorker_telephone(), w.getWorker_email() + "\n");
                }
            }
        }
    }
}
