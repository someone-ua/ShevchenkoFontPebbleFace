#pragma once
char* format_time(struct tm* tick_time);
static char* get_hour_text(int hour, int minute);
static char* get_minute_text(int minute);