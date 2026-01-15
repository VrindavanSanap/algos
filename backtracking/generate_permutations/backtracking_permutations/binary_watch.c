// Created by Vrindavan on 15/01/26
// binary_watch.c
// soultion to https://leetcode.com/problems/binary-watch
//
//

#include <stdbool.h>
#include <stdio.h>

int hours[4] = {1, 2, 4, 8};
int minutes[6] = {1, 2, 4, 8, 16, 32};

void get_hour_minute(bool state[10], int *hour, int *minute) {
for (int i = 0; i < 4; i++) {
        if (state[i]) *hour += hours[i];
    }
    // Next 6 bits are minutes
    for (int i = 0; i < 6; i++) {
        if (state[4 + i]) *minute += minutes[i];
    }
}
bool is_valid_state(bool state[10]) {
  int hour = 0;
  int minute = 0;
  get_hour_minute(state, &hour, &minute);

  if (hour >= 12) {
    return false;
  }
  if (minute >= 60) {
    return false;
  }
  return true;
}

void print_state(bool state[10]) {
  int hour = 0;
  int minute = 0;
  get_hour_minute(state, &hour, &minute);
  printf("%02d:%02d \n", hour, minute);
}

void print_valid_times(int num_to_turn_on, int num_turned_on, bool state[10],
                       int index) {
  if (num_turned_on == num_to_turn_on){
    if (is_valid_state(state)){
      print_state(state);
      return;
    }
  }
  if (index == 10 ) {
    return;
  }
  print_valid_times(num_to_turn_on, num_turned_on, state, index+1);
  state[index] = true;
  print_valid_times(num_to_turn_on, num_turned_on+1, state, index+1);

  state[index] = false;
}

int main(void) {

  int num_turned_on = 1;
  bool state[10] ={false};
  print_valid_times(1, 0, state ,0);
  return 0;
}
