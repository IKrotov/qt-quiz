#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include<question.h>
#include<module.h>


#include<QLabel>
#include<QVBoxLayout>
#include<QRadioButton>
//#include<QGroupBox>
#include<QFile>
#include<QJsonDocument>
#include<QDebug>
#include<QJsonArray>
#include<QJsonObject>
#include<QPushButton>
#include<QButtonGroup>
#include<QDesktopServices>
#include<QUrl>
#include<QMessageBox>

#include<QElapsedTimer>
#include<QTextBrowser>

#include<vector>
#include<string>
#include<sstream>


QLabel *label;
QPushButton *button;
QGroupBox *groupBox;
QVBoxLayout *vLayout;
QPushButton *openFileButton;
QTextBrowser *textBrowser;

int count = 0;
int rightAnswerCounter = 0;
QString html;

QElapsedTimer etimer;
auto countDown = QTime(0,1,30);
int testTimerMilisec = 90000;

std::vector<Question> questins;
std::vector<Module> modules;

//std::vector<Question> ParseQuestions(){

//    QFile file("/Users/aleksandr/work/qt_projects/first_project/json/test.json");
//    file.open(QIODevice::ReadOnly);
//    QByteArray jsonArr = file.readAll();
//    QString qs = file.readAll();
//    file.close();

//    QFile file1("/Users/aleksandr/work/test_files_for_qt/t7.html");
//    file1.open(QIODevice::ReadOnly);
//    html = file1.readAll();

//    QJsonDocument doc = QJsonDocument::fromJson(jsonArr);
//    QJsonValue jsonQuestions = doc["questions"];

//    std::vector<Question> questions;

//    // Если value это массив данных
//        if ( jsonQuestions.type() == QJsonValue::Array ) {

//            // Получаем массив
//            QJsonArray array = jsonQuestions.toArray();

//            for( int i = 0; i < array.size(); i++ ) {

//                        QJsonValueRef ref = array[i];
//                        // Если ValueRef это объект
//                        if ( ref.type() == QJsonValue::Object ) {
//                            QJsonObject obj = ref.toObject();
//                            QMap<QString, QVariant> map = obj.toVariantMap();

//                            qDebug() << map.value("question").toString();

//                            QString question = map.value("question").toString();
//                            QStringList answerOptions = map.value("answer_options").toStringList();
//                            QString rightAnser = map.value("right_answer").toString();
//                            QString imageLink = map.value("image_link").toString();
//                            QString docLink = map.value("doc_link").toString();

//                            questions.push_back({question, answerOptions, rightAnser, imageLink, docLink});
//                        }
//              }
//    }
//        return questions;

//}


std::vector<Module> ParseQuestions(){

    QFile file("/Users/aleksandr/work/qt_projects/first_project/json/test1.json");
    file.open(QIODevice::ReadOnly);
    QByteArray jsonArr = file.readAll();
    QString qs = file.readAll();
    file.close();

    QFile file1("/Users/aleksandr/work/test_files_for_qt/t7.html");
    file1.open(QIODevice::ReadOnly);
    html = file1.readAll();

    QJsonDocument doc = QJsonDocument::fromJson(jsonArr);
    QJsonValue jsonModules = doc["modules"];

    std::vector<Module> modules;

    // Если value это массив данных
        if ( jsonModules.type() == QJsonValue::Array ) {

            // Получаем массив
            QJsonArray array = jsonModules.toArray();

            for( int i = 0; i < array.size(); i++ ) {

                QJsonValueRef ref = array[i];
                // Если ValueRef это объект
                if ( ref.type() == QJsonValue::Object ) {
                    QJsonObject obj = ref.toObject();
                    QMap<QString, QVariant> map = obj.toVariantMap();

                    qDebug() << map.value("question").toString();

                    QString name = map.value("name").toString();
                    QString hash = map.value("hash").toString();
                    int time = map.value("time").toInt();
                    int score = map.value("score").toInt();
                    QJsonValue jsonQuestions = map.value("questions").toJsonValue();

                    std::vector<Question> questions;

                    // Если value это массив данных
                        if ( jsonQuestions.type() == QJsonValue::Array ) {

                            // Получаем массив
                            QJsonArray array = jsonQuestions.toArray();

                            for( int i = 0; i < array.size(); i++ ) {

                                        QJsonValueRef ref = array[i];
                                        // Если ValueRef это объект
                                        if ( ref.type() == QJsonValue::Object ) {
                                            QJsonObject obj = ref.toObject();
                                            QMap<QString, QVariant> map = obj.toVariantMap();

                                            qDebug() << map.value("question").toString();

                                            QString question = map.value("question").toString();
                                            QStringList answerOptions = map.value("answer_options").toStringList();
                                            QString rightAnser = map.value("right_answer").toString();
                                            QString type = map.value("type").toString();
                                            QString docLink = map.value("doc_link").toString();

                                            questions.push_back({question, answerOptions, type, rightAnser, docLink});
                                        }
                              }
                    }

                modules.push_back({name, hash, time, score, questions});
            }
          }
    }
        return modules;

}

