#include "qdotmatrixdisplay.h"
#include <QPainter>
#include <QRgb>
#include <QStyleOption>

#define DIAMETER_GAP_RATIO 4

unsigned char QDotMatrixDisplay::m_charsvector[256][7]={
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //' '
    {0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04}, //'!'
    {0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00}, //'"'
    {0x0A, 0x0A, 0x1F, 0x0A, 0x1F, 0x0A, 0x0A}, //'#'
    {0x04, 0x0E, 0x10, 0x0E, 0x01, 0x0E, 0x04}, //'$'
    {0x18, 0x19, 0x02, 0x04, 0x08, 0x13, 0x03}, //'%'
    {0x0C, 0x12, 0x12, 0x0C, 0x13, 0x12, 0x0D}, //'&'
    {0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00}, //'''
    {0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02}, //'('
    {0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08}, //')'
    {0x00, 0x04, 0x15, 0x0E, 0x15, 0x04, 0x00}, //'*'
    {0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00}, //'+'
    {0x00, 0x00, 0x00, 0x00, 0x0C, 0x04, 0x08}, //','
    {0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00}, //'-'
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C}, //'.'
    {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x00}, //'/'
    {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E}, //'0'
    {0x04, 0x0C, 0x14, 0x04, 0x04, 0x04, 0x0E}, //'1'
    {0x0E, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F}, //'2'
    {0x0E, 0x11, 0x01, 0x0E, 0x01, 0x11, 0x0E}, //'3'
    {0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02}, //'4'
    {0x1F, 0x10, 0x10, 0x1E, 0x01, 0x01, 0x1E}, //'5'
    {0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E}, //'6'
    {0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08}, //'7'
    {0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E}, //'8'
    {0x0E, 0x11, 0x11, 0x0F, 0x01, 0x01, 0x0E}, //'9'
    {0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x00}, //':'
    {0x00, 0x00, 0x08, 0x00, 0x08, 0x08, 0x10}, //';'
    {0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02}, //'<'
    {0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00}, //'='
    {0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08}, //'>'
    {0x0E, 0x11, 0x01, 0x02, 0x04, 0x00, 0x04}, //'?'
    {0x0E, 0x11, 0x17, 0x15, 0x17, 0x10, 0x0E}, //'@'
    {0x0E, 0x11, 0x11, 0x11, 0x1F, 0x11, 0x11}, //'A'
    {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E}, //'B'
    {0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E}, //'C'
    {0x1C, 0x12, 0x11, 0x11, 0x11, 0x12, 0x1C}, //'D'
    {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F}, //'E'
    {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10}, //'F'
    {0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0E}, //'G'
    {0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}, //'H'
    {0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E}, //'I'
    {0x07, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0C}, //'J'
    {0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11}, //'K'
    {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F}, //'L'
    {0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11}, //'M'
    {0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11}, //'N'
    {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}, //'O'
    {0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10}, //'P'
    {0x0E, 0x11, 0x11, 0x11, 0x15, 0x0E, 0x01}, //'Q'
    {0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11}, //'R'
    {0x0E, 0x11, 0x10, 0x0E, 0x01, 0x11, 0x0E}, //'S'
    {0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}, //'T'
    {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}, //'U'
    {0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04}, //'V'
    {0x11, 0x11, 0x11, 0x15, 0x15, 0x1B, 0x11}, //'W'
    {0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11}, //'X'
    {0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04}, //'Y'
    {0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F}, //'Z'
    {0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E}, //'['
    {0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00}, //'\'
    {0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E}, //']'
    {0x04, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00}, //'^'
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F}, //'_'
    {0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00}, //'`'
    {0x00, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x0F}, //'a'
    {0x10, 0x10, 0x1E, 0x11, 0x11, 0x11, 0x1E}, //'b'
    {0x00, 0x00, 0x0F, 0x10, 0x10, 0x10, 0x0F}, //'c'
    {0x01, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x0F}, //'d'
    {0x00, 0x00, 0x0E, 0x11, 0x1F, 0x10, 0x0E}, //'e'
    {0x06, 0x08, 0x08, 0x1C, 0x08, 0x08, 0x08}, //'f'
    {0x00, 0x0E, 0x11, 0x11, 0x0F, 0x01, 0x0E}, //'g'
    {0x10, 0x10, 0x16, 0x19, 0x11, 0x11, 0x11}, //'h'
    {0x04, 0x00, 0x0C, 0x04, 0x04, 0x04, 0x0E}, //'i'
    {0x02, 0x00, 0x06, 0x02, 0x02, 0x0A, 0x04}, //'j'
    {0x10, 0x10, 0x12, 0x14, 0x18, 0x14, 0x12}, //'k'
    {0x0C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E}, //'l'
    {0x00, 0x00, 0x1A, 0x15, 0x15, 0x15, 0x15}, //'m'
    {0x00, 0x00, 0x16, 0x19, 0x11, 0x11, 0x11}, //'n'
    {0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E}, //'o'
    {0x00, 0x00, 0x1C, 0x12, 0x12, 0x1C, 0x10}, //'p'
    {0x00, 0x00, 0x0E, 0x12, 0x12, 0x0E, 0x02}, //'q'
    {0x00, 0x00, 0x16, 0x18, 0x10, 0x10, 0x10}, //'r'
    {0x00, 0x00, 0x0F, 0x10, 0x0E, 0x01, 0x1E}, //'s'
    {0x08, 0x08, 0x1C, 0x08, 0x08, 0x09, 0x06}, //'t'
    {0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x0E}, //'u'
    {0x00, 0x00, 0x11, 0x11, 0x11, 0x0A, 0x04}, //'v'
    {0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0A}, //'w'
    {0x00, 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11}, //'x'
    {0x00, 0x00, 0x11, 0x11, 0x0F, 0x01, 0x0E}, //'y'
    {0x00, 0x00, 0x1F, 0x02, 0x04, 0x08, 0x1F}, //'z'
    {0x02, 0x04, 0x04, 0x08, 0x04, 0x04, 0x02}, //'{'
    {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}, //'|'
    {0x08, 0x04, 0x04, 0x02, 0x04, 0x04, 0x08}, //'}'
    {0x00, 0x00, 0x0A, 0x14, 0x00, 0x00, 0x00}, //'~'
};

