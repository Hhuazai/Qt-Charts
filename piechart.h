#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QPieSeries;
class QChart;
class QChartView;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class PieChart : public QWidget
{
    Q_OBJECT
public:
    explicit PieChart(QWidget *parent = 0);
    ~PieChart();

    QWidget *ShowView();

private:
    QPieSeries *series;
    QChart *chart;
    QChartView *chartView;
};

#endif // PIECHART_H
