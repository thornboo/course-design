package modle;

/*
定义管理人员的类
*/

public class Manager {
    private int manager_id;            // 工号
    private String manager_name;        // 姓名
    private String manager_password;    // 密码

    public int getManager_id() {
        return manager_id;
    }

    public void setManager_id(int manager_id) {
        this.manager_id = manager_id;
    }

    public String getManager_name() {
        return manager_name;
    }

    public void setManager_name(String manager_name) {
        this.manager_name = manager_name;
    }

    public String getManager_password() {
        return manager_password;
    }

    public void setManager_password(String manager_password) {
        this.manager_password = manager_password;
    }
}