QDotMatrixDisplay::QDotMatrixDisplay(QWidget *parent /*= 0*/) :
    QFrame(parent)
{
    m_columncount = 1;
    m_rowcount = 1;
    m_dotoncolor.setRgb(255,0,0);
    m_dotoffcolor.setRgb(50,0,0);
    m_autorotation_timer = NULL;
    m_text = "";
    updateCharactersBuffer();
    updateDotsBuffer();

    setFrameStyle(QFrame::Box | QFrame::Raised);
}

QDotMatrixDisplay::QDotMatrixDisplay(uint nCols, uint nRows, QWidget *parent /*= 0*/) :
    QFrame(parent)
{
    m_columncount = nCols;
    m_rowcount = nRows;
    m_dotoncolor.setRgb(255,0,0);
    m_dotoffcolor.setRgb(50,0,0);
    m_autorotation_timer = NULL;
    m_text = "";
    updateCharactersBuffer();
    updateDotsBuffer();

    setFrameStyle(QFrame::Box | QFrame::Raised);
}

QDotMatrixDisplay::~QDotMatrixDisplay()
{
}

void QDotMatrixDisplay::paintEvent ( QPaintEvent * e)
{
    QFrame::paintEvent(e);

    QPainter painter(this);

    painter.setPen( Qt::NoPen );

    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    double x_margin, y_margin;
    double width = rect().width();
    double height = rect().height();

    int framewidth = frameWidth();

    if((width-2*framewidth) / (height-2*framewidth) > (m_columncount*5.0)/(7*m_rowcount))
    {
       x_margin = ( (width-2*framewidth) - ((height-2*framewidth) * (m_columncount*5.0)/(7*m_rowcount)) ) / 2;
       y_margin = 0;
    }
    else if((width-2*framewidth) / (height-2*framewidth) < m_columncount*5.0/(7*m_rowcount))
    {
        y_margin = ( (height-2*framewidth) - ((width-2*framewidth) * (7.0*m_rowcount)/(m_columncount*5)) ) / 2;
        x_margin = 0;
    }
    else
    {
        x_margin = 0;
        y_margin = 0;
    }
    double diam = (width - 2*framewidth - 2*x_margin) / (m_columncount*(5+ 5.0/DIAMETER_GAP_RATIO ));
    double gap = diam/DIAMETER_GAP_RATIO;

    painter.setBrush( QBrush(m_dotoncolor));
        for (int j=0, k=0; j<7*m_rowcount; j++)
            for (int i = 0; i<5*m_columncount; i++,k++)
            {
                if(m_dotbuffer[k])
                    painter.drawEllipse( QPointF(framewidth+x_margin + gap/2 + diam/2 + i * (gap + diam), framewidth+y_margin + gap/2 + diam/2 + j * (gap + diam)), diam/2, diam/2 );
            }
        painter.setBrush( QBrush(m_dotoffcolor));
        for (int j=0, k=0; j<7*m_rowcount; j++)
            for (int i = 0; i<5*m_columncount; i++,k++)
            {
                if(!m_dotbuffer[k])
                    painter.drawEllipse( QPointF(framewidth+x_margin + gap/2 + diam/2 + i * (gap + diam), framewidth+y_margin + gap/2 + diam/2 + j * (gap + diam)), diam/2, diam/2 );
            }
}

