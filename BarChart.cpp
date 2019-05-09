#include "BarChart.h"

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QDebug>

BarChart::BarChart(QWidget *parent) : QWidget(parent)
{
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 <<  5 << 6;
    *set1 << 5 << 10 << 0 << 4 << 8 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 <<  4 << 5;
    *set4 << 9 << 7 << 5 << 3 <<  1 << 2;

    set0->setColor(Qt::red);                    //使用Qt定义好的color
    set1->setColor(QColor(255, 60, 190, 199));  //自定义颜色，rgba的范围都是0~255
                                                //其他未设置颜色的使用默认的颜色

    series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");


    //    QChart::NoAnimation        0x0    默认 无动画
    //    QChart::GridAxisAnimations 0x1
    //    QChart::SeriesAnimations   0x2
    //    QChart::AllAnimations      0x3    上面两种动画综合

    chart->setAnimationOptions(QChart::SeriesAnimations);

    //自定义图表轴 X轴
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);

    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    chart->axisY()->setRange(0, 20);


//    Constant             Value                          Description
//    Qt::AlignLeft        0x0001                         与左边缘对齐。
//    Qt::AlignRight       0x0002                         与右边缘对齐。
//    Qt::AlignHCenter     0x0004                         在可用空间中水平居中。
//    Qt::AlignJustify     0x0008                         在可用空间中对齐文本。

//    Qt::AlignTop         0x0020                         与顶部对齐。
//    Qt::AlignBottom      0x0040                         与底部对齐。
//    Qt::AlignVCenter     0x0080                         在可用空间中垂直居中。
//    Qt::AlignBaseline    0x0100                         与基线对齐。

//    Qt::AlignCenter      AlignVCenter | AlignHCenter    两个维度的中心。


    chart->legend()->setVisible(true);                 //默认为true
    chart->legend()->setAlignment(Qt::AlignBottom);    //默认为Qt::AlignTop

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


//    Constant                            Value       Description
//    QPainter::Antialiasing              0x01        指示引擎应该尽可能消除图元的边缘。
//    QPainter::TextAntialiasing          0x02        指示引擎应该尽可能抗锯齿文本。要强制禁用文本抗锯齿，请不要使用此提示。
//                                                    相反，应该在字体的风格策略上设置QFont::NoEntialias。
//    QPainter::SmoothPixmapTransform     0x04        指示引擎应该使用平滑的位图转换算法(如双线性)而不是最近邻算法。
//    QPainter::HighQualityAntialiasing   0x08        该值已过时，将被忽略，请改用抗锯齿渲染提示。
//    QPainter::NonCosmeticDefaultPen     0x10        该值已过时，QPen的默认值现在是非修饰性的。
//    QPainter::Qt4CompatiblePainting     0x20        兼容性提示告诉引擎使用与Qt 4中相同的基于X11的填充规则，其中混叠渲染的偏移量略小于半个像素。
//                                                    也将默认构造的笔视为化妆品。将Qt 4应用程序移植到Qt 5时可能会很有用。
}

BarChart::~BarChart()
{
    qDebug() << QStringLiteral("析构函数--BarChart");
}

QWidget *BarChart::ShowView()
{
    return chartView;
}
