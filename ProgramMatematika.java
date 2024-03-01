import java.util.Scanner;

public class ProgramMatematika {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pilihan;

        float alas_segitiga;
        float tinggi_segitiga;
        float tinggi_prisma;
        float v_p_s;
        float l_p_p_s;

        float alas_limas_segitiga;
        float tinggi_segitiga_limas;
        float tinggi_limas_segitiga;
        float l_p_l_s;
        float v_l_s;

        float sisi_alas_limas;
        float tinggi_limas_segiempat;
        float l_p_l_s_e;
        float v_l_s_e;

        float jariJari;
        float l_p_b;
        float v_b;

        float panjang_sisi_prisma;
        float tinggi_prisma_segiempat;
        float l_p_p_s_e;
        float v_p_s_e;

        float alas_b_d_segitiga;
        float tinggi_b_d_segitiga;
        float luas_segitiga;

        float sisi_a;
        float sisi_b;
        float sisi_c;
        float keliling_segitiga;

        float jariJari_bd;
        float luas_lingkaran;
        float keliling_lingkaran;

        float sisi_alas_limas_segienam;
        float tinggi_limas_segienam;
        float l_p_l_s_enam;
        float v_l_s_enam;

        float sisi_alas_prisma_segilima;
        float tinggi_prisma_segilima;
        float l_p_p_segilima;

        float alas_jajar_genjang;
        float tinggi_jajar_genjang;
        float luas_jajargenjang;
        float sisi_miring_jajargenjang;
        float keliling_jajargenjang;

        float diagonal1;
        float diagonal2;
        float luas_belah_ketupat;
        float sisi_belah_ketupat;
        float keliling_belah_ketupat;

        float alas_trapesium1;
        float alas_trapesium2;
        float tinggi_trapesium;
        float luas_trapesium;

        float sisi_trapesium1;
        float sisi_trapesium2;
        float sisi_trapesium3;
        float sisi_trapesium4;
        float keliling_trapesium;

        float diagonal_layang1;
        float diagonal_layang2;
        float luas_layang;
        float sisi_layang1;
        float sisi_layang2;
        float keliling_layang;

        System.out.println("||=====================================================================================||");
        System.out.println("||                  Pilihlah Salah Satu yang Ingin Anda Gunakan                        ||");
        System.out.println("||=====================================================================================||");
        System.out.println("||          1. Volume Prisma Segitiga                                                  ||");
        System.out.println("||          2. Luas Permukaan Prisma Segitiga                                          ||");
        System.out.println("||          3. Luas Permukaan Limas Segitiga                                           ||");
        System.out.println("||          4. Volume Limas Segitiga                                                   ||");
        System.out.println("||          5. Luas Permukaan Limas Segiempat                                          ||");
        System.out.println("||          6. Volume Limas Segiempat                                                  ||");
        System.out.println("||          7. Luas Permukaan Bola                                                     ||");
        System.out.println("||          8. Volume Bola                                                             ||");
        System.out.println("||          9. Luas Permukaan Prisma Segiempat                                         ||");
        System.out.println("||          10. Volume Prisma Segiempat                                                ||");
        System.out.println("||          11. Luas Segitiga                                                          ||");
        System.out.println("||          12. Keliling Segitiga                                                      ||");
        System.out.println("||          13. Luas Lingkaran                                                         ||");
        System.out.println("||          14. Keliling Lingkaran                                                     ||");
        System.out.println("||          15. Luas Permukaan Limas Segienam                                          ||");
        System.out.println("||          16. Volume Limas Segienam                                                  ||");
        System.out.println("||          17. Luas Permukaan Prisma Segilima                                         ||");
        System.out.println("||          18. Luas Jajar Genjang                                                     ||");
        System.out.println("||          19. Keliling Jajar Genjang                                                 ||");
        System.out.println("||          20. Luas Belah Ketupat                                                     ||");
        System.out.println("||          21. Keliling Belah Ketupat                                                 ||");
        System.out.println("||          22. Luas Trapesium                                                         ||");
        System.out.println("||          23. keliling Trapesium                                                     ||");
        System.out.println("||          24. Luas Layang Layang                                                     ||");
        System.out.println("||          25. Keliling Layang Layang                                                 ||");
        System.out.println("||=====================================================================================||");
        System.out.print("Masukkan Pilihan Anda : ");
        pilihan = scanner.nextInt();

