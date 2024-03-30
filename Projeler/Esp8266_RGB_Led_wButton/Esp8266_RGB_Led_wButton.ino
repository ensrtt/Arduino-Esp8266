/**
 * RGB LED Kontrol Sistemi
 * Bu program, bir buton ve potansiyometre kullanarak RGB LED'in farklı renk modlarını kontrol etmeyi sağlar.
 * Butona her basıldığında, LED farklı bir renk moduna geçer. Modlar arasında statik renkler, fade efekti,
 * strobe efektleri ve potansiyometrenin pozisyonuna bağlı dinamik renk değişimleri bulunur.
 * Potansiyometrenin değeri seri port üzerinden gönderilir, bu sayede gerçek zamanlı değer takibi yapılabilir.
 *
 *Detaylı bilgi için ziyaret edin:
 *https://github.com/ensrtt/Arduino-Esp8266/tree/main/Projeler/Esp8266_RGB_Led_wButton
 *
 *ESP8266 Nodemcu Lolin V3 + Common Anode RGB Led + 2 Pin Button + 10k Potansiyometre
 * Pin Bağlantıları:
 * - Button Pin: 4 10k pull-down
 * - Red LED Pin: 14 220ohm direnç ile
 * - Green LED Pin: 12 220ohm direnç ile
 * - Blue LED Pin: 13 220ohm direnç ile
 * - Potansiyometre A0 Pin'e bağlı
 *
 * Debounce mekanizması sayesinde, buton sıçramaları engellenir ve düzgün bir geçiş sağlanır.
 * Seri haberleşme için 115200 baud rate kullanılır.
 */


// Pin tanımlamaları
int buttonPin = 4; // Buton pin
int redPin = 14;    // RGB LED'in kırmızı bacağı
int greenPin = 12; // Yeşil bacağı
int bluePin = 13;  // Mavi bacağı
int potValue = analogRead(A0); // Potansiyometre orta bacağı

int buttonState = 0;         // Butonun anlık durumu
int lastButtonState = LOW;   // Butonun son durumu
unsigned long lastDebounceTime = 0;  // Son değişikliğin zamanı
unsigned long debounceDelay = 50;    // Debounce gecikmesi (milisaniye)
int ledMode = 0;             // LED modu (0'dan başlayarak 7'ye kadar)
unsigned long lastPrintTime = 0; // Son yazdırma zamanını saklamak için
const long printInterval = 1000; // Yazdırma aralığı (ms)
int lastPotValue = -1; // Son potansiyometre değerini saklamak için (Başlangıçta geçersiz bir değer)



void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // Seri iletişimi başlat
  Serial.begin(115200);
}




void loop() {
  int reading = digitalRead(buttonPin);

  // Eğer buton durumu son okumadan farklıysa, zamanı sıfırla
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Eğer buton durumu değişiklikten sonra sabit kaldıysa
    if (reading != buttonState) {
      buttonState = reading;

      // Eğer buton basıldıysa, modu değiştir
      if (buttonState == HIGH) {
        ledMode = (ledMode + 1) % 10; // Modları 0-10 arası döndür
        changeLEDMode(ledMode);
      }
    }
  }

  // Butonun durumunu güncelle
  lastButtonState = reading;

  // Potansiyometre değerini oku
  int currentPotValue = analogRead(A0);
  // Sadece potansiyometre değeri değiştiyse veya belirli bir süre geçtiyse yazdır
  if (currentPotValue != lastPotValue || millis() - lastPrintTime >= printInterval) {
    lastPotValue = currentPotValue; // Son değeri güncelle
    lastPrintTime = millis(); // Son yazdırma zamanını güncelle
    
    // Değeri seri port üzerinden yazdır
    Serial.print("Potansiyometre Değeri: ");
    Serial.println(currentPotValue);

    // Maplenmiş değeri hesapla ve yazdır
    int mappedValue = map(currentPotValue, 0, 1023, 0, 255);
    Serial.print("Potansiyometre Map Değeri: ");
    Serial.println(mappedValue);
  }
}



