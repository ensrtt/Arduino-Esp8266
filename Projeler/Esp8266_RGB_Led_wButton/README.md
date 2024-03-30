# ESP8266 ile Kontrol Edilen RGB LED Projesi
Bu proje, ESP8266 Lolin v3 modülü kullanılarak kontrol edilen bir RGB LED sistemi üzerine kuruludur. Kullanıcı, bir buton aracılığıyla farklı renk modları arasında geçiş yapabilir ve ayrıca bir potansiyometre ile RGB LED'in rengini dinamik olarak ayarlayabilir. Projede ortak anotlu bir RGB LED, 10k ohm pull-down dirençli bir buton ve 10k ohm potansiyometre kullanılmaktadır. Her LED bacağı için 220 ohm direnç kullanılarak LED'in korunması sağlanır.


## Projede Uygulanan Temel Kavramlar ve Pratikler
Bu proje, kullanıcıların ESP8266, buton, potansiyometre ve RGB LED kullanarak interaktif bir ışık deneyimi oluşturmalarını sağlar. Kullanıcı girişleri ile RGB LED'in renk modları arasında geçiş yapılmasına olanak tanır, bu da dinamik bir deneyim sunar. Butonun debounce mekanizması ve potansiyometrenin seri port üzerinden izlenmesi gibi önemli kavramlar uygulanır.

## Eğitim Amaçlı Faydaları
Bu proje aracılığıyla, kullanıcılar donanım ve yazılım entegrasyonu üzerine temel elektronik ve programlama pratiklerini uygulamalı olarak öğrenirler. Giriş kontrolünden seri haberleşmeye kadar geniş bir yelpazede teknik beceriler kazanılır, IoT konseptlerine giriş yapılır ve temel elektronik bileşenlerin kullanımıyla ilgili değerli bilgiler edinilir.

## Z Kuşağı İçin Alt Metin 😜

*Haydi biraz eğlenelim! 🚀 ESP8266 Lolin v3 ile ultra havalı bir RGB LED show'una hazır mısın? Bir butona bas 🔴, ve bakalım ışıklar senin için ne renk dansı yapacak 🌈. Potansiyometreyi çevir 🔧, LED'in ruh halini bugün nasıl istiyorsan öyle ayarla.*

*Bu projede oyunun kuralları basit: ESP8266 senin çubuğun 🎮, buton senin sihirli değneğin ✨, potansiyometre ise renk paletin 🎨. Debounce'la butonun sıçramasını kontrol altına al, seri portla potansiyometrenin dilinden anla 📡. Yani kısacası, bu projeyle hem teknolojiyi parmağında oynat, hem de renklerin dansına şahit ol!*

*Teknolojiyle iç içe bir maceraya atılmaya ne dersin? 🌟 Bu proje, sadece ışıklarla oynamaktan çok daha fazlası. Elektronik ve programlama dünyasına adım at 🚶‍♂️, IoT'nin kapılarını arala 🚪 ve yaratıcılığını konuştur 🎭. O zaman, hazırsan başlayalım!*

