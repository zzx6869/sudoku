#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

int mySIZE = 9;
vector<vector<int>> num(mySIZE, vector<int>(mySIZE, -1));
int endnum[9][9];
int blanknum[9][9];
int sudo[9][9];
bool sign = false;
bool exitorno=1;
int N,maxnum=80,minnum=17;
int dfs(int n);
bool check(int n, int num);
int dfs(int n)
{
    if (n > 80)
    {
        sign = true;
        return 0;
    }
    if (sudo[n / 9][n % 9] != 0)
    {
        dfs(n + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(n, i))
            {
                sudo[n / 9][n % 9] = i;
                dfs(n + 1);
                if (sign == true)
                    return 0;
                else
                    sudo[n / 9][n % 9] = 0;
            }
        }
    }
}
bool check(int n, int num)
{
    int row = n / 9;
    int col = n % 9;
    for (int i = 0; i < 9; i++)
    {
        if (i == col)
            continue;
        else {
            if (sudo[row][i] == num)
                return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (i == row)
            continue;
        else {
            if (sudo[i][col] == num)
                return false;
        }
    }
    if (row == col)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i == row)
            {
                continue;
            }
            else {
                if (sudo[i][i] == num)
                {
                    return false;
                }
            }
        }
    }
    if (row + col == 8)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i == row)
            {
                continue;
            }
            else {
                if (num == sudo[i][8 - i])
                {
                    return false;
                }
            }
        }
    }
    int x = n / 9 / 3 * 3;
    int y = n % 9 / 3 * 3;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (i == row && j == col)
                continue;
            else if (sudo[i][j] == num)
                return false;
        }
    }
    return true;
}


void MainWindow::on_exit_clicked()
{
    QDialog clo(this);
    QLabel *_close=new QLabel(&clo);
    _close->setText("感谢使用！");
    _sleep(5000);
    close();
    clo.exec();
    close();
}
//创建数独：
vector<int> getRandom(int total)
{
    srand((int)time(NULL));
    std::vector<int> input = *new std::vector<int>();
    for (int i = 0; i < total; i++) {
        input.push_back(i);
    }
    vector<int> output = *new vector<int>();

    int end = total;
    for (int i = 0; i < total; i++) {
        vector<int>::iterator iter = input.begin();
        int num = rand()%end;
        iter = iter+num;
        output.push_back(*iter);
        input.erase(iter);
        end--;
    }

    return output;
}

void print(const vector <vector<int>> &num)
{
    for (int i = 0; i < mySIZE; i++)
    {
        for (int j = 0; j < mySIZE; j++)
        {
            qDebug() << num[i][j];
        }
        qDebug() << endl;
    }
}

bool IsRightPlace(vector<vector<int>> &num, int row, int col)
{
    int n = num[row][col];
    //注意i < row
    for (int i = 0; i < row; i++)
    {
        if (num[i][col] == n)
            return false;
    }
    //注意i < col
    for (int i = 0; i < col; i++)
    {
        if (num[row][i] == n)
            return false;
    }
    if(row==col)
    {
        for(int i=0;i<col;i++)
        {
            if(num[i][i]==num[row][col])
                return false;
        }
    }
    if(row==8-col)
    {
        for(int a=0,b=8;a<row;a++,b--)
        {
            if(num[a][b]==num[row][col])
                return false;
        }
    }
    int row_start = row / 3;
    row_start *= 3;
    int row_end = row_start + 2;
    int col_start = col / 3;
    col_start *= 3;
    int col_end = col_start + 2;
    int i = row_start, j = col_start;
    //注意 k <= 8
    for (int k = 1; k <= 8; k++)
    {
        if (row != i || col != j)
        {
            if (num[i][j] == n)
                return false;
        }
        else
            break;
        if (j == col_end)
        {
            j = col_start;
            i = i + 1;
        }
        else
        {
            j = j + 1;
        }
    }
    return true;
}

bool generate_core(vector<vector<int>> &num, int row, int col)
{

    vector<int> number;
    for (int i = 1; i <= 9; i++)
        number.emplace_back(i);
    while (!number.empty())
    {
        int randindex = rand() % number.size();
        int randnum = number[randindex];
        number.erase(number.begin() + randindex);
        num[row][col] = randnum;
        if (IsRightPlace(num, row, col) == false)
            continue;
        if (row == mySIZE - 1 && col == mySIZE-1)
        {
            return true;
        }
        int nextrow, nextcol;
        if (col == mySIZE-1)
        {
            nextrow=row + 1;
            nextcol = 0;
        }
        else
        {
            nextrow = row;
            nextcol = col + 1;
        }
        bool next = generate_core(num, nextrow, nextcol);
        if (next)
            return true;
    }
    if (number.empty())
    {
        num[row][col] = -5;
        return false;
    }
}

