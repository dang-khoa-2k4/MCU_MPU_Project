#ifndef _FSM_H_
#define _FSM_H_

#include "fsm_auto.h"
#include "fsm_manual.h"
#include "fsm_tuning.h"

typedef enum 
{
    AUTO = 0,
    MANUAL = 1,
    TUNING = 2,
    INIT_FSM = 3
} MODE;

extern MODE fsm_state;
extern uint8_t lcd_data[4];

extern uint8_t time[3];
void fsm_init(void);
void fsm_run(void);

#endif // _FSM_H_