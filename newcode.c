#define H 118
#define E 121
#define L 56
#define O 63
#define U 62
#define R 119
#define D 94
#define space 0
  

int main(void)
{

	int hello_uuorld[12] = {H, E, L, L, O, space, U, U, O, R, L, D};

   // Declare volatile pointers to I/O registers (volatile means that the locations will not be cached,
   // even in registers
  
	volatile int *LED_ptr = (int *) 0xFF200040; // red LED address
	volatile int *HEX3_HEX0_ptr = (int *) 0xFF200020; // HEX3_HEX0 address
	volatile int *HEX5_HEX4_ptr = (int *) 0xFF200010; // HEX5_HEX4 address
	volatile int *SW_switch_ptr = (int *) 0xFF200030; // SW slider switch_pattern address
	volatile int *KEY_ptr = (int *) 0xFF200000; // pushbutton KEY address
	volatile int delay_count;

	
	//int SW_value;
	int speed = 1000000;
	int i = 0;
	
	int KeyPress = 0;
	int switch_pattern = 0;
	int ret = 0;
	int hex30 = 0; 	//32-Bit int for HEX3 - HEX0
	int hex3 = 0;
	int hex2 = 0;
	int hex1 = 0;
	int hex0 = 0;
	int hex54 = 0; 				// 32-Bit int for HEX5 - HEX4
	int hex5 = 0;
	int hex4 = 0;
	int pushVariable = 0;
	int toggle = 0;
	int toggleScroll = 1;
	int specificScrollInt = 0;
	int switch_pattern_value;
	int pattern[10] = {0,0,0,0,0,0,0,0,0,0};
	int SWvalue = 0;
	int KEY0 = 1;
	int push_value = 0;
	
	while (1)
	{
	
		if(*(KEY_ptr) == 8)
			switch_pattern = !switch_pattern;
		
		
		
		if(switch_pattern == 0)
		{
		
			hex5 = hello_uuorld[(i)%12];
			hex4 = hello_uuorld[(i+1)%12];
			hex3 = hello_uuorld[(i+2)%12];
			hex2 = hello_uuorld[(i+3)%12];
			hex1 = hello_uuorld[(i+4)%12];
			hex0 = hello_uuorld[(i+5)%12];
			
			i = (i+!KeyPress)%12;
			
		
			
			hex30 = (hex3 << 24) + (hex2 << 16) + (hex1 << 8) + (hex0);
			hex54 = (hex5 << 8) + (hex4);

		
			*(HEX3_HEX0_ptr) = hex30;
			*(HEX5_HEX4_ptr) = hex54;
			
		
			
			if(*(KEY_ptr) == 1)
				KeyPress = !KeyPress;
			
			for (delay_count = speed; delay_count != 0; --delay_count);
			
			
	
		}
		
		
		if(switch_pattern == 1)
		{
			switch_pattern_value = *SW_switch_ptr;
			
			pattern [5] = 0x7F & switch_pattern_value;
			pattern [4] = 0x7 & (switch_pattern_value >>
			
			
			if(*(KEY_ptr) == 0)
				KeyPress = !KeyPress;
			
		}
	
		
		
			

			
		
		if (*(KEY_ptr) == 2) 
		{
			if ( speed > 100000)
				speed = speed - 100000;
			else 
				speed = speed;
			
		}
		
		if (*(KEY_ptr) == 4) 
		{
			speed = speed + 100000;
			
		}
	
			
		
	}
	
	return 0;
}