void generate()
{

    srand((unsigned)time(NULL));
    if( generate_core(num, 0, 0) )
        print(num);
}
void MainWindow::on_newgame_clicked()
{
    sign=false;
    srand((int)time(NULL));
    N=rand()%(maxnum-minnum+1)+minnum;
    generate();
    vector<int> random_num=getRandom(81);
    ui->table->setEditTriggers(QAbstractItemView::CurrentChanged);
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            endnum[i][j]=0;
            ui->table->item(i,j)->setFlags(ui->table->item(i,j)->flags()|Qt::ItemIsEnabled);
            QTableWidgetItem *x=ui->table->item(i,j);
            x->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//            string s;
//            stringstream ss;
//            ss<<num[i][j];
//            ss>>s;
            x->setForeground(Qt::black);
            x->setText(QString::fromStdString(" "));
        }
    }
    for (int i=0;i<N;i++)
    {
        string s;
        if((random_num[i]+1)%9==0)
        {
            ui->table->item((random_num[i]+1)/9-1,8)->setText(QString::number(num[(random_num[i]+1)/9-1][8]));
            ui->table->item((random_num[i]+1)/9-1,8)->setFlags(ui->table->item((random_num[i]+1)/9-1,8)->flags()&~Qt::ItemIsEnabled);
            ui->table->item((random_num[i]+1)/9-1,8)->setForeground(Qt::blue);

        }
        else
        {
            ui->table->item((random_num[i]+1)/9,(random_num[i]+1)%9-1)->setText(QString::number(num[(random_num[i]+1)/9][(random_num[i]+1)%9-1]));
            ui->table->item((random_num[i]+1)/9,(random_num[i]+1)%9-1)->setFlags(ui->table->item((random_num[i]+1)/9,(random_num[i]+1)%9-1)->flags()&~Qt::ItemIsEnabled);
            ui->table->item((random_num[i]+1)/9,(random_num[i]+1)%9-1)->setForeground(Qt::blue);
        }
    }
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            QTableWidgetItem *x=ui->table->item(i,j);
            sudo[i][j]=blanknum[i][j]=endnum[i][j]=x->text().toInt();
            qDebug()<<sudo[i][j];
        }
    }
//    for(int i=0;i<N;i++)
//    {
//        random_num[]
//    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     //失败的背景图片添加：
//     QWidget *newwidget =new QWidget();
//     newwidget->setAutoFillBackground(true);
//     QPalette palette;
//     QPixmap pixmap(":/new/prefix1/-254474a4c1f0d915.jpg");
//     palette.setBrush(QPalette::Window,QBrush(pixmap));
//     newwidget->setPalette(palette);
//     newwidget->show();
     setFixedSize(1024,768);
     setWindowTitle("数独");
     QPalette palette;
     palette.setColor(QPalette::WindowText,Qt::yellow);
     ui->label->setPalette(palette);
     QDir *RECORD = new QDir;
     bool exist = RECORD->exists("RECORD");
     if(!exist)
       bool ok = RECORD->mkdir("RECORD");
