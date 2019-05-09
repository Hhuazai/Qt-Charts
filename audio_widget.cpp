#include "audio_widget.h"

#include "audio_xyseriesiodevice.h"

#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QValueAxis>

#include <QDebug>

AudioWidget::AudioWidget(QWidget *parent)
    : QWidget(parent),
      m_device(0),
      m_chart(0),
      m_series(0),
      m_audioInput(0),
      m_chartView(0)
{
    m_chart = new QChart;
    m_chartView = new QChartView(m_chart);
    m_series = new QLineSeries;
    m_chart->addSeries(m_series);

    QValueAxis *axistX = new QValueAxis;
    axistX->setRange(0, 2000);
    axistX->setTitleText("samples");
    axistX->setLabelFormat("%g");

    QValueAxis *axistY = new QValueAxis;
    axistY->setRange(-1, 1);
    axistY->setTitleText("Audio level");

    m_chart->setAxisX(axistX, m_series);
    m_chart->setAxisY(axistY, m_series);
    m_chart->legend()->hide();
    m_chart->setTitle("Data from the microphone");

    QAudioFormat formatAudio;
    formatAudio.setSampleRate(8000);
    formatAudio.setChannelCount(1);
    formatAudio.setSampleSize(8);
    formatAudio.setCodec("audio/pcm");
    formatAudio.setByteOrder(QAudioFormat::LittleEndian);
    formatAudio.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo inputDevices = QAudioDeviceInfo::defaultInputDevice();
    m_audioInput = new QAudioInput(inputDevices, formatAudio, this);

    m_device = new AudioXyseriesIODevice(m_series, this);
    m_device->open(QIODevice::WriteOnly);

    m_audioInput->start(m_device);
}

AudioWidget::~AudioWidget()
{
    qDebug() << QStringLiteral("析构函数--AudioWidget");
    m_audioInput->stop();
    m_device->close();
}

QWidget *AudioWidget::ShowView()
{
    return m_chartView;
}
