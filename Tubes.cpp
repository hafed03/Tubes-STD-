#include "Tubes.h"

bool isEmpty(Universitas U){
    return first(U) = NULL;
}

bool isEmpty(Fakultas F){
    return first(F) = NULL;
}

bool isEmpty(Relasi R){
    return first(R) = NULL;
}

void CreateListUniv(Universitas &U){
    first(U) = NULL;
    last(U) = NULL;
}

void CreateListFak(Fakultas &F){
    first(F) = NULL;
    last(F) = NULL;
}
void CreateListRel(Relasi &R){
    first(R) = NULL;
}

void AlokasiDataUniv(infotype X, addressUniv &P){
    P = new dataUniversitas;
    info(P).Nama_Univ = X.Nama_Univ;
    next(P) = NULL;
    prev(P) = NULL;
}

void AlokasiDataFak(infotype X,addressFak &F){
    F = new dataFakultas;
    X.jumlah = 0;
    info(F).Nama_Fak = X.Nama_Fak;
    next(F) = NULL;
    prev(F) = NULL;
}

void AlokasiRelasi(addressUniv x, addressFak y, addressRlsi &P){
  P = new listRelasi;
  toUniv(P) = x;
  toFak(P) = y;
  next(P) = NULL;
}

void InsertLastRelasi(Universitas U,Fakultas F,Relasi &L, addressRlsi P){
    string temp;
    addressUniv W;
    addressRlsi K,H;
    W = first(U);
    do{
            cout<<"Data Universitas"<<endl;
            cout<<"Universitas:"<<info(W).Nama_Univ<<endl;
            W = next(W);
    }while (W != first(U));
    cout<<"Universitas mana yang akan di tentukan relasinya"<<endl;
    cin.ignore();
    getline(cin,temp);
    W = SearchUniv(U,temp);
    addressFak S = first(F);
    while (S != NULL){
        cout<<"Data Fakultas"<<endl;
        cout<<"Fakultas:"<<info(S).Nama_Fak<<endl;
        S = next(S);
    }
    cout<<"Fakultas mana yang akan di tentukan Universitasnya"<<endl;
    getline(cin,temp);
    S = SearchFakultas(F,temp);
    if ((W != NULL) && (S != NULL)){
            info(W).jumlah++;
            AlokasiRelasi(W,S,K);
              cout<<"Universitas "<<info(toUniv(K)).Nama_Univ<<" memiliki";
              cout<<" fakultas "<<info(toFak(K)).Nama_Fak<<endl;
            H = first(L);
            if (first(L)== NULL) {
                    first(L) = K ;
            }
            else{
                    while (next(H)!= NULL) {
                            H = next(H);
                    }
                    next(H) = K;
            }
    }
}

void InsertLastRelasi2(Universitas U,Fakultas F,Relasi &L, addressRlsi P){
    string temp;
    addressFak W;
    addressRlsi K,H;
    W = first(F);
    do{
            cout<<"Data Fakultas"<<endl;
            cout<<"Fakultas:"<<info(W).Nama_Fak<<endl;
            W = next(W);
    }while (W != NULL);
    cout<<"Fakultas mana yang akan di tentukan relasinya"<<endl;
    cin.ignore();
    getline(cin,temp);
    W = SearchFakultas(F,temp);
    addressUniv S = first(U);
    do{
        cout<<"Data Universitas"<<endl;
        cout<<"Universitas:"<<info(S).Nama_Univ<<endl;
        S = next(S);
    }while (S != first(U));
    cout<<"Universitas mana yang akan di tentukan Fakultasnya"<<endl;
    getline(cin,temp);
    S = SearchUniv(U,temp);
    if ((W != NULL) && (S != NULL)){
            info(W).jumlah++;
            AlokasiRelasi(S,W,K);
              cout<<"Fakultas "<<info(toFak(K)).Nama_Fak<<" yang dimiliki ";
              cout<<"Universitas "<<info(toUniv(K)).Nama_Univ<<endl;
            H = first(L);
            if (first(L)== NULL) {
                    first(L) = K ;
            }
            else{
                    while (next(H)!= NULL) {
                            H = next(H);
                    }
                    next(H) = K;
            }
      }
}

void InsertFirstFak(Fakultas &F,addressFak P){
    if (first(F) == NULL){
            first(F) = P;
            last(F) = P;
    }else{
        next(P) = first(F);
        prev(first(F)) = P;
        first(F) = P;
    }
}