        switch (pilihan) {
            case 1:
                System.out.print("Masukkan Panjang Alas Segitiga : ");
                alas_segitiga = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Segitiga : ");
                tinggi_segitiga = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Prisma Segitiga : ");
                tinggi_prisma = scanner.nextFloat();
                v_p_s = volume_prisma_segitiga(alas_segitiga, tinggi_segitiga, tinggi_prisma);
                System.out.printf("Volume Prisma Segitiga Adalah : %.2f%n%n", v_p_s);
                break;
            case 2:
                System.out.print("Masukkan Panjang Alas Segitia : ");
                alas_segitiga = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Segitiga : ");
                tinggi_segitiga = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Prisma Segitiga : ");
                tinggi_prisma = scanner.nextFloat();
                l_p_p_s = luas_Permukaan_PrismaSegitiga(alas_segitiga, tinggi_segitiga, tinggi_prisma);
                System.out.printf("Luas Permukaan Prisma Segitiga Adalah : %.2f\n\n", l_p_p_s);
                break;
            case 3:
                System.out.print("Masukkan Panjang Alas Segitiga : ");
                alas_limas_segitiga = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Segitiga : ");
                tinggi_segitiga_limas = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Limas Segitiga : ");
                tinggi_limas_segitiga = scanner.nextFloat();
                l_p_l_s = luasPermukaanLimasSegitiga(alas_limas_segitiga, tinggi_segitiga_limas, tinggi_limas_segitiga);
                System.out.printf("Luas Permukaan Limas Segitiga : %.2f\n\n", l_p_l_s);
                break;
            case 4:
                System.out.print("Masukkan Panjang Alas Segitiga : ");
                alas_limas_segitiga = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Segitiga : ");
                tinggi_segitiga_limas = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Limas Segitiga : ");
                tinggi_limas_segitiga = scanner.nextFloat();
                v_l_s = volumeLimasSegitiga(alas_limas_segitiga, tinggi_segitiga_limas, tinggi_limas_segitiga);
                System.out.printf("Luas Permukaan Limas Segiempat Adalah : %.2f\n\n");
                break;
            case 5:
                System.out.print("Masukkan Panjang Sisi Alas Limas Segiempat : ");
                sisi_alas_limas = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Limas Segiempat : ");
                tinggi_limas_segiempat = scanner.nextFloat();
                l_p_l_s_e = luasPermukaanLimasSegiEmpat(sisi_alas_limas, tinggi_limas_segiempat);
                System.out.printf("Luas Permukaan Limas Segiempat Adalah : %.2f\n\n", l_p_l_s_e);
                break;
            case 6:
                System.out.print("Masukkan Panjang Sisi Alas Limas Segiempat : ");
                sisi_alas_limas = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Limas Segiempat : ");
                tinggi_limas_segiempat = scanner.nextFloat();
                v_l_s_e = volumeLimasSegiEmpat(sisi_alas_limas, tinggi_limas_segiempat);
                System.out.printf("Volume Limas Segiempat Adalah : %.2f\n\n");
                break;
            case 7:
                System.out.print("Masukkan Panjang Jari-jari Bola : ");
                jariJari = scanner.nextFloat();
                l_p_b = luasPermukaanBola(jariJari);
                System.out.printf("Luas Permukaan Bola Adalah : %.2f\n\n", l_p_b);
                break;
            case 8:
                System.out.print("Masukkan Panjang Jari-jari Bola : ");
                jariJari = scanner.nextFloat();
                v_b = volumeBola(jariJari);
                System.out.printf("Volume Bola Adalah : %.2f\n\n", v_b);
                break;
            case 9:
                System.out.print("Masukkan Panjang Sisi Prisma Segiempat : ");
                panjang_sisi_prisma = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Prisma Segiempat : ");
                tinggi_prisma_segiempat = scanner.nextFloat();
                l_p_p_s_e = luasPermukaanSegiEmpat(panjang_sisi_prisma, tinggi_prisma_segiempat);
                System.out.printf("Luas Permukaan Prisma Segiempat : ");
                break;
            case 10:
                System.out.print("Masukkan Panjang Sisi Prisma Segiempat : ");
                panjang_sisi_prisma = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Prisma Segiempat : ");
                tinggi_prisma_segiempat = scanner.nextFloat();
                v_p_s_e = volumePrismaSegiEmpat(panjang_sisi_prisma, tinggi_prisma_segiempat);
                System.out.printf("Volume Prisma Segiempat Adalah : ", v_p_s_e);
                break;
            case 11:
                System.out.print("Masukkan Panjang Alas Segitiga : ");
                alas_b_d_segitiga = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Segitiga : ");
                tinggi_b_d_segitiga = scanner.nextFloat();
                luas_segitiga = luasSegitiga(alas_b_d_segitiga, tinggi_b_d_segitiga);
                System.out.printf("Luas Segitiga Adalah : %.2f\n\n", luas_segitiga);
                break;
            case 12:
                System.out.print("Masukkan Panjang Sisi Pertama dari Segitiga : ");
                sisi_a = scanner.nextFloat();
                System.out.print("Masukkan Panjang Sisi Kedua dari Segitiga : ");
                sisi_b = scanner.nextFloat();
                System.out.print("Masukkan Panjang Sisi Ketiga dari Segitiga : ");
                sisi_c = scanner.nextFloat();
                keliling_segitiga = hitungKelilingSegitiga(sisi_a, sisi_b, sisi_c);
                System.out.printf("Keliling Segitiga Adalah : %.2f\n\n", keliling_segitiga);
                break;
            case 13:
                System.out.print("Masukkan Jari-jari Lingkaran : ");
                jariJari_bd = scanner.nextFloat();
                luas_lingkaran = hitungLuasLingkaran(jariJari_bd);
                System.out.printf("Luas Lingkaran Adalah : %.2f\n\n", jariJari_bd);
                break;
            case 14:
                System.out.print("Masukkan Jari-jari Lingkaran : ");
                jariJari_bd = scanner.nextFloat();
                keliling_lingkaran = hitungKelilingLingkaran(jariJari_bd);
                System.out.printf("Keliling Lingkaran Adalah : %.2f\n\n", jariJari_bd);
                break;
            case 15:
                System.out.print("Masukkan Panjang Sisi Alas Limas Segienam : ");
                sisi_alas_limas_segienam = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Limas Segienam : ");
                tinggi_limas_segienam = scanner.nextFloat();
                l_p_l_s_enam = hitungLuasPermukaanLimasSegienam(sisi_alas_limas_segienam, tinggi_limas_segienam);
                System.out.printf("Luas Permukaan Limas Segienam Adalah : %.2f\n\n", l_p_l_s_enam);
                break;
            case 16:
                System.out.print("Masukkan Panjang Sisi Alas Limas Segienam : ");
                sisi_alas_limas_segienam = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Limas Segienam : ");
                tinggi_limas_segienam = scanner.nextFloat();
                v_l_s_enam = hitungVolumeLimasSegienam(sisi_alas_limas_segienam, tinggi_limas_segienam);
                System.out.printf("Volume Limas Segienam Adalah : %.2f\n\n", v_l_s_enam);
                break;
            case 17:
                System.out.print("Masukkan Panjang Sisi Alas Prisma Segilima : ");
                sisi_alas_prisma_segilima = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Prisma Segilima : ");
                tinggi_prisma_segilima = scanner.nextFloat();
                l_p_p_segilima = hitungLuasPermukaanPrismaSegilima(sisi_alas_prisma_segilima, tinggi_prisma_segilima);
                System.out.printf("Luas Permukaan Prisma Segilima Adalah : %.2f\n\n", l_p_p_segilima);
                break;
            case 18:
                System.out.print("Masukkan Panjang Alas Jajar Genjang : ");
                alas_jajar_genjang = scanner.nextFloat();
                System.out.print("Masukkan Tinggi Jajar Genjang : ");
                tinggi_jajar_genjang = scanner.nextFloat();
                luas_jajargenjang = hitungLuasJajarGenjang(alas_jajar_genjang, tinggi_jajar_genjang);
                System.out.printf("Luas Jajar Genjang Adalah : %.2f\n\n", luas_jajargenjang);
                break;
            case 19:
                System.out.print("Masukkan Panjang Alas Jajar Genjang : ");
                alas_jajar_genjang = scanner.nextFloat();
                System.out.print("Masukkan Sisi Miring Jajar Genjang : ");
                sisi_miring_jajargenjang = scanner.nextFloat();
                keliling_jajargenjang = hitungKelilingJajarGenjang(alas_jajar_genjang, sisi_miring_jajargenjang);
                System.out.printf("Keliling Jajar Genjang Adalah : %.2f\n\n", keliling_jajargenjang);
                break;
            case 20:
                System.out.print("Masukkan Panjang Diagonal 1 dari Belah Ketupat : ");
                diagonal1 = scanner.nextFloat();
                System.out.print("Masukkan Panjang Diagonal 2 dari Belah Ketupat : ");
                diagonal2 = scanner.nextFloat();
                luas_belah_ketupat = hitungLuasBelahKetupat(diagonal1, diagonal2);
                System.out.printf("Luas Belah Ketupat Adalah : %.2f\n\n", luas_belah_ketupat);
                break;
            case 21:
                System.out.print("Masukkan Panjang Sisi Belah Ketupat : ");
                sisi_belah_ketupat = scanner.nextFloat();
                keliling_belah_ketupat = hitungKelilingBelahKetupat(sisi_belah_ketupat);
                System.out.printf("Keliling Belah Ketupat Adalah : %.2f\n\n", keliling_belah_ketupat);
                break;
            case 22:
                System.out.print("Masukkan Panjang Alas Atas dari Trapesium : ");
                alas_trapesium1 = scanner.nextFloat();
                System.out.print("Masukkan Panjang Alas Bawah dari Trapesium : ");
                alas_trapesium2 = scanner.nextFloat();
                System.out.print("Masukkan Tinggi dari Trapesium : ");
                tinggi_trapesium = scanner.nextFloat();
                luas_trapesium = hitungLuasTrapesium(alas_trapesium1, alas_trapesium2, tinggi_trapesium);
                System.out.printf("Luas Trapesium Adalah : %.2f\n\n", luas_trapesium);
                break;
            case 23:
                System.out.print("Masukkan Panjang Sisi Atas pada Trapesium : ");
                sisi_trapesium1 = scanner.nextFloat();
                System.out.print("Masukkan Panjang Sisi Bawah pada Trapesium : ");
                sisi_trapesium2 = scanner.nextFloat();
                System.out.print("Masukkan Panjang Sisi Samping A dari Trapesium : ");
                sisi_trapesium3 = scanner.nextFloat();
                System.out.print("Masukkan Panjang Sisi Samping B dari Trapesium : ");
                sisi_trapesium4 = scanner.nextFloat();
                keliling_trapesium = hitungKelilingTrapesium(sisi_trapesium1, sisi_trapesium2, sisi_trapesium3,
                        sisi_trapesium4);
                System.out.printf("Keliling Trapesim Adalah : ", keliling_trapesium);
                break;
            case 24:
                System.out.print("Masukkan Panjang Diagonal 1 dari Layang-layang : ");
                diagonal_layang1 = scanner.nextFloat();
                System.out.print("Masukkan Panjang Diagonal 2 dari Layang-layang : ");
                diagonal_layang2 = scanner.nextFloat();
                luas_layang = hitungLuasLayangLayang(diagonal_layang1, diagonal_layang2);
                System.out.printf("Luas Layang-layang Adalah : %.2f\n\n", luas_layang);
                break;
            case 25:
                System.out.print("Masukkan Panjang Sisi Layang-layang 1 : ");
                sisi_layang1 = scanner.nextFloat();
                System.out.print("Masukkan Panjang Sisi Layang-layang 2 : ");
                sisi_layang2 = scanner.nextFloat();
                keliling_layang = hitungKelilingLayangLayang(sisi_layang1, sisi_layang2);
                System.out.printf("Keliling Layang-layang Adalah : %.2f\n\n", keliling_layang);
                break;
            default:
                System.out.println("Pilihan Tidak Valid : ");
        }
        scanner.close();
    }
    
    
    

    static float volume_prisma_segitiga(float alas_segitiga, float tinggi_segitiga, float tinggi_prisma)
    {
        return 0.5f * alas_segitiga * tinggi_segitiga * tinggi_prisma;
    }

    static float luas_Permukaan_PrismaSegitiga(float alas_segitiga, float tinggi_segitiga, float tinggi_prisma)
    {
        return 2 * (0.5f * alas_segitiga * tinggi_segitiga ) + (alas_segitiga * tinggi_prisma);
    }

    static float luasPermukaanLimasSegitiga( float alas_limas_segitiga, float tinggi_segitiga_limas, float tinggi_limas_segitiga)
    {
        return (0.5f * alas_limas_segitiga * tinggi_segitiga_limas) + (3 * alas_limas_segitiga * tinggi_limas_segitiga);
    }

    static float volumeLimasSegitiga(float alas_limas_segitiga, float tinggi_segitiga_limas, float tinggi_limas_segitiga)
    {
        return (1.0f / 3.0f) * (alas_limas_segitiga * tinggi_segitiga_limas * tinggi_limas_segitiga);
    }

    static float luasPermukaanLimasSegiEmpat( float sisi_alas_limas, float tinggi_limas_segiempat)
    {
        return sisi_alas_limas * sisi_alas_limas + 4 * (0.5f * sisi_alas_limas * tinggi_limas_segiempat);
    }
    
    static float volumeLimasSegiEmpat( float sisi_alas_limas, float tinggi_limas_segiempat)
    {
        return (1.0f / 3.0f) * sisi_alas_limas * sisi_alas_limas * tinggi_limas_segiempat;
    }

    static float luasPermukaanBola(float jariJari)
    {
        return 4.0f * 3.14f * jariJari * jariJari;
    }

    static float volumeBola(float jariJari)
    {
        return (4.0f / 3.0f) * 3.14f * jariJari * jariJari * jariJari;
    }
    
    static float luasPermukaanSegiEmpat(float panjang_sisi_prisma, float tinggi_prisma_segiempat)
    {
        return 2 * (panjang_sisi_prisma * panjang_sisi_prisma + panjang_sisi_prisma * tinggi_prisma_segiempat);
    }

    static float volumePrismaSegiEmpat(float panjang_sisi_prisma, float tinggi_prisma_segiempat)
    {
        return panjang_sisi_prisma * panjang_sisi_prisma * tinggi_prisma_segiempat;
    }

    static float luasSegitiga(float alas_b_d_segitiga, float tinggi_b_d_segitiga)
    {
        return 0.5f * alas_b_d_segitiga * tinggi_b_d_segitiga;
    }

    static float hitungKelilingSegitiga(float sisi_a, float sisi_b, float sisi_c)
    {
        return sisi_a + sisi_b + sisi_c;
    }

    static float hitungLuasLingkaran(float jariJari_bd)
    {
        return 3.14f * jariJari_bd * jariJari_bd;
    }

    static float hitungKelilingLingkaran(float jariJari_bd)
    {
        return 2 * 3.14f * jariJari_bd;
    }

    static float hitungLuasPermukaanLimasSegienam(float sisi_alas_limas_segienam, float tinggi_limas_segienam)
    {
        return 3 * sisi_alas_limas_segienam * sisi_alas_limas_segienam * tinggi_limas_segienam / 2;
    }

    static float hitungVolumeLimasSegienam(float sisi_alas_limas_segienam, float tinggi_limas_segienam)
    {
        return (1.0f / 3.0f) * sisi_alas_limas_segienam * sisi_alas_limas_segienam * tinggi_limas_segienam;
    }
    
    static float hitungLuasPermukaanPrismaSegilima(float sisi_alas_prisma_segilima, float tinggi_prisma_segilima)
    {
        return 5 * (sisi_alas_prisma_segilima * tinggi_prisma_segilima);
    }

    static float hitungLuasJajarGenjang(float alas_jajar_genjang, float tinggi_jajar_genjang)
    {
        return alas_jajar_genjang * tinggi_jajar_genjang;
    }
    
    static float hitungKelilingJajarGenjang(float alas_jajar_genjang, float sisi_miring_jajargenjang)
    {
        return 2 * (alas_jajar_genjang + sisi_miring_jajargenjang);
    }

    static float hitungLuasBelahKetupat(float diagonal1, float diagonal2)
    {
        return (diagonal1 * diagonal2) / 2;
    }

    static float hitungKelilingBelahKetupat(float sisi_belah_ketupat)
    {
        return 4 * sisi_belah_ketupat;
    }

    static float hitungLuasTrapesium( float alas_trapesium1, float alas_trapesium2, float tinggi_trapesium)
    {
        return 0.5f * (alas_trapesium1 + alas_trapesium2) * tinggi_trapesium;
    }

    static float hitungKelilingTrapesium( float sisi_trapesium1, float sisi_trapesium2, float sisi_trapesium3, float sisi_trapesium4)
    {
        return sisi_trapesium1 + sisi_trapesium2 + sisi_trapesium3 + sisi_trapesium4;
    }

    static float hitungLuasLayangLayang( float diagonal_layang1, float diagonal_layang2)
    {
        return (diagonal_layang1 * diagonal_layang2) / 2;
    }

    static float hitungKelilingLayangLayang(float sisi_layang1, float sisi_layang2)
    {
        return 2 * (sisi_layang1 + sisi_layang2);
    }
}
