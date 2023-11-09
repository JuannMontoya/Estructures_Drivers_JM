/*
 * Keypad.h
 *
 *  Created on: Nov 8, 2023
 *      Author: Esteban
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include <stdint.h>

typedef struct{


}Keypad_t;

void keypad_init(void);

uint8_t keypad_handler(uint16_t column_to_evaluate);





#endif /* INC_KEYPAD_H_ */
