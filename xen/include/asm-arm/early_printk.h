/*
 * printk() for use before the final page tables are setup.
 *
 * Copyright (C) 2012 Citrix Systems, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __ARM_EARLY_PRINTK_H__
#define __ARM_EARLY_PRINTK_H__

#include <xen/config.h>

#ifdef CONFIG_EARLY_PRINTK

/* need to add the uart address offset in page to the fixmap address */
#define EARLY_UART_VIRTUAL_ADDRESS \
    (FIXMAP_ADDR(FIXMAP_CONSOLE) +(EARLY_UART_BASE_ADDRESS & ~PAGE_MASK))

#endif

#ifndef __ASSEMBLY__

#ifdef CONFIG_EARLY_PRINTK

void early_printk(const char *fmt, ...)
    __attribute__((format (printf, 1, 2)));
void noreturn early_panic(const char *fmt, ...)
    __attribute__((format (printf, 1, 2)));

#else

static inline  __attribute__((format (printf, 1, 2))) void
early_printk(const char *fmt, ...)
{}

static inline void noreturn
__attribute__((format (printf, 1, 2))) early_panic(const char *fmt, ...)
{while(1);}

#endif /* !CONFIG_EARLY_PRINTK */

#endif	/* __ASSEMBLY__ */

#endif
