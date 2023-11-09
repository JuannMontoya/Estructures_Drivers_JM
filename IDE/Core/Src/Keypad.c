

#include "ring_buffer.h"
#include "main.h"

/**
 * @brief This function initializes the control struct of the ring buffer
*/
void keypad_init(void)
{
	ROW_1_GPIO_Port->BSRR = ROW_1_Pin;
	ROW_2_GPIO_Port->BSRR = ROW_2_Pin;
	ROW_3_GPIO_Port->BSRR = ROW_3_Pin;
	ROW_4_GPIO_Port->BSRR = ROW_4_Pin;
}


/**
 * @brief this function adds the a data in the ring buffer
 *@Param data: value to write in the buffer
 */
uint8_t keypad_handler(uint16_t column_to_evaluate)
{

	uint8_t key_pressed = 0xFF; // Value to return

		/* Debounce the key press (remove noise in the key) */
	#define KEY_DEBOUNCE_MS 300 /*!> Minimum time required for since last press */
		static uint32_t last_pressed_tick = 0;
		if (HAL_GetTick() <= (last_pressed_tick + KEY_DEBOUNCE_MS)) {
			// less than KEY_DEBOUNCE_MS since last press. Probably noise
			return key_pressed; // return 0xFF
		}
		last_pressed_tick = HAL_GetTick();

		/* Check in which column the event happened */
		switch (column_to_evaluate) {
case COLUMN_1_Pin:
			ROW_1_GPIO_Port->BSRR = ROW_1_Pin; // turn on row 1
			ROW_2_GPIO_Port->BRR = ROW_2_Pin;  // turn off row 2
			ROW_3_GPIO_Port->BRR = ROW_3_Pin;  // turn off row 3
			ROW_4_GPIO_Port->BRR = ROW_4_Pin;  // turn off row 4
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
				key_pressed = 0x01; // if column 1 is still high -> column 1 + row 1 = key 1
				break;
			}

			ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
			ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
				key_pressed = 0x04; // if column 1 is still high -> column 1 + row 2 = key 4
				break;
			}

			ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
			ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
				key_pressed = 0x07; // if column 1 is still high -> column 1 + row 3 = key 7
				break;
			}

			ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
			ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_1_GPIO_Port->IDR & COLUMN_1_Pin) {
				key_pressed = 0x0E; // if column 1 is still high -> column 1 + row 4 = key *
				break;
			}

// Agrega un break al final de cada caso para evitar que el código continúe ejecutando los casos posteriores.
break;
//
case COLUMN_2_Pin:

			ROW_1_GPIO_Port->BSRR = ROW_1_Pin; // turn on row 1
			ROW_2_GPIO_Port->BRR = ROW_2_Pin;  // turn off row 2
			ROW_3_GPIO_Port->BRR = ROW_3_Pin;  // turn off row
			ROW_4_GPIO_Port->BRR = ROW_4_Pin;  // turn off row 4
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
			key_pressed = 0x02; // if column 1 is still high -> column 1 + row 1 = key 1
			break;
			}

			ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
			ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
			HAL_Delay(2); // wait for voltage to establish
			if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
							key_pressed = 0x05; // if column 1 is still high -> column 1 + row 2 = key 4
							break;
						}

						ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
						ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
							key_pressed = 0x08; // if column 1 is still high -> column 1 + row 3 = key 7
							break;
						}

						ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
						ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_2_GPIO_Port->IDR & COLUMN_2_Pin) {
						key_pressed = 0x00; // if column 1 is still high -> column 1 + row 4 = key *
							break;
						}

break;

case COLUMN_3_Pin:

			ROW_1_GPIO_Port->BSRR = ROW_1_Pin; // turn on row 1
						ROW_2_GPIO_Port->BRR = ROW_2_Pin;  // turn off row 2
						ROW_3_GPIO_Port->BRR = ROW_3_Pin;  // turn off row 3
						ROW_4_GPIO_Port->BRR = ROW_4_Pin;  // turn off row 4
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
							key_pressed = 0x03; // if column 1 is still high -> column 1 + row 1 = key 1
							break;
						}

						ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
						ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
							key_pressed = 0x06; // if column 1 is still high -> column 1 + row 2 = key 4
							break;
						}

						ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
						ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
							key_pressed = 0x09; // if column 1 is still high -> column 1 + row 3 = key 7
							break;
						}

						ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
						ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_3_GPIO_Port->IDR & COLUMN_3_Pin) {
							key_pressed = 0x0F; // if column 1 is still high -> column 1 + row 4 = key *
							break;
						}
					  break;

case COLUMN_4_Pin:

			ROW_1_GPIO_Port->BSRR = ROW_1_Pin; // turn on row 1
						ROW_2_GPIO_Port->BRR = ROW_2_Pin;  // turn off row 2
						ROW_3_GPIO_Port->BRR = ROW_3_Pin;  // turn off row 3
						ROW_4_GPIO_Port->BRR = ROW_4_Pin;  // turn off row 4
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
							key_pressed = 0x0A; // if column 1 is still high -> column 1 + row 1 = key 1
							break;
						}

						ROW_1_GPIO_Port->BRR = ROW_1_Pin; 	// turn off row 1
						ROW_2_GPIO_Port->BSRR = ROW_2_Pin; 	// turn on row 2
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
							key_pressed = 0x0B; // if column 1 is still high -> column 1 + row 2 = key 4
							break;
						}

						ROW_2_GPIO_Port->BRR = ROW_2_Pin; 	// turn off row 2
						ROW_3_GPIO_Port->BSRR = ROW_3_Pin; 	// turn on row 3
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
							key_pressed = 0x0C; // if column 1 is still high -> column 1 + row 3 = key 7
							break;
						}

						ROW_3_GPIO_Port->BRR = ROW_3_Pin;	// turn off row 3
						ROW_4_GPIO_Port->BSRR = ROW_4_Pin; 	// turn on row 4
						HAL_Delay(2); // wait for voltage to establish
						if (COLUMN_4_GPIO_Port->IDR & COLUMN_4_Pin) {
							key_pressed = 0x0D; // if column 1 is still high -> column 1 + row 4 = key *
							break;
						}
					  break;





	}
		keypad_init(); // set the columns high again
			return key_pressed; // invalid: 0xFF, valid:[0x00-0x0F]
}


