#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

#include <QQueue>

#include <qextserialport.h>

#include <QList>
#include <QMap>

#include <QPointer>

#include <QDateTime>
#include <qdotmatrixdisplay.h>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QextSerialPort *m_port;
    QLabel *m_status_bytes_recibidos;
    QDotMatrixDisplay *m_dotdisplay_EXP4;
    int m_cant_bytes_recibidos;
    int m_cant_bytes_enviados;

public:
    enum ColorRGB
    {
        RGB_R, RGB_G, RGB_B
    };

    struct EstadoGeneral
    {
        EstadoGeneral()
        {
            expansion = 3;
            for (int i = 0; i < 8; i++)
            {
                if (i < 2)
                    inputs[i] = false;
                if (i < 4)
                    leds_relays[i] = false;

                keys[i] = false;
                leds[i] = false;
                DIPinputs[i] = false;
            }

            seg7[0] = 123;
            seg7[1] = 456;

            adc = 0;
            dac = 0;
            rgb_r = false;
            rgb_g = false;
            rgb_b = false;
            buzzer = false;

            lcd[0] = "INFORMATICA II";
            lcd[1] = "    INFOTRONIC";

            dotmatrix_text = "INFO";
            dotmatrix_rotation = 4;

            expansion = 0;
        }
        int expansion;
        bool leds_relays[4];
        bool rgb_r;
        bool rgb_g;
        bool rgb_b;
        bool buzzer;
        bool DIPinputs[8];
        bool inputs[2];
        int seg7[2];
        QString dotmatrix_text;
        int dotmatrix_rotation;
        QString lcd[2];
        bool keys[8];
        int adc;
        int dac;
        bool leds[8];
        QDateTime rtc;
    } m_estado_general;

    bool m_init;

public:
    void EnumerarPuertos();
    void ActualizarEstadoConexion();

    void CerrarPuerto();

    bool Conectado();
    void NoConectadoError();
    void UpdateBytesTotales();

    void UpdateTodo();

    void UpdateLedRelay(int idx);
    void UpdateLedRelayEstado(QPushButton* relay, bool m_estado);
    void InvertirLedRelay(int idx);

    void EnviarComando(QString comando);
    void InvertirLED(int idx);
    void UpdateLED(int idx);
    void UpdateLEDEstado(QPushButton *led, bool estado);
    void PedirExpansion();
    void SetExpansion(int idx);

    void SetLCD(int idx, QString txt, bool update = true);
    void Set7Seg(int idx, QString txt, bool update = true, bool send = true);
    void SetMatricial(QString txt, bool send = true);
    void SetRotacionMatricial(int rot, bool send);
    void SetADC(int val);
    void SetDAC(int val);
    void SetRGB(ColorRGB color, bool estado);
    void SetEntrada(int idx, bool val);
    void SetEntradaDIP(int idx, bool val);
    void SetRTC(QDateTime horafecha, bool update = true, bool send = true);
    void SetBuzzer(bool estado);

    void UpdateLCD(int idx);
    void Update7Seg(int idx, bool both = true);
    void UpdateMatricial();
    void UpdateRotacionMatricial();
    void UpdateADC();
    void UpdateDAC();
    void UpdateRGB();
    void UpdateEntrada(int idx);
    void UpdateEntradaDIP(int idx);
    void UpdateTeclado(int idx, bool pressed = true);
    void UpdateTeclas(int idx, bool pressed = true);
    void UpdateRTC();

    void PressTeclado(int idx, int corto = true);
    void PressTeclas(int idx, int corto = true);
    void UpdateTabs();

    QQueue<int> m_teclado_cola;
    QQueue<int> m_teclas_cola;
    QByteArray m_datos_recibidos;

    void ProcesarComandos();
    void ProcesarComando(QString comando);
    void TitilarTeclado(int idx, int corto = true);
    void TitilarTeclas(int idx, int corto = true);


private slots:
    void onDatosRecibidos();

    void on_button_connect_clicked();

    void on_button_relay_1_clicked();
    void on_button_relay_2_clicked();
    void on_button_relay_3_clicked();
    void on_button_relay_4_clicked();

    void on_checkBox_RGBR_clicked(bool checked);
    void on_checkBox_RGBG_clicked(bool checked);
    void on_checkBox_RGBB_clicked(bool checked);
    void on_checkBox_buzzer_clicked(bool checked);

    void on_button_refresh_ports_clicked();

    void on_edit_lcd_1_textChanged(QString txt);
    void on_edit_lcd_2_textChanged(QString txt);

    void on_edit_7seg_izqEXP2_textChanged(QString txt);
    void on_edit_7seg_derEXP2_textChanged(QString txt);

    void on_edit_7seg_izqEXP3_textChanged(QString txt);
    void on_edit_7seg_derEXP3_textChanged(QString txt);

    void on_edit_matricial_EXP4_textChanged(const QString txt);

    void on_horizontalSlider_valueChanged(int value);

    void on_button_tecla_0_clicked();
    void on_button_tecla_1_clicked();
    void on_button_tecla_2_clicked();
    void on_button_tecla_3_clicked();
    void on_button_tecla_4_clicked();

    void on_button_teclaEXP3_0_clicked();
    void on_button_teclaEXP3_1_clicked();
    void on_button_teclaEXP3_2_clicked();
    void on_button_teclaEXP3_3_clicked();
    void on_button_teclaEXP3_4_clicked();
    void on_button_teclaEXP3_5_clicked();
    void on_button_teclaEXP3_6_clicked();
    void on_button_teclaEXP3_7_clicked();

    void on_button_teclaEXP4_1_clicked();
    void on_button_teclaEXP4_3_clicked();
    void on_button_teclaEXP4_5_clicked();
    void on_button_teclaEXP4_4_clicked();
    void on_button_teclaEXP4_7_clicked();

    void on_button_led1_EXP1_clicked();
    void on_button_led2_EXP1_clicked();
    void on_button_led3_EXP1_clicked();
    void on_button_led4_EXP1_clicked();
    void on_button_led5_EXP1_clicked();
    void on_button_led6_EXP1_clicked();
    void on_button_led7_EXP1_clicked();
    void on_button_led8_EXP1_clicked();

    void on_pushButton_sendrtc_clicked();
    void on_pushButton_systemtime_clicked();

    void ResetTeclado();
    void ResetTeclas();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
