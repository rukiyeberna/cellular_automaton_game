#include <raylib.h>
#include "simulasyon.hpp"

int main()
{   Color KAFAMAGORE = {34,16,41,255};

    const int EKRAN_GENISLIGI = 750;
    const int EKRAN_YUKSEKLIGI = 750;
    const int HUCRE_BOYUTU = 25;
    
    int FPS =12;

    InitWindow(EKRAN_GENISLIGI,EKRAN_YUKSEKLIGI,"GAME OF LIFE");
    SetTargetFPS(FPS);

    /*simulasyon objesi olusturup test edelim*/
    Simulasyon simulasyon(EKRAN_GENISLIGI,EKRAN_YUKSEKLIGI,HUCRE_BOYUTU);
    simulasyon.DegerEkle(3,4,1);

    /*simulasyon dongusu*/

    //saniyede 12 defa tekrar
    while(WindowShouldClose() == false)
    {
        // Olay gerçekleştirme

        // Durum  Güncelleme

        // Çizim
        BeginDrawing();
        ClearBackground(KAFAMAGORE);
        simulasyon.Cizim();
        EndDrawing();
    }
    CloseWindow();
}