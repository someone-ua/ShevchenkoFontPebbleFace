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
      return "рівно";
      break;
    case 1:
      return "одна хвилина";
      break;
    case 2:
      return "дві хвилини";
      break;
    case 3:
      return "три хвилини";
      break;
    case 4:
      return "чотири хвилини";
      break;
    case 5:
      return "п'ять хвилин";
      break;
    case 6:
      return "шість хвилин";
      break;
    case 7:
      return "сім хвилин";
      break;
    case 8:
      return "вісім хвилин";
      break;
    case 9:
      return "дев'ять хвилин";
      break;
    case 10:
      return "деять хвилин";
      break;
    case 11:
      return "одинадцять хвилин";
      break;
    case 12:
      return "дванадцять хвилин";
      break;
    case 13:
      return "тринадцять хвилин";
      break;
    case 14:
      return "чотирнадцять хвилин";
      break;
    case 15:
      return "п'ятнадцять хвилин";
      break;
    case 16:
      return "шістнадцять хвилин";
      break;
    case 17:
      return "сімнадцять хвилин";
      break;
    case 18:
      return "вісімнадцять хвилин";
      break;
    case 19:
      return "дев'ятнадцять хвилин";
      break;
    case 20:
      return "двадцять хвилин";
      break;
    case 21:
      return "двадцять одна хвилина";
      break;
    case 22:
      return "двадцять дві хвилини";
      break;
    case 23:
      return "двадцять три хвилини";
      break;
    case 24:
      return "двадцять чотири хвилини";
      break;
    case 25:
      return "чверть";
      break;    
    case 26:
      return "двадцять шість хвилин";
      break;
    case 27:
      return "двадцять сім хвилин";
      break;
    case 28:
      return "двадцять вісім хвилин";
      break;
    case 29:
      return "двадцять дев'ять хвилин";
      break;
    case 30:
      return "пів";
      break;
    case 31:
      return "тридцять одна хвилина";
      break;
    case 32:
      return "тридцять дві хвилини";
      break;
    case 33:
      return "тридцять три хвилини";
      break;
    case 34:
      return "тридцять чотири хвилини";
      break;
    case 35:
      return "тридцять п'ять хвилин";
      break;
    case 36:
      return "тридцять шість хвилин";
      break;
    case 37:
      return "тридцять сім хвилин";
      break;
    case 38:
      return "тридцять вісім хвилин";
      break;
    case 39:
      return "тридцять дев'ять хвилин";
      break;
    case 40:
      return "без двадцяти";
      break;
    case 41:
      return "без дев'ятнадцяти";
      break;
    case 42:
      return "без вісімнадцяти";
      break;
    case 43:
      return "без сімнадцяти";
      break;
    case 44:
      return "без шістнадцяти";
      break;
    case 45:
      return "без п'ятнадцяти";
      break;
    case 46:
      return "без чотирнадцяти";
      break;
    case 47:
      return "без тринадцяти";
      break;
    case 48:
      return "без дванадцяти";
      break;
    case 49:
      return "без одинадцяти";
      break;
    case 50:
      return "без десяти";
      break;
    case 51:
      return "без дев'яти";
      break;
    case 52:
      return "без восьми";
      break;
    case 53:
      return "без сіми";
      break;
    case 54:
      return "без шести";
      break;
    case 55:
      return "без п'яти";
      break;
    case 56:
      return "без чотирьох";
      break;
    case 57:
      return "без трьох";
      break;
    case 58:
      return "без двох";
      break;
    case 59:
      return "без одної";
      break;
  }  
  return "";
}
