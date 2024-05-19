#include <raylib.h>
#include "izgara.hpp"

int main()
{   Color KAFAMAGORE = {34,16,41,255};

    const int EKRAN_GENISLIGI = 750;
    const int EKRAN_YUKSEKLIGI = 750;
    const int HUCRE_BOYUTU = 25;
    
    int FPS =12;

    InitWindow(EKRAN_GENISLIGI,EKRAN_YUKSEKLIGI,"GAME OF LIFE");
    SetTargetFPS(FPS);

    Izgara izgara(EKRAN_GENISLIGI,EKRAN_YUKSEKLIGI,HUCRE_BOYUTU);

    izgara.DegerEkle(0,0,1);
    izgara.DegerEkle(2,1,1);//satir sutun
    /*simulasyon dongusu*/

    //saniyede 12 defa tekrar
    while(WindowShouldClose() == false)
    {
        // Olay gerçekleştirme

        // Durum  Güncelleme

        // Çizim
        BeginDrawing();
        ClearBackground(KAFAMAGORE);
        izgara.Cizim();
        EndDrawing();
    }
    CloseWindow();
}