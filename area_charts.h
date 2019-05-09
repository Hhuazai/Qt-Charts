#ifndef AREA_CHARTS_H
#define AREA_CHARTS_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QAreaSeries;
class QChart;
class QChartView;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class AreaChart : public QWidget
{
    Q_OBJECT

public:
    explicit AreaChart(QWidget *parent = 0);
    ~AreaChart();

    QWidget *ShowView();

private:
    QLineSeries *series0;
    QLineSeries *series1;

    QAreaSeries *series;
    QChart *chart;
    QChartView *chartView;
};

#endif // AREA_CHARTS_H


