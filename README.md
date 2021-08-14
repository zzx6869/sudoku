此项目为作者在程序设计Ⅱ大作业所写的数独程序，包含了一个数独游戏的所有基本功能  
项目不包含拓展部分的高级算法和多线程
若想体验程序，请在右侧release版本中下载即可，本部分为其实现代码以及文件
## 1.基本功能部分  

+ **程序说明信息以及交互**  
  点击菜单栏的开始按钮，并点击其中的规则，即可弹出规则界面弹窗：
  ![2290715-20210630203223990-1793966844.png](https://i.loli.net/2021/07/21/gkrNnYZQBOFKlh2.png)
  规则弹窗详细地介绍了数独程序中各个按键的作用以及游戏的规则说明。
  
  实现：
  
  通过创建一个非模态对话框，并在其上创建Qlabel类的标签来实现显示。
  
  ```c++
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
  ```
  
+ **难度选择**
  
  点击开始菜单栏中难度，可在三种难度中进行选择，根据数独待填空格的多少，对应“简单”“普通”和“困难”三种模式。如不进行选择，则生成数独的难度随机。![2290715-20210630203721638-90640443.jpg](https://i.loli.net/2021/07/21/tgjJWc7EKwVBTyC.jpg)

  实现：
  
  ```c++
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
  ```
  
+ **新的开始及基本操作**
  点击【新的开始】按钮，即可生成所选难度的可解数独。  
  点击【提示】则程序会自动显示下一步正确操作。
  点击【显示答案】则自动显示所有正确答案，即该数独的一个解。
  
  实现：通过DFS实现对数独的求解
  
  ```c++
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
  ```
  
  点击【确认】来判断结果的对错。  
  蓝色初始题给数字，无法修改。  
  红色表示提示or显示答案所给出的数字，无法修改。  
  黑色及空格表示待填入or已填入的数字，可以修改。
  ![2290715-20210630204805912-1755524579.png](https://i.loli.net/2021/07/21/ZAUXazcdRITi398.png)
  
  
  
+ **存档和读档**
  在当前状态下点击保存，程序会出现一个弹窗，可以输入自定义的状态名字，文件名默认为【自定义名称+保存的时间】  
  点击读取存档来获得之前储存过的存档。![2290715-20210630205250918-1477763794.png](https://i.loli.net/2021/07/21/DPnUFQwG7KciCp9.png)![2290715-20210630205256063-916436938.png](https://i.loli.net/2021/07/21/8BDHFLdWlcijg7e.png)  

  实现：
  
  ```c++
  //保存
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
      _save.exec();
  }
  ```
  
  ```c++
  //读取
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
  ```
  
+ **自定义数独**
  在一个空的数独盘中输入自定义的起始数独（可能有解可能无解），再点击【自定义数独】按钮，即完成自定义数独的设置。  
  若数独非法，程序则会弹出对话框提示数独非法，定义失败。![2290715-20210630205658697-840915071.png](https://i.loli.net/2021/07/21/neyjO5AvMK4i29l.png)

  实现：
  
  ```c++
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
  ```
  
+ **清空及退出**
  按【清空】按钮以清空当前所有状态。  
  按【退出】按钮，则程序5s后会自动退出并弹出对话框“感谢使用”。![2290715-20210630205917561-126594873.png](https://i.loli.net/2021/07/21/p3FAMj45t9HGk7P.png)
  
   实现：
  
  ```c++
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
              x->setForeground(Qt::black);
              x->setText(QString::fromStdString(" "));
          }
      }
  }
  
  ```
  
  ```c++
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
  ```

 ## 2.扩展部分

+ **图形化**
  利用QTCreater中的ui界面以及代码共同实现了数独界面的图形化，并且添加了~~可莉“求求你了，帮帮可莉吧”.jpg~~作为背景图片，糖葫芦可莉作为程序图标，按键对齐摆放等方式实现了对ui界面的优化。

  利用资源文件实现对ui界面的优化。
  
  ![image-20210708104713160.png](https://i.loli.net/2021/07/21/ihugYImLjbc6k3H.png)
  
  <img src="https://i.loli.net/2021/07/21/iP42fIBjGbEtW7p.png" alt="image-20210708104815196.png" style="zoom: 25%;" />
  
  <img src="https://i.loli.net/2021/07/21/GiV9FU7I1ypRMPz.png" alt="image-20210708104829606.png" style="zoom:25%;" />
  
  
  
+ **高级算法**
  在朴素DFS的基础上，添加了深度depth实现了迭代加深；

  `if (n > depth)
  	{
  		sign = 1;
  		return 0;
  	}`

  利用一个三维数组来进行统计每个格子各个数字可能出现的情况，并不断更新优化，最后再进行DFS，实现启发式搜索。

  ```c++
  void brush() {
      for (int i = 1; i < 10; i++) {
          for (int j = 1; j < 10; j++) {
              if (get(i, j) == 0) {
                  int num = 0;
                  int index = 0;
                  for (int k = 1; k < 10; k++)
                      if (arr[i][j][k] != 0) {
                          num++;
                          index = k;
                      }
                  if (num == 1)
                      set(i, j, arr[i][j][index]);
              }
          }
      }
  }
  ```

  利用thread头文件来创建多个线程，分别进行判断求解，实现解数独的优化。

  
