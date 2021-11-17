package Implement;

import modle.Worker;

public interface WorkerImp {
    // 添加员工
    void addWorker();
    // 删除员工
    void removeWorkerById();
    void removeWorkerByName();
    // 查找员工
    void searchWorkerById();
    void searchWorkerByName();
    // 修改员工信息
    void modifyWorkerById();
    void modifyWorkerByName();
}
