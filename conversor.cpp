#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);

    // Conectar el dial de Centrigados con el slot de esta clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));

    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kelv(int)));


    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2cent(int)));

    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2kelv(int)));


    connect(ui->inKelv, SIGNAL(valueChanged(int)),
            this, SLOT(kelv2cent(int)));

    connect(ui->inKelv, SIGNAL(valueChanged(int)),
            this, SLOT(kelv2fahr(int)));
}

Conversor::~Conversor()
{
    delete ui;
}

// Centigrados.
void Conversor::cent2fahr(int grados)
{
    if (ui->inCent->hasFocus()){
        int cf = (grados * 9.0/5) + 32;
        ui->inFahr->setValue(cf);
    }

}

void Conversor::cent2kelv(int grados)
{
    if (ui->inCent->hasFocus()){
        int ck = (grados + 273.15);
        ui->inKelv->setValue(ck);
    }

}
 // Farengeit


void Conversor::fahr2cent(int grados)
{
    if (ui->inFahr->hasFocus()){
        int fc = (grados - 32) * 5.0/9;
        ui->inCent->setValue(fc);
    }

}

void Conversor::fahr2kelv(int grados)
{
    if (ui->inFahr->hasFocus()){
        int fk = ((grados - 32) * 5.0/9)+ 273.15;
        ui->inKelv->setValue(fk);
    }

}

// Kelvin

void Conversor::kelv2cent(int grados)
{
    if (ui->inKelv->hasFocus()){
        int kc = (grados - 273.15);
        ui->inCent->setValue(kc);
    }
}

void Conversor::kelv2fahr(int grados)
{
    if (ui->inKelv->hasFocus()){
        int kf = ((grados - 273.15) * 9.0/5) + 32;
        ui->inFahr->setValue(kf);
    }
}