//     QString fileName = "RECORD/1.txt";
//     QString str="今天的天气很好适合跑步";
//     QFile file(fileName);
//     if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
//     {
//          qDebug() << "open fail!" << endl;
//     }
//     QTextStream in(&file);
//     in<<":"+str<<"\n";
//     file.close();
     ui->table->setEditTriggers(QAbstractItemView::CurrentChanged);
     connect(ui->table,SIGNAL(cellClicked(int,int)),this,SLOT(show_prodcut_sets(int,int)));
     connect(ui->rule,&QAction::triggered,[=](){
        QDialog *dlg=new QDialog(this);
        dlg->setWindowTitle("规则");
        dlg->setFixedSize(480,560);
        QLabel *rul=new QLabel;
        rul->adjustSize();
        rul->setGeometry(QRect(328,240,329,27*4));
        rul->setWordWrap(true);
        QScrollArea *scr2=new QScrollArea(dlg);
        scr2->setWidget(rul);
        rul->setAlignment(Qt::AlignTop);
        scr2->resize(720,660);
        rul->resize(720,600);
        rul->setParent(dlg);
        rul->setText("欢迎来到小黯战丿的数独程序""\n""操作说明：""\n""按【新的开始】以创建新的数独，难度随机.""\n""按【读取存档】来获得你之前玩过的存档.""\n""在空数独中输入"
                     "任意符合规范的数独，在按下【自定义数独】即可设置自定义数独"
                     "\n""按【退出游戏】游戏窗口将会在5s后自动关闭.""\n""点击数值为‘0’的待填格子，按下右边的某一按钮，即可填入数字.""\n""点击【提示】则会自动给出下一步正确步骤."
                     "\n""按【清空】以清空数独""\n""按【提示】以获得下一步正确答案""\n""按【显示答案】以获得最终数独答案""\n""按【保存】来保存当前状态""\n"
                     "按【确认】来判断对错""\n""左上角菜单栏可以选择难度""规则：""\n""本数独为对角线数独，任意行，列，主、副对角线以及宫内的数字不得""\n""重复。");
        dlg->show();
        dlg->setAttribute(Qt::WA_DeleteOnClose);
    });
     connect(ui->easy,&QAction::triggered,[=](){
        maxnum=80;
        minnum=60;
        ui->easy->setText("√简单");
        ui->simple->setText("普通");
        ui->hard->setText("困难");
     });
     connect(ui->simple,&QAction::triggered,[=](){
        maxnum=59;
        minnum=30;
        ui->easy->setText("简单");
        ui->simple->setText("√普通");
        ui->hard->setText("困难");
     });
     connect(ui->hard,&QAction::triggered,[=](){
        maxnum=29;
        minnum=17;
        ui->easy->setText("简单");
        ui->simple->setText("普通");
        ui->hard->setText("√困难");
     });
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::show_prodcut_sets(int row,int col)
{
    qDebug() << "所点击的单元格的row=" << row << ",col=" << col;
    // 获取所点击的单元格
    QTableWidgetItem* item = ui->table->item(row ,col);
    qDebug() << item->text();

}
void MainWindow::change_num(QString s,int row,int col)
{
     QTableWidgetItem* item = ui->table->item(row ,col);
     item->setText(s);
}

void MainWindow::on_confirm_clicked()
{
    dfs(0);
    bool isright=1;
    QDialog alock(this);
    alock.resize(400,320);
    alock.setWindowTitle("提示");
    QScrollArea *scr=new QScrollArea(&alock);
    scr->resize(400,320);
    QLabel *mes=new QLabel(&alock);
    mes->resize(400,1390);
    mes->setAlignment(Qt::AlignTop);
    scr->setWidget(mes);
    QString str=mes->text();
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            QTableWidgetItem *x=ui->table->item(i,j);
            if(x->text()!=" ")
                endnum[i][j]=x->text().toInt();
            else
                endnum[i][j]=0;
        }
    }
    for(int i=0;i<=8;i++)
    {
       for(int j=0;j<=8;j++)
        {
           if(sudo[i][j]==0)
           {
                exitorno=0;
                goto outside;
           }
        }
    }

    for(int i=0;i<=8;i++)
        for(int j=0;j<=8;j++)
        {
            if(endnum[i][j]!=sudo[i][j])
            {
                isright=0;
                mes->setText(str+="错误！");
                if(endnum[i][j]<0||endnum[i][j]>9)
                {
                    str+="第";
                    str.push_back('0'+i+1);
                    str+="行，第";
                    str.push_back('0'+j+1);
                    str+="列的数字不符合范围\n";
                    mes->setText(str);
                }
                else if(endnum[i][j]==0)
                {
                    str+="第";
                    str.push_back('0'+i+1);
                    str+="行，第";
                    str.push_back('0'+j+1);
                    str+="列的数字未填写\n";
                    mes->setText(str);
                }
                else
                {
                    str+="第";
                    str.push_back('0'+i+1);
                    str+="行，第";
                    str.push_back('0'+j+1);
                    str+="列的数字不符合限制条件\n";
                    mes->setText(str);
                }
            }
        }
    if(isright==1)
    {
        mes->setText("完全正确！");
    }
    alock.exec();
