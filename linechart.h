#ifndef LINECHART_H
#define LINECHART_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
class QChartView;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class LineChart : public QWidget
{
    Q_OBJECT
public:
    explicit LineChart(QWidget *parent = 0);
    ~LineChart();

    QWidget *ShowView();

private:
    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;
};

#endif // LINECHART_H