void changeLEDMode(int mode) {
  switch (mode) {
    case 0: // Kapalı
      setColor(0, 0, 0);
      break;
    case 1: // Kırmızı
      setColor(255, 0, 0);
      break;
    case 2: // Yeşil
      setColor(0, 255, 0);
      break;
    case 3: // Mavi
      setColor(0, 0, 255);
      break;
    case 4: // Beyaz
      setColor(255, 255, 255);
      break;
    case 5: // Fade (Bu kısmı kendinize göre doldurunuz)
      for (int i = 0; i <= 255; i++) {
    	setColor(i, i, i); // RGB değerlerini artır
    	delay(10);
  	  }
  	  for (int i = 255; i >= 0; i--) {
    	setColor(i, i, i); // RGB değerlerini azalt
    	delay(10);
  	  }
      break;
    case 6: // Beyaz strobe (Bu kısmı kendinize göre doldurunuz)
      for (int i = 0; i < 5; i++) { // 5 kez yanıp sönecek
        setColor(255, 255, 255); // Beyaz
        delay(100); // 100 ms yanık
        setColor(0, 0, 0); // Kapalı
        delay(100); // 100 ms söndü
  	  }
      break;
    case 7: // RGB strobe (Bu kısmı kendinize göre doldurunuz)
      for (int i = 0; i < 5; i++) { // Her renk için 5 kez yanıp sönecek
        // Kırmızı strobe
        setColor(255, 0, 0);
        delay(100);
        setColor(0, 0, 0);
        delay(100);

        // Yeşil strobe
        setColor(0, 255, 0);
        delay(100);
        setColor(0, 0, 0);
        delay(100);

        // Mavi strobe
        setColor(0, 0, 255);
        delay(100);
        setColor(0, 0, 0);
        delay(100);
      }
      break;
    case 8:
      // Renkler arası yumuşak geçiş için
      for (int i = 0; i < 256; i++) {
        // Kırmızıdan yeşile geçiş
        setColor(255 - i, i, 0);
        delay(10);
      }
      for (int i = 0; i < 256; i++) {
        // Yeşilden maviye geçiş
        setColor(0, 255 - i, i);
        delay(10);
      }
      for (int i = 0; i < 256; i++) {
        // Maviden kırmızıya geçiş
        setColor(i, 0, 255 - i);
        delay(10);
      }
      break;
    case 9: // Potansiyometre değerine göre RGB LED'in rengini ayarla
      // Potansiyometre değerine göre RGB LED'in rengini ayarla
      int mappedValue = map(potValue, 0, 1023, 0, 255); // 0-1023 arası değeri 0-255 arasına eşle

      // RGB LED için renk değerlerini hesapla
      int redValue = 0, greenValue = 0, blueValue = 0;

      // Potansiyometrenin değerine göre renk ayarları
      if (mappedValue < 85) { // 0-84 arası değerler için kırmızıya yakın renkler
        redValue = mappedValue * 3; // Kırmızı değeri arttır
        greenValue = 0;
        blueValue = 255 - mappedValue * 3; // Mavi değeri azalt
      } else if (mappedValue < 170) { // 85-169 arası değerler için yeşile yakın renkler
        mappedValue -= 85; // Aralığı 0-84'e çek
        redValue = 255 - mappedValue * 3; // Kırmızı değeri azalt
        greenValue = mappedValue * 3; // Yeşil değeri arttır
        blueValue = 0;
      } else { // 170-255 arası değerler için maviye yakın renkler
        mappedValue -= 170; // Aralığı 0-84'e çek
        redValue = 0;
        greenValue = 255 - mappedValue * 3; // Yeşil değeri azalt
        blueValue = mappedValue * 3; // Mavi değeri arttır
      }

      // Hesaplanan renk değerlerini kullanarak LED rengini ayarla
      setColor(redValue, greenValue, blueValue);
      break;
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
}
