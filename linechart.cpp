#include "linechart.h"

#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>

#include <QDebug>

LineChart::LineChart(QWidget *parent) : QWidget(parent)
{
    series = new QLineSeries;

    //两种方式给series添加数据
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    chart = new QChart;
    chart->addSeries(series);
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->setTitle("Line Chart");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);   //抗锯齿
}

LineChart::~LineChart()
{
    qDebug() << QStringLiteral("析构函数--LineChart");
}

QWidget *LineChart::ShowView()
{
    return chartView;
}
