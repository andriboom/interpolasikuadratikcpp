#include <iostream>
#include <conio.h>
using namespace std;
/*
    thn[0] = tahun 1
    thn[1] = tahun 2
    thn[2] = tahun 3

    jml[0] = jumlah penduduk tahun 1
    jml[1] = jumlah penduduk tahun 2
    jml[2] = jumlah penduduk tahun 3

    thnCari : tahun yang akan di dicari
    pers[0],pers[1],pers[2] = persamaan
    hasil : hasil perhitungan
*/

float thn[3],jml[3],thnCari,pers[3], hasil;
void sortByYear(){
    float tempThn, tempJml;
    for(int i=1;i<3;i++){
        for (int j=0;j<3-i;j++){
            if(thn[j] > thn[j+1]){
                tempThn = thn[j];
                tempJml = jml[j];
                thn[j] = thn[j+1];
                jml[j] = jml[j+1];
                thn[j+1] = tempThn;
                jml[j+1] = tempJml;
            }
        }
    }
}
int main()
{
    cout<<"==================================================="<<endl;
    cout<<"              Prediksi Jumlah Penduduk             "<<endl;
    cout<<"         menggunakan interpolasi kuadratik         "<<endl;
    cout<<"==================================================="<<endl;
    cout<<""<<endl;
    cout<<""<<endl;

    for(int i=0; i<3; i++){
        cout<<"Masukan Tahun ("<<i+1<<") : ";cin>>thn[i];
        cout<<"Masukan Jumlah Penduduk ("<<i+1<<") : ";cin>>jml[i];
    }
    cout<<"Masukan tahun yang di cari : "; cin>>thnCari;
    sortByYear();
    //perhitungan
    pers[0] = ((thnCari-thn[1])*(thnCari-thn[2]))/((thn[0]-thn[1])*(thn[0]-thn[2]));
    pers[1] = ((thnCari-thn[0])*(thnCari-thn[2]))/((thn[1]-thn[0])*(thn[1]-thn[2]));
    pers[2] = ((thnCari-thn[0])*(thnCari-thn[1]))/((thn[2]-thn[0])*(thn[2]-thn[1]));
    hasil = (jml[0]*pers[0])+(jml[1]*pers[1])+(jml[2]*pers[2]);

    cout<<""<<endl;
    for(int i=0; i<3; i++){
        cout<<"Tahun "<<thn[i];
        cout<<" Jumlah Penduduk "<<jml[i]<<endl;
    }
    cout<<"==================================================="<<endl;
    cout<<"Jumlah penduduk pada tahun "<<thnCari<<" Adalah : "<<hasil<<endl;
    getch();
    return 0;
}
