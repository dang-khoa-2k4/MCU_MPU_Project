/*
 * fsm_automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#include "fsm_auto.h"

static trafficLight_t light_1;
static trafficLight_t light_2;

static uint8_t auto_time[2][3] = { { 0 }, { 0 } };
static uint8_t color_flag_1 = 0;
static uint8_t color_flag_2 = 0;

void automatic_init(void)
{
	light_1 = INIT_AUTO;
	light_2 = INIT_AUTO;
	auto_time[0][RED_AUTO] = time[RED_AUTO];
	auto_time[0][GREEN_AUTO] = time[GREEN_AUTO];
	auto_time[0][AMBER_AUTO] = time[AMBER_AUTO];
	auto_time[1][RED_AUTO] = time[RED_AUTO];
	auto_time[1][GREEN_AUTO] = time[GREEN_AUTO];
	auto_time[1][AMBER_AUTO] = time[AMBER_AUTO];
}

static void count_down()
{
	if (isTimerExpired(LIGHT_TIMER))
	{
		auto_time[0][light_1]--;
		auto_time[1][light_2]--;
		if (auto_time[0][light_1] <= 0)
		{
			auto_time[0][light_1] = time[light_1];
			if (color_flag_1 <= 0)
				color_flag_1 = 1;
		}
		if (auto_time[1][light_2] <= 0)
		{
			auto_time[1][light_2] = time[light_2];
			if (color_flag_2 <= 0)
				color_flag_2 = 1;
		}
		setTimer(LIGHT_TIMER, 100);
	}
}

void automatic_generate_lcd_data(uint8_t * data)
{
	data[0] = light_1;
	data[1] = light_2;
	data[2] = auto_time[0][light_1];
	data[3] = auto_time[1][light_2];
}

void automatic_run(void)
{
	switch (light_1)
	{
	case INIT_AUTO:
		if (1)
		{
			light_1 = RED_AUTO;
			setTimer(LIGHT_TIMER, 100);
			light_1_handle(light_1);
		}
		break;
	case AMBER_AUTO:
		if (color_flag_1 > 0)
		{
			light_1 = RED_AUTO;
			light_1_handle(light_1);
			color_flag_1--;
		}
		break;
	case GREEN_AUTO:
		if (color_flag_1 > 0)
		{
			light_1 = AMBER_AUTO;
			light_1_handle(light_1);
			color_flag_1--;
		}
		break;
	case RED_AUTO:
		if (color_flag_1 > 0)
		{
			light_1 = GREEN_AUTO;
			light_1_handle(light_1);
			color_flag_1--;
		}
		break;
	default:
		break;
	}

	switch (light_2)
	{
	case INIT_AUTO:
		if (1)
		{
			light_2 = GREEN_AUTO;
			setTimer(LIGHT_TIMER, 100);
			light_2_handle(light_2);
		}
		break;
	case AMBER_AUTO:
		if (color_flag_2 > 0)
		{
			light_2 = RED_AUTO;
			light_2_handle(light_2);
			color_flag_2--;
		}
		break;
	case GREEN_AUTO:
		if (color_flag_2 > 0)
		{
			light_2 = AMBER_AUTO;
			light_2_handle(light_2);
			color_flag_2--;
		}
		break;
	case RED_AUTO:
		if (color_flag_2 > 0)
		{
			light_2 = GREEN_AUTO;
			light_2_handle(light_2);
			color_flag_2--;
		}
		break;
	default:
		break;
	}
	count_down();
}