outside:if(exitorno==0)
    {
        QDialog alock_2(this);
        alock_2.resize(400,320);
        alock_2.setWindowTitle("提示");
        QScrollArea *scr=new QScrollArea(&alock_2);
        scr->resize(400,320);
        QLabel *mes=new QLabel(&alock_2);
        mes->resize(400,1390);
        mes->setAlignment(Qt::AlignTop);
        scr->setWidget(mes);
        mes->setText("该数独无解！");
        alock_2.exec();
    }
}

void MainWindow::on_answer_clicked()
{
    exitorno=1;
    sign=false;
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            QTableWidgetItem *x=ui->table->item(i,j);
            if(x->text()!=" ")
                endnum[i][j]=sudo[i][j]=x->text().toInt();
            else
                endnum[i][j]=sudo[i][j]=0;
        }
    }
    dfs(0);
    for(int i=0;i<=8;i++)
    {
       for(int j=0;j<=8;j++)
        {
           if(sudo[i][j]==0)
           {
                exitorno=0;
                goto outside;
           }
        }
    }

    for(int i=0;i<=8;i++)
    {
       for(int j=0;j<=8;j++)
        {
            QTableWidgetItem *x=ui->table->item(i,j);
            if(sudo[i][j]!=endnum[i][j])
            {
                x->setText(QString::number(sudo[i][j]));
                x->setForeground(Qt::red);
                x->setFlags(x->flags()&~Qt::ItemIsEnabled);
            }
        }
    }
outside:if(exitorno==0)
    {
        QDialog alock_2(this);
        alock_2.resize(400,320);
        alock_2.setWindowTitle("提示");
        QScrollArea *scr=new QScrollArea(&alock_2);
        scr->resize(400,320);
        QLabel *mes=new QLabel(&alock_2);
        mes->resize(400,1390);
        mes->setAlignment(Qt::AlignTop);
        scr->setWidget(mes);
        mes->setText("该数独无解！");
        alock_2.exec();
    }
}

void MainWindow::on_tip_clicked()
{
    for(int i=0;i<=8;i++)
        for(int j=0;j<=8;j++)
        {
            QTableWidgetItem *x=ui->table->item(i,j);
            if(x->text()!=QString::number(num[i][j]))
            {
                endnum[i][j]=num[i][j];
                x->setText(QString::number(num[i][j]));
                x->setForeground(Qt::red);
                x->setFlags(x->flags()&~Qt::ItemIsEnabled);
                goto _break;
            }
        }
_break:;
}

void MainWindow::on_recall_2_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"读取存档","RECORD");
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    ui->table->setEditTriggers(QAbstractItemView::CurrentChanged);
    QByteArray array=file.readAll();
    QString s=array;
    qDebug()<<array;
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            ui->table->item(i,j)->setFlags(ui->table->item(i,j)->flags()|Qt::ItemIsEnabled);
            QTableWidgetItem *x=ui->table->item(i,j);
            x->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//            string s;
//            stringstream ss;
//            ss<<num[i][j];
//            ss>>s;
            x->setForeground(Qt::black);
            x->setText(QString::fromStdString(" "));
        }
    }


    int k=0;
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++,k+=2)
        {
            endnum[i][j]=QString(s[k]).toInt();
            ui->table->item(i,j)->setFlags(ui->table->item(i,j)->flags()|Qt::ItemIsEnabled);
            QTableWidgetItem *x=ui->table->item(i,j);
            x->setText(QString(s[k]));
        }
        k+=2;
    }
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++,k+=2)
        {
            sudo[i][j]=blanknum[i][j]=QString(s[k]).toInt();
            qDebug()<<blanknum[i][j];
        }
        k+=2;
    }

    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            ui->table->item(i,j)->setFlags(ui->table->item(i,j)->flags()|Qt::ItemIsEnabled);
            QTableWidgetItem *x=ui->table->item(i,j);
            if(blanknum[i][j]!=0)
            {
                x->setForeground(Qt::blue);
                x->setFlags(x->flags()&~Qt::ItemIsEnabled);
            }
        }
    }
}

