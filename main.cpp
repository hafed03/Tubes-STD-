#include <iostream>
#include "Tubes.h"
/*
Kelompok 16
1.Hafidz Lazuardi
2.Saskia Putri ananda
*/
using namespace std;

int main()
{
    Universitas U;
    Fakultas F;
    string X;
    Relasi L;
    addressRlsi P;
    int choice;
    bool Start = true;
    CreateListUniv(U);
    CreateListFak(F);
    CreateListRel(L);
        while (Start != false){
        cout << "*************************************************************\n";
        cout << "*              APLIKASI DATA PERGURUAN TINGGI               *\n";
        cout << "*************************************************************\n";
        cout << " |1|. Add Data Universitas                                  *\n";
        cout << " |2|. Add Data Fakultas                                     *\n";
        cout << " |3|. Penentuan relasi                                      *\n";
        cout << " |4|. Show All data                                         *\n";
        cout << " |5|. Delete universitas tertentu                           *\n";
        cout << " |6|. Delete Fakultas tertentu                              *\n";
        cout << " |7|. Show Universitas yang memiliki fakultas tertentu      *\n";
        cout << " |8|. Show Fakultas yang dimiliki universitas tertentu      *\n";
        cout << " |9|. Show Universitas yang memiliki fakultas terbanyak     *\n";
        cout << " |10|.Show Universitas yang memiliki fakultas tersedikit    *\n";
        cout << " |11|.Penentuan relasi2                                     *\n";
        cout << " |12|.Exit.                                                 *\n";
        cout << "*************************************************************\n";
        cout << " Enter your choice and press return: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            {
        cout << "Ini menu add data universitas\n";
        system("cls");
        infotype X;
        cout<<"Masukkan nama universitas:";
        cin.ignore();
        getline(cin,X.Nama_Univ);
        addressUniv P;
        AlokasiDataUniv(X,P);
        InsertUniv(U,P);
        cout<<"nama univ :"<< X.Nama_Univ <<" berhasil ditambah" <<endl;
        system("pause");
            }
        break;
        case 2:
        {
        cout << "Ini menu add data fakultas\n";
        system("cls");
        infotype X;
        cout<<"Masukkan nama fakultas:";
        cin.ignore();
        getline(cin,X.Nama_Fak);
        addressFak P;
        AlokasiDataFak(X,P);
        InsertFirstFak(F,P);
        cout<<"nama fakultas :"<< X.Nama_Fak <<"   berhasil ditambah" <<endl;
        system("pause");
        }
        break;
        case 3:
        system("cls");
        cout << "Ini menu untuk penentuan relasi\n";
        InsertLastRelasi(U,F,L,P);
        system("pause");
        break;
        case 4:
        system("cls");
        cout << "Ini menu showAll data\n";
        PrintAll(U,F,L);
        system("pause");
        break;
        case 5:
        system("cls");
        cout<<"masukkan nama univ yang akan di hapus:";
        cin.ignore();
        getline(cin,X);
        DeleteUniv(U,X,L);
        system("pause");
        // rest of code here
        break;
        case 6:
        system("cls");
        cout<<"masukkan nama fakultas yang akan di hapus:";
        cin.ignore();
        getline(cin,X);
        DeleteFak(F,X,L);
        system("pause");
        // rest of code here
        break;
        case 7:
        system("cls");
        cout << "Show Universitas yang memiliki fakultas tertentu\n";
        PrintUniv(L,U,F);
        system("pause");
        // rest of code here
        break;
        case 8:
        system("cls");
        cout << "Show Fakultas yang dimiliki universitas tertentu\n";
        PrintFak(L,U,F);
        system("pause");
        // rest of code here
        break;
        case 9:
        system("cls");
        cout << "Show Universitas yang memiliki fakultas terbanyak\n";
        PrintFakTerbanyak(U,F,L);
        system("pause");
        // rest of code here
        break;
        case 10:
        system("cls");
        cout << "Show Universitas yang memiliki fakultas tersedikit\n";
        PrintFakTersedikit(U,F,L);
        system("pause");
        // rest of code here
        break;
        case 11:
        system("cls");
        InsertLastRelasi2(U,F,L,P);
        system("pause");
        // rest of code here
        break;
        case 12:
        cout << "exit\n";
        Start = false;
        // rest of code here
        break;
        default:
        cout << "Not a Valid Choice. \n";
        cout << "Choose again.\n";
        cin >> choice;
        break;
    }
 }
    return 0;
}
