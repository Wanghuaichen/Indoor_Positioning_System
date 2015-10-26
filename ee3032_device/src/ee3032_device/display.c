#include "display.h"

static uint8 displayIcon[1440] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,
	0x0F,0x1F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
	0xC0,0xE0,0xF0,0xF8,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x07,
	0x0F,0x1F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x30,0x78,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x3F,0x1F,0x0F,0x07,0x03,
	0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xFE,0xFF,0x03,0x03,0x83,0xE3,0x23,
	0x23,0x27,0x66,0x0E,0x0C,0x1C,0x38,0x30,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x0F,0xC4,0xE0,0x33,0x70,
	0xF0,0xF0,0xD0,0x98,0x1C,0x2C,0x66,0xC3,0x83,0x03,0x03,0x07,0x0F,0xFD,0x7E,0x07,
	0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x0E,0x18,
	0x37,0x67,0xC7,0x83,0x03,0x06,0x0C,0x38,0xF1,0xF3,0x7C,0x0E,0x03,0x81,0x00,0x00,
	0x10,0xF1,0x03,0x0F,0x3E,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x01,0x01,0x03,0x02,0x06,0x07,0x03,0x00,0x18,0x1C,0x19,0x39,0x31,
	0x31,0x71,0x70,0x70,0x30,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x80,0x80,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0xC0,0xE0,0xC0,0x00,0x00,0x00,0x00,
	0x03,0x02,0x03,0x39,0x3F,0x1B,0x18,0x0C,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0C,0x0E,0x0F,0x07,0x83,0xF3,0xFB,0xBF,0xCF,0xE0,0xE0,0x70,0x78,
	0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xC0,0xC0,0xE0,0xF0,0xF0,0x78,0x78,0x7C,0x3C,0xFE,0xFF,0xFE,0x7C,
	0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x07,0x07,0x07,0x03,0x01,0x01,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x03,0x03,0x03,0x01,0x00,0x00,0xC0,0xF0,0xFE,0xFF,0xFF,0xCF,0xE3,0xF0,
	0xF8,0x78,0x3C,0x1E,0x0F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07,0x07,0x07,0x07,0x03,0x01,0x01,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xC0,
	0xC0,0xE0,0x80,0x00,0xC0,0xE0,0xC0,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x90,0xB8,0xF8,0xF8,0xFF,0x7F,0x3F,0x1E,0x0F,
	0x0F,0x0F,0x07,0x07,0x07,0x0F,0x0F,0x1E,0x1F,0x7F,0xFF,0xFB,0xF8,0xFC,0xB8,0x80,
	0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x73,0x73,0x7F,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,
	0x08,0x1E,0x3F,0x3F,0x3E,0x1E,0x08,0x00,0x00,0x00,0xC0,0xFF,0xFF,0xFF,0x7F,0x73,
	0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x0F,0x0F,0x07,0x37,0x7F,0x7F,0x3E,0xFC,
	0xFC,0xF8,0x70,0x38,0xF8,0xFC,0xFC,0x3C,0x3E,0x7F,0x7F,0x37,0x07,0x7F,0xE6,0xE0,
	0x76,0x1E,0x1E,0x8C,0x88,0x1C,0x1E,0x3E,0xF0,0xE0,0x70,0x60,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x01,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x1C,0x1F,0x0F,
	0xDC,0xF8,0xF1,0x33,0x33,0x71,0xF0,0xF8,0x0F,0x0F,0x0E,0x0C,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0x30,0x80,0x80,0xC0,0xC0,0x60,0x00,
	0x80,0xC0,0xC0,0x60,0x20,0x80,0xC0,0xC0,0x60,0x20,0x80,0xC0,0x60,0x20,0x00,0x00,
	0x80,0xC0,0x60,0x20,0x80,0x80,0xC0,0x60,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,
	0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,
	0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x8C,0x38,0x78,
	0x70,0x60,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x70,
	0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x06,
	0x00,0x00,0x00,0xFC,0xFC,0x0C,0xAF,0x0F,0xFC,0xFC,0x00,0x00,0x01,0x01,0x18,0x1C,
	0x0E,0x06,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x7F,0x7F,0x60,0x60,0x60,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/**
 * displaySummary
 * bit 7: all
 * bit 3: temperature
 * bit 2: power
 * bit 1: dot
 * bit 0: state
 */
