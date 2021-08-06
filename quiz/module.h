#ifndef MODULE_H
#define MODULE_H

#endif // MODULE_H

#include<question.h>

#include<QString>
#include<QStringList>

#include<vector>

struct Module{

    QString name;
    QString hash;
    int time;
    int score;
    std::vector<Question> questins;

};
