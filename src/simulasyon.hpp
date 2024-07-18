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
          kopyalanmisIzgara(genislik,yukseklik,hucreBoyutu)  ,
          calistir(false)
        {
            /*constructor ekleyelim*/
            izgara.RastgeleDoldur();
        };
        void Cizim();
        void DegerEkle(int satir, int sutun, int deger);
        int CanliKomsularimiSay(int satir,int sutun);
        /* simulasyonun durumunu oyun kurallarina göre guncellemekle sorumlu fonk --> Güncelle() */
        void Güncelle();
        bool CalisiyorMu(){return calistir;}
        void Baslat(){calistir = true;}
        void Bitir(){calistir = false;}
    private:
        /*attribute ekleyelim*/
        Izgara izgara;
        Izgara kopyalanmisIzgara;
        bool calistir;
};      
