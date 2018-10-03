#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        ui->listWidget->addItem(info.portName());
    }
    buf[0] = 128;
    buf[1] = 128;
    buf[2] = 128;
    buf[3] = 128;
    buf[4] = 128;

    tmr = new QTimer();
    tmr->setInterval(100);
    connect(tmr, SIGNAL(timeout()), this, SLOT(blink()));



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    port.close();
    port.setPortName(item->text());
    port.setBaudRate(115200);
    if (port.open(QIODevice::ReadWrite))
    {
        ui->label->setText("Выбран порт"+item->text());
        connect(&port,SIGNAL(readyRead()),this,SLOT(readSerial()));
    }



}

void MainWindow::readSerial()
{
    char tmp[25];
    int count =0;
    if(port.isOpen())
    {

        if (port.canReadLine())
        {
            port.readLine(tmp,25);
            count++;
        }

        QString str(tmp);


        ui->listWidget_2->addItem(str);
    }

}

void MainWindow::on_verticalSlider_valueChanged(int value)
{

}

void MainWindow::WriteData()
{
    port.write(buf);
    port.flush();
}



void MainWindow::on_verticalSlider_sliderMoved(int position)
{
    buf[0] =128- ui->verticalSlider->sliderPosition();
    WriteData();
}

void MainWindow::on_verticalSlider_sliderReleased()
{

}

void MainWindow::on_verticalSlider_2_sliderReleased()
{

}

void MainWindow::on_verticalSlider_3_sliderReleased()
{

}

void MainWindow::on_verticalSlider_4_sliderReleased()
{

}

void MainWindow::on_verticalSlider_5_sliderReleased()
{

}

void MainWindow::blink()
{
    static int i=0;
    static bool direction = true;
    buf[0]= 128-i; buf[1] = 128-i; buf[2] = 128-i;buf[3] = 128-i; buf[4] = 128-i;
    WriteData();
    if (direction)
        i+=5;
    if (!direction)
        i-=5;
    if (i==40 || i==0)
        direction = !direction;

}

void MainWindow::on_blinkButton_clicked()
{
    tmr->start();
}

void MainWindow::on_stopButton_clicked()
{
    tmr->stop();
}

void MainWindow::on_verticalSlider_2_sliderMoved(int position)
{
    buf[1] =128- ui->verticalSlider_2->sliderPosition();
    WriteData();
}

void MainWindow::on_verticalSlider_3_sliderMoved(int position)
{
    buf[2] =128- ui->verticalSlider_3->sliderPosition();
    WriteData();
}

void MainWindow::on_verticalSlider_4_sliderMoved(int position)
{
    buf[3] =128- ui->verticalSlider_4->sliderPosition();
    WriteData();
}

void MainWindow::on_verticalSlider_5_sliderMoved(int position)
{
    buf[4] =128- ui->verticalSlider_5->sliderPosition();
    WriteData();
}
