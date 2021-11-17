package modle;

/*
定义工资类
工资 = 工作时间 * 工时单价 + 奖金
*/

public class Salary {
    private int salary_id;        // 工资id
    private int worker_id;        // 员工id
    private float work_time;        // 工作时长
    private float work_price;            // 工时单价
    private float salary_bonus;        // 奖金
    private float salary_total;        // 总工资
    private String salary_date;        // 操作时间

    public float computeSalary(float work_time, float work_price, float salary_bonus) {
        float salary = work_time * work_price + salary_bonus;
        return salary;
    }

    public int getSalary_id() {
        return salary_id;
    }

    public void setSalary_id(int salary_id) {
        this.salary_id = salary_id;
    }

    public int getWorker_id() {
        return worker_id;
    }

    public void setWorker_id(int worker_id) {
        this.worker_id = worker_id;
    }

    public float getWork_time() {
        return work_time;
    }

    public void setWork_time(float work_time) {
        this.work_time = work_time;
    }

    public float getWork_price() {
        return work_price;
    }

    public void setWork_price(float work_price) {
        this.work_price = work_price;
    }

    public float getSalary_bonus() {
        return salary_bonus;
    }

    public void setSalary_bonus(float salary_bonus) {
        this.salary_bonus = salary_bonus;
    }

    public float getSalary_total() {
        return salary_total;
    }

    public void setSalary_total(float salary_total) {
        this.salary_total = salary_total;
    }

    public String getSalary_date() {
        return salary_date;
    }

    public void setSalary_date(String salary_date) {
        this.salary_date = salary_date;
    }

    @Override   // 表示子类重写了父类的方法
    public String toString() {
        return "Salary [ID=" + salary_id + ", 员工ID=" + worker_id + ", 工作时长=" + work_time + ", 工时单价="
                + work_price + ", 出勤奖金=" + salary_bonus + ", 工资总额=" + salary_total + ", 操作日期="
                + salary_date + "]";
    }
}
