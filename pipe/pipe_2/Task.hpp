#pragma once

#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;
typedef void (*task_t)();

void task1()
{
    cout << "逐日：三尺台上释千古 一曲谱半生 影随光而行" << endl;
    system("madplay C:/Users/Haope/Downloads/2skill1_1.mp3 &");
}

void task2()
{
    cout << "燃己：皮影话峥嵘 千古兴亡事 一杯浊酒中" << endl;
}

void task3()
{
    cout << "困奋：金丝银线缚将军 戏外人笑戏中臣" << endl;
}

void task4()
{
    cout << "诈降：鞞鼓动帷幕 二三哨声可当万马千军" << endl;
}

void LoadTasks(vector<task_t>* tasks)
{
    tasks->push_back(task1);
    tasks->push_back(task2);
    tasks->push_back(task3);
    tasks->push_back(task4);
}