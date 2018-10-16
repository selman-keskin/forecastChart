#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QDebug>

#include <QString>
#include <QTime>
#include <QLocale>
#include <QList>

#include <QGridLayout>
#include <QChart>
#include <QChartView>

#include <QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QValueAxis>

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/// seconds as "X days, X hours, X minutes, X seconds" string
QString secondsToString(qint64 seconds)
{
  const qint64 DAY = 86400;
  qint64 days = seconds / DAY;
  QTime t = QTime(0,0).addSecs(seconds % DAY);
  return QString("%1 days, %2 hours, %3 minutes, %4 seconds")
    .arg(days).arg(t.hour()).arg(t.minute()).arg(t.second());
}

void MainWindow::on_pushButton_clicked()
{
    dateTime_s.clear();
    temp_s.clear();

    QString format = "yyyy-MM-dd";
    //QDateTime beginDate = QDateTime::fromString("2018-07-13", format);
    //QDateTime endDate = QDateTime::fromString("2018-07-15", format);
    //qDebug() << beginDate;
    //qDebug() << endDate;

    QDate beginDate = ui->dateEdit->date();
    QDate endDate = ui->dateEdit_2->date();
    //qDebug() << beginDate;
    //qDebug() << endDate;
    ui->textEdit->append(beginDate.toString());
    ui->textEdit->append(endDate.toString());


    QDate currentDate = QDate::fromString("0000-00-00", format);
    //QDateTime currentDate = QDateTime::fromString("0000-00-00", format);

    QString betweenDates = "start_date=2018-07-2&end_date=2018-07-3";

    qDebug() << "Begin Date: " << beginDate.toString("yyyy-MM-dd");
    qDebug() << "End Date: " << endDate.toString("yyyy-MM-dd");

    // //

    while (beginDate < endDate)
        {
        currentDate = beginDate.addDays(1);

        //qDebug() << beginDate.toString("yyyy-MM-dd") << currentDate.toString("yyyy-MM-dd");
        QString beginDate_s = beginDate.toString("yyyy-MM-dd");
        QString currentDate_s = currentDate.toString("yyyy-MM-dd");
        QString betweenDates = "start_date=" +beginDate_s + "&end_date=" + currentDate_s;
        QString qUrl_s = "https://api.weatherbit.io/v2.0/history/hourly?city=Istanbul&"+betweenDates+"&key=" + ui->lineEdit->text();

        //qDebug() << qUrl_s;

        //Veri getirme islemi
        QNetworkRequest request;
        QSslConfiguration config = QSslConfiguration::defaultConfiguration();
        request.setSslConfiguration(config);
        request.setUrl(QUrl(qUrl_s));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QJsonObject json;
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());

        //Cevap bekle
        while(!reply->isFinished())
        {
            qApp->processEvents();
        }

        QByteArray response_data = reply->readAll();
        QString response_data_s(response_data);
        qDebug() << response_data_s;
        ui->textEdit->append(response_data_s);


        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject data = json_doc.object();
        QJsonArray jsonArray = data.value(QString("data")).toArray();

        foreach (const QJsonValue & v, jsonArray)
        {
            //qDebug() << v.toObject().value("temp").toDouble();
            //qDebug() << v.toObject().value("datetime").toString();

            temp_s.append(v.toObject().value("temp").toDouble());
            dateTime_s.append(v.toObject().value("datetime").toString());
        }

        beginDate = beginDate.addDays(1);
    }

    qDebug() << dateTime_s;
    qDebug() << temp_s;
}


