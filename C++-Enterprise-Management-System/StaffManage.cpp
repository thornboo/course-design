#include "StaffManage.h"

//定义全局变量
StaffManage SM;

StaffManage::StaffManage() {
    count = 0;
}


StaffManage::~StaffManage() {
    if (count == 0) {
        delete (head);
        delete (current);
    } else {
        while (head->next != nullptr) {
            BaseStaff *headPtr = head;
            head = head->next;
            delete (headPtr);
        }
    }
}

//查找指定的工号或姓名是否存在，如果存在，则返回对象在链表中的指针；如果不存在，返回NULL;
BaseStaff *StaffManage::search(string searchKey) {
    //根据传入的值，判断在链表结构中，是否存在编号或姓名为searchKey的员工对象
    BaseStaff *tmp = head;

    //循环遍历链表中的每个对象
    while (tmp != nullptr) {
        //判断输入工号或姓名是否有匹配
        if (tmp->getStaffNumber() == searchKey || tmp->getStaffNumber() == searchKey) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

//增加员工信息(功能1)
void StaffManage::addStaffInfos() {
    //每添加一个员工信息计数就加1
    count++;
    // 员工类型分类
    cout << "------------员工类型-------------" << endl;
    cout << "【1】技术类人员" << endl;
    cout << "【2】营销类人员" << endl;
    cout << "【3】管理类人员" << endl;
    cout << "【4】操作类人员" << endl;
    cout << "-------------------------------" << endl;
    cout << "-->请输入:";
    int inputType;
    cin >> inputType;
    //判断用户输入是否正确
    while ((inputType != 1) && (inputType != 2) && (inputType != 3) && (inputType != 4)) {
        cout << "-->输入格式错误，请重新输入！" << endl;
        cin.clear();
        cin >> inputType;
    }

    if (inputType == 1)  // 如果是技术类人员
    {
        if (count == 1)  // 若链表结构不存在，则创建一个新技术人员对象，并赋值给head
        {
            head = new TechnicalStaff();
            head->next = nullptr;
            current = head;
            cout << "添加员工信息成功!" << endl;
            return;
        } else {
            //创建新的对象
            BaseStaff *newTechnicalPtr = new TechnicalStaff();

            BaseStaff *tmp = head;
            //遍历链表查看是否有编号相同的对象
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newTechnicalPtr->getStaffNumber()) {
                    cout << "编号:" << newTechnicalPtr->getStaffNumber() << "已存在!" << endl;
                    //回收对象
                    delete (newTechnicalPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newTechnicalPtr;
            current = newTechnicalPtr;  // 将新指针对象赋值给current
            current->next = nullptr;
            cout << "添加员工信息成功!" << endl;
            return;
        }
    }

    if (inputType == 2) // 营销类人员
    {
        if (count == 1) //如果链表结构不存在，则创建一个新营销人员对象
        {
            head = new MarketingStaff();
            current = head;
            current->next = nullptr;
            cout << "添加员工信息成功!" << endl;
        } else {
            BaseStaff *newMarketingPtr = new MarketingStaff();
            BaseStaff *tmp = head;
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newMarketingPtr->getStaffNumber()) {
                    cout << "编号" << newMarketingPtr->getStaffNumber() << "已存在!" << endl;
                    delete (newMarketingPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newMarketingPtr;
            current = newMarketingPtr;
            current->next = nullptr;
            cout << "添加员工信息成功!" << endl;
            return;
        }
    }


    if (inputType == 3) //管理类人员
    {
        if (count == 1) {  //如果链表结构不存在，则创建一个新管理类人员对象
            head = new ManagementStaff();
            current = head;
            current->next = nullptr;
            cout << "添加员工信息成功!" << endl;
        } else {
            BaseStaff *newManagementPtr = new ManagementStaff();
            BaseStaff *tmp = head;
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newManagementPtr->getStaffNumber()) {
                    cout << "编号" << newManagementPtr->getStaffNumber() << "已存在" << endl;
                    delete (newManagementPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newManagementPtr;
            current = newManagementPtr;
            current = nullptr;
            cout << "添加员工信息成功!" << endl;
            return;
        }
    }

    if (inputType == 4) // 操作类人员
    {
        if (count == 1) { //如果链表结构不存在，则创建一个新操作类人员对象
            head = new OperatorStaff();
            current = head;
            current->next = nullptr;
            cout << "添加员工信息成功!" << endl;
        } else {
            BaseStaff *newOperatorPtr = new OperatorStaff();
            BaseStaff *tmp = head;
            while (tmp != nullptr) {
                if (tmp->getStaffNumber() == newOperatorPtr->getStaffNumber()) {
                    cout << "编号" << newOperatorPtr->getStaffNumber() << "已存在" << endl;
                    delete (newOperatorPtr);
                    return;
                }
                tmp = tmp->next;
            }

            current->next = newOperatorPtr;
            current = newOperatorPtr;
            current = nullptr;
            cout << "添加员工信息成功!" << endl;
            return;
        }
    }
}


//修改企业员工信息(功能2)
void StaffManage::modifyStaffInfos() {
    cout << "-->请输入工号:";
    string searchKey;
    cin >> searchKey;
    //调用search方法
    BaseStaff *staffInfoPtr = search(searchKey);

    if (staffInfoPtr == nullptr) {
        cout << "-->工号为:" << searchKey << "的员工不存在!" << endl;
        return;
    } else {
        //查找是那个指针对象
        BaseStaff *tmp = head;
        while (tmp != staffInfoPtr) {
            tmp = tmp->next;
        }
        cout << "原工号:" << tmp->getStaffNumber() << "\n新工号:";
        tmp->setStaffNumber();
        cout << "原姓名:" << tmp->getStaffName() << "\n新姓名:";
        tmp->setStaffName();
        cout << "原性别:" << tmp->getStaffSex() << "\n新性别:";
        tmp->setStaffSex();
        cout << "原工龄:" << tmp->getWorkYears() << "\n新工龄:";
        tmp->setWorkYears();
        cout << "原工资:" << tmp->getStaffSalary() << "\n新工资:";
        tmp->setStaffSalary();
        cout << "原等级:" << tmp->getStaffGrade() << "\n新等级:";
        tmp->setStaffGrade();
        cout << searchKey << "员工信息修改成功!" << endl;
    }
}

//删除员工信息(功能3)
void StaffManage::deleteStaffInfos() {
    cout << "-->请输入工号:";
    string searchKey;
    cin >> searchKey;
    //调用search方法
    BaseStaff *staffInfoPtr = search(searchKey);

    if (staffInfoPtr == nullptr) {
        cout << searchKey << "员工信息不存在!" << endl;
        return;
    } else {
        //查找是那个指针对象
        BaseStaff *tmp = head;
        while (tmp != staffInfoPtr) {
            tmp = tmp->next;
        }

        tmp = staffInfoPtr->next;
        // 回收内存空间
        delete (staffInfoPtr);
        cout << searchKey << "员工信息删除成功!" << endl;
    }
}

//查询单个员工信息(功能4)
void StaffManage::searchStaffInfos() {
    cout << "-->请输入你要查询的工号:";
    string searchKey;
    cin >> searchKey;
    //调用search方法
    BaseStaff *staffInfoPtr = search(searchKey);

    if (staffInfoPtr == nullptr) {
        cout << "工号为" << searchKey << "的员工不存在!" << endl;
        return;
    } else {
        cout << staffInfoPtr;
    }
}

//显示所有员工信息(功能5)
void StaffManage::showAllStaffInfos() {
    //判断head是否为NULL
    if (head == nullptr) {
        cout << "\n-->暂无职工信息！\n" << endl;
        return;
    }

    //将head指针值赋值给临时定义的指针变量
    BaseStaff *tmp = head;

    while (tmp != nullptr) {
        cout << tmp;
        tmp = tmp->next;
    }
}


//程序启动时，将文件中的数据加载到程序中
void StaffManage::readDatas() {
    fstream inFile;
    inFile.open("..\\staffdatas.dat", ios::in);
    if (!inFile) {
        cout << "打开文件失败!" << endl;
        exit(1);
    } else {
        cout << "数据读取成功！" << endl;
    }

    while (!inFile.eof())  // 判断文件是否读取结束
    {
        if (inFile.peek() == EOF) {
            inFile.close();
            break;
        } else {
            int i;  //i就是staffDutyType
            inFile >> i;//读取文件中当前行第一列的值，以" "分割的
            count++;
            if (count == 1) // 判断链表中是否已经有指针对象
            {
                switch (i) {
                    case 1: {
                        TechnicalStaff *TechnicalPtr = new TechnicalStaff();
                        head = TechnicalPtr;
                        current = TechnicalPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        //读取为对象赋值的顺序与写入的顺序保持一致
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->technology
                               >> current->devote;
                        break;
                    }
                    case 2: {
                        MarketingStaff *MarketingPtr = new MarketingStaff();
                        head = MarketingPtr;
                        current = MarketingPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->totalAnnualSales
                               >> current->customerReception;
                        break;
                    }
                    case 3: {
                        ManagementStaff *ManagementPtr = new ManagementStaff();
                        head = ManagementPtr;
                        current = ManagementPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->planningSuccessRate
                               >> current->targeAchievementRate
                               >> current->staffManagementRate;
                        break;
                    }
                    case 4: {
                        OperatorStaff *OperatorPtr = new OperatorStaff();
                        head = OperatorPtr;
                        current = OperatorPtr;
                        current->next = nullptr;
                        current->staffDutyType = i;
                        inFile >> current->staffNumber
                               >> current->staffName
                               >> current->staffSex
                               >> current->staffWorkYears
                               >> current->staffSalary
                               >> current->staffGrade
                               >> current->resolveFailureRate
                               >> current->workEfficiency
                               >> current->projectCompletion;
                        break;
                    }
                }
            } else { //如果链表中包含指针对象
                switch (i) {
                    case 1: {
                        TechnicalStaff *TechnicalPtr = new TechnicalStaff();
                        TechnicalPtr->staffDutyType = i;
                        inFile >> TechnicalPtr->staffNumber
                               >> TechnicalPtr->staffName
                               >> TechnicalPtr->staffSex
                               >> TechnicalPtr->staffWorkYears
                               >> TechnicalPtr->staffSalary
                               >> TechnicalPtr->staffGrade
                               >> TechnicalPtr->technology
                               >> TechnicalPtr->devote;
                        current->next = TechnicalPtr;
                        current = TechnicalPtr;
                        current->next = nullptr;
                        break;
                    }
                    case 2: {
                        MarketingStaff *MarketingPtr = new MarketingStaff();
                        MarketingPtr->staffDutyType = i;
                        inFile >> MarketingPtr->staffNumber
                               >> MarketingPtr->staffName
                               >> MarketingPtr->staffSex
                               >> MarketingPtr->staffWorkYears
                               >> MarketingPtr->staffSalary
                               >> MarketingPtr->staffGrade
                               >> MarketingPtr->totalAnnualSales
                               >> MarketingPtr->customerReception;
                        current->next = MarketingPtr;
                        current = MarketingPtr;
                        current->next = nullptr;
                        break;
                    }
                    case 3: {
                        ManagementStaff *ManagementPtr = new ManagementStaff();
                        ManagementPtr->staffDutyType = i;
                        inFile >> ManagementPtr->staffNumber
                               >> ManagementPtr->staffName
                               >> ManagementPtr->staffSex
                               >> ManagementPtr->staffWorkYears
                               >> ManagementPtr->staffSalary
                               >> ManagementPtr->staffGrade
                               >> ManagementPtr->planningSuccessRate
                               >> ManagementPtr->targeAchievementRate
                               >> ManagementPtr->staffManagementRate;
                        current->next = ManagementPtr;
                        current = ManagementPtr;
                        current->next = nullptr;
                        break;
                    }
                    case 4: {
                        OperatorStaff *OperatorPtr = new OperatorStaff();
                        OperatorPtr->staffDutyType = i;
                        inFile >> OperatorPtr->staffNumber
                               >> OperatorPtr->staffName
                               >> OperatorPtr->staffSex
                               >> OperatorPtr->staffWorkYears
                               >> OperatorPtr->staffSalary
                               >> OperatorPtr->staffGrade
                               >> OperatorPtr->resolveFailureRate
                               >> OperatorPtr->workEfficiency
                               >> OperatorPtr->projectCompletion;
                        current->next = OperatorPtr;
                        current = OperatorPtr;
                        current->next = nullptr;
                        break;
                    }
                }
            }
        }
    }
}


//在程序退出或添加，修改，删除时，将数据保存到文件中
void StaffManage::writeDatas() {
    fstream outFile;
    outFile.open("..\\staffdatas.dat", ios::out | ios::app);

    if (!outFile) {
        cout << "打开文件失败!" << endl;
        exit(1);
    }

    BaseStaff *headPtr = head;

    //判断是否头指针存在值
    if (headPtr == nullptr) {
        cout << "无数据需要保存！" << endl;
        return;
    }

    //链表有多个指针,需要保存从头指针开始，一直到最后的指针对象
    while (headPtr->next != nullptr) {
        if (headPtr->staffDutyType == 1)//判断指针对象是否是技术类人员
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->technology << " "
                    << headPtr->devote << endl;
        }

        if (headPtr->staffDutyType == 2) //营销类人员
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->totalAnnualSales << " "
                    << headPtr->customerReception << endl;
        }

        if (headPtr->staffDutyType == 3) //管理类人员
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->planningSuccessRate << " "
                    << headPtr->targeAchievementRate << " "
                    << headPtr->staffManagementRate << endl;
        }

        if (headPtr->staffDutyType == 4) //操作类人员
        {
            outFile << headPtr->staffDutyType << " "
                    << headPtr->getStaffNumber() << " "
                    << headPtr->getStaffName() << " "
                    << headPtr->getStaffSex() << " "
                    << headPtr->getWorkYears() << " "
                    << headPtr->getStaffGrade() << " "
                    << headPtr->getStaffSalary() << " "
                    << headPtr->resolveFailureRate << " "
                    << headPtr->workEfficiency << " "
                    << headPtr->projectCompletion << endl;
        }

        headPtr = headPtr->next;
    }

    //保存最后一个指针元素的数据
    if (headPtr->staffDutyType == 1)//判断指针对象是否是技术类人员
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->technology << " "
                << headPtr->devote << endl;
    }

    if (headPtr->staffDutyType == 2) //营销类人员
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->totalAnnualSales << " "
                << headPtr->customerReception << endl;
    }

    if (headPtr->staffDutyType == 3) //管理类人员
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->planningSuccessRate << " "
                << headPtr->targeAchievementRate << " "
                << headPtr->staffManagementRate << endl;
    }

    if (headPtr->staffDutyType == 4) //操作类人员
    {
        outFile << headPtr->staffDutyType << " "
                << headPtr->getStaffNumber() << " "
                << headPtr->getStaffName() << " "
                << headPtr->getStaffSex() << " "
                << headPtr->getWorkYears() << " "
                << headPtr->getStaffGrade() << " "
                << headPtr->getStaffSalary() << " "
                << headPtr->resolveFailureRate << " "
                << headPtr->workEfficiency << " "
                << headPtr->projectCompletion << endl;
    }
    cout << "数据保存成功!" << endl;
    outFile.close(); //关闭文件流
}