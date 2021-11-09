#include "pitches.h"
int melody[] = {
  NOTE_C3, NOTE_B3, NOTE_E3, NOTE_G3, NOTE_E3, NOTE_B3, NOTE_C3, NOTE_B3,NOTE_E3,NOTE_B3,NOTE_C3
};
int noteDurations[] = {
  2, 4, 4, 4, 4, 4, 2, 4,8,8,4
};
void setup() {
  Serial.begin(115200);
  ledcSetup(0,2000,8);
  ledcAttachPin(12, 0);
   

}

void loop() {
  // put your main code here, to run repeatedly:
 for (int thisNote = 0; thisNote < 11; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    ledcWriteTone(0,melody[thisNote]);
    delay(noteDuration);
    ledcWriteTone(0,0);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}
