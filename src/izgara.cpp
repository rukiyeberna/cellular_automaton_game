#include "izgara.hpp"
#include "raylib.h"

void Izgara::Cizim()
{
    for(int satir=0; satir < satirlar; satir++)
    {
        for(int sutun=0; sutun < sutunlar; sutun ++)
        {
            Color color = hucreler[satir][sutun] ? Color {0,255,0,255} : Color {16,16,16,255};
            //DrawRectangle(x,y,w,h,color);
            DrawRectangle(sutun * hucreBoyutu, satir * hucreBoyutu, hucreBoyutu - 1,hucreBoyutu -1 ,color);
        }
    }
}

void Izgara::DegerEkle(int satir, int sutun, int deger)
{
    if( IzgaraIcindeMi(satir,sutun) )
    {
        hucreler[satir][sutun] = deger;
    }
}

int Izgara::DegerAl(int satir, int sutun)
{
    if( IzgaraIcindeMi(satir,sutun))
    {
        return hucreler[satir][sutun];
    }
    return 0;
}

bool Izgara::IzgaraIcindeMi(int satir, int sutun)
{
    if(satir >=0 &&  satir< satirlar && sutun >= 0 && sutun< sutunlar )
    {
        return true;
    }
    return false;
}
