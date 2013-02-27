/*
 * CORERIVER TOUCHCORE 360L touchkey driver
 *
 * Copyright (C) 2012 Samsung Electronics Co.Ltd
 * Author: Taeyoon Yoon <tyoony.yoon@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef __LINUX_TC360_H
#define __LINUX_TC360_H

#define TC360_DEVICE	"tc360"

/*
 * struct regulator
 *
 * One for each consumer device.
 * Keep this in sync with drivers/regulator/core.c.
 */
struct regulator {
	struct device *dev;
	struct list_head list;
	int uA_load;
	int min_uV;
	int max_uV;
	char *supply_name;
	struct device_attribute dev_attr;
	struct regulator_dev *rdev;
	int use;
};

enum {
	TC360_SUSPEND_WITH_POWER_OFF = 0,
	TC360_SUSPEND_WITH_SLEEP_CMD,
};

struct tc360_platform_data {
	u8	enable;
	u32	gpio_scl;
	u32	gpio_sda;
	u32	gpio_int;
	u32	gpio_en;
	int	udelay;
	int	num_key;
	int	*keycodes;
	u8	suspend_type;
	u8	*touchscreen_is_pressed;
	u8	exit_flag;
	int	(*setup_power)(struct device *, bool);
	void	(*power)(bool);
	void	(*led_power)(bool);
	void	(*pin_configure)(bool to_gpios);
	void	(*int_set_pull)(bool);
	void	(*set_vled_regulator_state_mem_constraint)(bool);
};

#define SEC_FAC_TK
#if defined(SEC_FAC_TK)
extern struct class *sec_class;
#endif

#endif /* __LINUX_TC360_H */
