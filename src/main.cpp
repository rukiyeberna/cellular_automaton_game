#include <raylib.h>

int main()
{   Color KAFAMAGORE = {34,16,41,255};
    const int EKRAN_GENISLIGI = 750;
    const int EKRAN_YUKSEKLIGI = 750;
    
    int FPS =12;

    InitWindow(EKRAN_GENISLIGI,EKRAN_YUKSEKLIGI,"GAME OF LIFE");
    SetTargetFPS(FPS);

    /*simulasyon dongusu*/

    //saniyede 12 defa tekrar
    while(WindowShouldClose() == false)
    {
        // Olay gerçekleştirme

        // Durum  Güncelleme

        // Çizim
        BeginDrawing();
        ClearBackground(KAFAMAGORE);
        EndDrawing();
    }
    CloseWindow();
}