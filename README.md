İki ESP32 ile Bluetooth Kontrollü Denizaltı Projesi
---------------------------------------------------
3D Tasarım: Eyüp Ensar Tuncel
-
Kodlama & Elektronik: Emir Topay
----------------------------------------------------
Proje Özeti:
Bu proje, iki ESP32 modülü ve L298N motor sürücü kullanarak Bluetooth üzerinden kontrol edilen
bir mini denizaltı geliştirmeyi amaçlar.
Denizaltının hareketi iki ayrı pervane (motor) ile sağlanır:

- Motor A -> Denizaltının ileri ve geri hareketini kontrol eder.
- Motor B -> Denizaltının sağa ve sola dönüşünü sağlar.

Bir ESP32 kontrolcü (Master), diğer ESP32 ise motor sürücü (Slave) olarak görev yapar.
Master üzerindeki butonlar ile hareket komutları Bluetooth üzerinden Slave’e iletilir.

Donanım Yapısı:
- ESP32 Master:
  4 adet buton ile ileri, geri, sağ ve sol komutlarını gönderir.
  Bluetooth üzerinden Slave ESP32’ye seri komut iletir.

- ESP32 Slave + L298N:
  İki DC motoru tam güçte (PWM olmadan) sürer.
  Gelen komutlara göre Motor A ve Motor B’nin yönlerini değiştirir.

- Güç Sistemi:
  Motorlar için 7–12 V batarya.
  ESP32 için 5 V besleme.
  Tüm sistemin ortak GND bağlantısı yapılır.

Çalışma Mantığı:
1. Master ESP32 üzerindeki buton basıldığında, belirli bir harf komutu (F, B, R, L)
   Bluetooth ile gönderilir.
2. Slave ESP32 bu komutu alır ve L298N üzerinden ilgili motorları sürer:
   F -> Motor A ileri (denizaltı ileri)
   B -> Motor A geri (denizaltı geri)
   R -> Motor B sağ (denizaltı sağa döner)
   L -> Motor B sol (denizaltı sola döner)
   S / T -> Motorları durdurma komutları.


