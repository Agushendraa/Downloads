#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

#define PI 3.14159

void printUI();
void menu();
double hitungVolumeTabung(double radius, double height);
double hitungLuasPermukaanTabung(double radius, double height);
double hitungVolumeBola(double radius);
double hitungLuasPermukaanBola(double radius);
double hitungVolumeLimasSegiempat(double baseSideLength, double pyramidHeight);
double hitungLuasPermukaanLimasSegiempat(double baseSideLength, double pyramidHeight);
double hitungVolumePrismaSegitiga(double baseLength, double prismHeight, double triangleHeight);
double hitungLuasPermukaanPrismaSegitiga(double baseLength, double prismHeight, double triangleHeight);
double hitungVolumeKerucut(double radius, double coneHeight);
double hitungLuasPermukaanKerucut(double radius, double coneHeight);
char lanjutkanProgram();
void validasiInputInt(int *var, const char *pesan);
void validasiInputDouble(double *var, const char *pesan);

int main() {
    int pilihan;
    
    printUI();
    
    do {
        menu();
        validasiInputInt(&pilihan, "\t\t\tPilih bangun ruang (1-6): ");

        switch (pilihan) {
            case 1: {
                double radius, height;
                validasiInputDouble(&radius, "\t\t\tMasukkan jari-jari tabung: ");
                validasiInputDouble(&height, "\t\t\tMasukkan tinggi tabung: ");
                printf("\t\t\tVolume Tabung: %.2lf\n", hitungVolumeTabung(radius, height));
                printf("\t\t\tLuas Permukaan Tabung: %.2lf\n", hitungLuasPermukaanTabung(radius, height));
                break;
            }
            case 2: {
                double radius;
                validasiInputDouble(&radius, "\t\t\tMasukkan jari-jari bola: ");
                printf("\t\t\tVolume Bola: %.2lf\n", hitungVolumeBola(radius));
                printf("\t\t\tLuas Permukaan Bola: %.2lf\n", hitungLuasPermukaanBola(radius));
                break;
            }
            case 3: {
                double baseSideLength, pyramidHeight;
                validasiInputDouble(&baseSideLength, "\t\t\tMasukkan panjang sisi alas limas segiempat: ");
                validasiInputDouble(&pyramidHeight, "\t\t\tMasukkan tinggi limas: ");
                printf("\t\t\tVolume Limas Segiempat: %.2lf\n", hitungVolumeLimasSegiempat(baseSideLength, pyramidHeight));
                printf("\t\t\tLuas Permukaan Limas Segiempat: %.2lf\n", hitungLuasPermukaanLimasSegiempat(baseSideLength, pyramidHeight));
                break;
            }
            case 4: {
                double baseLength, prismHeight, triangleHeight;
                validasiInputDouble(&baseLength, "\t\t\tMasukkan panjang alas segitiga: ");
                validasiInputDouble(&triangleHeight, "\t\t\tMasukkan tinggi segitiga: ");
                validasiInputDouble(&prismHeight, "\t\t\tMasukkan tinggi prisma: ");
                printf("\t\t\tVolume Prisma Segitiga: %.2lf\n", hitungVolumePrismaSegitiga(baseLength, prismHeight, triangleHeight));
                printf("\t\t\tLuas Permukaan Prisma Segitiga: %.2lf\n", hitungLuasPermukaanPrismaSegitiga(baseLength, prismHeight, triangleHeight));
                break;
            }
            case 5: {
                double radius, coneHeight;
                validasiInputDouble(&radius, "\t\t\tMasukkan jari-jari kerucut: ");
                validasiInputDouble(&coneHeight, "\t\t\tMasukkan tinggi kerucut: ");
                printf("\t\t\tVolume Kerucut: %.2lf\n", hitungVolumeKerucut(radius, coneHeight));
                printf("\t\t\tLuas Permukaan Kerucut: %.2lf\n", hitungLuasPermukaanKerucut(radius, coneHeight));
                break;
            }
            case 6: { 
                printf("\t\t\tTerimakasih telah menggunakan program ini\n");
                break;
            }
            default: {
                printf("\t\t\tPilihan tidak valid.\n");
                break;
            }
        }
    } while (lanjutkanProgram() == 'y'); 
    
    system("cls"); 
    printf("\t\t\tTerimakasih telah menggunakan program ini\n");
    return 0;
}