void InsertUniv(Universitas &U, addressUniv P){
    addressUniv R = first(U);
    if ( R == NULL){
        next(P) = P;
        first(U) = P;
        last(U) = P;
        prev(P) = P;
    }else if (info(R).Nama_Univ >= info(P).Nama_Univ){
        next(P) = first(U);
        prev(first(U)) = P;
        first(U) = P;
        prev(first(U)) = last(U);
        next(last(U)) = first(U);
    }else{
        while (next(R) != first(U) && info(next(R)).Nama_Univ < info(P).Nama_Univ){
                R = next(R);
        }
        if (last(U) == P){
            prev(P) = last(U);
            next(last(U)) = P;
            last(U) = P;
            next(last(U)) = first(U);
            prev(first(U)) = last(U);
        }else{
            next(P) = next(R);
            prev(next(P)) = P;
            next(R) = P;
            prev(P) = R;
        }
    }
}

void DeleteRelasi(Relasi &R, addressRlsi &S){
    addressRlsi H;
    if (S == first(R)){
            first(R) = next(S);
            next(S) = NULL;
    }else{
        H = first(R);
        while (next(H) != S){
                H = next(H);
        }
        next(H) = next(S);
        next(S) = NULL;
    }

}

addressRlsi SearchFakRlsi(Relasi R,addressFak P){
    addressRlsi Q = first(R);
    while (toFak(Q) != P && next(Q) != NULL){
            Q = next(Q);
    }
    if (toFak(Q) != P){
            return NULL;
    }else{
        return Q;
    }
}

void DeleteFak(Fakultas &F, string X, Relasi &L){
    system("cls");
    if (isEmpty(F)){
            cout<<"tidak ada fakultas"<<endl;
    system("pause");
    }
    else{
        addressFak D;
        addressFak P = SearchFakultas(F,X);
        addressFak K = P;
        if ( P == NULL){
                cout<<"tidak ada fakultas"<<X<<endl;
        }
        else{
            addressRlsi  Q = first(L);
            while ( Q != NULL){
                if (toFak(Q) == P){
                    if(next(Q) == NULL){
                        DeleteRelasi(L,Q);
                        Q = NULL;
                    }else{
                        addressRlsi temp = Q;
                        Q = next(Q);
                        DeleteRelasi(L,temp);
                    }
                }else{
                    Q = next(Q);
                }
            }
            if (!isEmpty(F)){
                if ((K == first(F)) && (K == last(F))){
                    last(F)= NULL;
                    first(F) = NULL;
                    next(K) = NULL;
                    prev(K) = NULL;
                }else if (K = first(F)){
                    first(F) = next(K);
                    next(K)= NULL;
                }else if ( K == last(F)){
                    last(F) = prev(K);
                    next(last(F)) = NULL;
                }else{
                    next(prev(K)) = next(K);
                    prev(next(K)) = prev(K);
                }
          }
       }
   }
}


void DeleteUniv(Universitas &U, string X,Relasi &L){
    system("cls");
    if (isEmpty(U)){
            cout<<"tidak ada nama universitas"<<endl;
    system("pause");
    }
    else{
        addressUniv D;
        addressUniv P = SearchUniv(U,X);
        addressUniv K = P;
        if ( P == NULL){
                cout<<"tidak ada nama universitas"<<X<<endl;
        }
        else{
            addressRlsi  Q = first(L);
            while ( Q != NULL){
                if (toUniv(Q) == P){
                    if(next(Q) == NULL){
                        DeleteRelasi(L,Q);
                        Q = NULL;
                    }else{
                        addressRlsi temp = Q;
                        Q = next(Q);
                        DeleteRelasi(L,temp);
                    }
                }else{
                    Q = next(Q);
                }
            }
        if (!isEmpty(U) && K != NULL){
            if ((first(U) == K) && (last(U) == K)){
                    first(U) = NULL;
                    last(U) = NULL;
                    next(K) = NULL;
                    prev(K) = NULL;
             }else if (first(U) == K){
                 first(U) = next(K);
                 prev(first(U))= last(U);
                 next(last(U)) = first(U);
                 next(K) = NULL;
                 prev(K) = NULL;
             }else if (K == last(U)){
                 last(U) = prev(K);
                 prev(first(U)) = last(U);
                 next(last(U)) = first(U);
                 next(K)= NULL;
                 prev(K)= NULL;
             }else{
                 next(prev(K)) = next(K);
                 prev(next(K)) = prev(K);
                 next(K) = NULL;
                 prev(K) = NULL;
             }
           }
        }
    }
}

addressRlsi SearchUnivRlsi(Relasi R, addressUniv P){
    addressRlsi Q = first(R);
    if ( Q == NULL){
        return NULL;
    }else{
        while (Q != NULL && toUniv(Q) != P){
                Q = next(Q);
            }
        if (Q == NULL){
            return NULL;
        }else{
            return Q;
        }
    }
}