void MainWindow::on_save_clicked()
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh时mm分");
    QDialog _save(this);
    _save.resize(500,200);
    QTextEdit *get=new QTextEdit(&_save);
    get->resize(500,30);
    get->move(0,50);
    _save.setWindowTitle("保存");
    QPushButton *confirm_2=new QPushButton(&_save);
    confirm_2->resize(80,30);
    confirm_2->move(200,100);
    confirm_2->setText("确认");
    connect(confirm_2,&QPushButton::clicked,&_save,&QDialog::close);
    connect(confirm_2,&QPushButton::clicked,[=](){
            QString fileName="RECORD/"+get->toPlainText()+" "+current_date+".txt";
            QFile file(fileName);
            if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
            {
                qDebug() << "open fail!" << endl;
            }
            else
                qDebug()<<"open successfullu"<<endl;
            QTextStream in(&file);
            for(int i=0;i<=8;i++)
            {
                for(int j=0;j<=8;j++)
                {
                    QTableWidgetItem *x=ui->table->item(i,j);
                    endnum[i][j]=x->text().toInt();
                    in<<endnum[i][j]<<" ";
                }
                in<<"\n";
            }
            for(int i=0;i<=8;i++)
            {
                for(int j=0;j<=8;j++)
                {
                    QTableWidgetItem *x=ui->table->item(i,j);
                    in<<blanknum[i][j]<<" ";
                }
                in<<"\n";
            }
            file.close();
        });
//    QString fileName = "RECORD/1.txt";
//    QString str="今天的天气很好适合跑步";
//    QFile file(fileName);
//    if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
//    {
//         qDebug() << "open fail!" << endl;
//    }
//    else
//        qDebug()<<"open successfully"<<endl;
//    QTextStream in(&file);
//    in<<":"+str<<"\n";
//    file.close();
    _save.exec();
}

void MainWindow::on_clear_clicked()
{
    sign=false;
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            endnum[i][j]=0;
            ui->table->item(i,j)->setFlags(ui->table->item(i,j)->flags()|Qt::ItemIsEnabled);
            QTableWidgetItem *x=ui->table->item(i,j);
            x->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//            string s;
//            stringstream ss;
//            ss<<num[i][j];
//            ss>>s;
            x->setForeground(Qt::black);
            x->setText(QString::fromStdString(" "));
        }
    }
}




void MainWindow::on_user_defined_clicked()
{
    sign=false;
    bool t=0;
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=8;j++)
        {
            QTableWidgetItem *x=ui->table->item(i,j);
            if(x->text()!=' ')
                sudo[i][j]=endnum[i][j]=x->text().toInt();
            else
                sudo[i][j]=endnum[i][j]=0;
            qDebug()<<endnum[i][j]<<"\n";
        }
    }
    for(int row=0;row<9;row++)
        for(int col=0;col<9;col++){
            for (int i = 0; i < 9; i++)
            {
                if (i == col)
                    continue;
                else {
                    if (sudo[row][i] == sudo[row][col]&&sudo[row][col]!=0)
                        t=1;
                }
            }
            for (int i = 0; i < 9; i++)
            {
                if (i == row)
                    continue;
                else {
                    if (sudo[i][col] == sudo[row][col]&&sudo[row][col]!=0)
                        t=1;
                }
            }
            if (row == col)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (i == row)
                    {
                        continue;
                    }
                    else {
                        if (sudo[i][i] == sudo[row][col]&&sudo[row][col]!=0)
                        {
                            t=1;
                        }
                    }
                }
            }
            if (row + col == 8)
            {
                for (int i = 0; i < 9; i++)
                {
                    if (i == row)
                    {
                        continue;
                    }
                    else {
                        if (sudo[row][col] == sudo[i][8 - i]&&sudo[row][col]!=0)
                        {
                            t=1;
                        }
                    }
                }
            }
            int x = row/ 3 * 3;
            int y = col / 3 * 3;
            for (int i = x; i < x + 3; i++)
            {
                for (int j = y; j < y + 3; j++)
                {
                    if (i == row && j == col)
                        continue;
                    else if (sudo[i][j] == sudo[row][col]&&sudo[row][col]!=0)
                        t=1;
                }
            }
        }
    if(t==1)
    {
        QDialog alock(this);
        alock.resize(400,320);
        alock.setWindowTitle("提示");
        QScrollArea *scr=new QScrollArea(&alock);
        scr->resize(400,320);
        QLabel *mes=new QLabel(&alock);
        mes->resize(400,1390);
        mes->setAlignment(Qt::AlignTop);
        scr->setWidget(mes);
        mes->setText("该数独非法");
        alock.exec();
    }
}