static uint8 displaySummary = 0x8F;
static uint8 displayState = 0x02;
static uint8 displayDot = 0x02;
static uint8 displayPower = 60;
static uint16 displayTemperature = 270;

static void displayDotCircle(uint8 page, uint8 column);
static void displayCircle(uint8 page, uint8 column);
static void displayClearLastSixLine(void);
static void displayProjector(void);
static void displayBattary(void);
static void displayCelsius(void);
static void displayStateHandler(void);
static void displayDotHandler(void);
static void displayPowerHandler(void);
static void displayTemperatureHandler(void);

void displayStateUpdate(uint8 desktop)
{
	OS_CPU_SR  cpu_sr;

	OS_ENTER_CRITICAL();
	displaySummary |= 0x81;
	displayState = desktop;
	OS_EXIT_CRITICAL();
}

void displayDotUpdate(uint8 dot)
{
	OS_CPU_SR  cpu_sr;

	OS_ENTER_CRITICAL();
	displaySummary |= 0x82;
	displayDot = dot;
	OS_EXIT_CRITICAL();
}

void displayPowerUpdate(uint8 power)
{
	OS_CPU_SR  cpu_sr;

	OS_ENTER_CRITICAL();
	displaySummary |= 0x84;
	displayPower = power;
	OS_EXIT_CRITICAL();
}

void displayTemperatureUpdate(uint16 temperature)
{
	OS_CPU_SR  cpu_sr;

	OS_ENTER_CRITICAL();
	displaySummary |= 0x88;
	displayTemperature = temperature;
	OS_EXIT_CRITICAL();
}

void displayTask(void *pdata)
{
	OS_CPU_SR  cpu_sr;
	uint8 summary;

	(void)pdata;
	oledInitFromTask();
	OSTimeDly(2);
	oledClearScreen();
	displayBattary();
	displayCelsius();
	while (1) {
		OS_ENTER_CRITICAL();
		summary = displaySummary;
		displaySummary = 0x00;
		OS_EXIT_CRITICAL();
		if (summary & 0x80) {
			if (summary & 0x08) {
				displayTemperatureHandler();
			}
			if (summary & 0x04) {
				displayPowerHandler();
			}
			if (summary & 0x02) {
				displayDotHandler();
			}
			if (summary & 0x01) {
				displayStateHandler();
			}
		}
		OSTimeDly(10);
	}
}

static void displayDotCircle(uint8 page, uint8 column)
{
	uint8 buf[6];

	buf[0] = 0x3C;
	buf[1] = 0x42;
	buf[2] = 0x5A;
	buf[3] = 0x5A;
	buf[4] = 0x42;
	buf[5] = 0x3C;
	oledLoadPicture(page, column + 1, 1, 6, buf);
}

static void displayCircle(uint8 page, uint8 column)
{
	uint8 buf[6];

	buf[0] = 0x3C;
	buf[1] = 0x42;
	buf[2] = 0x42;
	buf[3] = 0x42;
	buf[4] = 0x42;
	buf[5] = 0x3C;
	oledLoadPicture(page, column + 1, 1, 6, buf);
}

static void displayClearLastSixLine(void)
{
	oledFillPage(2, 0x00);
	oledFillPage(3, 0x00);
	oledFillPage(4, 0x00);
	oledFillPage(5, 0x00);
	oledFillPage(6, 0x00);
	oledFillPage(7, 0x00);
}

static void displayProjector(void)
{
	oledPrint(4, 80, "Click!");
	oledLoadPicture(2, 0, 6, 48, &displayIcon[1152]);
}

static void displayBattary(void)
{
	uint8 buf[15];

	buf[0] = 0x1C;
	buf[1] = 0x7F;
	buf[2] = 0x41;
	buf[3] = 0x41;
	buf[4] = 0x41;
	buf[5] = 0x41;
	buf[6] = 0x41;
	buf[7] = 0x41;
	buf[8] = 0x41;
	buf[9] = 0x41;
	buf[10] = 0x41;
	buf[11] = 0x41;
	buf[12] = 0x41;
	buf[13] = 0x41;
	buf[14] = 0x7F;
	oledLoadPicture(0, 113, 1, 15, buf);
	oledPrint(0, 106, "%");
}

static void displayCelsius(void)
{
	uint8 buf[4];

	buf[0] = 0x00;
	buf[1] = 0x02;
	buf[2] = 0x05;
	buf[3] = 0x02;
	oledPrint(0, 12, ".");
	oledLoadPicture(0, 24, 1, 4, buf);
	oledPrint(0, 28, "C");
}

