#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLocale>

#include <QGridLayout>
#include <QChart>
#include <QChartView>
#include <QBarSeries>

#include <QAbstractAxis>
#include <QLineSeries>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QtCharts::QChart *chart;
    //QGridLayout *gridLayout;
    QtCharts::QChartView *chartView;

    QList<QString> dateTime_s_hour;
    QList<double> temp_s_hour;

    QList<QString> dateTime_s;
    QList<double> temp_s;

    //QList<QtCharts::QLineSeries *> dateTime_s;
    //QList<QtCharts::QLineSeries *> temp_s;

};

#endif // MAINWINDOW_H
