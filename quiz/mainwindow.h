#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGroupBox>

#include<QTimer>
#include<QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
        void on_replyButton_clicked();

        void on_openFileButton_clicked();

        void updateTime();

private:
    Ui::MainWindow *ui;
    QTimer *tmr;
};
#endif // MAINWINDOW_H
