package modle;

/*
定义工作人员的类
*/

import java.util.Date;

public class Worker {
    private int worker_id;                // 工号
    private String worker_name;            // 姓名
    private String worker_sex;            // 性别
    private String worker_duty;            // 职位
    private String worker_department;    // 部门
    private String worker_telephone;    // 电话
    private String worker_email;        // 邮箱

    public int getWorker_id() {
        return worker_id;
    }

    public void setWorker_id(int worker_id) {
        this.worker_id = worker_id;
    }

    public String getWorker_name() {
        return worker_name;
    }

    public void setWorker_name(String worker_name) {
        this.worker_name = worker_name;
    }

    public String getWorker_sex() {
        return worker_sex;
    }

    public void setWorker_sex(String worker_sex) {
        this.worker_sex = worker_sex;
    }

    public String getWorker_duty() {
        return worker_duty;
    }

    public void setWorker_duty(String worker_duty) {
        this.worker_duty = worker_duty;
    }

    public String getWorker_department() {
        return worker_department;
    }

    public void setWorker_department(String worker_department) {
        this.worker_department = worker_department;
    }

    public String getWorker_telephone() {
        return worker_telephone;
    }

    public void setWorker_telephone(String worker_telephone) {
        this.worker_telephone = worker_telephone;
    }

    public String getWorker_email() {
        return worker_email;
    }

    public void setWorker_email(String worker_email) {
        this.worker_email = worker_email;
    }
}