## Özellikler
- **Buton Kontrolü:** Buton aracılığıyla RGB LED için 9 farklı renk modu arasında geçiş yapma.
- **Potansiyometre Ayarı:** Potansiyometre ile RGB LED'in rengini ayarlama.
- **Debounce Mekanizması:** Buton sıçramalarını önlemek için debounce mekanizması.
- **Seri Port Gösterimi:** Potansiyometrenin anlık değerinin seri port üzerinden gösterilmesi.
## Gereksinimler
- ESP8266 Lolin v3 modülü
- Ortak anotlu RGB LED
- 10k ohm potansiyometre
- 10k ohm pull-down direnç
- 220 ohm dirençler (RGB LED'in her bacağı için birer tane)
- Buton
- Breadboard ve jumper kablolar
## Kurulum
### Sürücü Kurulumu
ESP8266 Lolin v3 modülü, CH340 USB dönüştürücü çipini kullanır. Bu çipi bilgisayarınızın tanıması için ilgili sürücüyü kurmanız gerekir. Sürücüyü [CH340 sürücüsünün resmi sayfasından](https://wch-ic.com/products/CH340.html) indirebilir ve kurulum talimatlarına uyarak kurulumu tamamlayabilirsiniz.

### Arduino IDE Ayarları
Projeyi yüklemek için Arduino IDE'yi kullanıyorsanız, ESP8266 için gerekli board manager URL'sini Arduino IDE'ye eklemeniz gerekmektedir. "File" > "Preferences" (Dosya > Tercihler) menüsünden "Additional Board Manager URLs" (Ekstra Kart Yöneticisi URL'leri) bölümüne http://arduino.esp8266.com/stable/package_esp8266com_index.json URL'sini ekleyin. Ardından "Tools" > "Board" > "Boards Manager" (Araçlar > Kart > Kart Yöneticisi) üzerinden ESP8266 kart paketini arayın ve yükleyin.

## Bağlantı Şeması
Aşağıdaki bağlantı şemasını takip ederek projenizi kurabilirsiniz:

- **Buton:** GPIO 4 pinine ve diğer tarafı GND'ye 10k ohm pull-down direnç üzerinden bağlanır.
- **RGB LED:**
  - **Kırmızı LED bacağı** GPIO 14 pinine ve arada 220 ohm direnç ile,
  - **Yeşil LED bacağı** GPIO 12 pinine ve arada 220 ohm direnç ile,
  - **Mavi LED bacağı** GPIO 13 pinine ve arada 220 ohm direnç ile bağlanır.
  - **Ortak anot (+)** bacağı ESP8266'nın 3.3V pinine bağlanır.
- **Potansiyometre:** Ortası A0 pinine, bir tarafı 3.3V'a, diğer tarafı GND'ye bağlanır.

![Esp8266 NodeMCU v3 ile buton ve potansiyometre kullanarak rgb led kontrolü bağlantı şeması](/Projeler/Esp8266_RGB_Led_wButton/Esp8266_RGB_Led_wButton_Wiring.png)

## Kodun Yüklenmesi
Projeyi ESP8266 modülünüze yüklemek için, öncelikle Arduino IDE'de Esp8266_RGB_Led_wButton.ino dosyasını açın. Ardından, "Tools" menüsünden ESP8266 Lolin v3 kartınızı ve doğru portu seçin. "Upload" butonuna basarak kodu ESP8266 modülünüze yükleyin.

## Kullanım
Kurulum tamamlandıktan sonra, butona her basışınızda RGB LED farklı bir renk moduna geçecektir. Potansiyometreyi çevirerek RGB LED'in rengini dinamik olarak değiştirebilirsiniz. Seri monitör üzerinden potansiyometrenin anlık değerini görebilirsiniz.

## Bilinen Sorunlar

Eğitim ve pratik amaçlı hazırlanan bu kod giriş seviyesinde olacak şekilde basit tutulmuştur ve bir çok geliştirme yapılabilir. Genel olarak, bu tür projelerde sıkça karşılaşılan bazı potansiyel sorunlar şunlar olabilir:
1. **Debounce Zamanlama Sorunları:** Buton debounce mekanizması, farklı donanım ve kullanım koşullarında düzgün çalışmayabilir. Yanlış ayarlanmış bir debounce süresi, buton basımını doğru algılamayabilir.
2. **Seri Port İletişim Problemleri:** Seri port üzerinden veri iletişimi, bazı durumlarda kesintiye uğrayabilir veya yanlış veri gönderimi olabilir.
3. **Analog Okuma Değerlerinde Doğruluk:** Potansiyometre ile yapılan analog okumaların doğruluğu, donanımsal toleranslar nedeniyle değişkenlik gösterebilir.
4. **RGB LED Rengi Doğruluğu:** Kodun renk hesaplamaları, özellikle farklı modlarda, beklenen renk tonlarını tam olarak yansıtmayabilir.

## Lisans
Bu proje MIT lisansı altında yayımlanmıştır. Bu, projeyi herhangi bir amaçla kullanabileceğiniz, değiştirebileceğiniz, birleştirebileceğiniz ve dağıtabileceğiniz anlamına gelir. Ayrıca, projenizi özel veya ticari kullanım için serbestçe dağıtabilirsiniz. Lisansın tam metni için projenin Lisans dosyasına bakınız.

## Katkıda Bulunma
Projeye katkıda bulunmak isteyenler için yönergeler. İster bir hata raporu isterse bir özellik talebi olsun, projeye katkıda bulunmak isteyenlerin uygun bir şekilde iletişim kurmaları ve değişikliklerini sunmaları beklenir. Katkıda bulunmak isteyenler, öncelikle bir issue açabilir veya doğrudan bir pull request gönderebilirler. Kabul edilen katkılar için yönergeler ve standartlar bu bölümde detaylandırılır.