void QDotMatrixDisplay::updateCharactersBuffer()
{
    if (m_text.size() > m_rowcount*m_columncount)
        m_characterbuffer.resize(m_text.size());
    else
        m_characterbuffer.resize(m_rowcount*m_columncount);

    for (int k = 0; k < m_text.size(); k++)
    {
        m_characterbuffer[k].resize(7);
        for (int j = 0; j<7; j++)
        {
            if(m_text[k] >= ' ' && m_text[k] <= '~')    //mapa de caracteres actualmente soportado
                m_characterbuffer[k][j] = m_charsvector[m_text[k].toLatin1()-' '][j];
            else
                m_characterbuffer[k][j] = 0x00;
        }
    }
//si el buffer de caracteres es menor que el tamaño del display, relleno con espacios en blanco
    for (int k = m_text.size(); k <  m_rowcount*m_columncount; k++)
    {
        m_characterbuffer[k].resize(7);
        for (int j = 0; j<7; j++)
            m_characterbuffer[k][j] = 0x00;
    }

}

void QDotMatrixDisplay::updateDotsBuffer()
{
    m_dotbuffer.resize(7*5*m_columncount*m_rowcount);

    for (int k = 0; k < m_rowcount*m_columncount; k++)
        for (int j = 0; j<7; j++)
            for (int i = 0; i<5; i++)
                if(m_characterbuffer[k][j] & (1<<(4-i)))
                    m_dotbuffer[i+(k%m_columncount)*5+j*5*m_columncount+k/m_columncount*5*7*m_columncount] = true;
                else
                    m_dotbuffer[i+(k%m_columncount)*5+j*5*m_columncount+k/m_columncount*5*7*m_columncount] = false;
}

int QDotMatrixDisplay::columnCount() const
{
    return m_columncount;
}

void QDotMatrixDisplay::setColumnCount(int columncount)
{
    m_columncount = columncount;

    updateCharactersBuffer();
    updateDotsBuffer();
    repaint();
}

int QDotMatrixDisplay::rowCount() const
{
    return m_rowcount;
}

void QDotMatrixDisplay::setRowCount(int rowcount)
{
    m_rowcount = rowcount;

    updateCharactersBuffer();
    updateDotsBuffer();
    repaint();
}

QString QDotMatrixDisplay::text() const
{
    return m_text;
}

void QDotMatrixDisplay::setText(const QString & text)
{
    m_text = text;
    m_dotbuffer.resize(7*5*m_columncount*m_rowcount);
    if (m_text.size() > m_rowcount*m_columncount)
        m_characterbuffer.resize(m_text.size());
    else
        m_characterbuffer.resize(m_rowcount*m_columncount);
    updateCharactersBuffer();
    updateDotsBuffer();
    repaint();
}

QColor QDotMatrixDisplay::dotONColor() const
{
    return m_dotoncolor;
}

void QDotMatrixDisplay::setDotONColor(const QColor & color)
{
    m_dotoncolor = color;
    repaint();
}

