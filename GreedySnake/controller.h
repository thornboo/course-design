#ifndef GREEDYSNAKE_CONTROLLER_H
#define GREEDYSNAKE_CONTROLLER_H

#endif //GREEDYSNAKE_CONTROLLER_H

class Controller {
public:
    Controller() : speed(200), key(1), score(0) {}

    void Start();  //开始界面

    void Select();  //选择难度

    void DrawGame();  //绘制地图等游戏信息界面

    int PlayGame();  //游戏的二级循环

    void UpdateScore(const int &);  //更新分数

    void RewriteScore();  //重新绘制分数

    int Menu();  //中途暂停或者死亡后的菜单

    void Game();  //游戏一级循环

    int GameOver();  //游戏结束界面

private:
    int speed;  //速度
    int key;    //选项值
    int score;  //分数
};