void ClearLayout(){

    //Очищаем слой

    while(QLayoutItem *item = vLayout->takeAt(0)){
        delete item->widget();
        delete item;
    }
}

void DrawQuestion(Question q){

    ClearLayout();

    //Заполняем слой новым вопросом


    textBrowser = new QTextBrowser();
    textBrowser->setText(html);
    vLayout->addWidget(textBrowser);

    label = new QLabel(q.question);
    vLayout->addWidget(label);


    for (int i=0;i<q.answer_options.length(); i++) {
        QRadioButton *b = new QRadioButton(q.answer_options[i]);
        vLayout->addWidget(b);
    }

    groupBox->setLayout(vLayout);
}

void DrawResult(){

    ClearLayout();

    std::stringstream ss;
    ss<< "Ваш результат: " << rightAnswerCounter << "/" << questins.size();
    QString resultString = QString::fromStdString(ss.str());

    QLabel *resultLabel = new QLabel(resultString);

    vLayout->addWidget(resultLabel);

    groupBox->setLayout(vLayout);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openFileButton = new QPushButton();

    modules = ParseQuestions();

    questins = modules[0].questins;

    vLayout = new QVBoxLayout;
    groupBox = ui->questionGroupBox;
    ui->replyButton->setText("Ответить");
    ui->openFileButton->setText("Открыть справночный материал");

    std::stringstream ss;
    ss<< count+1 << "/" << questins.size();
    QString title = QString::fromStdString(ss.str());
    ui->questionGroupBox->setTitle(title);

    DrawQuestion(questins[0]);

    etimer.start();

    tmr = new QTimer(this);
    //tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start(10);

    QTimer::singleShot(testTimerMilisec, this, SLOT(close()));

//    connect(openFileButton, SIGNAL(clicked()), this, SLOT(on_openFileButton_clecked()));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_replyButton_clicked()
{
    QButtonGroup group;
    QList<QRadioButton *> allButtons = ui->questionGroupBox->findChildren<QRadioButton *>();

    QString userAnswer = "";

    for (int i = 0; i<allButtons.size(); ++i ) {

        group.addButton(allButtons[i], i);

        if(allButtons[i]->isChecked()){

            userAnswer = allButtons[i]->text();
        }
    }

    if(userAnswer == questins[count].right_answer){

        rightAnswerCounter++;

        QMessageBox *mb = new QMessageBox();

        mb->setText("Верно!");
        mb->exec();
    } else {

        QMessageBox *mb = new QMessageBox();
        mb->setText("Ответ неверный :(");
        mb->exec();
    }

    if(count < questins.size() - 1){

        count++;

        std::stringstream ss;
        ss<< count+1 << "/" << questins.size();
        QString title = QString::fromStdString(ss.str());
        ui->questionGroupBox->setTitle(title);

        DrawQuestion(questins[count]);

    } else {

        DrawResult();

    }

}


void on_openFileButton_clecked(){

   QString path =  questins[count].doc_link;

   QUrl url = QUrl::fromLocalFile(path);

   QDesktopServices::openUrl(url);
}

void MainWindow::on_openFileButton_clicked()
{
    QString path = questins[count].doc_link;

    if(path != ""){

        QUrl url = QUrl::fromLocalFile(path);
        QDesktopServices::openUrl(url);
    }

}

void MainWindow::updateTime(){

    auto elapsed = etimer.elapsed();
    auto c = countDown.addMSecs(-elapsed);
    QString timestr = c.toString("hh:mm:ss.zzz");

    ui->timerLabel->setText(timestr);
}
