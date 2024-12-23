#include <stdio.h>
#include <string.h>

struct Product{
    int id;
    char name[50];
    float importPrice;
    float sellPrice;
    int quantity;
};
void nhapSanPham(struct Product products[], int *soLuong, float *doanhThu);
void hienThiSanPham(struct Product products[], int soLuong);
void nhapHang(struct Product products[], int *soLuong, float *doanhThu);
void capNhatSanPham(struct Product products[], int soLuong);
void sapXepSanPham(struct Product products[], int soLuong);
void timKiemSanPham(struct Product products[], int soLuong);
void banSanPham(struct Product products[], int *soLuong, float *doanhThu);
void hienThiDoanhThu(float doanhThu);

int main(){
    struct Product products[50];
    int soLuong=0;
    float doanhThu=0.0f;
    int luaChon;
    do{
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham (them vao kho)\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/giam)\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Hien thi doanh thu\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon){
            case 1:
                nhapSanPham(products, &soLuong, &doanhThu);
                break;
            case 2:
                hienThiSanPham(products, soLuong);
                break;
            case 3:
                nhapHang(products, &soLuong, &doanhThu);
                break;
            case 4:
                capNhatSanPham(products, soLuong);
                break;
            case 5:
                sapXepSanPham(products, soLuong);
                break;
            case 6:
                timKiemSanPham(products, soLuong);
                break;
            case 7:
                banSanPham(products, &soLuong, &doanhThu);
                break;
            case 8:
                hienThiDoanhThu(doanhThu);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (luaChon!=9);

    return 0;
}
void nhapSanPham(struct Product products[], int *soLuong, float *doanhThu){
    printf("Nhap so luong san pham: ");
    scanf("%d", soLuong);
    for(int i=0; i<*soLuong; i++){
        printf("\nNhap thong tin san pham thu %d:\n", i+1);
        printf("Ma san pham: ");
        scanf("%d", &products[i].id);
        printf("Ten san pham: ");
        getchar();
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")]=0;
        printf("Gia nhap: ");
        scanf("%f", &products[i].importPrice);
        printf("Gia ban: ");
        scanf("%f", &products[i].sellPrice);
        printf("So luong: ");
        scanf("%d", &products[i].quantity);
        *doanhThu -= products[i].quantity * products[i].importPrice;
    }
}
void hienThiSanPham(struct Product products[], int soLuong){
    if(soLuong==0){
        printf("Khong co san pham nao trong danh sach\n");
        return;
    }
    for(int i=0; i<soLuong; i++){
        printf("\nSan pham %d:\n", i+1);
        printf("Ma san pham: %d\n", products[i].id);
        printf("Ten san pham: %s\n", products[i].name);
        printf("Gia nhap: %.2f\n", products[i].importPrice);
        printf("Gia ban: %.2f\n", products[i].sellPrice);
        printf("So luong: %d\n", products[i].quantity);
    }
}
void nhapHang(struct Product products[], int *soLuong, float *doanhThu){
    int id, soLuongNhap;
    printf("Nhap ma san pham can nhap: ");
    scanf("%d", &id);
    for(int i=0; i<*soLuong; i++){
        if(products[i].id == id){
            printf("Nhap so luong can nhap: ");
            scanf("%d", &soLuongNhap);
            products[i].quantity += soLuongNhap;
            *doanhThu -= soLuongNhap * products[i].importPrice;
            printf("Da cap nhat so luong san pham\n");
            return;
        }
    }
    printf("San pham moi. Nhap thong tin san pham:\n");
    products[*soLuong].id=id;
    printf("Ten san pham: ");
    getchar();
    fgets(products[*soLuong].name, sizeof(products[*soLuong].name), stdin);
    products[*soLuong].name[strcspn(products[*soLuong].name, "\n")] = 0;
       printf("Gia ban: ");
    scanf("%f", &products[*soLuong].sellPrice);
    printf("Gia nhap: ");
    scanf("%f", &products[*soLuong].importPrice);
    printf("So luong: ");
    scanf("%d", &products[*soLuong].quantity);
    *doanhThu -= products[*soLuong].quantity * products[*soLuong].importPrice;
    (*soLuong)++;
}
void capNhatSanPham(struct Product products[], int soLuong){
    int id;
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%d", &id);
    for(int i=0; i<soLuong; i++){
        if (products[i].id==id){
            printf("Cap nhat thong tin san pham:\n");
            printf("Ten san pham: ");
            getchar();
            fgets(products[i].name, sizeof(products[i].name), stdin);
            products[i].name[strcspn(products[i].name, "\n")] = 0;
            printf("Gia nhap: ");
            scanf("%f", &products[i].importPrice);
            printf("Gia ban: ");
            scanf("%f", &products[i].sellPrice);
            printf("So luong: ");
            scanf("%d", &products[i].quantity);
            printf("Thong tin san pham da duoc cap nhat\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ma da nhap\n");
}
void sapXepSanPham(struct Product products[], int soLuong){
    int tangGiam;
    printf("Nhap 1 de sap xep tang, 0 de sap xep giam: ");
    scanf("%d", &tangGiam);
    for(int i=0; i<soLuong-1; i++){
        for(int j=i+1; j<soLuong; j++){
            if ((tangGiam && products[i].sellPrice > products[j].sellPrice) || (!tangGiam && products[i].sellPrice < products[j].sellPrice)){
                struct Product temp = products[i];
                products[i]=products[j];
                products[j]=temp;
            }
        }
    }
    printf("San pham da duoc sap xep\n");
}
void timKiemSanPham(struct Product products[], int soLuong){
    char tenTimKiem[100];
    printf("Nhap ten san pham can tim: ");
    getchar();
    fgets(tenTimKiem, sizeof(tenTimKiem), stdin);
    tenTimKiem[strcspn(tenTimKiem, "\n")] = 0;
    printf("Ket qua tim kiem:\n");
    int found=0;
    for(int i=0; i<soLuong; i++){
        if (strstr(products[i].name, tenTimKiem)){
            printf("\nSan pham %d:\n", i + 1);
            printf("Ma san pham: %d\n", products[i].id);
            printf("Ten san pham: %s\n", products[i].name);
            printf("Gia nhap: %.2f\n", products[i].importPrice);
            printf("Gia ban: %.2f\n", products[i].sellPrice);
            printf("So luong: %d\n", products[i].quantity);
            found=1;
        }
    }
    if (!found){
        printf("Khong tim thay san pham.\n");
    }
}
void banSanPham(struct Product products[], int *soLuong, float *doanhThu){
    int id, soLuongBan;
    printf("Nhap ma san pham can ban: ");
    scanf("%d", &id);
    for(int i=0; i<*soLuong; i++){
        if (products[i].id == id){
            printf("Nhap so luong can ban: ");
            scanf("%d", &soLuongBan);
            if (products[i].quantity==0){
                printf("San pham het hang\n");
                return;
            } else if (soLuongBan > products[i].quantity){
                printf("Khong du so luong hang trong kho\n");
                return;
            }
            products[i].quantity -= soLuongBan;
            *doanhThu += soLuongBan * products[i].sellPrice;
            printf("Ban san pham thanh cong\n");
            return;
        }
    }
    printf("Khong tim thay san pham \n");
}
void hienThiDoanhThu(float doanhThu){
    printf("Doanh thu hien tai: %.2f\n", doanhThu);
}
