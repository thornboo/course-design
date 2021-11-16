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
    private float salary_bouns;        // 奖金
    private float salary_total;        // 总工资
    private String salary_date;        // 操作时间

    public float computeSalary(float work_time, float work_price, float work_bouns) {
        float salary = work_time * work_price + salary_bouns;
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

    public float getWorktime() {
        return work_time;
    }

    public void setWorktime(float work_time) {
        this.work_time = work_time;
    }

    public float getWorkprice() {
        return work_price;
    }

    public void setWorkprice(float work_price) {
        this.work_price = work_price;
    }

    public float getSalarybouns() {
        return salary_bouns;
    }

    public void setSalarybouns(float salary_bouns) {
        this.salary_bouns = salary_bouns;
    }

    public float getSalarytotal() {
        return salary_total;
    }

    public void setSalarytotal(float salary_total) {
        this.salary_total = salary_total;
    }

    public String getSalarytime() {
        return salary_date = salary_date;
    }

    public void setSalarydate(String salary_date) {
        this.salary_date = salary_date;
    }

    @Override
    public String toString() {
        return "Salary [ID=" + salary_id + ", 员工ID=" + worker_id + ", 工作时长=" + work_time + ", 工时单价="
                + work_price + ", 出勤奖金=" + salary_bouns + ", 工资总额=" + salary_total + ", 操作日期="
                + salary_date + "]";
    }
}
