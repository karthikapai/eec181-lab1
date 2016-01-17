// Simple test program 
int main(void)
{
  volatile int * led = (int *) 0xFF200040; // red LED address
  volatile int * switchptr = (int *) 0xFF200030; // SW slider switch address
  volatile int * HEX3_HEX0 = (int *) 0xFF200020;
  volatile int * HEX5_HEX4 = (int *) 0xFF200010;
 // volatile int * HEX3_HEX0 = (int *) 0xFF200024;
  //volatile int * HEX3_HEX0 = (int *) 0xFF200023;

  int switch_value;

  while (1)
  {
    switch_value = *(switchptr);
    *(led) = switch_value;
    *(HEX3_HEX0) = 127;
    *(HEX5_HEX4) = 127;
   
  }
}
