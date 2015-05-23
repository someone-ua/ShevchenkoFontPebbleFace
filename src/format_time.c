#include <pebble.h>
#include "format_time.h"

char* format_time(struct tm* tick_time) {
  if (tick_time->tm_hour > 12 && !clock_is_24h_style())
    tick_time->tm_hour -= 12;
  
  static char buffer[100];
  
  strncpy(buffer,get_minute_text(tick_time->tm_min),sizeof(buffer));
  strncat(buffer," ",sizeof(buffer));
  
  return strncat(buffer,get_hour_text(tick_time->tm_hour, tick_time->tm_min),sizeof(buffer));
}

static char* get_hour_text(int hour, int minute) {
  switch (hour) {
    case 0:
      if (minute == 0)
        return "північ";
      if (minute > 0 && minute < 40)
        return "на першу";
      if (minute >= 40)
        return "перша";
      break;
    case 1:
      if (minute == 0)
        return "одна година";
      if (minute > 0 && minute < 40)
        return "на другу";
      if (minute >= 40)
        return "друга";
      break;
    case 2:
      if (minute == 0)
        return "друга година";
      if (minute > 0 && minute < 40)
        return "на третю";
      if (minute >= 40)
        return "третя";
      break;
    case 3:
      if (minute == 0)
        return "третя година";
      if (minute > 0 && minute < 40)
        return "на четверту";
      if (minute >= 40)
        return "четверта";
      break;
    case 4:
      if (minute == 0)
        return "четверта година";
      if (minute > 0 && minute < 40)
        return "на п'яту";
      if (minute >= 40)
        return "п'ята";
      break;
    case 5:
      if (minute == 0)
        return "п'ята година";
      if (minute > 0 && minute < 40)
        return "на шосту";
      if (minute >= 40)
        return "шоста";
      break;
    case 6:
      if (minute == 0)
        return "шоста година";
      if (minute > 0 && minute < 40)
        return "на сьому";
      if (minute >= 40)
        return "сьома";
      break;
    case 7:
      if (minute == 0)
        return "сьома година";
      if (minute > 0 && minute < 40)
        return "на восьму";
      if (minute >= 40)
        return "восьма";
      break;
    case 8:
      if (minute == 0)
        return "восьма година";
      if (minute > 0 && minute < 40)
        return "на дев'яту";
      if (minute >= 40)
        return "дев'ята";
      break;
    case 9:
      if (minute == 0)
        return "дев'ята година";
      if (minute > 0 && minute < 40)
        return "на десяту";
      if (minute >= 40)
        return "десята";
      break;
    case 10:
      if (minute == 0)
        return "десята година";
      if (minute > 0 && minute < 40)
        return "на одинадцяту";
      if (minute >= 40)
        return "одинадцята";
      break;
    case 11:
      if (minute == 0)
        return "одинадцята година";
      if (minute > 0 && minute < 40)
        return "на дванадцяту";
      if (minute >= 40)
        return "дванадцята";
      break;
    case 12:
      if (minute == 0)
        return "дванадцята година";
      if (minute > 0 && minute < 40) {
        if (clock_is_24h_style())
          return "на тринадцяту";
        else
          return "на першу";
      }
      if (minute >= 40) {
        if (clock_is_24h_style())
          return "тринадцята";
        else
          return "перша";
      }
      break;
    case 13:
      if (minute == 0)
        return "тринадцята година";
      if (minute > 0 && minute < 40)
        return "на чотирнадцяту";
      if (minute >= 40)
        return "чотирнадцята";
      break;
    case 14:
      if (minute == 0)
        return "чотирнадцята година";
      if (minute > 0 && minute < 40)
        return "на п'ятнадцяту";
      if (minute >= 40)
        return "п'ятнадцята";
      break;
    case 15:
      if (minute == 0)
        return "п'ятнадцята година";
      if (minute > 0 && minute < 40)
        return "на шістнадцяту";
      if (minute >= 40)
        return "шістнадцята";
      break;
    case 16:
      if (minute == 0)
        return "шістнадцята година";
      if (minute > 0 && minute < 40)
        return "на сімнадцяту";
      if (minute >= 40)
        return "сімнадцята";
      break;
    case 17:
      if (minute == 0)
        return "сімнадцята година";
      if (minute > 0 && minute < 40)
        return "на вісімнадцяту";
      if (minute >= 40)
        return "вісімнадцята";
      break;
    case 18:
      if (minute == 0)
        return "вісімнадцята година";
      if (minute > 0 && minute < 40)
        return "на дев'ятнадцяту";
      if (minute >= 40)
        return "дев'ятнадцята";
      break;
    case 19:
      if (minute == 0)
        return "дев'ятнадцята година";
      if (minute > 0 && minute < 40)
        return "на двадцяту";
      if (minute >= 40)
        return "двадцята";
      break;
    case 20:
      if (minute == 0)
        return "двадцята година";
      if (minute > 0 && minute < 40)
        return "на двадцять першу";
      if (minute >= 40)
        return "двадцять перша";
      break;
    case 21:
      if (minute == 0)
        return "двадцять перша година";
      if (minute > 0 && minute < 40)
        return "на двадцять другу";
      if (minute >= 40)
        return "двадцять друга";
      break;
    case 22:
      if (minute == 0)
        return "двадцять друга година";
      if (minute > 0 && minute < 40)
        return "на двадцять третю";
      if (minute >= 40)
        return "двадцять третя";
      break;
    case 23:
      if (minute == 0)
        return "двадцять третя година";
      if (minute > 0 && minute < 40)
        return "по двадцять третій";
      if (minute >= 40)
        return "північ";
      break;
  }
  return "";
}
  
  static char* get_minute_text(int minute) {
  switch (minute) {
    case 0:
      return "Рівно";
      break;
    case 1:
      return "Одна хвилина на";
      break;
    case 2:
      return "Дві хвилини на";
      break;
    case 3:
      return "Три хвилини на";
      break;
    case 4:
      return "Чотири хвилини на";
      break;
    case 5:
      return "П'ять хвилин на";
      break;
    case 6:
      return "Шість хвилин на";
      break;
    case 7:
      return "Сім хвилин на";
      break;
    case 8:
      return "Вісім хвилин на";
      break;
    case 9:
      return "Дев'ять хвилин на";
      break;
    case 10:
      return "Деять хвилин на";
      break;
    case 11:
      return "Одинадцять хвилин на";
      break;
    case 12:
      return "Дванадцять хвилин на";
      break;
    case 13:
      return "Тринадцять хвилин на";
      break;
    case 14:
      return "Чотирнадцять хвилин на";
      break;
    case 15:
      return "Чверть на";
      break;
    case 16:
      return "Шістнадцять хвилин на";
      break;
    case 17:
      return "Сімнадцять хвилин на";
      break;
    case 18:
      return "Вісімнадцять хвилин на";
      break;
    case 19:
      return "Дев'ятнадцять хвилин на";
      break;
    case 20:
      return "Двадцять хвилин на";
      break;
    case 21:
      return "Двадцять одна хвилина на";
      break;
    case 22:
      return "Двадцять дві хвилини на";
      break;
    case 23:
      return "Двадцять три хвилини на";
      break;
    case 24:
      return "Двадцять чотири хвилини на";
      break;
    case 25:
      return "Двадять п'ять хвилин на";
      break;    
    case 26:
      return "Двадцять шість хвилин на";
      break;
    case 27:
      return "Двадцять сім хвилин на";
      break;
    case 28:
      return "Двадцять вісім хвилин на";
      break;
    case 29:
      return "Двадцять дев'ять хвилин на";
      break;
    case 30:
      return "Пів на";
      break;
    case 31:
      return "Тридцять одна хвилина на";
      break;
    case 32:
      return "Тридцять дві хвилини на";
      break;
    case 33:
      return "Тридцять три хвилини на";
      break;
    case 34:
      return "Тридцять чотири хвилини на";
      break;
    case 35:
      return "Тридцять п'ять хвилин на";
      break;
    case 36:
      return "Тридцять шість хвилин на";
      break;
    case 37:
      return "Тридцять сім хвилин на";
      break;
    case 38:
      return "Тридцять вісім хвилин на";
      break;
    case 39:
      return "Тридцять дев'ять хвилин на";
      break;
    case 40:
      return "За двадцять хвилин";
      break;
    case 41:
      return "За дев'ятнадцять хвилин";
      break;
    case 42:
      return "За вісімнадцять хвилин";
      break;
    case 43:
      return "За сімнадцять хвилин";
      break;
    case 44:
      return "За шістнадцять хвилин";
      break;
    case 45:
      return "За чверть";
      break;
    case 46:
      return "За чотирнадцять хвилин";
      break;
    case 47:
      return "За тринадцять хвилин";
      break;
    case 48:
      return "За дванадцять хвилин";
      break;
    case 49:
      return "За одинадцять хвилин";
      break;
    case 50:
      return "За десять хвилин";
      break;
    case 51:
      return "За дев'ять хвилин";
      break;
    case 52:
      return "За вісім хвилин";
      break;
    case 53:
      return "За сім хвилин";
      break;
    case 54:
      return "За шість хвилин";
      break;
    case 55:
      return "За п'ять хвилин";
      break;
    case 56:
      return "За чотири хвилини";
      break;
    case 57:
      return "За три хвилини";
      break;
    case 58:
      return "За дві хвилини";
      break;
    case 59:
      return "За одну хвилину";
      break;
  }  
  return "";
}
