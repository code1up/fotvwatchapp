#pragma once

typedef enum {
  E_MATCHDAY_TODAY,
  E_MATCHDAY_TOMORROW,
  E_MATCHDAY_COMING_UP
} E_MATCHDAY;
  
typedef struct {
  char* awayTeam;
} Match;
  
Tuple* get_matches(E_MATCHDAY matchDay);
