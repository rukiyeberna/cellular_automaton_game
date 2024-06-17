#pragma once 

/*simulasyon class i grid tutmali*/
#include "izgara.hpp"

class Simulasyon 
{
    public:
        /*constructor ekleyelim*/
        Simulasyon(int genislik, int yukseklik, int hucreBoyutu)
        /*Initializer list*/
        : izgara(genislik,yukseklik,hucreBoyutu) 
        {

        };
        void Cizim();
        void DegerEkle(int satir, int sutun, int deger);
        int CanliKomsularimiSay(int satir,int sutun);
    private:
        /*attribute ekleyelim*/
        Izgara izgara;

};      
