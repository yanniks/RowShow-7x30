<<<<<<< HEAD
/* Copyright (c) 2010-2011, Code Aurora Forum. All rights reserved.
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
 *
<<<<<<< HEAD
=======
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/pm_runtime.h>
<<<<<<< HEAD
#include <linux/usb/msm_hsusb.h>
#include <linux/usb/msm_hsusb_hw.h>
#include <linux/usb/ulpi.h>
#include <linux/usb/otg.h>

#include <linux/usb/htc_info.h>
static struct usb_info *the_usb_info;
=======
#include <linux/usb/msm_hsusb_hw.h>
#include <linux/usb/ulpi.h>
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

#include "ci13xxx_udc.c"

#define MSM_USB_BASE	(udc->regs)

static irqreturn_t msm_udc_irq(int irq, void *data)
{
	return udc_irq();
}

static void ci13xxx_msm_notify_event(struct ci13xxx *udc, unsigned event)
{
<<<<<<< HEAD
	/* struct device *dev = udc->gadget.dev.parent; */
=======
	struct device *dev = udc->gadget.dev.parent;
	int val;
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

	switch (event) {
	case CI13XXX_CONTROLLER_RESET_EVENT:
		dev_dbg(dev, "CI13XXX_CONTROLLER_RESET_EVENT received\n");
		writel(0, USB_AHBBURST);
		writel(0, USB_AHBMODE);
		break;
<<<<<<< HEAD
=======
	case CI13XXX_CONTROLLER_STOPPED_EVENT:
		dev_dbg(dev, "CI13XXX_CONTROLLER_STOPPED_EVENT received\n");
		/*
		 * Put the transceiver in non-driving mode. Otherwise host
		 * may not detect soft-disconnection.
		 */
		val = otg_io_read(udc->transceiver, ULPI_FUNC_CTRL);
		val &= ~ULPI_FUNC_CTRL_OPMODE_MASK;
		val |= ULPI_FUNC_CTRL_OPMODE_NONDRIVING;
		otg_io_write(udc->transceiver, val, ULPI_FUNC_CTRL);
		break;
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
	default:
		dev_dbg(dev, "unknown ci13xxx_udc event\n");
		break;
	}
}

static struct ci13xxx_udc_driver ci13xxx_msm_udc_driver = {
	.name			= "ci13xxx_msm",
	.flags			= CI13XXX_REGS_SHARED |
				  CI13XXX_REQUIRE_TRANSCEIVER |
				  CI13XXX_PULLUP_ON_VBUS |
<<<<<<< HEAD
				  CI13XXX_DISABLE_STREAMING |
				  CI13XXX_ZERO_ITC,
=======
				  CI13XXX_DISABLE_STREAMING,
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

	.notify_event		= ci13xxx_msm_notify_event,
};

static int ci13xxx_msm_probe(struct platform_device *pdev)
{
	struct resource *res;
<<<<<<< HEAD
	struct usb_info *ui;
=======
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
	void __iomem *regs;
	int irq;
	int ret;

	dev_dbg(&pdev->dev, "ci13xxx_msm_probe\n");
<<<<<<< HEAD
	ui = kzalloc(sizeof(struct usb_info), GFP_KERNEL);
	if (!ui)
		return -ENOMEM;
	the_usb_info = ui;
=======
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(&pdev->dev, "failed to get platform resource mem\n");
		return -ENXIO;
	}

	regs = ioremap(res->start, resource_size(res));
	if (!regs) {
		dev_err(&pdev->dev, "ioremap failed\n");
		return -ENOMEM;
	}

	ret = udc_probe(&ci13xxx_msm_udc_driver, &pdev->dev, regs);
	if (ret < 0) {
		dev_err(&pdev->dev, "udc_probe failed\n");
		goto iounmap;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "IRQ not found\n");
		ret = -ENXIO;
		goto udc_remove;
	}

	ret = request_irq(irq, msm_udc_irq, IRQF_SHARED, pdev->name, pdev);
	if (ret < 0) {
		dev_err(&pdev->dev, "request_irq failed\n");
		goto udc_remove;
	}
<<<<<<< HEAD
	INIT_DELAYED_WORK(&ui->chg_stop, usb_chg_stop);
=======
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

	pm_runtime_no_callbacks(&pdev->dev);
	pm_runtime_enable(&pdev->dev);

	return 0;

udc_remove:
	udc_remove();
iounmap:
	iounmap(regs);

	return ret;
}

<<<<<<< HEAD
static void ci13xxx_msm_shutdown(struct platform_device *pdev)
{
	struct msm_otg *motg;
	struct ci13xxx *udc = _udc;

	if (!udc || !udc->transceiver)
		return;

	motg = container_of(udc->transceiver, struct msm_otg, otg);

	if (!atomic_read(&motg->in_lpm))
		ci13xxx_pullup(&udc->gadget, 0);

}

static struct platform_driver ci13xxx_msm_driver = {
	.probe = ci13xxx_msm_probe,
	.shutdown = ci13xxx_msm_shutdown,
=======
static struct platform_driver ci13xxx_msm_driver = {
	.probe = ci13xxx_msm_probe,
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
	.driver = { .name = "msm_hsusb", },
};

static int __init ci13xxx_msm_init(void)
{
	return platform_driver_register(&ci13xxx_msm_driver);
}
module_init(ci13xxx_msm_init);
