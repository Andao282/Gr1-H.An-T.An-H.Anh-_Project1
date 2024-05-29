#include <bits/stdc++.h>

using namespace std;

struct sinhvien{
    string hoten;
    int ngaysinh;
    char gioitinh;
    float diem;
};

void nhapthongtinmotsv(sinhvien *sv){
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, sv->hoten);
    
    do {
        cout <<"Nhap ngay sinh: ";
        cin >> sv-> ngaysinh;
        if (sv-> ngaysinh < 1 || sv -> ngaysinh > 31) {
            cout << "Ngay sinh khong hop le! Vui long nhap lai." << endl;
        }
    } while (sv->ngaysinh < 1 || sv -> ngaysinh > 31);
    
    do {
        cout << "Nhap gioi tinh (Male/Female)(M/F): ";
        cin >> sv->gioitinh;
        if (sv -> gioitinh != 'M' && sv -> gioitinh != 'F'){
        	cout << "Gioi tinh khong hop le! Vui long nhap lai. " << endl;
		}
    } while (sv -> gioitinh != 'M' && sv -> gioitinh != 'F');

    do {
        cout << "Nhap diem: ";
        cin >> sv->diem;
        if (sv->diem < 0 || sv->diem > 10) {
            cout << "Diem khong hop le! Vui long nhap lai." << endl;
        }
    } while (sv->diem < 0 || sv->diem > 10);
}

void nhapds(sinhvien *sv, int n){
    for(int i=0; i<n; i++) 
	{
		cout<<"Sinh vien thu "<<i+1<<endl;
        nhapthongtinmotsv(&sv[i]);
    }
}

void inthongtin(const sinhvien& sv){
    cout << "Ho ten: " << sv.hoten << endl;
    cout << "Ngay sinh: " << sv.ngaysinh << endl;
    cout << "Gioi tinh: " << sv.gioitinh << endl;
    cout << "Diem: "<< sv.diem << endl;
}

void hienthidanhsach(sinhvien sv[], int n){
	
	for (int i = 0; i < n; i++) 
	{
        cout << "Sinh vien thu "<< i+1 <<": "<< endl;
        inthongtin(sv[i]);
        cout << "-------------------------" << endl;
    }
}

void Suathongtin(sinhvien &sv){
    cout << "Nhap thong tin moi cho sinh vien: " << sv.hoten << endl;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin,sv.hoten);
    do {
        cout <<"Nhap ngay sinh: ";
        cin >> sv.ngaysinh;
        if (sv.ngaysinh < 1 || sv .ngaysinh > 31) {
            cout << "Ngay sinh khong hop le! Vui long nhap lai." << endl;
        }
    } while (sv.ngaysinh < 1 || sv . ngaysinh > 31);
    
    do {
        cout << "Nhap gioi tinh (Male/Female)(M/F): ";
        cin >> sv.gioitinh;
        if (sv . gioitinh != 'M' && sv . gioitinh != 'F'){
        	cout << "Gioi tinh khong hop le! Vui long nhap lai. " << endl;
		}
    } while (sv . gioitinh != 'M' && sv. gioitinh != 'F');

    do {
        cout << "Nhap diem: ";
        cin >> sv.diem;
        if (sv.diem < 0 || sv.diem > 10) {
            cout << "Diem khong hop le! Vui long nhap lai." << endl;
        }
    } while (sv.diem < 0 || sv.diem > 10);
}

void chenThongTinSinhVien(sinhvien *sv, int &n) {
    int vitri;
    cout << "Nhap vi tri muon chen: ";
    cin >> vitri;
    if (vitri >= 1 && vitri <= n + 1) {
        sinhvien svMoi;
        nhapthongtinmotsv (&svMoi);
        for (int i = n; i >= vitri; i--) {
            sv[i] = sv[i - 1];
        }
        sv[vitri - 1] = svMoi;
        n++; 
        cout << "Da chen thong tin sinh vien moi vao vi tri " << vitri << endl;
    } else {
        cout << "Vi tri chen khong hop le!" << endl;
    }
}

void sapXepTheoDiemGiamDan(sinhvien *sv, int n) {
		for (int i = 0; i < n - 1; i++) {
        	for (int j = i + 1; j < n; j++) {
            	if (sv[i].diem < sv[j].diem) {
                swap(sv[i], sv[j]);
            	}
        	}
    	}
}

