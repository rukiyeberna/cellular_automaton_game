#include "simulasyon.hpp"
#include <vector>
#include <utility>

/*cizim metodunun implementasyonu*/
void Simulasyon::Cizim()
{
    izgara.Cizim();
}

void Simulasyon::DegerEkle(int satir, int sutun, int deger)
{
    izgara.DegerEkle(satir,sutun,deger);
}

int Simulasyon::CanliKomsularimiSay(int satir, int sutun)
{
    int canliKomsular = 0;
    /*0-based matrisde*/
    /*8 komsu hücrenin bize göre konumlari baz alinarak olusturulan struct */
    std::vector<std::pair<int,int>> komsularinKonumlari =
    {
        //{satir,sutun} pairleri
        {-1,0},  // Üst komşu
        {1,0},   // Alt komşu
        {0,-1},  // Sol komşu
        {0,1},   // Sağ komşu
        {-1,-1}, // Sol üst çapraz komşu
        {-1,1},  // Sağ üst çapraz komşu
        {1,-1},  // Sol alt çapraz komşu
        {1,1}    // Sağ alt çapraz komşu
    };

    for(const auto& konum : komsularinKonumlari)
    { 
        /*
        modüler aritmetikten yararlanalim

        [5][29] + {0,1} = [5][0]

        yenisatir =(5+0+30)%30 = 5
        yenisutun = (29+1+30)%30 =0

        yenisatir = (satir+konum+totalsatirlar)% totalsatirlar,
         bu islemle toroidal olan düzlemimizde başta belirecek olan hücreleri tespit edebiiriz
        */
        int komsuSatiri = (satir + konum.first + izgara.SatirlariAl()) % izgara.SatirlariAl();
        int komsuSutun = (sutun + konum.second + izgara.SutunlariAl()) % izgara.SutunlariAl();
        canliKomsular += izgara.DegerAl(komsuSatiri,komsuSutun);
    }
    return canliKomsular;
}

/*oyunun mantigini iceren fonksiyon*/
void Simulasyon::Güncelle()
{
    if(CalisiyorMu())
    {
        /*oyun izgarasindaki her bir hucreyi kontrol edelim, nested loop gerekecek*/
        for(int satir =0; satir< izgara.SatirlariAl();satir ++)
        {
            for(int sutun =0; sutun<izgara.SutunlariAl();sutun ++)
            {
                int canliKomsular = CanliKomsularimiSay(satir,sutun);
                int deger = izgara.DegerAl(satir,sutun);

                /*kurallari implemente edelim*/
                if(deger == 1)
                {
                    /*olum gerceklesme durumu*/
                    if(canliKomsular>3 || canliKomsular<2)
                    {
                        kopyalanmisIzgara.DegerEkle(satir,sutun,0);
                    }
                    /*else kismi ekledik cunku her bir hucre yenilenmeli*/
                    else
                    {
                        kopyalanmisIzgara.DegerEkle(satir,sutun,1);
                    }
                }
                else
                {
                    if(canliKomsular ==3)
                    {
                        kopyalanmisIzgara.DegerEkle(satir,sutun,1);
                    }
                    else
                    {
                        kopyalanmisIzgara.DegerEkle(satir,sutun,0);
                    }
                }
            }
        }
        /*koyayi aslina tasiyalim*/
        izgara= kopyalanmisIzgara;
    }
}
