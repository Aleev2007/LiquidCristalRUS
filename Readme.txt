Это потомок от встроенной библиотеки LiquidCristal.
Весь функционал полностью сохранен.

Добавленно корректное отображениея символов русского языка,
включая символы Ё ё №

Случайный lcd.println(); теперь не добавляет 2 лишних сивола.

Корректно работает конструкция: 
lcd.print(( F("текст"));
для хранения строк во флэш памяти. 

ИСПОЛЬЗОВАНИЕ 
1. Скачайте https://github.com/Aleev2007/LiquidCristalRUS/releases/download/1.1.0/LiquidCrystalRUS.zip
2. Распакуйте LiquidCrystalRUS.zip в папку \Documents\Arduino\libraries\
3. В проекте выберите подключить библиотеку LiquidCrystalRUS.
4. Подключать LiquidCristal не требуется!
5. Примеры использования от LiquidCristal полностью подходят.
6. Для использования с экранами с интерфейсом I2C необходимо сначала установить библиотеку 
   https://github.com/johnrickman/LiquidCrystal_I2C и 
   ОБЯЗАТЕЛЬНО ЕЁ ПОДКЛЮЧИТЬ до LiquidCrystalRUS!
***********************

Помните, что конструкция:
...
const PROGMEM char str[] = "СТРОКА";
...
lcd.print(str);
...
НЕ РАБОТАЕТ!!!
Как правильно работать с PROGMEM написано здесь:
https://www.arduino.cc/reference/en/language/variables/utilities/progmem/
или если строки редко повторяются, но хочется 
весь тектс написать в одном месте, можно использовать:
#define str1 "Строка один"
#define str2 "СТРОКА 2"
....
lcd.print(F(str1));
lcd.print(F(str2));
 

Наслаждайтесь!!!
