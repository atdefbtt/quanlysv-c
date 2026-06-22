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
    sinhVien *sv, *sv_c, *sv_t;
    int pass = 0, check = 0;
    printf("\nNhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    sv = (sinhVien*) malloc(n * sizeof(sinhVien));

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
                free (sv_t);
                printf ("\nNhap so luong sinh vien muon them: ");
                scanf ("%d", &t); getchar();
               
                sv = (sinhVien*) realloc(sv, (n + t) * sizeof(sinhVien));

                for (i = n; i < (n + t); ++i){
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
                sv_t = (sinhVien*) malloc(t * sizeof(sinhVien));
                for (i = 0; i < t; ++i){
                    sv_t[i] = sv[i + n - t];
                }
                do{
                    
                    printf ("\n1. In danh sach ban dau/truoc do");
                    printf ("\n2. In danh sach sau khi them");
                    printf ("\n3. In danh sach sinhvien vua them");
                    printf ("\n0. Quay lai menu chuc nang\n");
                    scanf ("%d", &c);
                
                    switch(c){
                        case 1:

                        printf ("\n------------Thong tin sinh vien------------\n");
                        printf ("\n%-7s %-25s %-5s %-20s\n", "MSV", "HO TEN", "DIEM", "DIA CHI");
                        for (int i = 0; i < n - t ; ++i){
                            printf ("%-7d %-25s %-5.2f %-20s\n", sv[i].id, sv[i].hoTen, sv[i].diem, sv[i].diaChi);
                        }
                        break;
                        case 2:
                        if (pass == 2){                           
                            printf ("\n------------Thong tin sinh vien------------\n");
                            printf ("\n%-7s %-25s %-5s %-40s\n", "MSV", "HO TEN", "DIEM", "DIA CHI");
                            for (int i = 0; i < n; ++i){
                                printf ("%-7d %-25s %-5.2f %-40s\n", sv[i].id, sv[i].hoTen, sv[i].diem, sv[i].diaChi);
                            }
                            break;
                        } else {
                            printf ("\nChuc nang bi khoa do ban chua them sinh vien nao moi\n");
                            break;
                        }
                        case 3:
                        if (pass == 2){                           
                            printf ("\n------------Thong tin sinh vien------------\n");
                            printf ("\n%-7s %-25s %-5s %-40s\n", "MSV", "HO TEN", "DIEM", "DIA CHI");
                            for (int i = 0; i < t; ++i){
                                printf ("%-7d %-25s %-5.2f %-40s\n", sv_t[i].id, sv_t[i].hoTen, sv_t[i].diem, sv_t[i].diaChi);
                            }
                            break;
                        } else {
                            printf ("\nChuc nang bi khoa do ban chua them sinh vien nao moi\n");
                            break;
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
            free (sv_t);
            free (sv);
            return 0;

        }

    }

    return 0;
}

/// loi logic 2 bien sv_c & sv_m