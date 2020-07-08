#ifndef QDOTMATRIXDISPLAY_H
#define QDOTMATRIXDISPLAY_H

#include <QWidget>
#include <QColor>
#include <QVector>
#include <QByteArray>
#include <QFrame>
#include <QTimer>

class QDotMatrixDisplay : public QFrame
{
    Q_OBJECT

    Q_PROPERTY(int columnCount READ columnCount WRITE setColumnCount)
    Q_PROPERTY(int rowCount READ rowCount WRITE setRowCount)
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QColor dotONColor READ dotONColor WRITE setDotONColor)
    Q_PROPERTY(QColor dotOFFColor READ dotOFFColor WRITE setDotOFFColor)

public:
    explicit QDotMatrixDisplay(QWidget *parent = 0);
    explicit QDotMatrixDisplay(uint nCols, uint nRows, QWidget *parent = 0);
    ~QDotMatrixDisplay();
    void paintEvent ( QPaintEvent * e);

    enum AutoRotation
    {
        RotationRight, RotationLeft, RotationUp, RotationDown, NoRotation
    };

    int columnCount() const;
    void setColumnCount(int);
    int rowCount() const;
    void setRowCount(int);
    QString text() const;
    void setText(const QString &);
    QColor dotONColor() const;
    void setDotONColor(const QColor &);
    QColor dotOFFColor() const;
    void setDotOFFColor(const QColor &);
    void RotateLeft(int dots);
    void RotateRight(int dots);
    void RotateUp(int dots);
    void RotateDown(int dots);
    void RotateReset(void);
    void setAutoRotation(AutoRotation mode, int msec);
    
private:
    void updateCharactersBuffer();
    void updateDotsBuffer();

    int m_columncount;
    int m_rowcount;
    QString m_text;
    QColor m_dotoncolor;
    QColor m_dotoffcolor;
    QVector<bool> m_dotbuffer;
    QVector<QVector<unsigned char> > m_characterbuffer;
    QTimer *m_autorotation_timer;
    AutoRotation m_autorotation_mode;
    int m_autorotation_interval;

    static unsigned char m_charsvector[256][7];

private slots:
    void on_m_autorotation_timer_timeout();
};

#endif // QDOTMATRIXDISPLAY_H
