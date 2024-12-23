#include <stdio.h>
#include <string.h>

struct Book{
    int id;
    float price;
    char genre[50];
    char title[50];
    char author[50];
   
};
void nhapThongTinSach(struct Book books[], int *soLuong);
void hienThiThongTinSach(struct Book books[], int soLuong);
void themSach(struct Book books[], int *soLuong);
void xoaSachTheoMa(struct Book books[], int *soLuong);
void capNhatThongTinSach(struct Book books[], int soLuong);
void sapXepSachTheoGia(struct Book books[], int soLuong, int tangDan);
void timKiemSachTheoTen(struct Book books[], int soLuong);

int main(){
    struct Book books[50];
    int soLuong=0;
    int luaChon;
    do{
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon){
            case 1:
                nhapThongTinSach(books, &soLuong);
                break;
            case 2:
                hienThiThongTinSach(books, soLuong);
                break;
            case 3:
                themSach(books, &soLuong);
                break;
            case 4:
                xoaSachTheoMa(books, &soLuong);
                hienThiThongTinSach(books, soLuong);
                break;
            case 5:
                capNhatThongTinSach(books, soLuong);
                hienThiThongTinSach(books, soLuong);
                break;
            case 6:{
                int tangDan;
                printf("\nSap xep sach theo gia:\n1. Tang dan\n2. Giam dan\nLua chon: ");
                scanf("%d", &tangDan);
                sapXepSachTheoGia(books, soLuong, tangDan == 1);
                hienThiThongTinSach(books, soLuong);
                break;
            }
            case 7:
                timKiemSachTheoTen(books, soLuong);
                break;
            case 8:
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le\n");
        }
    }while(luaChon!=8);

    return 0;
}


void nhapThongTinSach(struct Book books[], int *soLuong){
    printf("\nNhap so luong sach: ");
    scanf("%d", soLuong);
    getchar();
    for(int i=0; i<*soLuong; i++){
        printf("\nNhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%d", &books[i].id);
        getchar();
        fflush(stdin);
        printf("Ten sach: ");
        fgets(books[i].title, sizeof(books[i].title), stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;
        fflush(stdin);
        printf("Tac gia: ");
        fgets(books[i].author, sizeof(books[i].author), stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;
        fflush(stdin);
          printf("The loai: ");
        fgets(books[i].genre, sizeof(books[i].genre), stdin);
        books[i].genre[strcspn(books[i].genre, "\n")] = 0;
        printf("Gia tien: ");
        scanf("%f", &books[i].price);
        getchar();
        fflush(stdin);
       
    }
}
void hienThiThongTinSach(struct Book books[], int soLuong){
    printf("\nDanh sach cac sach:\n");
    for(int i=0; i<soLuong; i++){
        printf("\nSach %d:\n", i+1);
        printf("Ma sach: %d\n", books[i].id);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].genre);
    }
}
void themSach(struct Book books[], int *soLuong){
    int viTri;
    printf("\nNhap vi tri muon them (0 den %d): ", *soLuong);
    scanf("%d", &viTri);

    if(viTri<0 || viTri>*soLuong){
        printf("\nVi tri khong hop le\n");
        return;
    }
    for(int i=*soLuong; i>viTri; i--){
        books[i] = books[i - 1];
    }
    printf("\nNhap thong tin sach moi:\n");
    printf("Ma sach: ");
    scanf("%d", &books[viTri].id);
    getchar();
    fflush(stdin);
    printf("Ten sach: ");
    fgets(books[viTri].title, sizeof(books[viTri].title), stdin);
    books[viTri].title[strcspn(books[viTri].title, "\n")] = 0;
    fflush(stdin);
    printf("Tac gia: ");
    fgets(books[viTri].author, sizeof(books[viTri].author), stdin);
    books[viTri].author[strcspn(books[viTri].author, "\n")] = 0;
    fflush(stdin);
    printf("Gia tien: ");
    scanf("%f", &books[viTri].price);
    getchar();
    fflush(stdin);
    printf("The loai: ");
    fgets(books[viTri].genre, sizeof(books[viTri].genre), stdin);
    books[viTri].genre[strcspn(books[viTri].genre, "\n")] = 0;
    (*soLuong)++;
}
void xoaSachTheoMa(struct Book books[], int *soLuong){
    int id;
    printf("\nNhap ma sach can xoa: ");
    scanf("%d", &id);
    int viTri= -1;
    for(int i=0; i<*soLuong; i++){
        if(books[i].id == id){
            viTri=i;
            break;
        }
    }
    if(viTri == -1){
        printf("\nKhong tim thay sach co ma %d\n", id);
        return;
    }
    for(int i=viTri; i<*soLuong-1; i++){
        books[i] = books[i+1];
    }
    (*soLuong)--;
    printf("\nDa xoa sach co ma %d\n", id);
}
void capNhatThongTinSach(struct Book books[], int soLuong){
    int id;
    printf("\nNhap ma sach can cap nhat: ");
    scanf("%d", &id);

    int viTri= -1;
    for(int i=0; i<soLuong; i++){
        if(books[i].id == id){
            viTri=i;
            break;
        }
    }
    if(viTri== -1){
        printf("\nKhong tim thay sach co ma %d\n", id);
        return;
    }
    printf("\nNhap thong tin moi cho sach co ma %d:\n", id);
    printf("Ten sach: ");
    getchar();
    fgets(books[viTri].title, sizeof(books[viTri].title), stdin);
    books[viTri].title[strcspn(books[viTri].title, "\n")] = 0;
    fflush(stdin);
    printf("Tac gia: ");
    fgets(books[viTri].author, sizeof(books[viTri].author), stdin);
    books[viTri].author[strcspn(books[viTri].author, "\n")] = 0;
    fflush(stdin);
    printf("Gia tien: ");
    scanf("%f", &books[viTri].price);
    getchar();
    fflush(stdin);
    printf("The loai: ");
    fgets(books[viTri].genre, sizeof(books[viTri].genre), stdin);
    books[viTri].genre[strcspn(books[viTri].genre, "\n")] = 0;
}
void sapXepSachTheoGia(struct Book books[], int soLuong, int tangDan){
    for(int i=0; i<soLuong-1; i++){
        for(int j=i+1; j<soLuong; j++){
            if((tangDan && books[i].price > books[j].price) || (!tangDan && books[i].price < books[j].price)){
                struct Book temp = books[i];
                books[i]=books[j];
                books[j]=temp;
            }
        }
    }
    printf("\nDanh sach da duoc sap xep\n");
}
void timKiemSachTheoTen(struct Book books[], int soLuong){
    char tenTimKiem[100];
    printf("\nNhap ten sach can tim: ");
    getchar();
    fgets(tenTimKiem, sizeof(tenTimKiem), stdin);
    tenTimKiem[strcspn(tenTimKiem, "\n")] = 0;
    printf("\nKet qua tim kiem:\n");
    int found=0;
    for(int i=0; i<soLuong; i++){
        if (strstr(books[i].title, tenTimKiem)){
            printf("\nSach %d:\n", i+1);
            printf("Ma sach: %d\n", books[i].id);
            printf("Ten sach: %s\n", books[i].title);
            printf("Tac gia: %s\n", books[i].author);
            printf("Gia tien: %.2f\n", books[i].price);
            printf("The loai: %s\n", books[i].genre);
            found=1;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sach voi ten '%s'\n", tenTimKiem);
    }
}