void MainWindow::on_pushButton_2_clicked()
{
    if (dateTime_s.count() != 0)
    {
    //dateTime_s.clear();
    //temp_s.clear();

    //Gecici veriler, saatte max 200 sorgu
    //dateTime_s.append("2018-07-13:00");
    //dateTime_s.append("2018-07-13:01");
    //dateTime_s.append("2018-07-13:02");
    //dateTime_s.append("2018-07-13:03");
    //dateTime_s.append("2018-07-13:04");
    //temp_s.append(26);
    //temp_s.append(12);
    //temp_s.append(23);
    //temp_s.append(17);
    //temp_s.append(27);

    chart  = new QtCharts::QChart;
    chart->setTitle("Saatlik Hava Durumu");

    //QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    //QList<QtCharts::QLineSeries*> lineSeriesList;

    //*series << QPointF(0, 9) << QPointF(9.4, 4.8) << QPointF(15, 20);



    QtCharts::QBarSet *set_temp = new QtCharts::QBarSet("Sıcaklık");
    //*set_temp << 1 << 2 << 3 << 4 << 5 << 6;


    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    QtCharts::QBarSeries *series_h = new QtCharts::QBarSeries();

    //QStringList dateTime;
    //dateTime << "Jan" << "Feb" << "Mar" << "Apr" << "May";
    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();

    //Saatlik liste
    if (ui->checkBox->checkState() == Qt::Checked)
    {
        dateTime_s_hour.clear();
        temp_s_hour.clear();

        for( int i=0; i<temp_s.count(); ++i )
        {
            //*set_temp << temp_s[i];
            //dateTime << dateTime_s[i];
            QStringList currentDateTime = dateTime_s[i].split(":");
            //qDebug() << currentDateTime[1];
            if(ui->comboBox->currentText() == currentDateTime[1])
            {
                //qDebug() << "addseries" << currentDateTime[1];
                dateTime_s_hour.append(dateTime_s[i]);
                temp_s_hour.append(temp_s[i]);
            }
        }

        qDebug() << dateTime_s_hour << temp_s_hour;

        //Y ekseni
        double max_temp = *std::max_element(temp_s_hour.begin(), temp_s_hour.end());
        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
        axisY->setRange(0, max_temp);
        axisY->setTickCount(1);
        axisY->setLabelFormat("%.1f");
        chart->setAxisY(axisY, series_h);

        for( int i=0; i<temp_s_hour.count(); ++i )
        {
            //*series << QPointF(temp_s[i],temp_s[i]);
            *set_temp << temp_s_hour[i];
            //dateTime << dateTime_s[i];
        }

        //X Ekseni
        axis->append(dateTime_s_hour);
        //axis->setLabelsAngle(90);

        chart->createDefaultAxes();
        chart->setAxisX(axis, series_h);

        series_h->append(set_temp);

        chart->addSeries(series_h);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    }
    else
    {
        //Y ekseni
        for( int i=0; i<temp_s.count(); ++i )
        {
            *series << QPointF(i,temp_s[i]);
            //*set_temp << temp_s[i];
            //dateTime << dateTime_s[i];
            //series->append(dateTime_s.count() - i,temp_s[i]);
            qDebug() << i <<temp_s[i];

        }

        //series->append(0, 31);
        //series->append(1, 31);
        //series->append(2, 31);
        //series->append(3, 29);
        //series->append(4, 29);
        //series->append(5, 29);
        //series->append(6, 29);
        //series->append(7, 29);

        double max_temp = *std::max_element(temp_s.begin(), temp_s.end());
        double min_temp = *std::min_element(temp_s.begin(), temp_s.end());

        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
        axisY->setRange(min_temp, max_temp);
        axisY->setTickCount(1);
        axisY->setLabelFormat("%.1f");
        chart->setAxisY(axisY, series);


        //X Ekseni
        axis->append(dateTime_s);
        axis->setLabelsAngle(90);

        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        //series->append(set_temp);
        chart->addSeries(series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

    }

    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedHeight(600);
    chartView->setFixedWidth(800);
    chartView->setChart(chart);
    chartView->setRubberBand(QtCharts::QChartView::HorizontalRubberBand);
    chartView->show();
}
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Uyarı");
        msgBox.setInformativeText("Herhangi bir veri yok, GET ile veri getiriniz.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int ret = msgBox.exec();

    }

}

void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->checkState() == Qt::Checked)
    {
        ui->comboBox->setEnabled(true);
    }
    else
    {
        ui->comboBox->setEnabled(false);

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    chart->zoomReset();
}


