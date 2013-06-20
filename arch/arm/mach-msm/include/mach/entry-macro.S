<<<<<<< HEAD
/*
 * Copyright (c) 2009-2010, Code Aurora Forum. All rights reserved.
=======
/* Copyright (c) 2010, Code Aurora Forum. All rights reserved.
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
<<<<<<< HEAD
 */

#if defined(CONFIG_MSM_VIC)
#include <mach/entry-macro-vic.S>
#elif defined(CONFIG_ARM_GIC)
#include <mach/entry-macro-qgic.S>
#else
#error "No interrupt controller selected!"
=======
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#if defined(CONFIG_ARM_GIC)
#include <mach/entry-macro-qgic.S>
#else
#include <mach/entry-macro-vic.S>
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
#endif
