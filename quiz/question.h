#ifndef QUESTION_H
#define QUESTION_H

#endif // QUESTION_H

#include<string>
#include<vector>

#include<QString>
#include<QStringList>

struct Question{

    QString question;
    QStringList answer_options;
    QString type;
    QString right_answer;
    QString doc_link;

};
