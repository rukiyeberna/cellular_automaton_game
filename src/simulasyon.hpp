#pragma once 

/*simulasyon class i grid tutmali*/
#include "izgara.hpp"

class Simulasyon 
{
    public:
        /*constructor ekleyelim*/
        Simulasyon(int genislik, int yukseklik, int hucreBoyutu)
        /*Initializer list*/
        : izgara(genislik,yukseklik,hucreBoyutu),
          kopyalanmisIzgara(genislik,yukseklik,hucreBoyutu)  
        {

        };
        void Cizim();
        void DegerEkle(int satir, int sutun, int deger);
        int CanliKomsularimiSay(int satir,int sutun);
        /* simulasyonun durumunu oyun kurallarina göre guncellemekle sorumlu fonk --> Güncelle() */
        void Güncelle();
    private:
        /*attribute ekleyelim*/
        Izgara izgara;
        Izgara kopyalanmisIzgara;
};      
