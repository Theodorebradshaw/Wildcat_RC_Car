void do_manual(byte command, DistanceStruct distances) {
  switch (command) {

    // Drive Motor
    case BRAKE_INPUT:
      setReverse(false);
      brake();
      Serial.println("Would stop");
      break;
    case FORWARD_INPUT:
      setReverse(false);
      disableBrake();
      Serial.println("Would go forward");
      break;
    case BACKWARDS_INPUT:
      setReverse(true);
      disableBrake();
      Serial.println("Would go backward");
      break;

    // Direction Motor
    case LEFT_INPUT:
      left();
      Serial.println("Would turn left");
      break;
    case RIGHT_INPUT:
      right();
      Serial.println("Would turn right");
      break;
    case STRAIGHT_INPUT:
      straight();
      Serial.println("Would turn Strait");
      break;
  }

  if (distances.front == CLOSE && !isReverse) {
    brake();
    Serial.println("braking");
  }
  if (distances.back == CLOSE && isReverse) {
    brake();
    Serial.println("braking");
  }
}
