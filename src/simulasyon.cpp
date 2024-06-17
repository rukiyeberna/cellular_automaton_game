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
    int CanliKomsular = 0;
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
        int komsuSatiri = satir + konum.first;
        int komsuSutun = sutun + konum.second;
        CanliKomsular += izgara.DegerAl(komsuSatiri,komsuSutun);
    }
    return CanliKomsular;
}
