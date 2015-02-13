#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <cmath>
#include <fstream>
#include "config.h"
#include "PartArray.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    config::Instance()->set2D();
    config::Instance()->randmode_standart();
    config::Instance()->srand(time(NULL));
    
    config::Instance()->ergGauss = 3e7 * 927.400915e-23; //3*10^-7 - намагниченность одной частицы (магн. Бора), 9274e-24 - эрг/Гс в обном Боре
    config::Instance()->santiMeter = 1E-7; //перевод нанометров в сантиметры
    double multiplier = pow(config::Instance()->ergGauss,2.)/pow(config::Instance()->santiMeter,3.); //множитель для вычисления энергии в ЭРГах
    
    int w=80,h=220;//высота и ширина частицы
    int d=2200; //параметр решетки
    int cell=3; //количество ячеек
    int l = (cell*d)+w+1; //высота и ширина решетки (4 ячейки всего)
    PartArray *sys= new PartArray(l,l,1);
    sys->dropSpinIce(w,h,d);
    cout<<"n="<<sys->count()<<"; d="<<d<<endl;

    double eInit = sys->calcEnergy1FastIncrementalFirst();
    ofstream f(QString("statsumm_%1_%2.dat").arg(sys->count()).arg(d).toStdString().c_str());
    double e;
    Vect m;
    
    do {
        e = sys->calcEnergy1FastIncremental(eInit);
        //e=round(e*1.0e15)/1.0e15;
        f<<e*multiplier<<"\t";
        m = sys->M();
        m*=config::Instance()->ergGauss;
        f<<m.x<<"\t"<<m.y<<endl;

    } while (sys->state->next());

    delete sys;
    f.close();
    cout<<"finish!"<<endl;

    return a.exec();
}