addressFak SearchFakultas(Fakultas F, string X){
    addressFak P = first(F);
    if (first(F) != NULL){
            while ((P != last(F)) && (info(P).Nama_Fak != X)){
                    P = next(P);
            }
            if (info(P).Nama_Fak != X){
                     P = NULL;
            }
    }
    return P;
}


addressUniv SearchUniv(Universitas U, string X){
    addressUniv P = first(U);
    if (P == NULL){
            return NULL;
    }else{
        while (info(P).Nama_Univ != X && next(P) != first(U)){
            P = next(P);
        }
        if (info(P).Nama_Univ != X){
                return NULL;
        }else{
            return P;
    }
  }
}

void PrintAll(Universitas U, Fakultas F, Relasi R){
    addressUniv P;
    addressRlsi Q;
    addressFak S;
    Q = first(R);
    while (Q != NULL){
        cout<<"Universitas:";
        cout<<info(toUniv(Q)).Nama_Univ<<endl;
        cout<<"Fakultas:";
        cout<<info(toFak(Q)).Nama_Fak<<endl;
        Q = next(Q);
    }
}

void PrintUniv(Relasi L,Universitas U,Fakultas F){
    addressFak W;
    addressRlsi S;
    string Fak;
    if (first(F) != NULL){
            W = first(F);
        while ( W != NULL){
                cout<<"Fakulatas:"<<info(W).Nama_Fak;
                cout<<endl;
                W = next(W);
        }
        cout<<"Pilih fakultas yang universitanya akan di tampilkan:";
        cin.ignore();
        getline(cin,Fak);
            W = SearchFakultas(F,Fak);
                    if ( W != NULL){
                            S = first(L);
                        cout<<"Universitas yang memiliki fakultas:"<<info(W).Nama_Fak<<endl;cout<<"adalah ";
                        while ( S != NULL){
                            if (toFak(S) == W){
                                    cout<<"Universitas:"<<info(toUniv(S)).Nama_Univ<<endl;
                            }
                            S = next(S);
                        }
                    }else{
                        cout<<"fakultas"<<Fak<<" tidak ditemukan";
                    }
    }else{
        cout<<"data fakultas tidak ada"<<endl;
    }
}

void PrintFak(Relasi L,Universitas U,Fakultas F){
    addressUniv W;
    addressRlsi S;
    string Univ;
    if (first(F) != NULL){
            W = first(U);
        do{
                cout<<"Universitas:"<<info(W).Nama_Univ<<endl;
                W = next(W);
        }while ( W != first(U));
        cout<<"Pilih Universitas yang fakultasnya akan di tampilkan:";
        cin.ignore();
        getline(cin,Univ);
            W = SearchUniv(U,Univ);
                    if ( W != NULL){
                            S = first(L);
                        cout<<"Fakultas yang dimiliki Universitas:"<<info(W).Nama_Univ<<endl;cout<<"adalah ";
                        while ( S != NULL){
                            if (toUniv(S) == W){
                                    cout<<"Fakultas:"<<info(toFak(S)).Nama_Fak<<endl;
                            }
                            S = next(S);
                        }
                    }else{
                        cout<<"Universitas"<<Univ<<" tidak ditemukan";
                    }
    }else{
        cout<<"data universitas tidak ada"<<endl;
    }
}

void PrintFakTerbanyak(Universitas U,Fakultas F,Relasi L){
    int maks = 0;
    addressUniv Q = first(U);
    if (first(U) != NULL){
        do{
            if (info(Q).jumlah > maks){
                maks = info(Q).jumlah;
            }
                Q = next(Q);
        }while (Q != first(U));
            Q = first(U);
         do{
                    if (info(Q).jumlah == maks){
                            cout<<"Universitas:"<<info(Q).Nama_Univ<<endl;
                    }
                    Q = next(Q);
         }while (Q != first(U));

    }
  }

void PrintFakTersedikit(Universitas U,Fakultas F,Relasi L){
    addressRlsi P= first(L);
    if (first(L) != NULL){
        int mini = info(toUniv(P)).jumlah;
        while (P != NULL){
            if (info(toUniv(P)).jumlah < mini){
                mini = info(toUniv(P)).jumlah;
            }
                P = next(P);
        }
            P = first(L);
         while (P != NULL){
                    if ( info(toUniv(P)).jumlah == mini){
                            cout<<"Universitas:"<<info(toUniv(P)).Nama_Univ<<endl;
                    }
                    P = next(P);
         }
    }
}





