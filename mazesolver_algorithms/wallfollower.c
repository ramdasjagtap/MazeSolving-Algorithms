#include <stdio.h>
#include <stdbool.h>
// Wall Follower.

// 3 sensors.
// if sensor = 1 ; wall is present, else no wall.
bool left_sensor, right_sensor, front_sensor;

// robot wheel.
bool left_wheel, right_wheel;

void left() {
  left_wheel = 0;
  right_wheel = 1;
  printf("turn left\n");
};

void right() {
  left_wheel = 1;
  right_wheel = 0;
  printf("turn right\n");
};

void forward() {
  left_wheel = 1;
  right_wheel = 0;
  printf("Go forward\n");
};

int main()
{
  // Keep the one hand on wall.(left/right).
  bool is_left, is_right, is_front;

  printf("Enter  the sensor values\n");
  scanf("%d%d%d", &left_sensor, &right_sensor, &front_sensor);

  is_left = left_sensor ? 1 : 0;
  is_right = right_sensor ? 1 : 0;
  is_front = front_sensor ? 1 : 0;

  bool at_goal = 0;

  while (!at_goal)
  {
    if (!front_sensor && !left_sensor && !right_sensor) {
      printf("Stop\n");
      at_goal = 1;
      break;
    }

    if (!left_sensor) {
      // take left turn and go forward.
      left();
      forward();
    } else if (!right_sensor) {
      // take right turn and go forward
      right();
      forward();
    } else if (!front_sensor) {
      // go forward.
      forward();
    } else {
      // round turn.
      right();
      right();
    }

    break;
  }

  return 0;
}