QColor QDotMatrixDisplay::dotOFFColor() const
{
    return m_dotoffcolor;
}

void QDotMatrixDisplay::setDotOFFColor(const QColor & color)
{
    m_dotoffcolor = color;
    repaint();
}

void QDotMatrixDisplay::RotateLeft(int dots)
{
    int character_offset = dots/5;

    for (int k = 0; k < 7; k++)
    {
        QVector<unsigned char> aux;
        //copia
        aux.resize(m_characterbuffer.size());
        for(int j = 0; j <  m_characterbuffer.size(); j++)
            aux[j] = m_characterbuffer[j][k];
        for(int j = 0; j <  m_characterbuffer.size(); j++)
        {
            m_characterbuffer[j][k] = (aux[(j+character_offset)%m_characterbuffer.size()]<<(dots%5)) & 0x1F;
            m_characterbuffer[j][k] |= ((aux[(j+1+character_offset)%m_characterbuffer.size()]<<(dots%5)) & 0x3E0) >> 5;
        }
    }
    updateDotsBuffer();
    repaint();
}

void QDotMatrixDisplay::RotateRight(int dots)
{
    int character_offset = (dots/5) % m_characterbuffer.size();

    for (int k = 0; k < 7; k++)
    {
        QVector<unsigned char> aux;
        //copia
        aux.resize(m_characterbuffer.size());
        for(int j = 0; j <  m_characterbuffer.size(); j++)
            aux[j] = m_characterbuffer[j][k];
        for(int j = 0; j <  m_characterbuffer.size(); j++)
        {
            m_characterbuffer[j][k] = (aux[(j-character_offset + m_characterbuffer.size())%m_characterbuffer.size()]>>(dots%5)) & 0x1F;
            m_characterbuffer[j][k] |= (aux[(j-1-character_offset + m_characterbuffer.size())%m_characterbuffer.size()]<<(5-dots%5)) & 0x1F;
        }
    }
    updateDotsBuffer();
    repaint();
}

void QDotMatrixDisplay::RotateUp(int dots)
{
    //rotacion de texto completo
    for (int k = 0; k < m_characterbuffer.size(); k++)
    {
        //copia
        QVector<unsigned char> aux = m_characterbuffer[k];//  (m_characterbuffer[j*m_columncount+k]);

        for(int j = 0; j < 7 ; j++)
        {
            m_characterbuffer[k][j] = aux[(j+dots)%7];
        }
    }


    updateDotsBuffer();
    repaint();
}

void QDotMatrixDisplay::RotateDown(int dots)
{
    int vertical_offset = dots % 7;

    //rotacion de texto completo
    for (int k = 0; k < m_characterbuffer.size(); k++)
    {
        //copia
        QVector<unsigned char> aux = m_characterbuffer[k];//  (m_characterbuffer[j*m_columncount+k]);

        for(int j = 0; j < 7 ; j++)
        {
            m_characterbuffer[k][j] = aux[(j-vertical_offset+7)%7];
        }
    }

    updateDotsBuffer();
    repaint();
}

void QDotMatrixDisplay::RotateReset()
{
    updateCharactersBuffer();
    updateDotsBuffer();
    repaint();
}

void QDotMatrixDisplay::setAutoRotation(AutoRotation mode, int msec)
{
    if(mode == NoRotation)
    {
        if (m_autorotation_timer)
        {
            delete m_autorotation_timer;
            m_autorotation_timer = NULL;
        }
    }
    else
    {
        m_autorotation_mode = mode;
        m_autorotation_interval = msec;
        if (!m_autorotation_timer)
        {
            m_autorotation_timer = new QTimer(this);
            connect(m_autorotation_timer,SIGNAL(timeout()),this,SLOT(on_m_autorotation_timer_timeout()));
        }
        m_autorotation_timer->start(msec);
    }
}

void QDotMatrixDisplay::on_m_autorotation_timer_timeout()
{
    switch(m_autorotation_mode)
    {
    case RotationRight: RotateRight(1); break;
    case RotationLeft: RotateLeft(1); break;
    case RotationUp: RotateUp(1); break;
    case RotationDown: RotateDown(1); break;
    default: break;
    }
}
