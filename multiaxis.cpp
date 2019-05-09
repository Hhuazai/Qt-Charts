#include "multiaxis.h"

#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QSplineSeries>
#include <QCategoryAxis>
#include <QDebug>

MultiAxis::MultiAxis(QWidget *parent) : QWidget(parent)
{
    chart = new QChart();
    chart->legend()->setVisible(false);
    chart->setTitle("Multiaxis chart example");

    //X轴
    QValueAxis *axisX = new QValueAxis();
    axisX->setTickCount(10);
    axisX->setLinePenColor(Qt::red);

    //Y轴
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 20);
    axisY->setLinePenColor(Qt::yellow);

    //两条曲线
    QSplineSeries *series1 = new QSplineSeries;
    *series1 << QPointF(1, 5) << QPoint(3.5, 18) << QPointF(4.8, 7.5) << QPointF(10, 2.5);

    QSplineSeries *series2 = new QSplineSeries;
    *series2 << QPointF(1, 0.5) << QPointF(1.5, 4.5) << QPointF(2.4, 2.5) << QPointF(4.3, 12.5)
            << QPointF(5.2, 3.5) << QPointF(7.4, 16.5) << QPointF(8.3, 7.5) << QPointF(10, 17);

    //Y轴分割轴
    QCategoryAxis *axisY3 = new QCategoryAxis;
    axisY3->append("Low",  5);
    axisY3->append("Medium", 12);
    axisY3->append("High", 17);
    axisY3->setLinePenColor(Qt::cyan);
    axisY3->setGridLinePen(series2->pen());

//    //给X轴添加分割轴
//    QCategoryAxis *axisX3 = new QCategoryAxis;
//    axisX3->append("111", 3);
//    axisX3->append("222", 6);
//    axisX3->append("333", 10);
//    axisX3->setLinePenColor(Qt::cyan);
//    axisX3->setGridLinePen(series2->pen());

    //给chart添加轴
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisY3, Qt::AlignRight);
//    chart->addAxis(axisX3, Qt::AlignBottom);

    //给chart添加曲线
    chart->addSeries(series1);
    chart->addSeries(series2);

    //将指定轴附加到series
    series1->attachAxis(axisX);
    series2->attachAxis(axisX);
    series1->attachAxis(axisY);
    series2->attachAxis(axisY);
    series1->attachAxis(axisY3);
    series2->attachAxis(axisY3);
//    series1->attachAxis(axisX3);
//    series2->attachAxis(axisX3);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

MultiAxis::~MultiAxis()
{
    qDebug() << QStringLiteral("析构函数--MultiAxis");
}

QWidget *MultiAxis::ShowView()
{
    return chartView;
}
