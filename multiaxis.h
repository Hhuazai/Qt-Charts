#ifndef MULTIAXIS_H
#define MULTIAXIS_H

#include <QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class MultiAxis : public QWidget
{
    Q_OBJECT

public:
    explicit MultiAxis(QWidget *parent = 0);
    ~MultiAxis();

    QWidget *ShowView();

private:
    QChart *chart;
    QChartView *chartView;
};

#endif // MULTIAXIS_H
