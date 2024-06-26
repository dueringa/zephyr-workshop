#include <zephyr/zbus/zbus.h>
#include <zephyr/shell/shell.h>

#include "message_channel.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app, CONFIG_LED_MODULE_LOG_LEVEL);

static void led_msg(enum sys_states msg)
{
	int err;

	err = zbus_chan_pub(&led_ch, &msg, K_SECONDS(1));
	if (err) {
		LOG_ERR("zbus_chan_pub, error: %d", err);
	}
}

static int cmd_led(const struct shell *sh, size_t argc, char **argv,
		    void *data)
{
	int val = (intptr_t)data;

	switch (val) {
	case 0:
		led_msg(SYS_SLEEP);
		break;
	case 1:
		led_msg(SYS_STANDBY);
		break;
	/* Add your code here */

	/* */
	default:
		shell_print(sh, "Invalid argument");
		break;
	}

	return 0;
}

SHELL_SUBCMD_DICT_SET_CREATE(sub_led_cmds, cmd_led,
	(sys_sleep, 0, "System is sleeping"),
	(sys_standby, 1, "System is in standby")
	/* Add your code here */

	/* */
);

SHELL_STATIC_SUBCMD_SET_CREATE(my_app_cmds,
	SHELL_CMD(led, &sub_led_cmds, "Led module commands", NULL),
	SHELL_SUBCMD_SET_END /* Array terminated. */
);
SHELL_CMD_REGISTER(my_app, &my_app_cmds, "my App test", NULL);

int main(void)
{
	return 0;
}
