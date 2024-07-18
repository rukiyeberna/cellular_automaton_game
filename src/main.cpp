#include <raylib.h>
#include <iostream>
#include "simulasyon.hpp"

int main()
{   Color KAFAMAGORE = {34,16,41,255};

    const int EKRAN_GENISLIGI = 1000;
    const int EKRAN_YUKSEKLIGI = 1000;
    const int HUCRE_BOYUTU =10;
    
    int FPS =12;

    InitWindow(EKRAN_GENISLIGI,EKRAN_YUKSEKLIGI,"GAME OF LIFE");
    SetTargetFPS(FPS);

    /*simulasyon objesi olusturup test edelim*/
    Simulasyon simulasyon(EKRAN_GENISLIGI,EKRAN_YUKSEKLIGI,HUCRE_BOYUTU);


    /*
      komsularim sinirda ise ne olur peki, bakalim
      en ucta oldugu icin yeni komsularimi tespit ederken ortaya cikan bu problemi cözmek icin farkli bir cok yol var,
      Ben toroidal grid kullanacagim. Toroidal gridde, kenardan çıkan bir hücre karşı kenardan tekrar girer.
      Bu sayede, kenar problemlerini ortadan kaldırabiliriz ve hücreler sonsuz bir düzlemdeymiş gibi davranabilir.

      izgara ya tanıtmak icin moduler aritmetikten yararlanalim
    */


    /*simulasyon dongusu*/

    //saniyede 12 defa tekrar
    while(WindowShouldClose() == false)
    {
        // Olay gerçekleştirme
        if(IsKeyPressed(KEY_ENTER))
        {
            simulasyon.Baslat();
            SetWindowTitle("GAME OF LIFE STARTTT..........");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            simulasyon.Bitir();
            SetWindowTitle("GAME OF LIFE STOP..........");
        }
        // Durum  Güncelleme
        simulasyon.Güncelle();

        // Çizim
        BeginDrawing();
        ClearBackground(KAFAMAGORE);
        simulasyon.Cizim();
        EndDrawing();
    }
    CloseWindow();
}