#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char hoTen[25], diaChi[100];
    float diem;
} sinhVien;

int main(){
    int n, m, i;
    sinhVien *sv;
    int pass = 0;
    printf("\nNhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    sv = (sinhVien*) malloc(n * sizeof(sinhVien));


    while(1){
        int lChon;

        printf ("CAC CHUC NANG\n");
        printf ("1. Nhap thong tin sinh vien\n");
        printf ("2. Them sinh vien vao danh sach truoc do\n");
        printf ("3. In danh sach\n");
        printf ("0. Thoat chuong trinh\n");

        scanf ("%d", &lChon); getchar();
        switch(lChon){
            case 1:
            for (i = 0 ; i < n; ++i){
                printf ("\nNhap ma sinh vien: ");
                scanf("%d", &sv[i].id);

                printf("\nNhap ten sinh vien: ");
                fgets (sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
                sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = '\0';

                printf("\nNhap diem: ");
                scanf ("%d", &sv[i].diem);

                printf("\nNhap dia chi: ");
                fgets (sv[i].diaChi, sizeof(sv[i].diaChi), stdin);
                sv[i].diaChi[strcspn(sv[i].diaChi, "\n")] = '\0';
            }
            pass = 1;
            case 2:
            if (pass){  
                int t = 0;
                printf ("\nNhap so luong sinh vien muon them: ");
                scanf ("%d", &t); getchar();
                m = n + t;
                for (i = n; i < m; ++i){
                    printf ("\nNhap ma sinh vien: ");
                    scanf("%d", &sv[i].id);

                    printf("\nNhap ten sinh vien: ");
                    fgets (sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
                    sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = '\0';

                    printf("\nNhap diem: ");
                    scanf ("%d", &sv[i].diem);

                    printf("\nNhap dia chi: ");
                    fgets (sv[i].diaChi, sizeof(sv[i].diaChi), stdin);
                    sv[i].diaChi[strcspn(sv[i].diaChi, "\n")] = '\0';
                }
            } else {
                printf ("Ban chua nhap thong tin sinh vien ban dau");
            }
            case 3:
            if (pass){
                printf ("\n------------Thong tin sinh vien------------\n");
                printf ("\n%-12s %-25s %-5s %-40s\n", "MA SINH VIEN", "HO TEN", "DIEM", "DIA CHI");
                for (int i = 0; i < m; ++i){
                    printf ("%-12d %-25s %-5d %-40s", sv[i].id, sv[i].hoTen, sv[i].diem, sv[i].diaChi);
                }
            } else {
                printf ("Chua co du lieu sinh vien");
            }
            case 0:

        }

    }

    return 0;
}