#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CHIP "/dev/gpiochip0"
#define LINE 17

int main(void)
{
	struct gpiod_chip* chip = gpiod_chip_open(CHIP);
	if (!chip)
	{
		fprintf(stderr, "Error opening gpio chip\n");
		exit(1);
	}

	struct gpiod_line_config* line_config = gpiod_line_config_new();
	if (!line_config)
	{
		gpiod_chip_close(chip);

		fprintf(stderr, "Error getting line config\n");
		exit(1);
	}

	struct gpiod_line_settings* line_settings = gpiod_line_settings_new();
	if (!line_settings)
	{
		gpiod_chip_close(chip);
		gpiod_line_config_free(line_config);

		fprintf(stderr, "Error creating line settings\n");
		exit(1);
	}
	gpiod_line_settings_set_direction(line_settings, GPIOD_LINE_DIRECTION_OUTPUT);

	unsigned int lines[] = {LINE};
	gpiod_line_config_add_line_settings(line_config, lines, 1, line_settings);

	struct gpiod_line_request* line_request = gpiod_chip_request_lines(chip, NULL, line_config);
	if (!line_request)
	{
		gpiod_line_settings_free(line_settings);
		gpiod_line_config_free(line_config);
		gpiod_chip_close(chip);

		fprintf(stderr, "Error getting line request\n");
		exit (1);
	}

	// Turn LED on
	for (int i = 0; i < 5; i++)
	{
		printf("LED on\n");
		gpiod_line_request_set_value(line_request, LINE, GPIOD_LINE_VALUE_ACTIVE);
		sleep(1);
		printf("LED off\n");
		gpiod_line_request_set_value(line_request, LINE, GPIOD_LINE_VALUE_INACTIVE);
		sleep(1);
	}
	
	gpiod_line_request_release(line_request);
	gpiod_line_config_free(line_config);
	gpiod_chip_close(chip);

	return 0;
}
