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
        return "першої";
      if (minute >= 40)
        return "одна";
      break;
    case 1:
      if (minute == 0)
        return "одна година";
      if (minute > 0 && minute < 40)
        return "другої";
      if (minute >= 40)
        return "два";
      break;
    case 2:
      if (minute == 0)
        return "дві години";
      if (minute > 0 && minute < 40)
        return "третьої";
      if (minute >= 40)
        return "три";
      break;
    case 3:
      if (minute == 0)
        return "три години";
      if (minute > 0 && minute < 40)
        return "четвертої";
      if (minute >= 40)
        return "чотири";
      break;
    case 4:
      if (minute == 0)
        return "чотири години";
      if (minute > 0 && minute < 40)
        return "п'ятої";
      if (minute >= 40)
        return "п'ять";
      break;
    case 5:
      if (minute == 0)
        return "п'ять годин";
      if (minute > 0 && minute < 40)
        return "шостої";
      if (minute >= 40)
        return "шість";
      break;
    case 6:
      if (minute == 0)
        return "шість годин";
      if (minute > 0 && minute < 40)
        return "сьомої";
      if (minute >= 40)
        return "сім";
      break;
    case 7:
      if (minute == 0)
        return "сім годин";
      if (minute > 0 && minute < 40)
        return "восьмої";
      if (minute >= 40)
        return "вісім";
      break;
    case 8:
      if (minute == 0)
        return "вісім годин";
      if (minute > 0 && minute < 40)
        return "дев'ятої";
      if (minute >= 40)
        return "дев'ять";
      break;
    case 9:
      if (minute == 0)
        return "дев'ять годин";
      if (minute > 0 && minute < 40)
        return "десятої";
      if (minute >= 40)
        return "десять";
      break;
    case 10:
      if (minute == 0)
        return "десять годин";
      if (minute > 0 && minute < 40)
        return "одинадцятої";
      if (minute >= 40)
        return "одинадцять";
      break;
    case 11:
      if (minute == 0)
        return "одинадцять годин";
      if (minute > 0 && minute < 40)
        return "дванадцятої";
      if (minute >= 40)
        return "дванадцять";
      break;
    case 12:
      if (minute == 0)
        return "дванадцять годин";
      if (minute > 0 && minute < 40) {
        if (clock_is_24h_style())
          return "тринадцятої";
        else
          return "першої";
      }
      if (minute >= 40) {
        if (clock_is_24h_style())
          return "тринадцять";
        else
          return "одна";
      }
      break;
    case 13:
      if (minute == 0)
        return "тринадцять годин";
      if (minute > 0 && minute < 40)
        return "чотирнадцятої";
      if (minute >= 40)
        return "чотирнадцять";
      break;
    case 14:
      if (minute == 0)
        return "чотирнадцять годин";
      if (minute > 0 && minute < 40)
        return "п'ятнадцятої";
      if (minute >= 40)
        return "п'ятнадцять";
      break;
    case 15:
      if (minute == 0)
        return "п'ятнадцять годин";
      if (minute > 0 && minute < 40)
        return "шістнадцятої";
      if (minute >= 40)
        return "шістнадцять";
      break;
    case 16:
      if (minute == 0)
        return "шістнадцять годин";
      if (minute > 0 && minute < 40)
        return "сімнадцятої";
      if (minute >= 40)
        return "сімнадцять";
      break;
    case 17:
      if (minute == 0)
        return "сімнадцять годин";
      if (minute > 0 && minute < 40)
        return "вісімнадцятої";
      if (minute >= 40)
        return "вісімнадцять";
      break;
    case 18:
      if (minute == 0)
        return "вісімнадцять годин";
      if (minute > 0 && minute < 40)
        return "дев'ятнадцятої";
      if (minute >= 40)
        return "дев'ятнадцять";
      break;
    case 19:
      if (minute == 0)
        return "дев'ятнадцять годин";
      if (minute > 0 && minute < 40)
        return "двадцятої";
      if (minute >= 40)
        return "двадцять";
      break;
    case 20:
      if (minute == 0)
        return "двадцять годин";
      if (minute > 0 && minute < 40)
        return "двадцять першої";
      if (minute >= 40)
        return "двадцять одна";
      break;
    case 21:
      if (minute == 0)
        return "двадцять одна година";
      if (minute > 0 && minute < 40)
        return "двадцять другої";
      if (minute >= 40)
        return "двадцять дві";
      break;
    case 22:
      if (minute == 0)
        return "двадцять дві години";
      if (minute > 0 && minute < 40)
        return "двадцять третьої";
      if (minute >= 40)
        return "двадцять три";
      break;
    case 23:
      if (minute == 0)
        return "двадцять три години";
      if (minute > 0 && minute < 40)
        return "двадцять четвертої";
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
      return "Одна хвилина";
      break;
    case 2:
      return "Дві хвилини";
      break;
    case 3:
      return "Три хвилини";
      break;
    case 4:
      return "Чотири хвилини";
      break;
    case 5:
      return "П'ять хвилин";
      break;
    case 6:
      return "Шість хвилин";
      break;
    case 7:
      return "Сім хвилин";
      break;
    case 8:
      return "Вісім хвилин";
      break;
    case 9:
      return "Дев'ять хвилин";
      break;
    case 10:
      return "Деять хвилин";
      break;
    case 11:
      return "Одинадцять хвилин";
      break;
    case 12:
      return "Дванадцять хвилин";
      break;
    case 13:
      return "Тринадцять хвилин";
      break;
    case 14:
      return "Чотирнадцять хвилин";
      break;
    case 15:
      return "Чверть";
      break;
    case 16:
      return "Шістнадцять хвилин";
      break;
    case 17:
      return "Сімнадцять хвилин";
      break;
    case 18:
      return "Вісімнадцять хвилин";
      break;
    case 19:
      return "Дев'ятнадцять хвилин";
      break;
    case 20:
      return "Двадцять хвилин";
      break;
    case 21:
      return "Двадцять одна хвилина";
      break;
    case 22:
      return "Двадцять дві хвилини";
      break;
    case 23:
      return "Двадцять три хвилини";
      break;
    case 24:
      return "Двадцять чотири хвилини";
      break;
    case 25:
      return "Двадять п'ять";
      break;    
    case 26:
      return "Двадцять шість хвилин";
      break;
    case 27:
      return "Двадцять сім хвилин";
      break;
    case 28:
      return "Двадцять вісім хвилин";
      break;
    case 29:
      return "Двадцять дев'ять хвилин";
      break;
    case 30:
      return "Пів";
      break;
    case 31:
      return "Тридцять одна хвилина";
      break;
    case 32:
      return "Тридцять дві хвилини";
      break;
    case 33:
      return "Тридцять три хвилини";
      break;
    case 34:
      return "Тридцять чотири хвилини";
      break;
    case 35:
      return "Тридцять п'ять хвилин";
      break;
    case 36:
      return "Тридцять шість хвилин";
      break;
    case 37:
      return "Тридцять сім хвилин";
      break;
    case 38:
      return "Тридцять вісім хвилин";
      break;
    case 39:
      return "Тридцять дев'ять хвилин";
      break;
    case 40:
      return "Без двадцяти";
      break;
    case 41:
      return "Без дев'ятнадцяти";
      break;
    case 42:
      return "Без вісімнадцяти";
      break;
    case 43:
      return "Без сімнадцяти";
      break;
    case 44:
      return "Без шістнадцяти";
      break;
    case 45:
      return "Без чверті";
      break;
    case 46:
      return "Без чотирнадцяти";
      break;
    case 47:
      return "Без тринадцяти";
      break;
    case 48:
      return "Без дванадцяти";
      break;
    case 49:
      return "Без одинадцяти";
      break;
    case 50:
      return "Без десяти";
      break;
    case 51:
      return "Без дев'яти";
      break;
    case 52:
      return "Без восьми";
      break;
    case 53:
      return "Без сіми";
      break;
    case 54:
      return "Без шести";
      break;
    case 55:
      return "Без п'яти";
      break;
    case 56:
      return "Без чотирьох";
      break;
    case 57:
      return "Без трьох";
      break;
    case 58:
      return "Без двох";
      break;
    case 59:
      return "Без одної";
      break;
  }  
  return "";
}
