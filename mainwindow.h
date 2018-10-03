#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "qserialport.h"
#include "qserialportinfo.h"
#include "QListWidgetItem"
#include "QTimer"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void readSerial();


    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_sliderMoved(int position);

    void on_verticalSlider_sliderReleased();

    void on_verticalSlider_2_sliderReleased();

    void on_verticalSlider_3_sliderReleased();

    void on_verticalSlider_4_sliderReleased();

    void on_verticalSlider_5_sliderReleased();

    void blink();

    void on_blinkButton_clicked();

    void on_stopButton_clicked();

    void on_verticalSlider_2_sliderMoved(int position);

    void on_verticalSlider_3_sliderMoved(int position);

    void on_verticalSlider_4_sliderMoved(int position);

    void on_verticalSlider_5_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QSerialPort port;
    QByteArray buf;
    QTimer *tmr;

    void WriteData();


};

#endif // MAINWINDOW_H