sinhvien timSinhVienDiemCaoNhat(const sinhvien *sv, int n){
    sinhvien svMax = sv[0];
    for (int i = 1; i < n; ++i) {
        if (sv[i].diem > svMax.diem) {
            svMax = sv[i];
        }
    }
    return svMax;
}

void sinhVienNamCaoDiemNhatVaNuThapDiemNhat(const sinhvien *sv, int n) {
    sinhvien svNamMax = {"", 0, 'M', 0};
    sinhvien svNuMin = {"", 0, 'F', 10};

    for (int i = 0; i < n; ++i) {
        if (sv[i].gioitinh == 'M' && sv[i].diem > svNamMax.diem) {
            svNamMax = sv[i];
        }
        if (sv[i].gioitinh == 'F' && sv[i].diem < svNuMin.diem) {
            svNuMin = sv[i];
        }
    }

    cout << "Sinh vien nam co diem cao nhat: " << endl;
    inthongtin(svNamMax);
    cout << "-------------------------" << endl;
    cout << "Sinh vien nu co diem thap nhat: " << endl;
    inthongtin(svNuMin);
    cout << "-------------------------" << endl;
}

void danhSachSinhVienTenBatDauBangN(const sinhvien *sv, int n) {
	cout << "Danh sach sinh vien co ten bat dau bang chu 'N': "<<endl;
    for(int i = 0; i < n; ++i) 
	{
        if (sv[i].hoten[0] == 'N') 
		{
            inthongtin(sv[i]);
            cout<<"-------------------------" << endl;
        }
    }
}

void Menu (){
    cout << "/t/t================MENU================" << endl;
    cout << "/t/t1. Nhap thong tin 1 sinh vien. "<< endl;
    cout << "/t/t2. Nhap thong tin danh sach sinh vien. "<< endl;
    cout << "/t/t3. In thong tin 1 sinh vien. "<< endl;
    cout << "/t/t4. Hien thi danh sach sinh vien. "<< endl;
    cout << "/t/t5. Sua thong tin 1 sinh vien. "<< endl;
    cout << "/t/t6. Chen thong tin 1 sinh vien. " << endl;
    cout << "/t/t7. Sap xep danh sach theo diem. " << endl;
    cout << "/t/t8. Sinh vien diem cao nhat. " << endl;
    cout << "/t/t9. Sinh vien nam cao diem nhat & sinh vien nu thap diem nhat. " << endl;
    cout << "/t/t10. Danh sach sinh vien ten bat dau bang chu 'N'. "<< endl;
    cout << "/t/t====================================" <<endl;
}

int main(){
    int n;
    sinhvien *sv1;
    int luachon;
    
    do {
        Menu();
        cout << "Nhap lua chon cua ban (1-10): ";
        cin >> luachon;
        
        switch (luachon){
            case 1:
                sv1 = new sinhvien[1];
                nhapds(sv1, 1);
                break;
            case 2:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                sv1 = new sinhvien[n];
                nhapds(sv1, n);
                break;
            case 3:
                int k;
                cout << "Nhap vi tri sinh vien can xem: ";
                cin >> k;
                if (k >= 1 && k <= n) {
                    inthongtin(sv1[k - 1]); 
                } else {
                    cout << "Vi tri sinh vien khong hop le!" << endl;
                }
                break;
            case 4:
                hienthidanhsach(sv1, n);
                break;
            case 5:
                int vitri;
                cout << "Nhap vi tri sinh vien muon sua: ";
                cin >> vitri;
                if (vitri >= 1 && vitri <= n) {
                    Suathongtin(sv1[vitri - 1]); 
                    cout << "Da sua thong tin cho sinh vien thu " << vitri << endl;
                } else {
                    cout << "Vi tri sinh vien khong hop le!" << endl;
                }
                break;
            case 6:
                chenThongTinSinhVien(sv1, n);
                break;
            case 7:
                sapXepTheoDiemGiamDan(sv1, n);
                hienthidanhsach(sv1, n);
                break;
            case 8:
            	{
               	sinhvien svMax = timSinhVienDiemCaoNhat(sv1, n);
                cout << "Sinh vien co diem cao nhat: " << endl;
                inthongtin(svMax);
                cout << "-------------------------" << endl;
                break;
            }
            case 9:
            	sinhVienNamCaoDiemNhatVaNuThapDiemNhat(sv1, n);
                break;
            case 10:
			    danhSachSinhVienTenBatDauBangN(sv1, n);
                break;
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                break;
        }
    } while (luachon != 0);

    return 0;
}
