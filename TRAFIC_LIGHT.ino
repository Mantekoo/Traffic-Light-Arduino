// Pin untuk lampu tiap simpang: Merah, Kuning, Hijau
const int redPins[]    = {4, 7, 10, 13};
const int yellowPins[] = {3, 6, 9, 12};
const int greenPins[]  = {2, 5, 8, 11};

const int jumlahSimpang = 4;

void setup() {
  // Set semua pin sebagai output
  for (int i = 0; i < jumlahSimpang; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }
}

void loop() {
  for (int aktif = 0; aktif < jumlahSimpang; aktif++) {
    // Semua simpang merah
    allRed();

    // Fase transisi: merah + kuning untuk simpang aktif
    digitalWrite(yellowPins[aktif], HIGH);
    delay(3000); // 3 detik

    // Fase hijau: hanya simpang aktif yang hijau, lainnya tetap merah
    digitalWrite(redPins[aktif], LOW);
    digitalWrite(yellowPins[aktif], LOW);
    digitalWrite(greenPins[aktif], HIGH);
    delay(5000); // 5 detik

    // Fase kuning: simpang aktif
    digitalWrite(greenPins[aktif], LOW);
    digitalWrite(yellowPins[aktif], HIGH);
    delay(3000); // 3 detik

    // Matikan kuning simpang aktif (siap ganti ke simpang berikutnya)
    digitalWrite(yellowPins[aktif], LOW);
  }
}

void allRed() {
  // Semua lampu merah menyala, lainnya mati
  for (int i = 0; i < jumlahSimpang; i++) {
    digitalWrite(redPins[i], HIGH);
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(greenPins[i], LOW);
  }
}