void menu() {
    printf("\n\t\t\t=====================================================\n");
    printf("\t\t\t||                 PILIH BANGUN RUANG              ||\n");
    printf("\t\t\t||  PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN   ||\n");
    printf("\t\t\t=====================================================\n");
    printf("\t\t\t||              1. Tabung                          ||\n");                               
    printf("\t\t\t||              2. Bola                            ||\n");
    printf("\t\t\t||              3. Limas Segiempat                 ||\n");
    printf("\t\t\t||              4. Prisma Segitiga                 ||\n");
    printf("\t\t\t||              5. Kerucut                         ||\n");
    printf("\t\t\t||              6. Keluar                          ||\n");
    printf("\t\t\t=====================================================\n");
}

char lanjutkanProgram() {
    char pilihan;
    printf("\t\t\tApakah ingin kembali ke menu utama? (y/n): ");
    scanf(" %c", &pilihan);
    while (getchar() != '\n'); 
    return pilihan; 
}

void validasiInputDouble(double *var, const char *pesan) {
    char buff[1000]; 
    char check; 

    while (1) {
        printf("%s", pesan); 
        fflush(stdin); 
        if (fgets(buff, sizeof(buff), stdin) != NULL) { 
            if (sscanf(buff, "%lf %c", var, &check) == 1) { 
                break; 
            }
        }
        printf("\t\t\t\t\tInput salah! Silakan masukkan angka.\n"); 
    }
}

void validasiInputInt(int *var, const char *pesan) {
    char buff[1000]; 
    char check; 

    while (1) {
        printf("%s", pesan); 
        fflush(stdin); 
        if (fgets(buff, sizeof(buff), stdin) != NULL) { 
            if (sscanf(buff, "%d %c", var, &check) == 1) { 
                break; 
            }
        }
        printf("\t\t\t\t\tInput salah! Silakan masukkan angka.\n"); 
    }
}

double hitungVolumeTabung(double radius, double height) {
    return PI * radius * radius * height;
}

double hitungLuasPermukaanTabung(double radius, double height) {
    return 2 * PI * radius * (radius + height);
}

double hitungVolumeBola(double radius) {
    return (4.0 / 3.0) * PI * pow(radius, 3);
}

double hitungLuasPermukaanBola(double radius) {
    return 4 * PI * radius * radius;
}

double hitungVolumeLimasSegiempat(double baseSideLength, double pyramidHeight) {
    return (1.0 / 3.0) * baseSideLength * baseSideLength * pyramidHeight;
}

double hitungLuasPermukaanLimasSegiempat(double baseSideLength, double pyramidHeight) {
    double baseArea = baseSideLength * baseSideLength;
    double sideArea = 2 * baseSideLength * sqrt((baseSideLength / 2) * (baseSideLength / 2) + pyramidHeight * pyramidHeight);
    return baseArea + sideArea; 
}

double hitungVolumePrismaSegitiga(double baseLength, double prismHeight, double triangleHeight) {
    return (0.5 * baseLength * triangleHeight) * prismHeight;
}

double hitungLuasPermukaanPrismaSegitiga(double baseLength, double prismHeight, double triangleHeight) {
    double baseArea = 0.5 * baseLength * triangleHeight;
    double basePerimeter = baseLength + 2 * sqrt((baseLength / 2) * (baseLength / 2) + triangleHeight * triangleHeight);
    return 2 * baseArea + basePerimeter * prismHeight;
}

double hitungVolumeKerucut(double radius, double coneHeight) {
    return (1.0 / 3.0) * PI * radius * radius * coneHeight;
}

double hitungLuasPermukaanKerucut(double radius, double coneHeight) {
double slantHeight = sqrt(radius * radius + coneHeight * coneHeight);
   return PI * radius * (radius + slantHeight);
}

void printUI() {
    system("cls"); 
    printf("\t\t\t=====================================================\n");
    printf("\t\t\t||                  PROGRAM MODUL 1                ||\n");
    printf("\t\t\t||   PROGRAM MENGHITUNG LUAS ALAS DAN VOLUME       ||\n");
    printf("\t\t\t=====================================================\n");
    printf("\t\t\tTekan Enter untuk melanjutkan... "); 
    getchar(); 
}