static void displayStateHandler(void)
{
	static uint8 prevState = 0x03;
	OS_CPU_SR  cpu_sr;
	uint8 curState;

	OS_ENTER_CRITICAL();
	curState = displayState;
	OS_EXIT_CRITICAL();
	switch (curState) {
	case 0x00:
		if (prevState == 0x03) {
			displayClearLastSixLine();
			displayDotCircle(3, 48);
			displayCircle(4, 48);
			displayCircle(5, 48);
			displayCircle(6, 48);
			oledPrint(3, 56, "3D Mouse");
			oledPrint(4, 56, "3D Object");
			oledPrint(5, 56, "Idle");
			oledPrint(6, 56, "Calibration");
			oledLoadPicture(2, 0, 6, 48, &displayIcon[0]);
		}
		oledPrint(1, 28, "  3D Mouse ");
		break;
	case 0x01:
		if (prevState == 0x03) {
			displayClearLastSixLine();
			displayCircle(3, 48);
			displayDotCircle(4, 48);
			displayCircle(5, 48);
			displayCircle(6, 48);
			oledPrint(3, 56, "3D Mouse");
			oledPrint(4, 56, "3D Object");
			oledPrint(5, 56, "Idle");
			oledPrint(6, 56, "Calibration");
			oledLoadPicture(2, 0, 6, 48, &displayIcon[288]);
		}
		oledPrint(1, 28, " 3D Object ");
		break;
	case 0x02:
		if (prevState == 0x03) {
		displayClearLastSixLine();
		displayCircle(3, 48);
		displayCircle(4, 48);
		displayDotCircle(5, 48);
		displayCircle(6, 48);
		oledPrint(3, 56, "3D Mouse");
		oledPrint(4, 56, "3D Object");
		oledPrint(5, 56, "Idle");
		oledPrint(6, 56, "Calibration");
		oledLoadPicture(2, 0, 6, 48, &displayIcon[576]);
	}
		oledPrint(1, 28, "    Idle   ");
		break;
	case 0x03:
		oledPrint(1, 28, "Calibration");
		displayClearLastSixLine();
		displayProjector();
		break;
	default:
		break;
	}
	prevState = curState;
}

static void displayDotHandler(void)
{
	OS_CPU_SR  cpu_sr;
	uint8 dot;
	uint8 i;

	OS_ENTER_CRITICAL();
	dot = displayDot;
	OS_EXIT_CRITICAL();
	for (i = 0; i < 4; i++) {
		if (i == dot) {
			displayDotCircle(i + 3, 48);
		} else {
			displayCircle(i + 3, 48);
		}
		oledLoadPicture(2, 0, 6, 48, &displayIcon[dot * 288]);
	}
}

static void displayPowerHandler(void)
{
	OS_CPU_SR  cpu_sr;
	uint8 power;
	uint8 buf[10];
	uint8 i;

	OS_ENTER_CRITICAL();
	power = displayPower;
	OS_EXIT_CRITICAL();
	if (power == 100) {
		oledPrint(0, 88, "100");
	} else {
		buf[3] = 0;
		buf[2] = power % 10 + '0';
		buf[1] = (power / 10) % 10;
		buf[0] = ' ';
		if (buf[1] == 0) {
			buf[1] = ' ';
		} else {
			buf[1] += '0';
		}
		oledPrint(0, 88, (char *)buf);
	}
	power /= 10;
	for (i = 0; i < 10 - power; i++) {
		buf[i] = 0x41;
	}
	for (i = 10 - power; i < 10; i++) {
		buf[i] = 0x5D;
	}
	oledLoadPicture(0, 116, 1, 10, buf);
}

static void displayTemperatureHandler(void)
{
	OS_CPU_SR  cpu_sr;
	uint16 temperature;
	uint8 buf[3];

	OS_ENTER_CRITICAL();
	temperature = displayTemperature;
	OS_EXIT_CRITICAL();
	buf[2] = 0;
	buf[1] = (temperature / 10) % 10 + '0';
	buf[0] = temperature / 100;
	if (buf[0] == 0) {
		buf[0] = ' ';
	} else {
		buf[0] += '0';
	}
	oledPrint(0, 0, (char *)buf);
	buf[1] = temperature % 10 + '0';
	oledPrint(0, 18, (char *)&buf[1]);
}
