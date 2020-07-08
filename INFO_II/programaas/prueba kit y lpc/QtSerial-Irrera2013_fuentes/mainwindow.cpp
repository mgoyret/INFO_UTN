#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qextserialenumerator.h>

#include <QMessageBox>
#include <QDebug>

#include <QTimer>


#define SS_RELAY_ON         "background-color: yellow; color: black; font-weight: bold;"
#define SS_RELAY_OFF        "background-color: brown; color: white; font-weight: normal;"

#define SS_LED_ON           "background-color: red; color: white; font-weight: bold;"
#define SS_LED_OFF          "background-color: black; color: white; font-weight: normal;"

#define SS_TECLA_PRESS      "background-color: blue; border: 2px solid lightblue;"
#define SS_TECLA_RELEASE	"background-color: none;"

#define SS_INPUT_ON         "background-color: green;"
#define SS_INPUT_OFF        "background-color: red;"

#define LOG_MAXCOUNT    500

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_port(NULL), m_cant_bytes_recibidos(0),
    m_cant_bytes_enviados(0), ui(new Ui::MainWindow)
{
    m_init = true;

    ui->setupUi(this);

    UpdateTabs();

    EnumerarPuertos();
    ActualizarEstadoConexion();

    //Inicializar el display matricial
    m_dotdisplay_EXP4 = new QDotMatrixDisplay(4, 1, ui->groupBox_displayEXP4);
    m_dotdisplay_EXP4->setGeometry(QRect(30, 30, 440, 154));
    m_dotdisplay_EXP4->setStyleSheet(QString::fromUtf8("background-color: black; border: 2px solid red;"));
    m_dotdisplay_EXP4->setText("INFO");

    //Inicializar panel de la status bar
    m_status_bytes_recibidos = new QLabel;
    ui->statusBar->addWidget(m_status_bytes_recibidos);

    UpdateBytesTotales();

    UpdateTodo();

    m_init = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTabs()
{
    bool enable = Conectado();

    ui->tabWidget->setTabEnabled(1, enable);
    //ui->tabWidget->setTabEnabled(2, enable);
    ui->tab_estado_general->setDisabled(!enable);
    //ui->tab_grafico_adc->setDisabled(!enable);
}

void MainWindow::EnumerarPuertos()
{
    ui->comboBox_puertos->clear();

    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();

    for (int i = 0; i < ports.size(); i++)
    {

    #ifdef Q_OS_WIN
        ui->comboBox_puertos->addItem(ports.at(i).friendName, ports.at(i).portName);
    #elif (defined Q_OS_UNIX)
        ui->comboBox_puertos->addItem(ports.at(i).friendName, ports.at(i).physName);
    #endif

        /*qDebug() << "port name:" << ports.at(i).portName;
        qDebug() << "friendly name:" << ports.at(i).friendName;
        qDebug() << "physical name:" << ports.at(i).physName;
        qDebug() << "enumerator name:" << ports.at(i).enumName;
        qDebug() << "vendor ID:" << QString::number(ports.at(i).vendorID, 16);
        qDebug() << "product ID:" << QString::number(ports.at(i).productID, 16);*/
    }
}

void MainWindow::UpdateLCD(int idx)
{
    if (idx == 0)
        ui->edit_lcd_1->setText(m_estado_general.lcd[idx]);
    else if (idx == 1)
        ui->edit_lcd_2->setText(m_estado_general.lcd[idx]);
}

void MainWindow::Update7Seg(int idx, bool both /*= true*/)
{
    QString aux;

    if (idx == 0)
    {
        if(m_estado_general.expansion == 1)
            ui->seg7_izqEXP2->display(aux.sprintf("%03d", m_estado_general.seg7[idx]));
        else
            ui->seg7_izqEXP3->display(aux.sprintf("%03d", m_estado_general.seg7[idx]));

        if (both)
        {
            if(m_estado_general.expansion == 1)
                ui->edit_7seg_izqEXP2->setText(QString::number(m_estado_general.seg7[idx]));
            else
                ui->edit_7seg_izqEXP3->setText(QString::number(m_estado_general.seg7[idx]));
        }
    }
    else if (idx == 1)
    {
        if(m_estado_general.expansion == 1)
            ui->seg7_derEXP2->display(aux.sprintf("%03d", m_estado_general.seg7[idx]));
        else
            ui->seg7_derEXP3->display(aux.sprintf("%03d", m_estado_general.seg7[idx]));

        if (both)
        {
            if(m_estado_general.expansion == 1)
                ui->edit_7seg_derEXP2->setText(QString::number(m_estado_general.seg7[idx]));
            else
                ui->edit_7seg_derEXP3->setText(QString::number(m_estado_general.seg7[idx]));
        }
    }
}

void MainWindow::UpdateMatricial()
{
    m_dotdisplay_EXP4->setText(m_estado_general.dotmatrix_text);
}

void MainWindow::UpdateRotacionMatricial()
{
    switch (m_estado_general.dotmatrix_rotation)
    {
    case 0: m_dotdisplay_EXP4->setAutoRotation(QDotMatrixDisplay::RotationRight, 100); break;
    case 1: m_dotdisplay_EXP4->setAutoRotation(QDotMatrixDisplay::RotationLeft, 100); break;
    case 2: m_dotdisplay_EXP4->setAutoRotation(QDotMatrixDisplay::RotationUp, 500); break;
    case 3: m_dotdisplay_EXP4->setAutoRotation(QDotMatrixDisplay::RotationDown, 500); break;
    case 4: m_dotdisplay_EXP4->setAutoRotation(QDotMatrixDisplay::NoRotation,100 ); break;
    }
}

void MainWindow::UpdateLedRelay(int idx)
{
    switch (idx)
    {
    case 0: UpdateLedRelayEstado(ui->button_relay_1, m_estado_general.leds_relays[idx]); break;
    case 1: UpdateLedRelayEstado(ui->button_relay_2, m_estado_general.leds_relays[idx]); break;
    case 2: UpdateLedRelayEstado(ui->button_relay_3, m_estado_general.leds_relays[idx]); break;
    case 3: UpdateLedRelayEstado(ui->button_relay_4, m_estado_general.leds_relays[idx]); break;
    }
}

void MainWindow::UpdateLED(int idx)
{
    switch (idx)
    {
    case 0: UpdateLEDEstado(ui->button_led1_EXP1, m_estado_general.leds[idx]); break;
    case 1: UpdateLEDEstado(ui->button_led2_EXP1, m_estado_general.leds[idx]); break;
    case 2: UpdateLEDEstado(ui->button_led3_EXP1, m_estado_general.leds[idx]); break;
    case 3: UpdateLEDEstado(ui->button_led4_EXP1, m_estado_general.leds[idx]); break;
    case 4: UpdateLEDEstado(ui->button_led5_EXP1, m_estado_general.leds[idx]); break;
    case 5: UpdateLEDEstado(ui->button_led6_EXP1, m_estado_general.leds[idx]); break;
    case 6: UpdateLEDEstado(ui->button_led7_EXP1, m_estado_general.leds[idx]); break;
    case 7: UpdateLEDEstado(ui->button_led8_EXP1, m_estado_general.leds[idx]); break;
    }
}

void MainWindow::UpdateDAC()
{
    ui->label_dac->setText(QString::number(m_estado_general.dac));
}

void MainWindow::UpdateTodo()
{
    for (int i = 0; i < 8; i++)
    {
        if (i < 2)
        {
            UpdateLCD(i);
            Update7Seg(i);
            UpdateEntrada(i);
        }

        if (i < 4)
        {
            UpdateLedRelay(i);
        }

        UpdateLED(i);
    }
    UpdateMatricial();
}

void MainWindow::UpdateLedRelayEstado(QPushButton* relay, bool estado)
{
    relay->setStyleSheet(estado?SS_RELAY_ON:SS_RELAY_OFF);
}

void MainWindow::UpdateLEDEstado(QPushButton* led, bool estado)
{
    led->setStyleSheet(estado?SS_LED_ON:SS_LED_OFF);
}

void MainWindow::on_button_connect_clicked()
{
    if (!m_port)	//Si no hay conexión activa
    {
        //Obtenemos el nombre del puerto
        QString sPort;
        int i = ui->comboBox_puertos->currentIndex();
        if (i != -1 && ui->comboBox_puertos->itemText(i) == ui->comboBox_puertos->currentText())
            sPort = ui->comboBox_puertos->itemData(i).toString();
        else
            sPort = ui->comboBox_puertos->currentText();

        if(sPort.isEmpty())
        {
            QMessageBox::critical(this, QString::fromUtf8("Error de conexión"), QString::fromUtf8("Seleccione un puerto válido"));
            return;
        }

        //Abrimos el puerto en modo "EventDriven". También podría ser en modo "Polling".
        m_port = new QextSerialPort(sPort, QextSerialPort::EventDriven);

        m_port->setBaudRate(BAUD9600);		//9600 baud
        m_port->setFlowControl(FLOW_OFF);	//Sin control de flujo
        m_port->setParity(PAR_NONE);		//Sin paridad
        m_port->setDataBits(DATA_8);		//8 bits de datos
        m_port->setStopBits(STOP_1);		//1 bit de stop

        if (m_port->open(QIODevice::ReadWrite) == true)	//Abrimos el puerto en modo lectura-escritura
        {
            //Conectamos las señales que nos interesen
            connect(m_port, SIGNAL(readyRead()), this, SLOT(onDatosRecibidos()));
            //connect(m_port, SIGNAL(dsrChanged(bool)), this, SLOT(onDsrChanged(bool)));	//Podríamos conectar una señal para saber cuando cambie el DSR

            //if (!(m_port->lineStatus() & LS_DSR))		//Control de DSR
            //	qDebug() << "warning: device is not turned on";

            ui->tabWidget->setCurrentIndex(1);
        }
        else
            CerrarPuerto();
    }
    else	//Si no, cerramos la conexión
        CerrarPuerto();

    ActualizarEstadoConexion();
    UpdateTabs();
    PedirExpansion();
}

void MainWindow::CerrarPuerto()
{
    m_port->close();
    delete m_port;
    m_port = NULL;
}

void MainWindow::ActualizarEstadoConexion()
{
    if (Conectado())
    {
        ui->edit_estado->setStyleSheet("font-weight: bold; color: black; background-color: lightgreen;");
        ui->edit_estado->setText("CONECTADO");
        ui->button_connect->setText("Desconectar");
    }
    else
    {
        ui->edit_estado->setStyleSheet("font-weight: normal; color: white; background-color: red;");
        ui->edit_estado->setText("Desconectado");
        ui->button_connect->setText("Conectar");
    }
}

void MainWindow::PedirExpansion()
{
    if (Conectado())
        EnviarComando("E");
}

void MainWindow::on_button_relay_1_clicked()
{
    if (Conectado())
        InvertirLedRelay(0);
    else
        NoConectadoError();
}

void MainWindow::on_button_relay_2_clicked()
{
    if (Conectado())
        InvertirLedRelay(1);
    else
        NoConectadoError();
}

void MainWindow::on_button_relay_3_clicked()
{
    if (Conectado())
        InvertirLedRelay(2);
    else
        NoConectadoError();
}

void MainWindow::on_button_relay_4_clicked()
{
    if (Conectado())
        InvertirLedRelay(3);
    else
        NoConectadoError();
}

void MainWindow::EnviarComando(QString comando)
{
    //Controlar si en modo socket o rs232
    qDebug() << comando;

    QByteArray send = (comando + "\r\n").toLatin1();

    m_port->write(send);

    ui->list_log_enviados->addItem(comando);

    //ui->list_log_enviados->scrollTo(ui->list_log_enviados->item(ui->list_log_enviados->count()-1));
    ui->list_log_enviados->setCurrentRow(ui->list_log_enviados->count()-1);

    if(ui->list_log_enviados->count() > LOG_MAXCOUNT)
        for(int i=0;i<LOG_MAXCOUNT/5;i++)
            delete ui->list_log_enviados->takeItem(i);

    m_cant_bytes_enviados += send.size();
}

void MainWindow::InvertirLedRelay(int idx)
{
    m_estado_general.leds_relays[idx] = !m_estado_general.leds_relays[idx];

    EnviarComando("3" + QString::number(idx) + (m_estado_general.leds_relays[idx]?"1":"0"));

    UpdateLedRelay(idx);
}

void MainWindow::InvertirLED(int idx)
{
    m_estado_general.leds[idx] = !m_estado_general.leds[idx];

    EnviarComando("8" + QString::number(idx) + (m_estado_general.leds[idx]?"1":"0"));

    UpdateLED(idx);
}

QString FijarAnchoString(QString str, int ancho)
{
    if (str.size() == ancho)
        return str;
    else if (str.size() > ancho)
        return str.mid(0, ancho);
    else
        while (str.size() < ancho)
            str += ' ';

    return str;
}

void MainWindow::SetLCD(int idx, QString txt, bool update /*= true*/)
{
    txt = FijarAnchoString(txt, 16);

    m_estado_general.lcd[idx] = txt;

    EnviarComando(QString::number(idx + 1) + txt);

    if (update)
        UpdateLCD(idx);
}

void MainWindow::Set7Seg(int idx, QString txt, bool update /*= true*/, bool send /*= true*/)
{
    m_estado_general.seg7[idx] = txt.toInt();

    if (send)
    {
        txt.sprintf("%3d", txt.toInt());
        EnviarComando(QString::number(6 - idx) + txt);
    }

    Update7Seg(idx, update);
}

void MainWindow::SetMatricial(QString txt, bool send /*= true*/)
{
    m_estado_general.dotmatrix_text = txt;

    if (send)
        EnviarComando(QString("9") + txt);

    UpdateMatricial();
}

void MainWindow::SetRotacionMatricial(int rot, bool send /*= true*/)
{
    m_estado_general.dotmatrix_rotation = rot;

    if (send)
        EnviarComando("A" + QString::number(rot));

    UpdateRotacionMatricial();
}

void MainWindow::SetDAC(int val)
{
    m_estado_general.dac = val;

    EnviarComando("7" + QString::number(val));

    UpdateDAC();
}

bool MainWindow::Conectado()
{
    return m_port && m_port->isOpen();
}

void MainWindow::NoConectadoError()
{
    if (!m_init)
        QMessageBox::warning(this, QString::fromUtf8("Error de conexión"), "No conectado");
}

void MainWindow::onDatosRecibidos()
{
    QByteArray bytes;
    int cant = m_port->bytesAvailable();
    bytes.resize(cant);

    m_port->read(bytes.data(), bytes.size());

    m_datos_recibidos += bytes;

    /*qDebug() << "bytes read:" << bytes.size();
    qDebug() << "bytes:" << bytes;*/

    ui->text_log->appendPlainText(bytes);
    ui->text_log->moveCursor(QTextCursor::End);

    m_cant_bytes_recibidos += cant;

    UpdateBytesTotales();

    ProcesarComandos();
}

void MainWindow::ProcesarComandos()
{
    QString comando;

    for (int i = 0; i < m_datos_recibidos.count(); i++)
    {
        unsigned char dato = m_datos_recibidos[i];

        switch (dato)
        {
            case '\n':
            case '\r':
                if (comando != "")
                {
                    ProcesarComando(comando);
                    comando = "";
                }
                break;
            default:
                comando += dato;
                break;
        }
    }

    m_datos_recibidos = comando.toLatin1();
}

void MainWindow::ProcesarComando(QString comando)
{
    ui->list_log->addItem(comando);
    ui->list_log->setCurrentRow(ui->list_log->count()-1);

    if(ui->list_log->count() > LOG_MAXCOUNT)
        for(int i=0;i<LOG_MAXCOUNT/5;i++)
            delete ui->list_log->takeItem(i);

    unsigned char base = comando[0].toLatin1();

    switch (base)
    {
        case 'E':
            SetExpansion(comando.mid(1, -1).toInt());
            break;
        case '0':
        {
            unsigned char teclado = comando[1].toLatin1();

            if(m_estado_general.expansion == 1 || m_estado_general.expansion == 2)
            {
                const int teclas[8] = {0, 4, 1, 5, 2, 6, 3, 7};
                TitilarTeclado(teclas[teclado - '0'], false);
                Set7Seg(0, comando.mid(2, -1), true, false);
            }
            else if(m_estado_general.expansion == 3)
            {
                const int teclas[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};
                TitilarTeclado(teclas[teclado - '0'], false);
                switch(teclas[teclado - '0'])
                {
                case 3: SetRotacionMatricial(2, false); break;
                case 5: SetRotacionMatricial(3, false); break;
                case 1: SetRotacionMatricial(1, false); break;
                case 7: SetRotacionMatricial(0, false); break;
                case 4: SetRotacionMatricial(4, false); break;
                }
            }
            break;
        }
        case '1':
        {
            unsigned char tecla = comando[1].toLatin1();
            TitilarTeclas(tecla - '0', false);
            Set7Seg(1, comando.mid(1, -1), true, false);
            break;
        }
        case '2':
            SetADC(comando.mid(1, -1).toInt());
            break;
        case '3':
        {
            int entradas = comando.mid(1, -1).toInt();
            for (int i = 0; i < 2; i++)
                SetEntrada(i, entradas & (0x01 << i));
            break;
        }
        case '4':
        {
            int entradas = comando.mid(1, -1).toInt();
            for (int i = 0; i < 8; i++)
                SetEntradaDIP(i, entradas & (0x01 << i));
            break;
        }
        case 'B':
        {
            SetRTC(QDateTime::fromString(comando.mid(1,-1),"ssmmHHddMMyyyy"), true, false);
            break;
        }
    }
}

void MainWindow::SetExpansion(int idx)
{
    m_estado_general.expansion = idx;
    for (int i = 0; i < ui->tabWidget_expansiones->count(); i++)
    {
        if(i!=idx)
            ui->tabWidget_expansiones->setTabEnabled(i,false);
    }
    ui->tabWidget_expansiones->setTabEnabled(idx,true);
    ui->tabWidget_expansiones->setCurrentIndex(idx);
}

void MainWindow::SetADC(int val)
{
    m_estado_general.adc = val;

    UpdateADC();
}

void MainWindow::UpdateADC()
{
    ui->progressBar->setValue(m_estado_general.adc);
    ui->label_adc->setText(QString::number(m_estado_general.adc));
}

void MainWindow::SetEntrada(int idx, bool val)
{
    m_estado_general.inputs[idx] = val;

    UpdateEntrada(idx);
}

void MainWindow::SetEntradaDIP(int idx, bool val)
{
    m_estado_general.DIPinputs[idx] = val;

    UpdateEntradaDIP(idx);
}

void MainWindow::UpdateEntrada(int idx)
{
    QCheckBox *entrada = NULL;

    switch (idx)
    {
    case 0: entrada = ui->check_entrada_1; break;
    case 1: entrada = ui->check_entrada_2; break;
    }

    if (entrada)
    {
        bool on = m_estado_general.inputs[idx];

        entrada->setChecked(on);
        entrada->setStyleSheet(on?SS_INPUT_ON:SS_INPUT_OFF);
    }
}

void MainWindow::UpdateEntradaDIP(int idx)
{
    QCheckBox *entrada = NULL;

    switch (idx)
    {
    case 0: entrada = ui->checkBox_DIP1_EXP1; break;
    case 1: entrada = ui->checkBox_DIP2_EXP1; break;
    case 2: entrada = ui->checkBox_DIP3_EXP1; break;
    case 3: entrada = ui->checkBox_DIP4_EXP1; break;
    case 4: entrada = ui->checkBox_DIP5_EXP1; break;
    case 5: entrada = ui->checkBox_DIP6_EXP1; break;
    case 6: entrada = ui->checkBox_DIP7_EXP1; break;
    case 7: entrada = ui->checkBox_DIP8_EXP1; break;
    }

    if (entrada)
    {
        bool on = m_estado_general.DIPinputs[idx];
        entrada->setChecked(on);
    }
}

void MainWindow::UpdateTeclado(int idx, bool pressed /*= true*/)
{
    QPushButton* button = NULL;

    if(m_estado_general.expansion == 2)
        switch (idx)
        {
        case 0: button = ui->button_teclaEXP3_0; break;
        case 1: button = ui->button_teclaEXP3_1; break;
        case 2: button = ui->button_teclaEXP3_2; break;
        case 3: button = ui->button_teclaEXP3_3; break;
        case 4: button = ui->button_teclaEXP3_4; break;
        case 5: button = ui->button_teclaEXP3_5; break;
        case 6: button = ui->button_teclaEXP3_6; break;
        case 7: button = ui->button_teclaEXP3_7; break;
        }
    else if(m_estado_general.expansion == 3)
        switch (idx)
        {
        case 0: button = ui->button_teclaEXP4_0; break;
        case 1: button = ui->button_teclaEXP4_1; break;
        case 2: button = ui->button_teclaEXP4_2; break;
        case 3: button = ui->button_teclaEXP4_3; break;
        case 4: button = ui->button_teclaEXP4_4; break;
        case 5: button = ui->button_teclaEXP4_5; break;
        case 6: button = ui->button_teclaEXP4_6; break;
        case 7: button = ui->button_teclaEXP4_7; break;
        case 8: button = ui->button_teclaEXP4_8; break;
        }

    if (button)
        button->setStyleSheet(pressed?SS_TECLA_PRESS:SS_TECLA_RELEASE);
}

void MainWindow::UpdateTeclas(int idx, bool pressed /*= true*/)
{
    QPushButton* button = NULL;

    switch (idx)
    {
    case 0: button = ui->button_tecla_0; break;
    case 1: button = ui->button_tecla_1; break;
    case 2: button = ui->button_tecla_2; break;
    case 3: button = ui->button_tecla_3; break;
    case 4: button = ui->button_tecla_4; break;
    }

    if (button)
        button->setStyleSheet(pressed?SS_TECLA_PRESS:SS_TECLA_RELEASE);
}

void MainWindow::UpdateBytesTotales()
{
    m_status_bytes_recibidos->setText(QString::number(m_cant_bytes_recibidos) + " byte(s) recibidos, " + QString::number(m_cant_bytes_enviados) + " byte(s) enviados.");
}

void MainWindow::on_button_refresh_ports_clicked()
{
    EnumerarPuertos();
}

void MainWindow::on_edit_lcd_1_textChanged(QString txt)
{
    if (Conectado())
        SetLCD(0, txt, false);
    else
        NoConectadoError();
}

void MainWindow::on_edit_lcd_2_textChanged(QString txt)
{
    if (Conectado())
        SetLCD(1, txt, false);
    else
        NoConectadoError();
}

void MainWindow::on_edit_7seg_izqEXP3_textChanged(QString txt)
{
    if (Conectado())
        Set7Seg(0, txt, false, true);
    else
        NoConectadoError();
}

void MainWindow::on_edit_7seg_derEXP3_textChanged(QString txt)
{
    if (Conectado())
        Set7Seg(1, txt, false, true);
    else
        NoConectadoError();
}

void MainWindow::on_edit_7seg_izqEXP2_textChanged(const QString txt)
{
    if (Conectado())
        Set7Seg(0, txt, false, true);
    else
        NoConectadoError();
}

void MainWindow::on_edit_7seg_derEXP2_textChanged(const QString txt)
{
    if (Conectado())
        Set7Seg(1, txt, false, true);
    else
        NoConectadoError();
}

void MainWindow::PressTeclado(int idx, int corto /*= true*/)
{
    if(m_estado_general.expansion == 2)
    {
        QString txt;

        txt.sprintf("%3d", idx);

        Set7Seg(0, txt, true, false);
    }
    else  if(m_estado_general.expansion == 3)
    {
        switch(idx)
        {
        case 3: SetRotacionMatricial(2, true); break;
        case 5: SetRotacionMatricial(3, true); break;
        case 1: SetRotacionMatricial(1, true); break;
        case 7: SetRotacionMatricial(0, true); break;
        case 4: SetRotacionMatricial(4, true); break;
        }
    }

    TitilarTeclado(idx, corto);
}

void MainWindow::PressTeclas(int idx, int corto /*= true*/)
{
    QString txt;

    txt.sprintf("%3d", idx);

    if(m_estado_general.expansion == 1 || m_estado_general.expansion == 2)
        Set7Seg(1, txt, true, false);

    TitilarTeclas(idx, corto);
}

void MainWindow::TitilarTeclado(int idx, int corto /*= true*/)
{
    UpdateTeclado(idx, true);

    //Agregamos el índice de la tecla actual a la cola, para que luego la retire la función llamada por el timer
    m_teclado_cola.enqueue(idx);

    //Generamos un timer instantáneo que llamará al slot "ResetTeclado"
    QTimer::singleShot(corto?500:2000, this, SLOT(ResetTeclado()));
}

void MainWindow::TitilarTeclas(int idx, int corto /*= true*/)
{
    UpdateTeclas(idx, true);

    //Agregamos el índice de la tecla actual a la cola, para que luego la retire la función llamada por el timer
    m_teclas_cola.enqueue(idx);

    //Generamos un timer instantáneo que llamará al slot "ResetTeclas"
    QTimer::singleShot(corto?500:2000, this, SLOT(ResetTeclas()));
}

void MainWindow::on_button_teclaEXP3_0_clicked()
{
    if (Conectado())
        PressTeclado(0);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP3_1_clicked()
{
    if (Conectado())
        PressTeclado(1);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP3_2_clicked()
{
    if (Conectado())
        PressTeclado(2);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP3_3_clicked()
{
    if (Conectado())
        PressTeclado(3);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP3_4_clicked()
{
    if (Conectado())
        PressTeclado(4);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP3_5_clicked()
{
    if (Conectado())
        PressTeclado(5);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP3_6_clicked()
{
    if (Conectado())
        PressTeclado(6);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP3_7_clicked()
{
    if (Conectado())
        PressTeclado(7);
    else
        NoConectadoError();
}

void MainWindow::ResetTeclado()
{
    int idx = m_teclado_cola.dequeue();
    UpdateTeclado(idx, false);
}

void MainWindow::ResetTeclas()
{
    int idx = m_teclas_cola.dequeue();
    UpdateTeclas(idx, false);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if (Conectado())
        SetDAC(value);
    else
        NoConectadoError();
}

void MainWindow::on_checkBox_RGBR_clicked(bool checked)
{
     if (Conectado())
         SetRGB(RGB_R, checked);
     else
         NoConectadoError();
}

void MainWindow::on_checkBox_RGBG_clicked(bool checked)
{
    if (Conectado())
        SetRGB(RGB_G, checked);
    else
        NoConectadoError();
}

void MainWindow::on_checkBox_RGBB_clicked(bool checked)
{
    if (Conectado())
        SetRGB(RGB_B, checked);
    else
        NoConectadoError();
}

void MainWindow::on_checkBox_buzzer_clicked(bool checked)
{
    if (Conectado())
        SetBuzzer(checked);
    else
        NoConectadoError();
}

void MainWindow::SetBuzzer(bool estado)
{
    m_estado_general.buzzer = estado;
    EnviarComando("4" + QString("3") + (estado?"1":"0"));
}

void MainWindow::SetRGB(ColorRGB color, bool estado)
{
    switch(color)
    {
        case RGB_R:
             m_estado_general.rgb_r = estado; break;
        case RGB_G:
             m_estado_general.rgb_g = estado; break;
        case RGB_B:
             m_estado_general.rgb_b = estado; break;
    }

    EnviarComando("4" + QString::number((int)color) + (estado?"1":"0"));

    UpdateRGB();
}

void MainWindow::SetRTC(QDateTime horafecha, bool update /*= true*/, bool send /*= true*/)
{
    m_estado_general.rtc = horafecha;

    if (send)
    {
        QString comando;
        comando.sprintf("B%02d%02d%02d%02d%02d%04d\r",horafecha.time().second(),horafecha.time().minute(),horafecha.time().hour()\
                        ,horafecha.date().day(),horafecha.date().month(),horafecha.date().year());
        EnviarComando(comando);
    }

    if (update)
        UpdateRTC();
}

void MainWindow::UpdateRTC()
{
    if(!ui->dateTimeEdit->hasFocus())
        ui->dateTimeEdit->setDateTime(m_estado_general.rtc);
}

void MainWindow::UpdateRGB()
{
    ui->frame_RGB->setStyleSheet( QString("background-color: rgb(") + (m_estado_general.rgb_r?"255 ,":"0 ,") + (m_estado_general.rgb_g?"255 ,":"0 ,") + (m_estado_general.rgb_b?"255)":"0)") );
}

void MainWindow::on_button_led1_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(0);
    else
        NoConectadoError();
}

void MainWindow::on_button_led2_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(1);
    else
        NoConectadoError();
}

void MainWindow::on_button_led3_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(2);
    else
        NoConectadoError();
}

void MainWindow::on_button_led4_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(3);
    else
        NoConectadoError();
}

void MainWindow::on_button_led5_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(4);
    else
        NoConectadoError();
}

void MainWindow::on_button_led6_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(5);
    else
        NoConectadoError();
}

void MainWindow::on_button_led7_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(6);
    else
        NoConectadoError();
}

void MainWindow::on_button_led8_EXP1_clicked()
{
    if (Conectado())
        InvertirLED(7);
    else
        NoConectadoError();
}

void MainWindow::on_edit_matricial_EXP4_textChanged(const QString txt)
{
    if (Conectado())
        SetMatricial(txt, true);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP4_1_clicked()
{
    if (Conectado())
        PressTeclado(1);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP4_3_clicked()
{
    if (Conectado())
        PressTeclado(3);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP4_4_clicked()
{
    if (Conectado())
        PressTeclado(4);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP4_7_clicked()
{
    if (Conectado())
        PressTeclado(7);
    else
        NoConectadoError();
}

void MainWindow::on_button_teclaEXP4_5_clicked()
{
    if (Conectado())
        PressTeclado(5);
    else
        NoConectadoError();
}

void MainWindow::on_button_tecla_0_clicked()
{
    if (Conectado())
        PressTeclas(0);
    else
        NoConectadoError();
}

void MainWindow::on_button_tecla_1_clicked()
{
    if (Conectado())
        PressTeclas(1);
    else
        NoConectadoError();
}

void MainWindow::on_button_tecla_2_clicked()
{
    if (Conectado())
        PressTeclas(2);
    else
        NoConectadoError();
}

void MainWindow::on_button_tecla_3_clicked()
{
    if (Conectado())
        PressTeclas(3);
    else
        NoConectadoError();
}

void MainWindow::on_button_tecla_4_clicked()
{
    if (Conectado())
        PressTeclas(4);
    else
        NoConectadoError();
}


void MainWindow::on_pushButton_sendrtc_clicked()
{
    if (Conectado())
        SetRTC(ui->dateTimeEdit->dateTime(), false, true);
    else
        NoConectadoError();
}

void MainWindow::on_pushButton_systemtime_clicked()
{
    if (Conectado())
        SetRTC(QDateTime::currentDateTime(), true, true);
    else
        NoConectadoError();
}
