#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char hoTen[25], diaChi[100];
    float diem;
} sinhVien;

int main(){
    int n, m, i, t = 0;
    sinhVien *sv, *sv_c, *sv_m;
    int pass = 0;
    printf("\nNhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    sv = (sinhVien*) malloc(n * sizeof(sinhVien));
    sv_m = (sinhVien*) malloc(n * sizeof(sinhVien));
    sv_c = (sinhVien*) malloc(n * sizeof(sinhVien));

    while(1){
        int lChon;

        printf ("\nCAC CHUC NANG\n");
        printf ("1. Nhap thong tin sinh vien\n");
        printf ("2. Them sinh vien vao danh sach truoc do\n");
        printf ("3. In danh sach\n");
        printf ("0. Thoat chuong trinh\n");

        scanf ("%d", &lChon); getchar();
        switch(lChon){
            case 1:
            if (!pass){
                for (i = 0 ; i < n; ++i){
                    printf ("\nNhap ma sinh vien: ");
                    scanf("%d", &sv[i].id); getchar ();

                    printf("\nNhap ten sinh vien: ");
                    fgets (sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
                    sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = '\0';

                    printf("\nNhap diem: ");
                    scanf ("%f", &sv[i].diem); getchar ();

                    printf("\nNhap dia chi: ");
                    fgets (sv[i].diaChi, sizeof(sv[i].diaChi), stdin);
                    sv[i].diaChi[strcspn(sv[i].diaChi, "\n")] = '\0';

                    sv_c[i] = sv[i];
                }
                pass = 1;
                break;
            } else {
                printf ("\nBan da nhap thong tin ban dau roi chi can them\n");
                break;
            }
            break;
            case 2:
            if (pass){  
                free (sv);
                printf ("\nNhap so luong sinh vien muon them: ");
                scanf ("%d", &t); getchar();
               
                sv_c = (sinhVien*) realloc(sv_c, (n + t) * sizeof(sinhVien));
                sv_m = (sinhVien*) realloc(sv_m, (n + t) * sizeof(sinhVien));

                for (i = n; i < (n + t); ++i){
                    printf ("\nNhap ma sinh vien: ");
                    scanf("%d", &sv_m[i].id); getchar ();

                    printf("\nNhap ten sinh vien: ");
                    fgets (sv_m[i].hoTen, sizeof(sv_m[i].hoTen), stdin);
                    sv_m[i].hoTen[strcspn(sv_m[i].hoTen, "\n")] = '\0';

                    printf("\nNhap diem: ");
                    scanf ("%f", &sv_m[i].diem); getchar ();

                    printf("\nNhap dia chi: ");
                    fgets (sv_m[i].diaChi, sizeof(sv_m[i].diaChi), stdin);
                    sv_m[i].diaChi[strcspn(sv_m[i].diaChi, "\n")] = '\0';
                }
                n += t;                 
                pass = 2;
                break;
            } else {
                printf ("\nBan chua nhap thong tin sinh vien ban dau\n");
                break;
            }
            case 3:
            if (pass){
                int c;

                do{
                    
                    printf ("\n1. In danh sach ban dau/truoc do");
                    printf ("\n2. In danh sach sau khi them");
                    printf ("\n0. Quay lai menu chuc nang\n");
                    scanf ("%d", &c);
                
                    switch(c){
                        case 1:
                        if (pass == 2){
                            for (i = n; i < (n + t); ++i){
                                sv_c[i] = sv_m[i];
                            }
                        }
                        printf ("\n------------Thong tin sinh vien------------\n");
                        printf ("\n%-7s %-25s %-5s %-20s\n", "MSV", "HO TEN", "DIEM", "DIA CHI");
                        for (int i = 0; i < (n + t); ++i){
                            printf ("%-7d %-25s %-5.2f %-20s\n", sv_c[i].id, sv_c[i].hoTen, sv_c[i].diem, sv_c[i].diaChi);
                        }
                        break;
                        case 2:
                        if (pass == 2){
                                for (i = 0; i < n; ++i){
                                sv_m[i] = sv_c[i];
                            }                            
                            printf ("\n------------Thong tin sinh vien------------\n");
                            printf ("\n%-7s %-25s %-5s %-40s\n", "MSV", "HO TEN", "DIEM", "DIA CHI");
                            for (int i = 0; i < (n + t); ++i){
                                printf ("%-7d %-25s %-5.2f %-40s\n", sv_m[i].id, sv_m[i].hoTen, sv_m[i].diem, sv_m[i].diaChi);
                            }
                            break;
                        } else {
                            printf ("\nChuc nang bi khoa do ban chua them sinh vien nao moi\n");
                        }
                    }

                } while(c != 0);
                if (c == 0) {
                    break;
                }

            } else {
                printf ("\nChua co du lieu sinh vien\n");
                break;
            }
            case 0:
            free (sv_m);
            free (sv_c);
            return 0;

        }

    }

    return 0;
}

/// loi in