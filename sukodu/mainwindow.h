#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QRadioButton>
#include<QTime>
#include<cstdlib>
#include<QDebug>
#include<vector>
#include<sstream>
#include<string>
#include<QDir>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QString>
#include<QDialog>
#include<QScrollArea>
#include<QFile>
#include<QFileDialog>
#include<QFileInfo>
#include<QDateTime>
#include<QTextEdit>
#include<QTime>
#include<QByteArray>
#include<fstream>
#include<QDataStream>
#include<QPalette>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void print(const vector <vector<int>> &num);
    void createnum(QPushButton *newgame,QPushButton *btn);

private slots:
    void on_exit_clicked();
    void on_newgame_clicked();
    void show_prodcut_sets(int row,int col);
    void change_num(QString s,int row,int col);
    void on_confirm_clicked();

    void on_answer_clicked();

    void on_tip_clicked();

    void on_recall_2_clicked();

    void on_save_clicked();

    void on_clear_clicked();

    void on_solve_clicked();

    void on_user_defined_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
