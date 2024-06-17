/* 
.hpp
Bu bir header dosyasidir
classlari burda yazariz
.cpp 
Burada implementation dosyasidir
header file da tanimlanan fonklar burda implemente edilir

*****
amac abstraction of code ---> oop
*/

//1 kez derleme saglama
#pragma once 
#include <vector> // 2D gorunum icin

class Izgara
{
    public:
        Izgara(int genislik, int yukseklik, int hucreBoyutu)
        :   satirlar(yukseklik/hucreBoyutu), sutunlar(genislik/hucreBoyutu), hucreBoyutu(hucreBoyutu), hucreler(satirlar,std ::vector<int>(sutunlar,0)) {};
        void Cizim();
        void DegerEkle(int satir,int sutun,int deger);
        int  DegerAl(int satir,int sutun);/*komsu hucreler icin gerekli*/
        bool IzgaraIcindeMi(int satir, int sutun);
        int  SatirlariAl(){return satirlar;}
        int  SutunlariAl(){return sutunlar;}
        void RastgeleDoldur();
    private:
        int satirlar;
        int sutunlar;
        int hucreBoyutu;
        std::vector<std::vector<int>>hucreler;
};