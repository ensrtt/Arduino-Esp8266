ESP8266 ile Kontrol Edilen RGB LED Projesi
Bu proje, ESP8266 Lolin v3 modülü kullanılarak kontrol edilen bir RGB LED sistemi üzerine kuruludur. Kullanıcı, bir buton aracılığıyla farklı renk modları arasında geçiş yapabilir ve ayrıca bir potansiyometre ile RGB LED'in rengini dinamik olarak ayarlayabilir. Projede ortak anotlu bir RGB LED, 10k ohm pull-down dirençli bir buton ve 10k ohm potansiyometre kullanılmaktadır. Her LED bacağı için 220 ohm direnç kullanılarak LED'in korunması sağlanır.

Özellikler
Buton Kontrolü: Buton aracılığıyla RGB LED için 9 farklı renk modu arasında geçiş yapma.
Potansiyometre Ayarı: Potansiyometre ile RGB LED'in rengini ayarlama.
Debounce Mekanizması: Buton sıçramalarını önlemek için debounce mekanizması.
Seri Port Gösterimi: Potansiyometrenin anlık değerinin seri port üzerinden gösterilmesi.
Gereksinimler
ESP8266 Lolin v3 modülü
Ortak anotlu RGB LED
10k ohm potansiyometre
10k ohm pull-down direnç
220 ohm dirençler (RGB LED'in her bacağı için birer tane)
Buton
Breadboard ve jumper kablolar
Kurulum
Sürücü Kurulumu
ESP8266 Lolin v3 modülü, CH340 USB dönüştürücü çipini kullanır. Bu çipi bilgisayarınızın tanıması için ilgili sürücüyü kurmanız gerekir. Sürücüyü CH340 sürücüsünün resmi sayfasından indirebilir ve kurulum talimatlarına uyarak kurulumu tamamlayabilirsiniz.

Arduino IDE Ayarları
Projeyi yüklemek için Arduino IDE'yi kullanıyorsanız, ESP8266 için gerekli board manager URL'sini Arduino IDE'ye eklemeniz gerekmektedir. "File" > "Preferences" (Dosya > Tercihler) menüsünden "Additional Board Manager URLs" (Ekstra Kart Yöneticisi URL'leri) bölümüne http://arduino.esp8266.com/stable/package_esp8266com_index.json URL'sini ekleyin. Ardından "Tools" > "Board" > "Boards Manager" (Araçlar > Kart > Kart Yöneticisi) üzerinden ESP8266 kart paketini arayın ve yükleyin.

Bağlantı Şeması
Aşağıdaki bağlantı şemasını takip ederek projenizi kurabilirsiniz:

Buton: GPIO 4 pinine ve diğer tarafı GND'ye 10k ohm pull-down direnç üzerinden bağlanır.
RGB LED:
Kırmızı LED bacağı GPIO 14 pinine ve arada 220 ohm direnç ile,
Yeşil LED bacağı GPIO 12 pinine ve arada 220 ohm direnç ile,
Mavi LED bacağı GPIO 13 pinine ve arada 220 ohm direnç ile bağlanır.
Ortak anot (+) bacağı ESP8266'nın 3.3V pinine bağlanır.
Potansiyometre: Ortası A0 pinine, bir tarafı 3.3V'a, diğer tarafı GND'ye bağlanır.
Bağlantı Şeması Buraya <!-- Bağlantı şeması için bir görsel linki yerleştirin -->

Kodun Yüklenmesi
Projeyi ESP8266 modülünüze yüklemek için, öncelikle Arduino IDE'de Esp8266_RGB_Led_wButton.ino dosyasını açın. Ardından, "Tools" menüsünden ESP8266 Lolin v3 kartınızı ve doğru portu seçin. "Upload" butonuna basarak kodu ESP8266 modülünüze yükleyin.

Kullanım
Kurulum tamamlandıktan sonra, butona her basışınızda RGB LED farklı bir renk moduna geçecektir. Potansiyometreyi çevirerek RGB LED'in rengini dinamik olarak değiştirebilirsiniz. Seri monitör üzerinden potansiyometrenin anlık değerini görebilirsiniz.
