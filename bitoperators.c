#include <stdio.h>

#define ENGINE_ON 0x01
#define AC_ON 0x02
#define BEAMS_ON 0x04
#define RADIO_ON 0x08

int main(){
  // unsigned does not use sign bit
  unsigned int x = 0x0b; //1011
  unsigned int y = 0x0a; //1010
  printf("%d in hex is 0x%x\n", x, x);
  printf("0x%X XNOR 0x%X = 0x%X\n", x, y, ~(x ^ y));
  //Use bits for togglea
  // First bit: Engine on/off
  // Second bit: AC on/off
  // Third bit: Beams on/off
  // Fourth bit: Radio on/off
  // Char requires a byte => 8 bits
  unsigned char state_of_car = 0;
  // Radio on
  state_of_car |= RADIO_ON; // 0000 1000
  // AC on
  // 0000 1000 | 0000 0010 = 0000 1010
  state_of_car |= AC_ON;
  // Radio off
  // 0000 1010 & 0000 0010 = 0000 0010
  state_of_car =& RADIO_ON;
  return 0;
}
